#pragma once

#include "NBezier/bezier_requirements.h"
#include "NBezier/bezier_split.h"
#include "NBezier/defines.h"
#include "NBezier/math/pow.h"
#include "NBezier/bezier_length_result.h"

#include <boost/qvm/mat.hpp>
#include <boost/qvm/vec_operations.hpp>

#include <boost/math/ccmath/ccmath.hpp>

#include <array>
#include <concepts>
#include <memory>
#include <optional>
#include <type_traits>

OpenNameSpace(NBezier);

struct BezierLength
{
    StaticClass(BezierLength);

public:
    template<size_t CacheDepth = 3, typename BezierPointsType>
    static constexpr auto get(const BezierPointsType& points)
    {
        typedef typename BezierPointsType::PointsScalar PointScalar;

        auto result = LengthResult<PointScalar, CacheDepth>{};

        result.m_length = process<CacheDepth, 0>(points, result.m_cache, size_t(0));

        return result;
    }

private:
    template<size_t CacheDepth, size_t Depth, typename BezierPointsType>
    static constexpr auto process(const BezierPointsType& points, auto& cache, const size_t& cachePos)
    {
        typedef typename BezierPointsType::PointsScalar PointScalar;

        const auto& points_length = pointsLength(points);

        if(points_length)
            return *points_length;

        const auto split = BezierSplit::at(points, PointScalar(0.5));

        constexpr auto DepthInc = []() -> size_t {
            if constexpr(Depth < CacheDepth)
                return Depth + size_t(1);
            else
                return Depth;
        }();

        const auto cache_pos_left = [&]() -> size_t {
            if constexpr(Depth < CacheDepth)
                return cachePos + size_t(1);
            else
                return cache.size() + 1;
        }();

        const auto cache_pos_right = [&]() -> size_t {
            if constexpr(Depth < CacheDepth)
                return cachePos + Math::Pow::get2<size_t, CacheDepth - Depth>();
            else
                return cache.size() + 1;
        }();

        const auto length_left = process<CacheDepth, DepthInc>(split.m_left, cache, cache_pos_left);
        const auto length_right = process<CacheDepth, DepthInc>(split.m_right, cache, cache_pos_right);
        const auto length = length_left + length_right;

        writeChache(length, cache, cachePos);

        return length;
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

    static constexpr void writeChache(const auto& value, auto& cache, const auto& cachePos)
    {
        if(cachePos == 0 || cachePos > cache.size())
            return;

        cache[cachePos - 1] = value;
    }
};

CloseNameSpace(NBezier);