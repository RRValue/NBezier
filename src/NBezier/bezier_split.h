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
    const BezierPoints<Scalar, Dimension, Degree> m_left = {};
    const BezierPoints<Scalar, Dimension, Degree> m_right = {};
};

struct BezierSplit
{
    StaticClass(BezierSplit);

    template<typename Scalar, size_t Dimension, size_t Degree>
        requires BezierSplitRequirement<Scalar, Dimension, Degree>
    static constexpr auto at(const BezierPoints<Scalar, Dimension, Degree>& p, const Scalar& at)
    {
        return splitPoints(p, at, std::make_index_sequence<Degree>{});
    }

private:
    template<std::size_t Index, typename Scalar, size_t Dimension, size_t Degree>
    static constexpr void splitPoint(const BezierPoints<Scalar, Dimension, Degree>& p, BezierSplitResult<Scalar, Dimension, Degree>& r, const Scalar& at)
    {
        // p_left reduce p from right (Degree - Index - 1) times)
        // p_right reduce p from left (Index + 1) times)

        //r.m_left[Index] = Bezir::point(p_left, at);
        //r.m_right[Degree - Index - 1] = Bezir::point(p_right, at);

        int ii = 0;
        ii++;
    }

    template<typename Scalar, size_t Dimension, size_t Degree, std::size_t... Indices>
    static constexpr auto splitPoints(const BezierPoints<Scalar, Dimension, Degree>& p, const Scalar& at, std::index_sequence<Indices...>)
    {
        BezierSplitResult<Scalar, Dimension, Degree> result = {};

        (splitPoint<Indices>(p, result, at), ...);

        return result;
    }
};

CloseNameSpace(NBezier);