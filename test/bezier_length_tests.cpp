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
    [[maybe_unused]] constexpr auto length = BezierLength::get(bezier);

    EXPECT_TRUE(std::abs(exp_length - length) < float(1e-05));
}