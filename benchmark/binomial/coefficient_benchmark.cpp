#include "NBezier/binomial/coefficient.h"

#include <benchmark/benchmark.h>

UseNameSpace(NBezier::Binomial);

static void BM_CoefficientGetCompileTime(benchmark::State& state)
{
    for(auto _ : state)
    {
        [[maybe_unused]] constexpr auto _2_choose_0 = Coefficient::get(2, 0);
        [[maybe_unused]] constexpr auto _2_choose_1 = Coefficient::get(2, 1);
        [[maybe_unused]] constexpr auto _2_choose_2 = Coefficient::get(2, 2);
        [[maybe_unused]] constexpr auto _2_choose_3 = Coefficient::get(2, 3);
    }
}

static void BM_CoefficientGetRuntime(benchmark::State& state)
{
    float _2_choose_0 = 0;
    float _2_choose_1 = 0;
    float _2_choose_2 = 0;
    float _2_choose_3 = 0;

    for(auto _ : state)
    {
        benchmark::DoNotOptimize(_2_choose_0 = Coefficient::get(2, 0));
        benchmark::DoNotOptimize(_2_choose_1 = Coefficient::get(2, 1));
        benchmark::DoNotOptimize(_2_choose_2 = Coefficient::get(2, 2));
        benchmark::DoNotOptimize(_2_choose_3 = Coefficient::get(2, 3));
    }
}

BENCHMARK(BM_CoefficientGetCompileTime);
BENCHMARK(BM_CoefficientGetRuntime);