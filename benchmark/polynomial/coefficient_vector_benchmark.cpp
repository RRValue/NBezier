#include "NBezier/polynomial/coefficient_vector.h"

#include <benchmark/benchmark.h>

UseNameSpace(NBezier::Polynomial);

template<size_t Derivative>
using CoefficientVector5 = CoefficientVector<float, 5, Derivative>;

static void BM_CoefficientVectorGetCompileTime(benchmark::State& state)
{
    for(auto _ : state)
    {
        [[maybe_unused]] constexpr auto c0 = CoefficientVector5<0>::get();
        [[maybe_unused]] constexpr auto c1 = CoefficientVector5<1>::get();
        [[maybe_unused]] constexpr auto c2 = CoefficientVector5<2>::get();
        [[maybe_unused]] constexpr auto c3 = CoefficientVector5<3>::get();
        [[maybe_unused]] constexpr auto c4 = CoefficientVector5<4>::get();
        [[maybe_unused]] constexpr auto c5 = CoefficientVector5<5>::get();
    }
}

static void BM_CoefficientVectorGetRunTime(benchmark::State& state)
{
    auto c0 = boost::qvm::vec<float, 6>{};
    auto c1 = boost::qvm::vec<float, 6>{};
    auto c2 = boost::qvm::vec<float, 6>{};
    auto c3 = boost::qvm::vec<float, 6>{};
    auto c4 = boost::qvm::vec<float, 6>{};
    auto c5 = boost::qvm::vec<float, 6>{};

    for(auto _ : state)
    {
        benchmark::DoNotOptimize(c0 = CoefficientVector5<0>::get());
        benchmark::DoNotOptimize(c1 = CoefficientVector5<1>::get());
        benchmark::DoNotOptimize(c2 = CoefficientVector5<2>::get());
        benchmark::DoNotOptimize(c3 = CoefficientVector5<3>::get());
        benchmark::DoNotOptimize(c4 = CoefficientVector5<4>::get());
        benchmark::DoNotOptimize(c5 = CoefficientVector5<5>::get());
    }
}

BENCHMARK(BM_CoefficientVectorGetCompileTime);
BENCHMARK(BM_CoefficientVectorGetRunTime);