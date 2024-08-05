#include "NBezier/bezier_points.h"

#include "bezier_test_types.h"

#include <gtest/gtest.h>

UseNameSpace(NBezier);

TEST(So, what)
{
    constexpr auto p0 = boost::qvm::vec<float, 2>{0, 1};
    constexpr auto p1 = boost::qvm::vec<float, 2>{1, 2};

    BezierPoints<float, 2, 1> b{};
    b.setPoint<0>(p0);
    b.setPoint<1>(p1);
    b.getPoint<0>();

    constexpr BezierPoints<float, 2, 1> constexpr_b{p0, p1};
    constexpr auto pout = constexpr_b.getPoint<0>();
}