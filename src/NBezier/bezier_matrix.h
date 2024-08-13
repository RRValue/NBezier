#pragma once

#include "NBezier/defines.h"

#include "NBezier/binomial/coefficient.h"

#include <boost/qvm/mat.hpp>
#include <boost/qvm/mat_access.hpp>

#include <concepts>

OpenNameSpace(NBezier);

template<typename Scalar>
concept BezierMatrixCellType = (std::signed_integral<Scalar> || std::floating_point<Scalar>)&&  //
    !std::is_same<Scalar, bool>::value;

template<size_t Degree>
concept BezierMatrixDegreeRequirement = Degree > 0;

template<typename Scalar, size_t Degree>
    requires BezierMatrixCellType<Scalar> &&  //
             BezierMatrixDegreeRequirement<Degree>
struct BezierMatrix
{
    StaticClass(BezierMatrix);

    typedef boost::qvm::mat<Scalar, Degree, Degree> Matrix;

private:
    template<std::size_t Index>
    NBInline static constexpr void fillCell(Matrix& m)
    {
        constexpr auto row = Index / Degree;
        constexpr auto col = Index % Degree;

        constexpr auto signbit = (Degree - 1 + row + col) % 2 ? false : true;
        constexpr auto sign = signbit ? int(1) : int(-1);
        constexpr auto row_factor = Binomial::Coefficient<int>::get(Degree - 1, row);
        constexpr auto col_factor = Binomial::Coefficient<int>::get(Degree - 1 - row, col);
        constexpr auto value = sign * row_factor * col_factor;

        boost::qvm::write_mat_element_idx(row, col, m, value);
    }

    template<std::size_t... Indices>
    NBInline static constexpr void generateMatrix(Matrix& m, std::index_sequence<Indices...>)
    {
        (fillCell<Indices>(m), ...);
    }

public:
    static constexpr Matrix get() noexcept
    {
        Matrix m = {};

        generateMatrix(m, std::make_index_sequence<Degree * Degree>{});

        return m;
    }

    bool operator==(const BezierMatrix&) const noexcept = default;
};

CloseNameSpace(NBezier);