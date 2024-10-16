#pragma once

#include "NBezier/defines.h"

#include "NBezier/binomial/coefficient.h"

#include <boost/qvm/mat.hpp>
#include <boost/qvm/mat_access.hpp>

#include <concepts>

OpenNameSpace(NBezier);

template<typename Scalar>
concept WeightMatrixCellType = (std::signed_integral<Scalar> || std::floating_point<Scalar>)&&  //
    !std::is_same<Scalar, bool>::value;

template<size_t Degree>
concept WeightMatrixDegreeRequirement = Degree > 0;

struct WeightMatrix
{
    StaticClass(WeightMatrix);

public:
    template<typename Scalar, size_t Degree>
        requires WeightMatrixCellType<Scalar> &&  //
                 WeightMatrixDegreeRequirement<Degree>
    static constexpr auto get() noexcept
    {
        return generateMatrix<Scalar, Degree>(std::make_index_sequence<Degree * Degree>{});
    }

    bool operator==(const WeightMatrix&) const noexcept = default;

private:
    template<typename Scalar, size_t Degree, std::size_t... Indices>
    NBInline static constexpr auto generateMatrix(std::index_sequence<Indices...>)
    {
        boost::qvm::mat<Scalar, Degree, Degree> m = {};

        (fillCell<Scalar, Degree, Indices>(m), ...);

        return m;
    }

    template<typename Scalar, std::size_t Degree, std::size_t Index>
    NBInline static constexpr void fillCell(auto& m)
    {
        constexpr auto row = Index / Degree;
        constexpr auto col = Index % Degree;

        constexpr auto signbit = (Degree - 1 + row + col) % 2 ? false : true;
        constexpr auto sign = signbit ? int(1) : int(-1);
        constexpr auto row_factor = Binomial::Coefficient::get(Scalar(Degree - 1), Scalar(row));
        constexpr auto col_factor = Binomial::Coefficient::get(Scalar(Degree - 1 - row), Scalar(col));
        constexpr auto value = sign * row_factor * col_factor;

        boost::qvm::A<row, col>(m) = value;
    }
};

CloseNameSpace(NBezier);