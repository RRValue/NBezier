#include "NBezier/bezier.h"
#include "NBezier/curve_matrix.h"

#include "bezier_test_types.h"

#include <gtest/gtest.h>

UseNameSpace(NBezier);

TEST(So, what)
{
    Bezier<float, 2, 1> b;
    b.setPoint<0>(boost::qvm::vec<float, 2>{0, 1});
    b.setPoint<1>(boost::qvm::vec<float, 2>{1, 2});

    constexpr auto p0 = b.getPoint<0>();

    const auto p = b.point(0.5f);
}