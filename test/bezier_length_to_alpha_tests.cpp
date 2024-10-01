#include "NBezier/defines.h"

#include "NBezier/bezier_length.h"
#include "NBezier/bezier_length_to_alpha.h"
#include "NBezier/bezier_points.h"

#include <gtest/gtest.h>

UseNameSpace(NBezier);

TEST(Bezier, LengthToAlpha)
{
    constexpr auto p0 = Point<float, 2>{-1, 1};
    constexpr auto p1 = Point<float, 2>{0, -1};
    constexpr auto p2 = Point<float, 2>{1, 1};

    constexpr auto points = BezierPoints<float, 2, 2>{p0, p1, p2};
    constexpr auto result = BezierLength::get(points);
    //constexpr auto cache = result.m_cache;

    constexpr auto alpha0 = BezierLengthToAlpha::get(points, float(1), result);
    constexpr auto alpha1 = BezierLengthToAlpha::get(points, float(1.47894692), result);
    auto alpha2 = BezierLengthToAlpha::get(points, float(0.504211843) + float(0.400836170) + float(0.313840568), result);  
    //auto alpha1 = BezierLengthToAlpha::get(points, float(1));

    EXPECT_TRUE(alpha0 < float(1e-05));
    EXPECT_TRUE(alpha1 < float(1e-05));
    EXPECT_TRUE(alpha2 < float(1e-05));
    //EXPECT_TRUE(alpha1 < float(1e-05));
}