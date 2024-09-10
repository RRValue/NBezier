#include "NBezier/bezier.h"
#include "NBezier/bezier_length.h"

#include <benchmark/benchmark.h>

UseNameSpace(NBezier);

#if !defined(MSVC)
static void BM_BezierLengthCompileTime(benchmark::State& state)
{
    constexpr auto p0 = Point<float, 2>{-1, 1};
    constexpr auto p1 = Point<float, 2>{0, -1};
    constexpr auto p2 = Point<float, 2>{1, 1};

    constexpr auto bezier = BezierPoints<float, 2, 2>{p0, p1, p2};

    for(auto _ : state)
    {
        [[maybe_unused]] constexpr auto length_compile_time = BezierLength::get(bezier);
    }
}

BENCHMARK(BM_BezierLengthCompileTime);
#endif  // !defined(MSVC)

static void BM_BezierLengthRunTime(benchmark::State& state)
{
    constexpr auto p0 = Point<float, 2>{-1, 1};
    constexpr auto p1 = Point<float, 2>{0, -1};
    constexpr auto p2 = Point<float, 2>{1, 1};

    constexpr auto bezier = BezierPoints<float, 2, 2>{p0, p1, p2};

    for(auto _ : state)
    {
        benchmark::DoNotOptimize(BezierLength::get(bezier));
    }
}
BENCHMARK(BM_BezierLengthRunTime);