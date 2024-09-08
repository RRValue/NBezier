#pragma once

#include "NBezier/bezier_split.h"
#include "NBezier/defines.h"

#include <boost/qvm/map_mat_vec.hpp>
#include <boost/qvm/mat.hpp>
#include <boost/qvm/vec_operations.hpp>

#include <concepts>
#include <memory>
#include <optional>

OpenNameSpace(NBezier);

template<size_t Dimension, size_t NParameter>
concept BezierLengthRequirement = NParameter > 0 && Dimension > 0;

template<typename Scalar>
struct BezierLengthNode
{
    using Length = std::optional<Scalar>;
    using BezierLengthNodePtr = std::unique_ptr<BezierLengthNode>;

    Length m_length = {};
    Scalar m_alpha = Scalar(0);
    BezierLengthNode* m_left = nullptr;
    BezierLengthNode* m_right = nullptr;
};

struct BezierLength
{
    StaticClass(BezierLength);

public:
    template<typename PointsType>
    static constexpr auto get(const PointsType& p)
    {
        typedef typename boost::qvm::mat_traits<PointsType>::scalar_type PointScalar;
        constexpr auto Dim = boost::qvm::mat_traits<PointsType>::rows;
        constexpr auto NumPoints = boost::qvm::mat_traits<PointsType>::cols;

        static_assert(BezierLengthRequirement<Dim, NumPoints>);

        auto result = BezierLengthNode<PointScalar>{};

        process(result, p, 0);

        return result;
    }

private:
    template<typename PointsType>
    static constexpr void process(auto& node, const PointsType& points, const size_t& depth)
    {
        typedef typename boost::qvm::mat_traits<PointsType>::scalar_type PointScalar;

        const auto& points_length = pointsLength(points);

        if(points_length)
        {
            node.m_length = points_length;

            return;
        }
        const auto split = BezierSplit::at(points, PointScalar(0.5));

        node.m_left = new BezierLengthNode<PointScalar>{};
        node.m_right = new BezierLengthNode<PointScalar>{};

        process(*node.m_left, split.m_left.getPoints(), depth + 1);
        process(*node.m_right, split.m_right.getPoints(), depth + 1);
    }

    template<typename PointsType>
    static constexpr auto pointsLength(const PointsType& points)
    {
        typedef typename boost::qvm::mat_traits<PointsType>::scalar_type PointScalar;
        constexpr auto NumPoints = boost::qvm::mat_traits<PointsType>::cols;

        const auto length_parts = partsLength<PointScalar>(points, std::make_index_sequence<NumPoints - 1>{});
        auto length_start_end = boost::qvm::mag(boost::qvm::col<NumPoints - 1>(points) - boost::qvm::col<0>(points));

        auto result = std::optional<PointScalar>{};

        if(std::abs(length_parts - length_start_end) <= PointScalar(1e-05))
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
    static constexpr void addPointsDiff(const auto& points, auto& length)
    {
        const auto& p0 = boost::qvm::col<I>(points);
        const auto& p1 = boost::qvm::col<J>(points);

        length += boost::qvm::mag(p1 - p0);
    }
};

CloseNameSpace(NBezier);