#include "NBezier/binomial_coefficient.h"

#include "bezier_test_types.h"

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
    EXPECT_EQ(TestFixture::TestType::get(0, 0), TestFixture::Type(1));

    EXPECT_EQ(TestFixture::TestType::get(0, 1), TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, SecondRow)
{
    EXPECT_EQ(TestFixture::TestType::get(1, 0), TestFixture::Type(1));
    EXPECT_EQ(TestFixture::TestType::get(1, 1), TestFixture::Type(1));

    EXPECT_EQ(TestFixture::TestType::get(1, 2), TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, ThirdRow)
{
    EXPECT_EQ(TestFixture::TestType::get(2, 0), TestFixture::Type(1));
    EXPECT_EQ(TestFixture::TestType::get(2, 1), TestFixture::Type(2));
    EXPECT_EQ(TestFixture::TestType::get(2, 2), TestFixture::Type(1));

    EXPECT_EQ(TestFixture::TestType::get(2, 3), TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, FourthRow)
{
    EXPECT_EQ(TestFixture::TestType::get(3, 0), TestFixture::Type(1));
    EXPECT_EQ(TestFixture::TestType::get(3, 1), TestFixture::Type(3));
    EXPECT_EQ(TestFixture::TestType::get(3, 2), TestFixture::Type(3));
    EXPECT_EQ(TestFixture::TestType::get(3, 3), TestFixture::Type(1));

    EXPECT_EQ(TestFixture::TestType::get(3, 4), TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, FifthRow)
{
    EXPECT_EQ(TestFixture::TestType::get(4, 0), TestFixture::Type(1));
    EXPECT_EQ(TestFixture::TestType::get(4, 1), TestFixture::Type(4));
    EXPECT_EQ(TestFixture::TestType::get(4, 2), TestFixture::Type(6));
    EXPECT_EQ(TestFixture::TestType::get(4, 3), TestFixture::Type(4));
    EXPECT_EQ(TestFixture::TestType::get(4, 4), TestFixture::Type(1));

    EXPECT_EQ(TestFixture::TestType::get(4, 5), TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, SixthRow)
{
    EXPECT_EQ(TestFixture::TestType::get(5, 0), TestFixture::Type(1));
    EXPECT_EQ(TestFixture::TestType::get(5, 1), TestFixture::Type(5));
    EXPECT_EQ(TestFixture::TestType::get(5, 2), TestFixture::Type(10));
    EXPECT_EQ(TestFixture::TestType::get(5, 3), TestFixture::Type(10));
    EXPECT_EQ(TestFixture::TestType::get(5, 4), TestFixture::Type(5));
    EXPECT_EQ(TestFixture::TestType::get(5, 5), TestFixture::Type(1));

    EXPECT_EQ(TestFixture::TestType::get(5, 6), TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, SeventhRow)
{
    EXPECT_EQ(TestFixture::TestType::get(6, 0), TestFixture::Type(1));
    EXPECT_EQ(TestFixture::TestType::get(6, 1), TestFixture::Type(6));
    EXPECT_EQ(TestFixture::TestType::get(6, 2), TestFixture::Type(15));
    EXPECT_EQ(TestFixture::TestType::get(6, 3), TestFixture::Type(20));
    EXPECT_EQ(TestFixture::TestType::get(6, 4), TestFixture::Type(15));
    EXPECT_EQ(TestFixture::TestType::get(6, 5), TestFixture::Type(6));
    EXPECT_EQ(TestFixture::TestType::get(6, 6), TestFixture::Type(1));

    EXPECT_EQ(TestFixture::TestType::get(6, 7), TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, EighthRow)
{
    EXPECT_EQ(TestFixture::TestType::get(7, 0), TestFixture::Type(1));
    EXPECT_EQ(TestFixture::TestType::get(7, 1), TestFixture::Type(7));
    EXPECT_EQ(TestFixture::TestType::get(7, 2), TestFixture::Type(21));
    EXPECT_EQ(TestFixture::TestType::get(7, 3), TestFixture::Type(35));
    EXPECT_EQ(TestFixture::TestType::get(7, 4), TestFixture::Type(35));
    EXPECT_EQ(TestFixture::TestType::get(7, 5), TestFixture::Type(21));
    EXPECT_EQ(TestFixture::TestType::get(7, 6), TestFixture::Type(7));
    EXPECT_EQ(TestFixture::TestType::get(7, 7), TestFixture::Type(1));

    EXPECT_EQ(TestFixture::TestType::get(7, 8), TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, NinethRow)
{
    EXPECT_EQ(TestFixture::TestType::get(8, 0), TestFixture::Type(1));
    EXPECT_EQ(TestFixture::TestType::get(8, 1), TestFixture::Type(8));
    EXPECT_EQ(TestFixture::TestType::get(8, 2), TestFixture::Type(28));
    EXPECT_EQ(TestFixture::TestType::get(8, 3), TestFixture::Type(56));
    EXPECT_EQ(TestFixture::TestType::get(8, 4), TestFixture::Type(70));
    EXPECT_EQ(TestFixture::TestType::get(8, 5), TestFixture::Type(56));
    EXPECT_EQ(TestFixture::TestType::get(8, 6), TestFixture::Type(28));
    EXPECT_EQ(TestFixture::TestType::get(8, 7), TestFixture::Type(8));
    EXPECT_EQ(TestFixture::TestType::get(8, 8), TestFixture::Type(1));

    EXPECT_EQ(TestFixture::TestType::get(8, 9), TestFixture::Type(0));
}

TYPED_TEST_P(BinomialCoefficientTest, TenthRow)
{
    EXPECT_EQ(TestFixture::TestType::get(9, 0), TestFixture::Type(1));
    EXPECT_EQ(TestFixture::TestType::get(9, 1), TestFixture::Type(9));
    EXPECT_EQ(TestFixture::TestType::get(9, 2), TestFixture::Type(36));
    EXPECT_EQ(TestFixture::TestType::get(9, 3), TestFixture::Type(84));
    EXPECT_EQ(TestFixture::TestType::get(9, 4), TestFixture::Type(126));
    EXPECT_EQ(TestFixture::TestType::get(9, 5), TestFixture::Type(126));
    EXPECT_EQ(TestFixture::TestType::get(9, 6), TestFixture::Type(84));
    EXPECT_EQ(TestFixture::TestType::get(9, 7), TestFixture::Type(36));
    EXPECT_EQ(TestFixture::TestType::get(9, 8), TestFixture::Type(9));
    EXPECT_EQ(TestFixture::TestType::get(9, 9), TestFixture::Type(1));

    EXPECT_EQ(TestFixture::TestType::get(9, 10), TestFixture::Type(0));
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