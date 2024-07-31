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
        template<typename Scalar, size_t Index>
        static constexpr auto mult(Scalar& e, Scalar a)
        {
            e *= a;
        }

        template<typename Scalar, size_t... Indices>
        static constexpr auto generateExponent(Scalar a, std::index_sequence<Indices...>)
        {
            auto e = Scalar(1);

            (mult<Scalar, Indices>(e, a), ...);

            return e;
        }

        template<typename Scalar, size_t NParameter, size_t Index>
        static constexpr void setExponent(auto& c, Scalar a)
        {
            A<Index>(c) = generateExponent<Scalar>(a, std::make_index_sequence<NParameter - 1 - Index>{});
        }

        template<typename Scalar, size_t NParameter, size_t... Indices>
        static constexpr void setExponents(auto& c, Scalar a, std::index_sequence<Indices...>)
        {
            (setExponent<Scalar, NParameter, Indices>(c, a), ...);
        }

        template<size_t Derivative, typename Scalar, size_t NParameter>
        static constexpr auto getExponents(Scalar a)
        {
            auto e = boost::qvm::vec<Scalar, NParameter>{};

            setExponents<Scalar, NParameter>(e, a, std::make_index_sequence<NParameter>{});

            return e;
        }

        template<size_t Derivative, typename Scalar, size_t NParameter, size_t Dimension>
            requires PolynomialEvaluationType<Scalar> &&  //
                     PolynomialEvaluationRequirement<NParameter, Dimension>
        static constexpr boost::qvm::vec<Scalar, Dimension> eval(boost::qvm::mat<Scalar, Dimension, NParameter> p, Scalar a)
        {
            const auto c = PolynomialCoefficients<Scalar, NParameter - 1, Derivative>::getDiagonal();
            const auto e = getExponents<Derivative, Scalar, NParameter>(a);

            return p * c * e;
        }
    };
}  // namespace NBezier