#pragma once

#include "NBezier/defines.h"

#include "NBezier/bezier_requirements.h"
#include "NBezier/split_weight_matrix.h"

#include <boost/qvm/mat.hpp>

#include <concepts>

OpenNameSpace(NBezier);

template<typename Scalar, size_t Degree>
concept SplitMatricesRequirement = BezierType<Scalar> && Degree > 0;

template<typename Scalar, size_t Degree>
    requires SplitMatricesRequirement<Scalar, Degree>
struct SplitMatriesResult
{
    boost::qvm::mat<Scalar, Degree, Degree> m_left = {};
    boost::qvm::mat<Scalar, Degree, Degree> m_right = {};
};

struct SplitMatrices
{
    StaticClass(SplitMatrices);

    template<typename Scalar, size_t Degree>
        requires SplitMatricesRequirement<Scalar, Degree>
    static constexpr auto get(const Scalar& alpha) noexcept
    {
        auto result = SplitMatriesResult<Scalar, Degree>{SplitWeightMatrix::getLeft<Scalar, Degree>(),  //
                                                         SplitWeightMatrix::getRight<Scalar, Degree>()};

        generate<Scalar, Degree>(result, alpha);

        return result;
    }

private:
    template<typename Scalar>
    struct UV
    {
        Scalar u;
        Scalar v;

        Scalar u_accum;
        Scalar v_accum;
    };

private:
    template<typename Scalar, size_t Degree>
    NBInline static constexpr auto generate(auto& matrices, const Scalar& alpha)
    {
        auto params = UV{alpha, Scalar(1) - alpha, Scalar(1), Scalar(1)};

        assignPotences<Degree>(matrices, params, std::make_index_sequence<Degree - 1>{});

        return matrices;
    }

    template<size_t Degree, size_t... Steps>
    NBInline static constexpr void assignPotences(auto& matrices, auto& params, std::index_sequence<Steps...>)
    {
        (assignPotence<Steps, Degree>(matrices, params), ...);
    }

    template<size_t Step, size_t Degree>
    NBInline static constexpr void assignPotence(auto& matrices, auto& params)
    {
        params.u_accum *= params.u;
        params.v_accum *= params.v;

        constexpr auto assign_steps = std::make_index_sequence<Degree - Step - 1>{};

        assignRow<Step + 1>(matrices.m_left, params.u_accum, assign_steps);
        assignRowInverse<Degree, Step + 1>(matrices.m_right, params.v_accum, assign_steps);
        assignDiagonal<0, Step + 1>(matrices.m_left, params.v_accum, assign_steps);
        assignDiagonalInverse<Degree, 0, Step + 1>(matrices.m_right, params.u_accum, assign_steps);
    }

    template<size_t Row, size_t... Steps>
    NBInline static constexpr void assignRow(auto& dst, const auto& value, std::index_sequence<Steps...>)
    {
        (assignCell<Row, Row + Steps>(dst, value), ...);
    }

    template<size_t Degree, size_t Row, size_t... Steps>
    NBInline static constexpr void assignRowInverse(auto& dst, const auto& value, std::index_sequence<Steps...>)
    {
        (assignCell<Degree - 1 - Row, Degree - 1 - (Row + Steps)>(dst, value), ...);
    }

    template<size_t Row, size_t Column, size_t... Steps>
    NBInline static constexpr void assignDiagonal(auto& dst, const auto& value, std::index_sequence<Steps...>)
    {
        (assignCell<Row + Steps, Column + Steps>(dst, value), ...);
    }

    template<size_t Degree, size_t Row, size_t Column, size_t... Steps>
    NBInline static constexpr void assignDiagonalInverse(auto& dst, const auto& value, std::index_sequence<Steps...>)
    {
        (assignCell<Degree - 1 - (Row + Steps), Degree - 1 - (Column + Steps)>(dst, value), ...);
    }

    template<size_t Row, size_t Column>
    NBInline static constexpr void assignCell(auto& dst, const auto& value)
    {
        constexpr auto row = Row;
        constexpr auto column = Column;

        boost::qvm::A<row, column>(dst) *= value;
    }
};

CloseNameSpace(NBezier);