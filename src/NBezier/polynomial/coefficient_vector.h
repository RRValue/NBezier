#pragma once

#include "NBezier/defines.h"
#include "NBezier/binomial/type.h"

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_access.hpp>

#include <boost/qvm/mat.hpp>
#include <boost/qvm/mat_access.hpp>

#include <concepts>

OpenNameSpace(NBezier);
OpenNameSpace(Polynomial);

template<size_t Derivative, size_t Degree>
concept DerivativeRequirement =  //
    0 <= Derivative && Derivative <= Degree;

template<Binomial::Type Scalar, size_t Degree, size_t Derivative>
    requires DerivativeRequirement<Derivative, Degree>
struct CoefficientVector
{
    StaticClass(CoefficientVector);

private:
    template<size_t Index>
    NBInline static constexpr void initCoefficients(auto& c)
    {
        A<Index>(c) = Scalar(1);
    }

    template<size_t... Indices>
    NBInline static constexpr auto initCoefficients(std::index_sequence<Indices...>)
    {
        boost::qvm::vec<Scalar, Degree + 1> c;

        (initCoefficients<Indices>(c), ...);

        return c;
    }

    template<size_t Derivative, size_t Index>
    NBInline static constexpr void multCoefficient(auto& c)
    {
        A<Index>(c) *= (Degree - Index - Derivative);
    }

    template<size_t Derivative, size_t... Indices>
    NBInline static constexpr void derive(auto& c, std::index_sequence<Indices...>)
    {
        (multCoefficient<Derivative, Indices>(c), ...);
    }

    template<size_t Derivative>
    NBInline static constexpr void deriveCoefficients(auto& c)
    {
        derive<Derivative>(c, std::make_index_sequence<Degree + 1>{});
    }

    template<size_t... Derivatives>
    NBInline static constexpr void generateCoefficients(auto& c, std::index_sequence<Derivatives...>)
    {
        (deriveCoefficients<Derivatives>(c), ...);
    }

public:
    static constexpr auto get() noexcept
    {
        constexpr auto init_vec = initCoefficients(std::make_index_sequence<Degree + 1>{});
        auto c = init_vec;

        generateCoefficients(c, std::make_index_sequence<Derivative>{});

        return c;
    }

    bool operator==(const CoefficientVector&) const noexcept = default;
};

CloseNameSpace(Polynomial);
CloseNameSpace(NBezier);