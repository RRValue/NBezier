#include "NBezier/binomial/coefficient.h"
#include "NBezier/binomial/type.h"

#include "binomial_test_types.h"

#include <gtest/gtest.h>

UseNameSpace(NBezier::Binomial);

template<typename T>
class CoefficientTest : public testing::Test
{
};

TYPED_TEST_SUITE_P(CoefficientTest);

TYPED_TEST_P(CoefficientTest, FirstRow)
{
    constexpr auto _0_choose_0 = Coefficient::get(TypeParam(0), TypeParam(0));
    constexpr auto _0_choose_1 = Coefficient::get(TypeParam(0), TypeParam(1));

    EXPECT_EQ(_0_choose_0, TypeParam(1));
    EXPECT_EQ(_0_choose_1, TypeParam(0));
}

TYPED_TEST_P(CoefficientTest, SecondRow)
{
    constexpr auto _1_choose_0 = Coefficient::get(TypeParam(1), TypeParam(0));
    constexpr auto _1_choose_1 = Coefficient::get(TypeParam(1), TypeParam(1));
    constexpr auto _1_choose_2 = Coefficient::get(TypeParam(1), TypeParam(2));

    EXPECT_EQ(_1_choose_0, TypeParam(1));
    EXPECT_EQ(_1_choose_1, TypeParam(1));
    EXPECT_EQ(_1_choose_2, TypeParam(0));
}

TYPED_TEST_P(CoefficientTest, ThirdRow)
{
    constexpr auto _2_choose_0 = Coefficient::get(TypeParam(2), TypeParam(0));
    constexpr auto _2_choose_1 = Coefficient::get(TypeParam(2), TypeParam(1));
    constexpr auto _2_choose_2 = Coefficient::get(TypeParam(2), TypeParam(2));
    constexpr auto _2_choose_3 = Coefficient::get(TypeParam(2), TypeParam(3));

    EXPECT_EQ(_2_choose_0, TypeParam(1));
    EXPECT_EQ(_2_choose_1, TypeParam(2));
    EXPECT_EQ(_2_choose_2, TypeParam(1));
    EXPECT_EQ(_2_choose_3, TypeParam(0));
}

TYPED_TEST_P(CoefficientTest, FourthRow)
{
    constexpr auto _3_choose_0 = Coefficient::get(TypeParam(3), TypeParam(0));
    constexpr auto _3_choose_1 = Coefficient::get(TypeParam(3), TypeParam(1));
    constexpr auto _3_choose_2 = Coefficient::get(TypeParam(3), TypeParam(2));
    constexpr auto _3_choose_3 = Coefficient::get(TypeParam(3), TypeParam(3));
    constexpr auto _3_choose_4 = Coefficient::get(TypeParam(3), TypeParam(4));

    EXPECT_EQ(_3_choose_0, TypeParam(1));
    EXPECT_EQ(_3_choose_1, TypeParam(3));
    EXPECT_EQ(_3_choose_2, TypeParam(3));
    EXPECT_EQ(_3_choose_3, TypeParam(1));
    EXPECT_EQ(_3_choose_4, TypeParam(0));
}

TYPED_TEST_P(CoefficientTest, FifthRow)
{
    constexpr auto _4_choose_0 = Coefficient::get(TypeParam(4), TypeParam(0));
    constexpr auto _4_choose_1 = Coefficient::get(TypeParam(4), TypeParam(1));
    constexpr auto _4_choose_2 = Coefficient::get(TypeParam(4), TypeParam(2));
    constexpr auto _4_choose_3 = Coefficient::get(TypeParam(4), TypeParam(3));
    constexpr auto _4_choose_4 = Coefficient::get(TypeParam(4), TypeParam(4));
    constexpr auto _4_choose_5 = Coefficient::get(TypeParam(4), TypeParam(5));

    EXPECT_EQ(_4_choose_0, TypeParam(1));
    EXPECT_EQ(_4_choose_1, TypeParam(4));
    EXPECT_EQ(_4_choose_2, TypeParam(6));
    EXPECT_EQ(_4_choose_3, TypeParam(4));
    EXPECT_EQ(_4_choose_4, TypeParam(1));
    EXPECT_EQ(_4_choose_5, TypeParam(0));
}

