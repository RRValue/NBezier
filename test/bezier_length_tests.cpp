#include "NBezier/bezier_length.h"
#include "NBezier/bezier_points.h"

#include "bezier_test_types.h"

#include <gtest/gtest.h>

UseNameSpace(NBezier);

#if !defined(MSVC)
TEST(Bezier, LengthConstexpr)
{
    constexpr auto p0 = Point<float, 2>{-1, 1};
    constexpr auto p1 = Point<float, 2>{0, -1};
    constexpr auto p2 = Point<float, 2>{1, 1};

    constexpr auto bezier = BezierPoints<float, 2, 2>{p0, p1, p2};
    constexpr auto exp_length = float(2.957885715);
    constexpr auto cache_length_compile_time = BezierLength::get(bezier);
    const auto cache_length_run_time = BezierLength::get(bezier);
    constexpr auto length_compile_time = cache_length_compile_time[0];
    const auto length_run_time = cache_length_run_time[0];

    EXPECT_TRUE(std::equal(std::cbegin(cache_length_compile_time), std::cend(cache_length_compile_time),  //
                           std::cbegin(cache_length_run_time), std::cend(cache_length_run_time),          //
                           [](const auto& lhs, const auto& rhs) { return std::abs(lhs - rhs) < 1e-05f; }));
    EXPECT_EQ(length_compile_time, length_run_time);
    EXPECT_TRUE(std::abs(exp_length - length_compile_time) < float(1e-05));
    EXPECT_TRUE(std::abs(exp_length - length_run_time) < float(1e-05));
}
#endif  //! defined(MSVC)

TEST(Bezier, LengthRunTime)
{
    constexpr auto p0 = Point<float, 2>{-1, 1};
    constexpr auto p1 = Point<float, 2>{0, -1};
    constexpr auto p2 = Point<float, 2>{1, 1};

    constexpr auto bezier = BezierPoints<float, 2, 2>{p0, p1, p2};
    constexpr auto exp_length = float(2.957885715);
    const auto length_cache = BezierLength::get(bezier);
    const auto length_run_time = length_cache[0];

    EXPECT_TRUE(std::abs(exp_length - length_run_time) < float(1e-05));
}