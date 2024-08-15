#pragma once

#include "NBezier/defines.h"

#include "NBezier/bezier.h"
#include "NBezier/bezier_requirements.h"

#include <boost/math/ccmath/sqrt.hpp>
#include <boost/qvm/mat_operations.hpp>
#include <boost/qvm/vec_operations.hpp>

#include <concepts>

OpenNameSpace(NBezier);

template<typename Scalar, size_t Dimension, size_t Degree>
concept BezierSplitRequirement = BezierType<Scalar> &&                     //
                                 BezierDimensionRequirement<Dimension> &&  //
                                 Degree > 0;

template<typename Scalar, size_t Dimension, size_t Degree>
    requires BezierSplitRequirement<Scalar, Dimension, Degree>
struct BezierSplitResult
{
    BezierPoints<Scalar, Dimension, Degree> m_left = {};
    BezierPoints<Scalar, Dimension, Degree> m_right = {};
};

struct BezierSplit
{
    StaticClass(BezierSplit);

    template<typename Scalar, size_t Dimension, size_t Degree>
        requires BezierSplitRequirement<Scalar, Dimension, Degree>
    static constexpr auto at(const BezierPoints<Scalar, Dimension, Degree>& p, const Scalar& at)
    {
        return splitPoints(p, at, std::make_index_sequence<Degree + 1>{});
    }

private:
    template<typename Scalar, size_t Dimension, size_t Degree, std::size_t... Indices>
    static constexpr auto splitPoints(const BezierPoints<Scalar, Dimension, Degree>& p, const Scalar& at, std::index_sequence<Indices...>)
    {
        BezierSplitResult<Scalar, Dimension, Degree> result = {};

        (splitPoint<Degree, Indices>(p, result, at), ...);

        return result;
    }

    template<size_t Degree, std::size_t Index>
    NBInline static constexpr void splitPoint(const auto& p, auto& r, const auto& at)
    {
        r.m_left.setPoint<Index>(Bezier::point(p.reduceFromLeft<Index>(), at));
        r.m_right.setPoint<Degree - Index>(Bezier::point(p.reduceFromRight<Index>(), at));
    }
};

CloseNameSpace(NBezier);