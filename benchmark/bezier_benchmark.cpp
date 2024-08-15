#include "NBezier/bezier.h"

#include <benchmark/benchmark.h>

UseNameSpace(NBezier);

static void BM_BezierPositionCompileTime(benchmark::State& state)
{
    constexpr auto p0 = Point<float, 3>{-1, 1, 0};
    constexpr auto p1 = Point<float, 3>{0, 0, 0};
    constexpr auto p2 = Point<float, 3>{1, 1, 0};
    constexpr BezierPoints<float, 3, 2> b{p0, p1, p2};

    for(auto _ : state)
    {
        constexpr auto result = Bezier::point(b, 0.5f);
    }
}

static void BM_BezierPositionRunTime(benchmark::State& state)
{
    constexpr auto p0 = Point<float, 3>{-1, 1, 0};
    constexpr auto p1 = Point<float, 3>{0, 0, 0};
    constexpr auto p2 = Point<float, 3>{1, 1, 0};
    constexpr BezierPoints<float, 3, 2> b{p0, p1, p2};

    auto result= Point<float, 3>{};

    for(auto _ : state)
    {
        benchmark::DoNotOptimize(result = Bezier::point(b, 0.5f));
    }
}

static void BM_BezierTangentRunTime(benchmark::State& state)
{
    constexpr auto p0 = Point<float, 3>{-1, 1, 0};
    constexpr auto p1 = Point<float, 3>{0, 0, 0};
    constexpr auto p2 = Point<float, 3>{1, 1, 0};
    constexpr BezierPoints<float, 3, 2> b{p0, p1, p2};

    auto result = Point<float, 3>{};

    for(auto _ : state)
    {
        benchmark::DoNotOptimize(result = Bezier::tangent(b, 0.5f));
    }
}

static void BM_BezierNormalRunTime(benchmark::State& state)
{
    constexpr auto p0 = Point<float, 3>{-1, 1, 0};
    constexpr auto p1 = Point<float, 3>{0, 0, 0};
    constexpr auto p2 = Point<float, 3>{1, 1, 0};
    constexpr BezierPoints<float, 3, 2> b{p0, p1, p2};

    auto result = Point<float, 3>{};

    for(auto _ : state)
    {
        benchmark::DoNotOptimize(result = Bezier::normal(b, 0.5f));
    }
}

BENCHMARK(BM_BezierPositionCompileTime);
BENCHMARK(BM_BezierPositionRunTime);
BENCHMARK(BM_BezierTangentRunTime);
BENCHMARK(BM_BezierNormalRunTime);