TYPED_TEST_P(CoefficientTest, SixthRow)
{
    constexpr auto _5_choose_0 = Coefficient::get(TypeParam(5), TypeParam(0));
    constexpr auto _5_choose_1 = Coefficient::get(TypeParam(5), TypeParam(1));
    constexpr auto _5_choose_2 = Coefficient::get(TypeParam(5), TypeParam(2));
    constexpr auto _5_choose_3 = Coefficient::get(TypeParam(5), TypeParam(3));
    constexpr auto _5_choose_4 = Coefficient::get(TypeParam(5), TypeParam(4));
    constexpr auto _5_choose_5 = Coefficient::get(TypeParam(5), TypeParam(5));
    constexpr auto _5_choose_6 = Coefficient::get(TypeParam(5), TypeParam(6));

    EXPECT_EQ(_5_choose_0, TypeParam(1));
    EXPECT_EQ(_5_choose_1, TypeParam(5));
    EXPECT_EQ(_5_choose_2, TypeParam(10));
    EXPECT_EQ(_5_choose_3, TypeParam(10));
    EXPECT_EQ(_5_choose_4, TypeParam(5));
    EXPECT_EQ(_5_choose_5, TypeParam(1));
    EXPECT_EQ(_5_choose_6, TypeParam(0));
}

TYPED_TEST_P(CoefficientTest, SeventhRow)
{
    constexpr auto _6_choose_0 = Coefficient::get(TypeParam(6), TypeParam(0));
    constexpr auto _6_choose_1 = Coefficient::get(TypeParam(6), TypeParam(1));
    constexpr auto _6_choose_2 = Coefficient::get(TypeParam(6), TypeParam(2));
    constexpr auto _6_choose_3 = Coefficient::get(TypeParam(6), TypeParam(3));
    constexpr auto _6_choose_4 = Coefficient::get(TypeParam(6), TypeParam(4));
    constexpr auto _6_choose_5 = Coefficient::get(TypeParam(6), TypeParam(5));
    constexpr auto _6_choose_6 = Coefficient::get(TypeParam(6), TypeParam(6));
    constexpr auto _6_choose_7 = Coefficient::get(TypeParam(6), TypeParam(7));

    EXPECT_EQ(_6_choose_0, TypeParam(1));
    EXPECT_EQ(_6_choose_1, TypeParam(6));
    EXPECT_EQ(_6_choose_2, TypeParam(15));
    EXPECT_EQ(_6_choose_3, TypeParam(20));
    EXPECT_EQ(_6_choose_4, TypeParam(15));
    EXPECT_EQ(_6_choose_5, TypeParam(6));
    EXPECT_EQ(_6_choose_6, TypeParam(1));
    EXPECT_EQ(_6_choose_7, TypeParam(0));
}

TYPED_TEST_P(CoefficientTest, EighthRow)
{
    constexpr auto _7_choose_0 = Coefficient::get(TypeParam(7), TypeParam(0));
    constexpr auto _7_choose_1 = Coefficient::get(TypeParam(7), TypeParam(1));
    constexpr auto _7_choose_2 = Coefficient::get(TypeParam(7), TypeParam(2));
    constexpr auto _7_choose_3 = Coefficient::get(TypeParam(7), TypeParam(3));
    constexpr auto _7_choose_4 = Coefficient::get(TypeParam(7), TypeParam(4));
    constexpr auto _7_choose_5 = Coefficient::get(TypeParam(7), TypeParam(5));
    constexpr auto _7_choose_6 = Coefficient::get(TypeParam(7), TypeParam(6));
    constexpr auto _7_choose_7 = Coefficient::get(TypeParam(7), TypeParam(7));
    constexpr auto _7_choose_8 = Coefficient::get(TypeParam(7), TypeParam(8));

    EXPECT_EQ(_7_choose_0, TypeParam(1));
    EXPECT_EQ(_7_choose_1, TypeParam(7));
    EXPECT_EQ(_7_choose_2, TypeParam(21));
    EXPECT_EQ(_7_choose_3, TypeParam(35));
    EXPECT_EQ(_7_choose_4, TypeParam(35));
    EXPECT_EQ(_7_choose_5, TypeParam(21));
    EXPECT_EQ(_7_choose_6, TypeParam(7));
    EXPECT_EQ(_7_choose_7, TypeParam(1));
    EXPECT_EQ(_7_choose_8, TypeParam(0));
}

