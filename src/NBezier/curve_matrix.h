#pragma once

#include "binomial/coefficient.h"

#include <boost/qvm/mat.hpp>
#include <boost/qvm/mat_access.hpp>

#include <concepts>

namespace NBezier
{
    template<typename ScalarType>
    concept CurveMatrixCellType = (std::signed_integral<ScalarType> || std::floating_point<ScalarType>)&&  //
        !std::is_same<ScalarType, bool>::value;
    
    template<size_t Degree>
    concept CurveMatrixDegreeRequirement = Degree > 0;

    template<typename ScalarType, size_t Degree>
        requires CurveMatrixCellType<ScalarType> &&  //
                 CurveMatrixDegreeRequirement<Degree>
    struct CurveMatrix
    {
        typedef boost::qvm::mat<ScalarType, Degree, Degree> Matrix;

    private:
        template<std::size_t Index>
        static constexpr void fillCell(Matrix& m)
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
        static constexpr void generateMatrix(Matrix& m, std::index_sequence<Indices...>)
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

        bool operator==(const CurveMatrix&) const noexcept = default;
    };
}  // namespace NBezier