#include "NBezier/bezier_split.h"

#include "bezier_test_types.h"

#include <gtest/gtest.h>

UseNameSpace(NBezier);

TEST(So, what3)
{
    constexpr auto p0 = boost::qvm::vec<float, 3>{-1, 1, 0};
    constexpr auto p1 = boost::qvm::vec<float, 3>{0, 0, 0};
    constexpr auto p2 = boost::qvm::vec<float, 3>{1, 1, 0};
    constexpr auto p3 = boost::qvm::vec<float, 3>{2, 2, 1};
    constexpr BezierPoints<float, 3, 3> b{p0, p1, p2, p3};

    constexpr auto left_right = BezierSplit::at(b, 0.5f);
    constexpr auto left = left_right.m_left;
    constexpr auto right = left_right.m_right;

    int ii = 0;
    ii++;
}