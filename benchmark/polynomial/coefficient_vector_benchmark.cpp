#include "NBezier/polynomial/coefficient_vector.h"

#include <benchmark/benchmark.h>

UseNameSpace(NBezier::Polynomial);

template<size_t Derivative>
    using CoefficientVector4 = CoefficientVector<float, 4, Derivative>;

static void BM_CoefficientVectorGetCompileTime(benchmark::State& state)
{
    for(auto _ : state)
    {
        constexpr auto c0 = CoefficientVector4<0>::get();
        constexpr auto c1 = CoefficientVector4<1>::get();
        constexpr auto c2 = CoefficientVector4<2>::get();
        constexpr auto c3 = CoefficientVector4<3>::get();
        constexpr auto c4 = CoefficientVector4<4>::get();
    }
}

static void BM_CoefficientVectorGetRunTime(benchmark::State& state)
{
    auto c0 = boost::qvm::vec<float, 5>{};
    auto c1 = boost::qvm::vec<float, 5>{};
    auto c2 = boost::qvm::vec<float, 5>{};
    auto c3 = boost::qvm::vec<float, 5>{};
    auto c4 = boost::qvm::vec<float, 5>{};

    for(auto _ : state)
    {
        benchmark::DoNotOptimize(c0 = CoefficientVector4<0>::get());
        benchmark::DoNotOptimize(c1 = CoefficientVector4<1>::get());
        benchmark::DoNotOptimize(c2 = CoefficientVector4<2>::get());
        benchmark::DoNotOptimize(c3 = CoefficientVector4<3>::get());
        benchmark::DoNotOptimize(c4 = CoefficientVector4<4>::get());
    }
}

BENCHMARK(BM_CoefficientVectorGetCompileTime);
BENCHMARK(BM_CoefficientVectorGetRunTime);