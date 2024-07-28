#include "NBezier/binomial_coefficient.h"

#include <gtest/gtest.h>

using namespace NBezier;

template<typename T>
class BinomialCoefficientTest : public testing::Test
{
public:
    typedef BinomialCoefficient<T> TestType;
    typedef T Type;
};

TYPED_TEST_SUITE_P(BinomialCoefficientTest);

TYPED_TEST_P(BinomialCoefficientTest, FirstRow)
{
    constexpr auto _0_choose_0 = TestFixture::TestType::get(0, 0);
    constexpr auto _0_choose_1 = TestFixture::TestType::get(0, 1);

    EXPECT_EQ(_0_choose_0, TestFixture::Type(1));
    EXPECT_EQ(_0_choose_1, TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, SecondRow)
{
    constexpr auto _1_choose_0 = TestFixture::TestType::get(1, 0);
    constexpr auto _1_choose_1 = TestFixture::TestType::get(1, 1);
    constexpr auto _1_choose_2 = TestFixture::TestType::get(1, 2);

    EXPECT_EQ(_1_choose_0, TestFixture::Type(1));
    EXPECT_EQ(_1_choose_1, TestFixture::Type(1));
    EXPECT_EQ(_1_choose_2, TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, ThirdRow)
{
    constexpr auto _2_choose_0 = TestFixture::TestType::get(2, 0);
    constexpr auto _2_choose_1 = TestFixture::TestType::get(2, 1);
    constexpr auto _2_choose_2 = TestFixture::TestType::get(2, 2);
    constexpr auto _2_choose_3 = TestFixture::TestType::get(2, 3);

    EXPECT_EQ(_2_choose_0, TestFixture::Type(1));
    EXPECT_EQ(_2_choose_1, TestFixture::Type(2));
    EXPECT_EQ(_2_choose_2, TestFixture::Type(1));
    EXPECT_EQ(_2_choose_3, TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, FourthRow)
{
    constexpr auto _3_choose_0 = TestFixture::TestType::get(3, 0);
    constexpr auto _3_choose_1 = TestFixture::TestType::get(3, 1);
    constexpr auto _3_choose_2 = TestFixture::TestType::get(3, 2);
    constexpr auto _3_choose_3 = TestFixture::TestType::get(3, 3);
    constexpr auto _3_choose_4 = TestFixture::TestType::get(3, 4);

    EXPECT_EQ(_3_choose_0, TestFixture::Type(1));
    EXPECT_EQ(_3_choose_1, TestFixture::Type(3));
    EXPECT_EQ(_3_choose_2, TestFixture::Type(3));
    EXPECT_EQ(_3_choose_3, TestFixture::Type(1));
    EXPECT_EQ(_3_choose_4, TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, FifthRow)
{
    constexpr auto _4_choose_0 = TestFixture::TestType::get(4, 0);
    constexpr auto _4_choose_1 = TestFixture::TestType::get(4, 1);
    constexpr auto _4_choose_2 = TestFixture::TestType::get(4, 2);
    constexpr auto _4_choose_3 = TestFixture::TestType::get(4, 3);
    constexpr auto _4_choose_4 = TestFixture::TestType::get(4, 4);
    constexpr auto _4_choose_5 = TestFixture::TestType::get(4, 5);

    EXPECT_EQ(_4_choose_0, TestFixture::Type(1));
    EXPECT_EQ(_4_choose_1, TestFixture::Type(4));
    EXPECT_EQ(_4_choose_2, TestFixture::Type(6));
    EXPECT_EQ(_4_choose_3, TestFixture::Type(4));
    EXPECT_EQ(_4_choose_4, TestFixture::Type(1));
    EXPECT_EQ(_4_choose_5, TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, SixthRow)
{
    constexpr auto _5_choose_0 = TestFixture::TestType::get(5, 0);
    constexpr auto _5_choose_1 = TestFixture::TestType::get(5, 1);
    constexpr auto _5_choose_2 = TestFixture::TestType::get(5, 2);
    constexpr auto _5_choose_3 = TestFixture::TestType::get(5, 3);
    constexpr auto _5_choose_4 = TestFixture::TestType::get(5, 4);
    constexpr auto _5_choose_5 = TestFixture::TestType::get(5, 5);
    constexpr auto _5_choose_6 = TestFixture::TestType::get(5, 6);

    EXPECT_EQ(_5_choose_0, TestFixture::Type(1));
    EXPECT_EQ(_5_choose_1, TestFixture::Type(5));
    EXPECT_EQ(_5_choose_2, TestFixture::Type(10));
    EXPECT_EQ(_5_choose_3, TestFixture::Type(10));
    EXPECT_EQ(_5_choose_4, TestFixture::Type(5));
    EXPECT_EQ(_5_choose_5, TestFixture::Type(1));
    EXPECT_EQ(_5_choose_6, TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, SeventhRow)
{
    constexpr auto _6_choose_0 = TestFixture::TestType::get(6, 0);
    constexpr auto _6_choose_1 = TestFixture::TestType::get(6, 1);
    constexpr auto _6_choose_2 = TestFixture::TestType::get(6, 2);
    constexpr auto _6_choose_3 = TestFixture::TestType::get(6, 3);
    constexpr auto _6_choose_4 = TestFixture::TestType::get(6, 4);
    constexpr auto _6_choose_5 = TestFixture::TestType::get(6, 5);
    constexpr auto _6_choose_6 = TestFixture::TestType::get(6, 6);
    constexpr auto _6_choose_7 = TestFixture::TestType::get(6, 7);

    EXPECT_EQ(_6_choose_0, TestFixture::Type(1));
    EXPECT_EQ(_6_choose_1, TestFixture::Type(6));
    EXPECT_EQ(_6_choose_2, TestFixture::Type(15));
    EXPECT_EQ(_6_choose_3, TestFixture::Type(20));
    EXPECT_EQ(_6_choose_4, TestFixture::Type(15));
    EXPECT_EQ(_6_choose_5, TestFixture::Type(6));
    EXPECT_EQ(_6_choose_6, TestFixture::Type(1));
    EXPECT_EQ(_6_choose_7, TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, EighthRow)
{
    constexpr auto _7_choose_0 = TestFixture::TestType::get(7, 0);
    constexpr auto _7_choose_1 = TestFixture::TestType::get(7, 1);
    constexpr auto _7_choose_2 = TestFixture::TestType::get(7, 2);
    constexpr auto _7_choose_3 = TestFixture::TestType::get(7, 3);
    constexpr auto _7_choose_4 = TestFixture::TestType::get(7, 4);
    constexpr auto _7_choose_5 = TestFixture::TestType::get(7, 5);
    constexpr auto _7_choose_6 = TestFixture::TestType::get(7, 6);
    constexpr auto _7_choose_7 = TestFixture::TestType::get(7, 7);
    constexpr auto _7_choose_8 = TestFixture::TestType::get(7, 8);

    EXPECT_EQ(_7_choose_0, TestFixture::Type(1));
    EXPECT_EQ(_7_choose_1, TestFixture::Type(7));
    EXPECT_EQ(_7_choose_2, TestFixture::Type(21));
    EXPECT_EQ(_7_choose_3, TestFixture::Type(35));
    EXPECT_EQ(_7_choose_4, TestFixture::Type(35));
    EXPECT_EQ(_7_choose_5, TestFixture::Type(21));
    EXPECT_EQ(_7_choose_6, TestFixture::Type(7));
    EXPECT_EQ(_7_choose_7, TestFixture::Type(1));
    EXPECT_EQ(_7_choose_8, TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, NinethRow)
{
    constexpr auto _8_choose_0 = TestFixture::TestType::get(8, 0);
    constexpr auto _8_choose_1 = TestFixture::TestType::get(8, 1);
    constexpr auto _8_choose_2 = TestFixture::TestType::get(8, 2);
    constexpr auto _8_choose_3 = TestFixture::TestType::get(8, 3);
    constexpr auto _8_choose_4 = TestFixture::TestType::get(8, 4);
    constexpr auto _8_choose_5 = TestFixture::TestType::get(8, 5);
    constexpr auto _8_choose_6 = TestFixture::TestType::get(8, 6);
    constexpr auto _8_choose_7 = TestFixture::TestType::get(8, 7);
    constexpr auto _8_choose_8 = TestFixture::TestType::get(8, 8);
    constexpr auto _8_choose_9 = TestFixture::TestType::get(8, 9);

    EXPECT_EQ(_8_choose_0, TestFixture::Type(1));
    EXPECT_EQ(_8_choose_1, TestFixture::Type(8));
    EXPECT_EQ(_8_choose_2, TestFixture::Type(28));
    EXPECT_EQ(_8_choose_3, TestFixture::Type(56));
    EXPECT_EQ(_8_choose_4, TestFixture::Type(70));
    EXPECT_EQ(_8_choose_5, TestFixture::Type(56));
    EXPECT_EQ(_8_choose_6, TestFixture::Type(28));
    EXPECT_EQ(_8_choose_7, TestFixture::Type(8));
    EXPECT_EQ(_8_choose_8, TestFixture::Type(1));
    EXPECT_EQ(_8_choose_9, TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, TenthRow)
{
    constexpr auto _9_choose_0 = TestFixture::TestType::get(9, 0);
    constexpr auto _9_choose_1 = TestFixture::TestType::get(9, 1);
    constexpr auto _9_choose_2 = TestFixture::TestType::get(9, 2);
    constexpr auto _9_choose_3 = TestFixture::TestType::get(9, 3);
    constexpr auto _9_choose_4 = TestFixture::TestType::get(9, 4);
    constexpr auto _9_choose_5 = TestFixture::TestType::get(9, 5);
    constexpr auto _9_choose_6 = TestFixture::TestType::get(9, 6);
    constexpr auto _9_choose_7 = TestFixture::TestType::get(9, 7);
    constexpr auto _9_choose_8 = TestFixture::TestType::get(9, 8);
    constexpr auto _9_choose_9 = TestFixture::TestType::get(9, 9);
    constexpr auto _9_choose_10 = TestFixture::TestType::get(9, 10);

    EXPECT_EQ(_9_choose_0, TestFixture::Type(1));
    EXPECT_EQ(_9_choose_1, TestFixture::Type(9));
    EXPECT_EQ(_9_choose_2, TestFixture::Type(36));
    EXPECT_EQ(_9_choose_3, TestFixture::Type(84));
    EXPECT_EQ(_9_choose_4, TestFixture::Type(126));
    EXPECT_EQ(_9_choose_5, TestFixture::Type(126));
    EXPECT_EQ(_9_choose_6, TestFixture::Type(84));
    EXPECT_EQ(_9_choose_7, TestFixture::Type(36));
    EXPECT_EQ(_9_choose_8, TestFixture::Type(9));
    EXPECT_EQ(_9_choose_9, TestFixture::Type(1));
    EXPECT_EQ(_9_choose_10, TestFixture::Type(0));
}

REGISTER_TYPED_TEST_SUITE_P(BinomialCoefficientTest,  //
                            FirstRow,                 //
                            SecondRow,                //
                            ThirdRow,                 //
                            FourthRow,                //
                            FifthRow,                 //
                            SixthRow,                 //
                            SeventhRow,               //
                            EighthRow,                //
                            NinethRow,                //
                            TenthRow);

using BinomialCoefficientTypes = ::testing::Types<unsigned int,        //
                                                  int,                 //
                                                  size_t,              //
                                                  unsigned long long,  //
                                                  long long,           //
                                                  char,                //
                                                  unsigned char,       //
                                                  float,               //
                                                  double>;

INSTANTIATE_TYPED_TEST_SUITE_P(BinomialCoefficientTests, BinomialCoefficientTest, BinomialCoefficientTypes);