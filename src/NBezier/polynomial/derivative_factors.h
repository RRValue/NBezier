#pragma once

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_access.hpp>

#include <boost/qvm/mat.hpp>
#include <boost/qvm/mat_access.hpp>

#include <concepts>

namespace NBezier
{
    namespace Polynomial
    {
        template<typename Scalar>
        concept DerivativeFactorsType = (std::integral<Scalar> || std::floating_point<Scalar>)&&  //
            !std::is_same<Scalar, bool>::value;

        template<size_t Derivative, size_t Degree>
        concept DerivativeRequirement =  //
            0 <= Derivative && Derivative <= Degree;

        template<typename Scalar, size_t Degree, size_t Derivative>
            requires DerivativeFactorsType<Scalar> &&  //
                     DerivativeRequirement<Derivative, Degree>
        struct DerivativeFactors
        {
        private:
            template<size_t Index>
            static constexpr void initCoefficients(auto& c)
            {
                A<Index>(c) = Scalar(1);
            }

            template<size_t... Indices>
            static constexpr void initCoefficients(auto& c, std::index_sequence<Indices...>)
            {
                (initCoefficients<Indices>(c), ...);
            }

            template<size_t Derivative, size_t Index>
            static constexpr void multCoefficient(auto& c)
            {
                A<Index>(c) *= (Degree - Index - Derivative);
            }

            template<size_t Derivative, size_t... Indices>
            static constexpr void derive(auto& c, std::index_sequence<Indices...>)
            {
                (multCoefficient<Derivative, Indices>(c), ...);
            }

            template<size_t Derivative>
            static constexpr void deriveCoefficients(auto& c)
            {
                derive<Derivative>(c, std::make_index_sequence<Degree + 1>{});
            }

            template<size_t... Derivatives>
            static constexpr void generateCoefficients(auto& c, std::index_sequence<Derivatives...>)
            {
                (deriveCoefficients<Derivatives>(c), ...);
            }

            template<size_t Index>
            static constexpr void assignDiagonalCell(auto& m, auto& c)
            {
                boost::qvm::A<Index, Index>(m) = boost::qvm::A<Index>(c);
            }

            template<size_t... Indices>
            static constexpr void assignDiagonalMatrix(auto& m, auto& c, std::index_sequence<Indices...>)
            {
                (assignDiagonalCell<Indices>(m, c), ...);
            }

        public:
            static constexpr auto get() noexcept
            {
                boost::qvm::vec<Scalar, Degree + 1> c = {};

                initCoefficients(c, std::make_index_sequence<Degree + 1>{});
                generateCoefficients(c, std::make_index_sequence<Derivative>{});

                return c;
            }

            static constexpr auto getDiagonal() noexcept
            {
                auto c = get();

                boost::qvm::mat<Scalar, Degree + 1, Degree + 1> m = {};

                assignDiagonalMatrix(m, c, std::make_index_sequence<Degree + 1>{});

                return m;
            }

            bool operator==(const DerivativeFactors&) const noexcept = default;
        };
    }  // namespace Polynomial
}  // namespace NBezier