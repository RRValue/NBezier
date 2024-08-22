#pragma once

#include "NBezier/defines.h"

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_access.hpp>
#include <boost/qvm/vec_operations.hpp>

#include <concepts>
#include <utility>

OpenNameSpace(NBezier);
OpenNameSpace(Polynomial);

template<class T>
concept VariableVectorType = (std::integral<T> || std::floating_point<T>) &&  //
                             !std::is_same<T, bool>::value;

template<size_t Degree, size_t Derivative>
concept GetRequirement = Derivative <= Degree;

template<typename Scalar, size_t Degree>
    requires VariableVectorType<Scalar>
struct VariableVector
{
    StaticClass(VariableVector);

private:
    template<size_t Index>
    NBInline static constexpr auto mult(Scalar& value, const Scalar& variable)
    {
        value *= variable;
    }

    template<size_t... Indices>
    NBInline static constexpr auto potentiate(const Scalar& variable, std::index_sequence<Indices...>)
    {
        auto value = Scalar(1);

        (mult<Indices>(value, variable), ...);

        return value;
    }

    template<size_t Derivative, size_t Index>
    NBInline static constexpr void generateNthVariable(auto& vec, const Scalar& variable)
    {
        A<Index>(vec) = potentiate(variable, std::make_index_sequence<Degree - Index - Derivative>{});
    }

    template<size_t Derivative, size_t... Indices>
    NBInline static constexpr void generateVariables(auto& vec, const Scalar& variable, std::index_sequence<Indices...>)
    {
        (generateNthVariable<Derivative, Indices>(vec, variable), ...);
    }

public:
    template<size_t Derivative>
        requires GetRequirement<Degree, Derivative>
    static constexpr auto get(const Scalar& variable)
    {
        auto vec = boost::qvm::vec<Scalar, Degree + 1>{};

        generateVariables<Derivative>(vec, variable, std::make_index_sequence<Degree + 1 - Derivative>{});

        return vec;
    }

    bool operator==(const VariableVector&) const noexcept = default;
};

CloseNameSpace(Polynomial);
CloseNameSpace(NBezier);