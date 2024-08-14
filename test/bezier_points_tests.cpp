#include "NBezier/bezier_points.h"

#include "bezier_test_types.h"

#include <gtest/gtest.h>

UseNameSpace(NBezier);

TEST(BezierPoints, test)
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

TEST(BezierPoints, reduceLeftAndRight)
{
    constexpr auto p0 = boost::qvm::vec<float, 2>{0, 4};
    constexpr auto p1 = boost::qvm::vec<float, 2>{1, 5};
    constexpr auto p2 = boost::qvm::vec<float, 2>{2, 6};
    constexpr auto p3 = boost::qvm::vec<float, 2>{3, 7};

    constexpr auto bezier_points = BezierPoints<float, 2, 3>{p0, p1, p2, p3};

    constexpr auto left_d_0 = bezier_points.reduceFromLeft<0>();
    constexpr auto left_d_1 = bezier_points.reduceFromLeft<1>();
    constexpr auto left_d_2 = bezier_points.reduceFromLeft<2>();
    constexpr auto left_d_3 = bezier_points.reduceFromLeft<3>();

    constexpr auto right_d_0 = bezier_points.reduceFromRight<0>();
    constexpr auto right_d_1 = bezier_points.reduceFromRight<1>();
    constexpr auto right_d_2 = bezier_points.reduceFromRight<2>();
    constexpr auto right_d_3 = bezier_points.reduceFromRight<3>();

    constexpr auto exp_left_d_0 = BezierPoints<float, 2, 0>{p0};
    constexpr auto exp_left_d_1 = BezierPoints<float, 2, 1>{p0, p1};
    constexpr auto exp_left_d_2 = BezierPoints<float, 2, 2>{p0, p1, p2};
    constexpr auto exp_left_d_3 = BezierPoints<float, 2, 3>{p0, p1, p2, p3};

    constexpr auto exp_right_d_0 = BezierPoints<float, 2, 0>{p3};
    constexpr auto exp_right_d_1 = BezierPoints<float, 2, 1>{p2, p3};
    constexpr auto exp_right_d_2 = BezierPoints<float, 2, 2>{p1, p2, p3};
    constexpr auto exp_right_d_3 = BezierPoints<float, 2, 3>{p0, p1, p2, p3};

    EXPECT_EQ(left_d_0, exp_left_d_0);
    EXPECT_EQ(left_d_1, exp_left_d_1);
    EXPECT_EQ(left_d_2, exp_left_d_2);
    EXPECT_EQ(left_d_3, exp_left_d_3);

    EXPECT_EQ(right_d_0, exp_right_d_0);
    EXPECT_EQ(right_d_1, exp_right_d_1);
    EXPECT_EQ(right_d_2, exp_right_d_2);
    EXPECT_EQ(right_d_3, exp_right_d_3);
}