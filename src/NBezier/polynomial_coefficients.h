#pragma once

#include "binomial_coefficient.h"

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_access.hpp>

#include <boost/qvm/mat.hpp>
#include <boost/qvm/mat_access.hpp>

#include <concepts>

namespace NBezier
{
    template<typename ScalarType>
    concept PolynomialCoefficientType = (std::integral<ScalarType> || std::floating_point<ScalarType>)&&  //
        !std::is_same<ScalarType, bool>::value;
    
    template<size_t Degree>
    concept PolynomialCoefficientRequirement = Degree >= 0;

    template<size_t Derivative, size_t Degree>
    concept PolynomialDerivativeRequirement = //
        0 <= Derivative && Derivative <= Degree;

    template<typename ScalarType, size_t Degree>
        requires PolynomialCoefficientType<ScalarType> &&  //
                 PolynomialCoefficientRequirement<Degree>
    struct PolynomialCoefficients
    {
    private:
        static constexpr size_t NCoefficients = Degree + 1;

    public:
        typedef boost::qvm::vec<ScalarType, NCoefficients> Coefficients;
        typedef boost::qvm::mat<ScalarType, NCoefficients, NCoefficients> CoefficientsMatrix;

    private:
        template<size_t Index>
        static constexpr void initCoefficients(Coefficients& c)
        {
            A<Index>(c) = ScalarType(1);
        }

        template<size_t... Indices>
        static constexpr void initCoefficients(Coefficients& c, std::index_sequence<Indices...>)
        {
            (initCoefficients<Indices>(c), ...);
        }

        template<size_t Derivative, size_t Index>
        static constexpr void multCoefficient(Coefficients& c)
        {
            A<Index>(c) *= (Degree - Index - Derivative);
        }

        template<size_t Derivative, size_t... Indices>
        static constexpr void derive(Coefficients& c, std::index_sequence<Indices...>)
        {
            (multCoefficient<Derivative, Indices>(c), ...);
        }

        template<size_t Derivative>
        static constexpr void deriveCoefficients(Coefficients& c)
        {
            derive<Derivative>(c, std::make_index_sequence<NCoefficients>{});
        }

        template<size_t... Derivatives>
        static constexpr void generateCoefficients(Coefficients& c, std::index_sequence<Derivatives...>)
        {
            (deriveCoefficients<Derivatives>(c), ...);
        }

    public:
        template<size_t Derivative>
            requires PolynomialDerivativeRequirement<Derivative, Degree>
        static constexpr Coefficients get() noexcept
        {
            Coefficients c = {};

            initCoefficients(c, std::make_index_sequence<NCoefficients>{});
            generateCoefficients(c, std::make_index_sequence<Derivative>{});

            return c;
        }

        template<size_t Index>
        static constexpr void assignDiagonalCell(CoefficientsMatrix& m, Coefficients& c)
        {
            boost::qvm::A<Index, Index>(m) = boost::qvm::A<Index>(c);
        }

        template<size_t... Indices>
        static constexpr void assignDiagonalMatrix(CoefficientsMatrix& m, Coefficients& c, std::index_sequence<Indices...>)
        {
            (assignDiagonalCell<Indices>(m, c), ...);
        }

        template<size_t Derivative>
            requires PolynomialDerivativeRequirement<Derivative, Degree>
        static constexpr CoefficientsMatrix getDiagonal() noexcept
        {
            auto c = get<Derivative>();

            CoefficientsMatrix m = {};

            assignDiagonalMatrix(m, c, std::make_index_sequence<NCoefficients>{});

            return m;
        }

        bool operator==(const PolynomialCoefficients&) const noexcept = default;
    };
}  // namespace NBezier