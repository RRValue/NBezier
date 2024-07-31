#pragma once

#include "polynomial_coefficients.h"

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
        template<size_t Derivative, typename Scalar, size_t NParameter>
        static constexpr auto getExponents(Scalar a)
        {
            return boost::qvm::vec<Scalar, NParameter>{};
        }

        template<size_t Derivative, typename Scalar, size_t NParameter, size_t Dimension>
            requires PolynomialEvaluationType<Scalar> &&  //
                     PolynomialEvaluationRequirement<NParameter, Dimension>
        static constexpr boost::qvm::vec<Scalar, Dimension> eval(boost::qvm::mat<Scalar, NParameter, Dimension> p, Scalar a)
        {
            const auto c = PolynomialCoefficients<Scalar, NParameter - 1, Derivative>::getDiagonal();
            const auto e = getExponents<Derivative, Scalar, NParameter>(a);

            return p * c * e;
        }
    };
}  // namespace NBezier