TYPED_TEST_P(CoefficientTest, NinethRow)
{
    constexpr auto _8_choose_0 = Coefficient::get(TypeParam(8), TypeParam(0));
    constexpr auto _8_choose_1 = Coefficient::get(TypeParam(8), TypeParam(1));
    constexpr auto _8_choose_2 = Coefficient::get(TypeParam(8), TypeParam(2));
    constexpr auto _8_choose_3 = Coefficient::get(TypeParam(8), TypeParam(3));
    constexpr auto _8_choose_4 = Coefficient::get(TypeParam(8), TypeParam(4));
    constexpr auto _8_choose_5 = Coefficient::get(TypeParam(8), TypeParam(5));
    constexpr auto _8_choose_6 = Coefficient::get(TypeParam(8), TypeParam(6));
    constexpr auto _8_choose_7 = Coefficient::get(TypeParam(8), TypeParam(7));
    constexpr auto _8_choose_8 = Coefficient::get(TypeParam(8), TypeParam(8));
    constexpr auto _8_choose_9 = Coefficient::get(TypeParam(8), TypeParam(9));

    EXPECT_EQ(_8_choose_0, TypeParam(1));
    EXPECT_EQ(_8_choose_1, TypeParam(8));
    EXPECT_EQ(_8_choose_2, TypeParam(28));
    EXPECT_EQ(_8_choose_3, TypeParam(56));
    EXPECT_EQ(_8_choose_4, TypeParam(70));
    EXPECT_EQ(_8_choose_5, TypeParam(56));
    EXPECT_EQ(_8_choose_6, TypeParam(28));
    EXPECT_EQ(_8_choose_7, TypeParam(8));
    EXPECT_EQ(_8_choose_8, TypeParam(1));
    EXPECT_EQ(_8_choose_9, TypeParam(0));
}

TYPED_TEST_P(CoefficientTest, TenthRow)
{
    constexpr auto _9_choose_0 = Coefficient::get(TypeParam(9), TypeParam(0));
    constexpr auto _9_choose_1 = Coefficient::get(TypeParam(9), TypeParam(1));
    constexpr auto _9_choose_2 = Coefficient::get(TypeParam(9), TypeParam(2));
    constexpr auto _9_choose_3 = Coefficient::get(TypeParam(9), TypeParam(3));
    constexpr auto _9_choose_4 = Coefficient::get(TypeParam(9), TypeParam(4));
    constexpr auto _9_choose_5 = Coefficient::get(TypeParam(9), TypeParam(5));
    constexpr auto _9_choose_6 = Coefficient::get(TypeParam(9), TypeParam(6));
    constexpr auto _9_choose_7 = Coefficient::get(TypeParam(9), TypeParam(7));
    constexpr auto _9_choose_8 = Coefficient::get(TypeParam(9), TypeParam(8));
    constexpr auto _9_choose_9 = Coefficient::get(TypeParam(9), TypeParam(9));
    constexpr auto _9_choose_10 = Coefficient::get(TypeParam(9), TypeParam(10));

    EXPECT_EQ(_9_choose_0, TypeParam(1));
    EXPECT_EQ(_9_choose_1, TypeParam(9));
    EXPECT_EQ(_9_choose_2, TypeParam(36));
    EXPECT_EQ(_9_choose_3, TypeParam(84));
    EXPECT_EQ(_9_choose_4, TypeParam(126));
    EXPECT_EQ(_9_choose_5, TypeParam(126));
    EXPECT_EQ(_9_choose_6, TypeParam(84));
    EXPECT_EQ(_9_choose_7, TypeParam(36));
    EXPECT_EQ(_9_choose_8, TypeParam(9));
    EXPECT_EQ(_9_choose_9, TypeParam(1));
    EXPECT_EQ(_9_choose_10, TypeParam(0));
}

REGISTER_TYPED_TEST_SUITE_P(CoefficientTest,  //
                            FirstRow,         //
                            SecondRow,        //
                            ThirdRow,         //
                            FourthRow,        //
                            FifthRow,         //
                            SixthRow,         //
                            SeventhRow,       //
                            EighthRow,        //
                            NinethRow,        //
                            TenthRow);

INSTANTIATE_TYPED_TEST_SUITE_P(CoefficientTests, CoefficientTest, CoefficientTypes);