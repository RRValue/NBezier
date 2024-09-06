#include "NBezier/bezier_split.h"

#include "bezier_test_types.h"

#include <gtest/gtest.h>

UseNameSpace(NBezier);

TEST(So, what3)
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

    constexpr auto split = BezierSplit::at(bezier, 0.5f);
    [[maybe_unused]] constexpr auto left_bezier = split.m_left;
    [[maybe_unused]] constexpr auto right_bezier = split.m_right;
}