#pragma once

#include "NBezier/bezier_split.h"
#include "NBezier/defines.h"

#include <boost/qvm/map_mat_vec.hpp>
#include <boost/qvm/mat.hpp>
#include <boost/qvm/vec_operations.hpp>

#include <boost/math/ccmath/ccmath.hpp>

#include <concepts>
#include <memory>
#include <optional>
#include <type_traits>

OpenNameSpace(NBezier);

struct BezierLength
{
    StaticClass(BezierLength);

public:
    template<typename BezierPointsType>
    static constexpr auto get(const BezierPointsType& p)
    {
        return process(p, 0);
    }

private:
    template<typename BezierPointsType>
    static constexpr auto process(const BezierPointsType& points, const size_t& depth)
    {
        typedef typename BezierPointsType::PointsScalar PointScalar;

        const auto& points_length = pointsLength(points);

        if(points_length)
            return *points_length;

        const auto split = BezierSplit::at(points, PointScalar(0.5));
        const auto length_left = process(split.m_left, depth + 1);
        const auto length_right = process(split.m_right, depth + 1);

        return length_left + length_right;
    }

    template<typename BezierPointsType>
    static constexpr auto pointsLength(const BezierPointsType& points)
    {
        typedef typename BezierPointsType::PointsScalar PointScalar;
        constexpr auto NumPoints = BezierPointsType::PointsDegree + 1;

        const auto length_parts = partsLength<PointScalar>(points, std::make_index_sequence<NumPoints - 1>{});
        const auto length_start_end = getPointsDiffNorm<0, NumPoints - 1>(points);

        auto result = std::optional<PointScalar>{};

        if(boost::math::ccmath::abs(length_parts - length_start_end) <= PointScalar(1e-07))
            result = length_parts;

        return result;
    }

    template<typename Scalar, size_t... Indices>
    static constexpr auto partsLength(const auto& points, std::index_sequence<Indices...>)
    {
        auto result = Scalar(0);

        (addPointsDiff<Indices, Indices + 1>(points, result), ...);

        return result;
    }

    template<size_t I, size_t J>
    static constexpr auto getPointsDiffNorm(const auto& points)
    {
        if(std::is_constant_evaluated())
        {
            const auto p0 = points.template getPoint<I>();
            const auto p1 = points.template getPoint<J>();

            return boost::math::ccmath::sqrt(boost::qvm::mag_sqr(p1 - p0));
        }
        else
        {
            const auto& p0 = boost::qvm::col<I>(points.getPoints());
            const auto& p1 = boost::qvm::col<J>(points.getPoints());

            return boost::qvm::mag(p1 - p0);
        }
    }

    template<size_t I, size_t J>
    static constexpr void addPointsDiff(const auto& points, auto& length)
    {
        length += getPointsDiffNorm<I, J>(points);
    }
};

CloseNameSpace(NBezier);