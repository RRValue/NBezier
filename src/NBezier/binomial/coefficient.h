#pragma once

#include <concepts>

namespace NBezier
{
    namespace Binomial
    {
        template<class T>
        concept Factorialable = (std::integral<T> || std::floating_point<T>)&&  //
            !std::is_same<T, bool>::value;

        template<typename T>
            requires Factorialable<T>
        struct Coefficient
        {
            static constexpr T get(const T& n, const T& k) noexcept
            {
                if(k > n)
                    return T(0);

                if(k == 0 || k == n)
                    return 1;

                auto result = float(1);

                for(float i = 1.0f; i <= float(k); i += 1.0f)
                    result *= (float(n) + 1.0f - i) / i;

                return T(result);
            }
        };
    }  // namespace Binomial
}  // namespace NBezier