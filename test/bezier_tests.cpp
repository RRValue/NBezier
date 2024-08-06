#include "NBezier/bezier.h"

#include "bezier_test_types.h"

#include <gtest/gtest.h>

UseNameSpace(NBezier);

TEST(So, what2)
{
    constexpr auto p0 = boost::qvm::vec<float, 3>{-1, 1, 0};
    constexpr auto p1 = boost::qvm::vec<float, 3>{0, 0, 0};
    constexpr auto p2 = boost::qvm::vec<float, 3>{1, 1, 0};
    constexpr BezierPoints<float, 3, 2> b{p0, p1, p2};

    constexpr auto position = Bezier::point(b, 0.5f);
    constexpr auto tangent = Bezier::tangent(b, 0.5f);
    constexpr auto normal = Bezier::normal(b, 0.5f);
    constexpr auto curvature = Bezier::curvature(b, 0.5f);
}