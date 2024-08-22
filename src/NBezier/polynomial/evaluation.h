#pragma once

#include "NBezier/defines.h"

#include "NBezier/points.h"
#include "NBezier/polynomial/coefficient_vector.h"
#include "NBezier/polynomial/variable.h"

#include <boost/qvm/mat.hpp>
#include <boost/qvm/mat_operations.hpp>

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_mat_operations.hpp>

#include <boost/qvm/map_mat_vec.hpp>

#include <concepts>

OpenNameSpace(NBezier);
OpenNameSpace(Polynomial);

template<typename Scalar>
concept EvaluationType = std::floating_point<Scalar>;

template<size_t Dimension, size_t NParameter>
concept EvaluationRequirement = NParameter > 0 && Dimension > 0;

struct Evaluation
{
private:
    template<size_t Index>
    NBInline static constexpr void cwiseProduct(auto& lhs, const auto& rhs)
    {
        A<Index>(lhs) *= A<Index>(rhs);
    }

    template<size_t... Indices>
    NBInline static constexpr void cwiseProduct(auto& lhs, const auto& rhs, std::index_sequence<Indices...>)
    {
        (cwiseProduct<Indices>(lhs, rhs), ...);
    }

    template<typename Scalar, size_t NumIndices>
    NBInline static constexpr auto cwiseProduct(const auto& lhs, const auto& rhs)
    {
        boost::qvm::vec<Scalar, NumIndices> result = lhs;

        cwiseProduct(result, rhs, std::make_index_sequence<NumIndices>{});

        return result;
    }

public:
    StaticClass(Evaluation);

    template<size_t Derivative, typename Scalar, size_t Dimension, size_t NParameter>
        requires EvaluationType<Scalar> &&  //
                 EvaluationRequirement<Dimension, NParameter>
    static constexpr auto eval(const Points<Scalar, Dimension, NParameter>& p, const Scalar& a)
    {
        constexpr auto c = CoefficientVector<Scalar, NParameter - 1, Derivative>::get();
        const auto v = Variable<Scalar, NParameter - 1>::variableVector<Derivative>(a);

        return p * cwiseProduct<Scalar, NParameter>(c, v);
    }
};

CloseNameSpace(Polynomial);
CloseNameSpace(NBezier);