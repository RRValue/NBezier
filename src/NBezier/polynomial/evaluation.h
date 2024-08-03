#pragma once

#include "NBezier/defines.h"

#include "NBezier/polynomial/derivative_factors.h"
#include "NBezier/polynomial/variable.h"

#include <boost/qvm/mat.hpp>
#include <boost/qvm/mat_operations.hpp>

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_mat_operations.hpp>

#include <boost/qvm/map_mat_vec.hpp>

#include <concepts>

OpenNameSpace(NBezier);
OpenNameSpace(Polynomial);

template<typename ScalarType>
concept EvaluationType = std::floating_point<ScalarType>;

template<size_t NParameter, size_t Dimension>
concept EvaluationRequirement = NParameter > 0 && Dimension > 0;

struct Evaluation
{
    StaticClass(Evaluation);

    template<size_t Derivative, typename Scalar, size_t NParameter, size_t Dimension>
        requires EvaluationType<Scalar> &&  //
                 EvaluationRequirement<NParameter, Dimension>
    static constexpr auto eval(boost::qvm::mat<Scalar, Dimension, NParameter> p, Scalar a)
    {
        const auto c = DerivativeFactors<Scalar, NParameter - 1, Derivative>::getDiagonal();
        const auto v = Variable<Scalar, NParameter - 1>::variableVector<Derivative>(a);

        return p * c * v;
    }
};

CloseNameSpace(Polynomial);
CloseNameSpace(NBezier);