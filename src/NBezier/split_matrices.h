#pragma once

#include "NBezier/defines.h"

#include "NBezier/bezier_requirements.h"

#include <boost/qvm/mat.hpp>

#include <concepts>

OpenNameSpace(NBezier);

template<typename Scalar, size_t Degree>
concept SplitMatricesRequirement = BezierType<Scalar> && Degree > 0;

template<typename Scalar, size_t Degree>
    requires SplitMatricesRequirement<Scalar, Degree>
struct SplitMatriesResult
{
    boost::qvm::mat<Scalar, Degree, Degree> m_left = {};
    boost::qvm::mat<Scalar, Degree, Degree> m_right = {};
};

struct SplitMatrices
{
    StaticClass(SplitMatrices);

    template<typename Scalar, size_t Degree>
        requires SplitMatricesRequirement<Scalar, Degree>
    static constexpr auto get()
    {
        return SplitMatriesResult<Scalar, Degree>{};
    }
};

CloseNameSpace(NBezier);