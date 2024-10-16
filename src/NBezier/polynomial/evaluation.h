#pragma once

#include "NBezier/defines.h"

#include "NBezier/points.h"
#include "NBezier/polynomial/coefficient_vector.h"
#include "NBezier/polynomial/variable_vector.h"

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
    StaticClass(Evaluation);

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
    template<size_t Derivative, typename PointsType, typename Scalar>
        requires EvaluationType<Scalar>
    static constexpr auto eval(const PointsType& p, const Scalar& a)
    {
        typedef typename boost::qvm::mat_traits<PointsType>::scalar_type PointScalar;
        constexpr auto Dim = boost::qvm::mat_traits<PointsType>::rows;
        constexpr auto NumPoints = boost::qvm::mat_traits<PointsType>::cols;

        static_assert(EvaluationRequirement<Dim, NumPoints>);

        constexpr auto c = CoefficientVector<PointScalar, NumPoints - 1, Derivative>::get();
        const auto v = VariableVector<PointScalar, NumPoints - 1, Derivative>::get(a);

        return p * cwiseProduct<PointScalar, NumPoints>(c, v);
    }
};

CloseNameSpace(Polynomial);
CloseNameSpace(NBezier);