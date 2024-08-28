#pragma once

#include "NBezier/defines.h"

#include "NBezier/bezier.h"
#include "NBezier/bezier_requirements.h"
#include "NBezier/split_matrices.h"

#include <boost/qvm/mat_operations.hpp>

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
        const auto matrices = SplitMatrices::get<Scalar, Degree + 1>(at);
        const auto& points = p.getPoints();

        return BezierSplitResult<Scalar, Dimension, Degree>{points * matrices.m_left,  //
                                                            points * matrices.m_right};
    }
};

CloseNameSpace(NBezier);