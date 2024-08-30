#pragma once

#include "NBezier/defines.h"

#include "NBezier/binomial/type.h"

#include <concepts>

OpenNameSpace(NBezier);
OpenNameSpace(Binomial);

struct Coefficient
{
    StaticClass(Coefficient);

    template<Type T>
    static constexpr T get(const T& n, const T& k) noexcept
    {
        if(k > n)
            return 0;

        if(k == 0 || k == n)
            return 1;

        auto result = float(1);

        for(float i = 1.0f; i <= float(k); i += 1.0f)
            result *= (float(n) + 1.0f - i) / i;

        return result;
    }
};

CloseNameSpace(Binomial);
CloseNameSpace(NBezier);