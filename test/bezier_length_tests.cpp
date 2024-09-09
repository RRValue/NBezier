#include "NBezier/bezier_length.h"
#include "NBezier/bezier_points.h"

#include "bezier_test_types.h"

#include <gtest/gtest.h>

UseNameSpace(NBezier);

TEST(Bezier, Length)
{
    constexpr auto p0 = Point<float, 2>{-1, 1};
    constexpr auto p1 = Point<float, 2>{0, -1};
    constexpr auto p2 = Point<float, 2>{1, 1};

    [[maybe_unused]] constexpr auto bezier = BezierPoints<float, 2, 2>{p0, p1, p2};
    [[maybe_unused]] constexpr auto exp_length = float(2.957885715);
    [[maybe_unused]] constexpr auto length_compile_time = BezierLength::get(bezier);
    [[maybe_unused]] const auto length_run_time = BezierLength::get(bezier);

    EXPECT_EQ(length_compile_time, length_run_time);
    EXPECT_TRUE(std::abs(exp_length - length_compile_time) < float(1e-05));
    EXPECT_TRUE(std::abs(exp_length - length_run_time) < float(1e-05));
}