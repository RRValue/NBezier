#include "NBezier/bezier_length.h"
#include "NBezier/bezier_points.h"
#include "NBezier/points.h"

#include "bezier_test_types.h"

#include <boost/qvm/map_mat_vec.hpp>
#include <boost/qvm/mat.hpp>
#include <boost/qvm/vec_operations.hpp>

#include <gtest/gtest.h>

UseNameSpace(NBezier);

TEST(So, what4)
{
    constexpr auto p0 = Point<float, 2>{-1, 1};
    constexpr auto p1 = Point<float, 2>{0, 0};
    constexpr auto p2 = Point<float, 2>{1, 1};

    [[maybe_unused]] constexpr auto bezier = BezierPoints<float, 2, 2>{p0, p1, p2};

    [[maybe_unused]] auto tree = BezierLength::get(bezier.getPoints());
}