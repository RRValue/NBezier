#include "NBezier/bezier.h"
#include "NBezier/bezier_split.h"

#include <benchmark/benchmark.h>

UseNameSpace(NBezier);

static void BM_BezierSplitCompileTime(benchmark::State& state)
{
    constexpr auto p0 = Point<float, 6>{-4, -4, -4, -4, -4, -4};
    constexpr auto p1 = Point<float, 6>{-3, -3, -3, -3, -3, -3};
    constexpr auto p2 = Point<float, 6>{-2, -2, -2, -2, -2, -2};
    constexpr auto p3 = Point<float, 6>{-1, -1, -1, -1, -1, -1};
    constexpr auto p4 = Point<float, 6>{0, 0, 0, 0, 0, 0};
    constexpr auto p5 = Point<float, 6>{1, 1, 1, 1, 1, 1};
    constexpr auto p6 = Point<float, 6>{2, 2, 2, 2, 2, 2};
    constexpr auto p7 = Point<float, 6>{3, 3, 3, 3, 3, 3};
    constexpr auto p8 = Point<float, 6>{4, 4, 4, 4, 4, 4};

    constexpr auto bezier = BezierPoints<float, 6, 8>{p0, p1, p2, p3, p4, p5, p6, p7, p8};

    for(auto _ : state)
    {
        [[maybe_unused]] constexpr auto split = BezierSplit::at(bezier, 0.5f);
    }
}

static void BM_BezierSplitRunTimeDegree2Dim3(benchmark::State& state)
{
    constexpr auto p0 = Point<float, 3>{-4, -4, -4};
    constexpr auto p1 = Point<float, 3>{-3, -3, -3};
    constexpr auto p2 = Point<float, 3>{-2, -2, -2};

    constexpr auto bezier = BezierPoints<float, 3, 2>{p0, p1, p2};

    auto split_result = BezierSplitResult<float, 3, 2>{};

    for(auto _ : state)
    {
        benchmark::DoNotOptimize(split_result = BezierSplit::at(bezier, 0.5f));
    }
}

static void BM_BezierSplitRunTimeDegree2(benchmark::State& state)
{
    constexpr auto p0 = Point<float, 6>{-4, -4, -4, -4, -4, -4};
    constexpr auto p1 = Point<float, 6>{-3, -3, -3, -3, -3, -3};
    constexpr auto p2 = Point<float, 6>{-2, -2, -2, -2, -2, -2};

    constexpr auto bezier = BezierPoints<float, 6, 2>{p0, p1, p2};

    auto split_result = BezierSplitResult<float, 6, 2>{};

    for(auto _ : state)
    {
        benchmark::DoNotOptimize(split_result = BezierSplit::at(bezier, 0.5f));
    }
}

static void BM_BezierSplitRunTimeDegree3(benchmark::State& state)
{
    constexpr auto p0 = Point<float, 6>{-4, -4, -4, -4, -4, -4};
    constexpr auto p1 = Point<float, 6>{-3, -3, -3, -3, -3, -3};
    constexpr auto p2 = Point<float, 6>{-2, -2, -2, -2, -2, -2};
    constexpr auto p3 = Point<float, 6>{-1, -1, -1, -1, -1, -1};

    constexpr auto bezier = BezierPoints<float, 6, 3>{p0, p1, p2, p3};

    auto split_result = BezierSplitResult<float, 6, 3>{};

    for(auto _ : state)
    {
        benchmark::DoNotOptimize(split_result = BezierSplit::at(bezier, 0.5f));
    }
}

static void BM_BezierSplitRunTimeDegree4(benchmark::State& state)
{
    constexpr auto p0 = Point<float, 6>{-4, -4, -4, -4, -4, -4};
    constexpr auto p1 = Point<float, 6>{-3, -3, -3, -3, -3, -3};
    constexpr auto p2 = Point<float, 6>{-2, -2, -2, -2, -2, -2};
    constexpr auto p3 = Point<float, 6>{-1, -1, -1, -1, -1, -1};
    constexpr auto p4 = Point<float, 6>{0, 0, 0, 0, 0, 0};

    constexpr auto bezier = BezierPoints<float, 6, 4>{p0, p1, p2, p3, p4};

    auto split_result = BezierSplitResult<float, 6, 4>{};

    for(auto _ : state)
    {
        benchmark::DoNotOptimize(split_result = BezierSplit::at(bezier, 0.5f));
    }
}

