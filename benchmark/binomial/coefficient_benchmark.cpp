#include "NBezier/binomial/coefficient.h"

#include <benchmark/benchmark.h>

UseNameSpace(NBezier::Binomial);

static void BM_CoefficientGetCompileTime(benchmark::State& state)
{
    using CoefficientF = Coefficient<float>;

    for(auto _ : state)
    {
        constexpr auto _2_choose_0 = CoefficientF::get(2, 0);
        constexpr auto _2_choose_1 = CoefficientF::get(2, 1);
        constexpr auto _2_choose_2 = CoefficientF::get(2, 2);
        constexpr auto _2_choose_3 = CoefficientF::get(2, 3);
    }
}

static void BM_CoefficientGetRuntime(benchmark::State& state)
{
    using CoefficientF = Coefficient<float>;

    for(auto _ : state)
    {
        auto _2_choose_0 = CoefficientF::get(2, 0);
        auto _2_choose_1 = CoefficientF::get(2, 1);
        auto _2_choose_2 = CoefficientF::get(2, 2);
        auto _2_choose_3 = CoefficientF::get(2, 3);
    }
}

BENCHMARK(BM_CoefficientGetCompileTime);
BENCHMARK(BM_CoefficientGetRuntime);