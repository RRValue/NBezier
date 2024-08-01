#pragma once

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_access.hpp>
#include <boost/qvm/vec_operations.hpp>

#include <concepts>
#include <utility>

namespace NBezier
{
    template<class T>
    concept PolynomialVariableType = (std::integral<T> || std::floating_point<T>)&&  //
        !std::is_same<T, bool>::value;

    template<size_t Degree, size_t Derivative>
    concept GetRequirement = Derivative <= Degree;

    template<typename Scalar, size_t Degree>
        requires PolynomialVariableType<Scalar>
    struct PolynomialVariable
    {
    private:
        template<size_t Index>
        static constexpr auto mult(Scalar& value, const Scalar& variable)
        {
            value *= variable;
        }

        template<size_t... Indices>
        static constexpr auto potentiate(const Scalar& variable, std::index_sequence<Indices...>)
        {
            auto value = Scalar(1);

            (mult<Indices>(value, variable), ...);

            return value;
        }

        template<size_t Derivative, size_t Index>
        static constexpr void generateNthVariable(auto& vec, const Scalar& variable)
        {
            A<Index>(vec) = potentiate(variable, std::make_index_sequence<Degree - Index - Derivative>{});
        }

        template<size_t Derivative, size_t... Indices>
        static constexpr void generateVariables(auto& vec, const Scalar& variable, std::index_sequence<Indices...>)
        {
            (generateNthVariable<Derivative, Indices>(vec, variable), ...);
        }

    public:
        template<size_t Derivative>
            requires GetRequirement<Degree, Derivative>
        static constexpr auto variableVector(const Scalar& variable)
        {
            auto vec = boost::qvm::vec<Scalar, Degree + 1>{};

            generateVariables<Derivative>(vec, variable, std::make_index_sequence<Degree + 1 - Derivative>{});

            return vec;
        }

        bool operator==(const PolynomialVariable&) const noexcept = default;
    };
}  // namespace NBezier