static void BM_BezierSplitRunTimeDegree5(benchmark::State& state)
{
    constexpr auto p0 = Point<float, 6>{-4, -4, -4, -4, -4, -4};
    constexpr auto p1 = Point<float, 6>{-3, -3, -3, -3, -3, -3};
    constexpr auto p2 = Point<float, 6>{-2, -2, -2, -2, -2, -2};
    constexpr auto p3 = Point<float, 6>{-1, -1, -1, -1, -1, -1};
    constexpr auto p4 = Point<float, 6>{0, 0, 0, 0, 0, 0};
    constexpr auto p5 = Point<float, 6>{1, 1, 1, 1, 1, 1};

    constexpr auto bezier = BezierPoints<float, 6, 5>{p0, p1, p2, p3, p4, p5};

    auto split_result = BezierSplitResult<float, 6, 5>{};

    for(auto _ : state)
    {
        benchmark::DoNotOptimize(split_result = BezierSplit::at(bezier, 0.5f));
    }
}

static void BM_BezierSplitRunTimeDegree6(benchmark::State& state)
{
    constexpr auto p0 = Point<float, 6>{-4, -4, -4, -4, -4, -4};
    constexpr auto p1 = Point<float, 6>{-3, -3, -3, -3, -3, -3};
    constexpr auto p2 = Point<float, 6>{-2, -2, -2, -2, -2, -2};
    constexpr auto p3 = Point<float, 6>{-1, -1, -1, -1, -1, -1};
    constexpr auto p4 = Point<float, 6>{0, 0, 0, 0, 0, 0};
    constexpr auto p5 = Point<float, 6>{1, 1, 1, 1, 1, 1};
    constexpr auto p6 = Point<float, 6>{2, 2, 2, 2, 2, 2};

    constexpr auto bezier = BezierPoints<float, 6, 6>{p0, p1, p2, p3, p4, p5, p6};

    auto split_result = BezierSplitResult<float, 6, 6>{};

    for(auto _ : state)
    {
        benchmark::DoNotOptimize(split_result = BezierSplit::at(bezier, 0.5f));
    }
}

static void BM_BezierSplitRunTimeDegree7(benchmark::State& state)
{
    constexpr auto p0 = Point<float, 6>{-4, -4, -4, -4, -4, -4};
    constexpr auto p1 = Point<float, 6>{-3, -3, -3, -3, -3, -3};
    constexpr auto p2 = Point<float, 6>{-2, -2, -2, -2, -2, -2};
    constexpr auto p3 = Point<float, 6>{-1, -1, -1, -1, -1, -1};
    constexpr auto p4 = Point<float, 6>{0, 0, 0, 0, 0, 0};
    constexpr auto p5 = Point<float, 6>{1, 1, 1, 1, 1, 1};
    constexpr auto p6 = Point<float, 6>{2, 2, 2, 2, 2, 2};
    constexpr auto p7 = Point<float, 6>{3, 3, 3, 3, 3, 3};

    constexpr auto bezier = BezierPoints<float, 6, 7>{p0, p1, p2, p3, p4, p5, p6, p7};

    auto split_result = BezierSplitResult<float, 6, 7>{};

    for(auto _ : state)
    {
        benchmark::DoNotOptimize(split_result = BezierSplit::at(bezier, 0.5f));
    }
}

static void BM_BezierSplitRunTimeDegree8(benchmark::State& state)
{
    constexpr auto p0 = Point<float, 6>{-4, -4, -4, -4, -4, -4};
    constexpr auto p1 = Point<float, 6>{-3, -3, -3, -3, -3, -3};
    constexpr auto p2 = Point<float, 6>{-2, -2, -2, -2, -2, -2};
    constexpr auto p3 = Point<float, 6>{-1, -1, -1, -1, -1, -1};
    constexpr auto p4 = Point<float, 6>{0, 0, 0, 0, 0, 0};
    constexpr auto p5 = Point<float, 6>{1, 1, 1, 1, 1, 1};
    constexpr auto p6 = Point<float, 6>{2, 2, 2, 2, 2, 2};
    constexpr auto p7 = Point<float, 6>{3, 3, 3, 3, 3, 3};
    constexpr auto p8 = Point<float, 6>{4, 4, 4, 4, 4, 4};

    constexpr auto bezier = BezierPoints<float, 6, 8>{p0, p1, p2, p3, p4, p5, p6, p7, p8};

    auto split_result = BezierSplitResult<float, 6, 8>{};

    for(auto _ : state)
    {
        benchmark::DoNotOptimize(split_result = BezierSplit::at(bezier, 0.5f));
    }
}

BENCHMARK(BM_BezierSplitCompileTime);
BENCHMARK(BM_BezierSplitRunTimeDegree2Dim3);
BENCHMARK(BM_BezierSplitRunTimeDegree2);
BENCHMARK(BM_BezierSplitRunTimeDegree3);
BENCHMARK(BM_BezierSplitRunTimeDegree4);
BENCHMARK(BM_BezierSplitRunTimeDegree5);
BENCHMARK(BM_BezierSplitRunTimeDegree6);
BENCHMARK(BM_BezierSplitRunTimeDegree7);
BENCHMARK(BM_BezierSplitRunTimeDegree8);