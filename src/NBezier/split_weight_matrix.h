#pragma once

#include "NBezier/defines.h"

#include "NBezier/binomial/coefficient.h"

#include <boost/qvm/mat.hpp>
#include <boost/qvm/mat_access.hpp>

#include <concepts>

OpenNameSpace(NBezier);

template<typename Scalar>
concept SplitWeightMatrixCellType = (std::signed_integral<Scalar> || std::floating_point<Scalar>) &&  //
                                    !std::is_same<Scalar, bool>::value;

template<size_t Degree>
concept SplitWeightMatrixDegreeRequirement = Degree > 0;

struct SplitWeightMatrix
{
    StaticClass(SplitWeightMatrix);

public:
    template<typename Scalar, size_t Degree>
        requires SplitWeightMatrixCellType<Scalar> &&  //
                 SplitWeightMatrixDegreeRequirement<Degree>
    static constexpr auto getLeft() noexcept
    {
        return generateLeft<Scalar, Degree>(std::make_index_sequence<Degree * Degree>{});
    }

    template<typename Scalar, size_t Degree>
        requires SplitWeightMatrixCellType<Scalar> &&  //
                 SplitWeightMatrixDegreeRequirement<Degree>
    static constexpr auto getRight() noexcept
    {
        return generateRight<Scalar, Degree>(std::make_index_sequence<Degree * Degree>{});
    }

    bool operator==(const SplitWeightMatrix&) const noexcept = default;

private:
    template<typename Scalar, size_t Degree, std::size_t... Indices>
    NBInline static constexpr auto generateLeft(std::index_sequence<Indices...>)
    {
        boost::qvm::mat<Scalar, Degree, Degree> m = {};

        (fillCellLeft<Scalar, Degree, Indices>(m), ...);

        return m;
    }

    template<typename Scalar, std::size_t Degree, std::size_t Index>
    NBInline static constexpr void fillCellLeft(auto& m)
    {
        constexpr auto row = Index / Degree;
        constexpr auto col = Index % Degree;

        if(col < row)
            return;

        boost::qvm::A<row, col>(m) = Binomial::Coefficient::get(Scalar(col), Scalar(row));
    }

    template<typename Scalar, size_t Degree, std::size_t... Indices>
    NBInline static constexpr auto generateRight(std::index_sequence<Indices...>)
    {
        boost::qvm::mat<Scalar, Degree, Degree> m = {};

        (fillCellRight<Scalar, Degree, Indices>(m), ...);

        return m;
    }

    template<typename Scalar, std::size_t Degree, std::size_t Index>
    NBInline static constexpr void fillCellRight(auto& m)
    {
        constexpr auto row = Index / Degree;
        constexpr auto col = Index % Degree;

        if(col > row)
            return;

        boost::qvm::A<row, col>(m) = Binomial::Coefficient::get(Scalar(Degree - col - 1), Scalar(row - col));
    }
};

CloseNameSpace(NBezier);