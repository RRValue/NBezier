#include "NBezier/math/pow.h"

#include <gtest/gtest.h>

UseNameSpace(NBezier);
UseNameSpace(Math);

TEST(Math, Pow2)
{
    constexpr auto r0 = Math::Pow::get2<size_t, 0>();
    constexpr auto r1 = Math::Pow::get2<size_t, 1>();
    constexpr auto r2 = Math::Pow::get2<size_t, 2>();
    constexpr auto r3 = Math::Pow::get2<size_t, 3>();
    constexpr auto r4 = Math::Pow::get2<size_t, 4>();

    EXPECT_EQ(r0, 1);
    EXPECT_EQ(r1, 2);
    EXPECT_EQ(r2, 4);
    EXPECT_EQ(r3, 8);
    EXPECT_EQ(r4, 16);
}