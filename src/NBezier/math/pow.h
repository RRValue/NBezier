#pragma once

#include "NBezier/defines.h"

#include <utility>

OpenNameSpace(NBezier);
OpenNameSpace(Math);

struct Pow
{
private:
    template<size_t Index>
    NBInline static constexpr auto mult(auto& value, const auto& variable)
    {
        value *= variable;
    }

    template<typename Scalar, size_t... Count>
    NBInline static constexpr auto potentiate(const Scalar& base, std::index_sequence<Count...>)
    {
        auto value = Scalar(1);

        (mult<Count>(value, base), ...);

        return value;
    }

public:
    template<size_t Power, typename Scalar>
    NBInline static constexpr auto get(const Scalar& base)
    {
        return potentiate<Scalar>(Scalar(2), std::make_index_sequence<Power>{});
    }

    template<typename Scalar, size_t Power>
    NBInline static constexpr auto get2()
    {
        return potentiate<Scalar>(Scalar(2), std::make_index_sequence<Power>{});
    }
};

CloseNameSpace(Math);
CloseNameSpace(NBezier);