#pragma once

#include "polynomial_coefficients.h"
#include "polynomial_variable.h"

#include <boost/qvm/mat.hpp>
#include <boost/qvm/mat_operations.hpp>

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_mat_operations.hpp>

#include <boost/qvm/map_mat_vec.hpp>

#include <concepts>

namespace NBezier
{
    template<typename ScalarType>
    concept PolynomialEvaluationType = std::floating_point<ScalarType>;

    template<size_t NParameter, size_t Dimension>
    concept PolynomialEvaluationRequirement = NParameter > 0 && Dimension > 0;

    struct PolynomialEvaluation
    {
        template<size_t Derivative, typename Scalar, size_t NParameter, size_t Dimension>
            requires PolynomialEvaluationType<Scalar> &&  //
                     PolynomialEvaluationRequirement<NParameter, Dimension>
        static constexpr auto eval(boost::qvm::mat<Scalar, Dimension, NParameter> p, Scalar a)
        {
            const auto c = PolynomialCoefficients<Scalar, NParameter - 1, Derivative>::getDiagonal();
            const auto v = PolynomialVariable<Scalar, NParameter - 1>::variableVector<Derivative>(a);

            return p * c * v;
        }
    };
}  // namespace NBezier