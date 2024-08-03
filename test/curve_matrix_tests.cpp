#include "NBezier/curve_matrix.h"

#include "bezier_test_types.h"

#include <gtest/gtest.h>

#include <boost/qvm/mat_access.hpp>

#include <concepts>
#include <tuple>

UseNameSpace(NBezier);

template<typename T>
class CurveMatrixGenerationTest : public testing::Test
{
public:
    typedef T Scalar;
};

TYPED_TEST_SUITE_P(CurveMatrixGenerationTest);

TYPED_TEST_P(CurveMatrixGenerationTest, Generation)
{
    using S = TestFixture::Scalar;

    {
        constexpr auto m = CurveMatrix<S, 1>::get();
        EXPECT_EQ(A00(m), S(1));
    }

    {
        constexpr auto m = CurveMatrix<S, 2>::get();
        EXPECT_EQ(A00(m), S(-1));
        EXPECT_EQ(A01(m), S(1));
        EXPECT_EQ(A10(m), S(1));
        EXPECT_EQ(A11(m), S(0));
    }

    {
        constexpr auto m = CurveMatrix<S, 3>::get();
        EXPECT_EQ(A00(m), S(1));
        EXPECT_EQ(A01(m), S(-2));
        EXPECT_EQ(A02(m), S(1));
        EXPECT_EQ(A10(m), S(-2));
        EXPECT_EQ(A11(m), S(2));
        EXPECT_EQ(A12(m), S(0));
        EXPECT_EQ(A20(m), S(1));
        EXPECT_EQ(A21(m), S(0));
        EXPECT_EQ(A22(m), S(0));
    }

    {
        constexpr auto m = CurveMatrix<S, 4>::get();
        EXPECT_EQ(A00(m), S(-1));
        EXPECT_EQ(A01(m), S(3));
        EXPECT_EQ(A02(m), S(-3));
        EXPECT_EQ(A03(m), S(1));
        EXPECT_EQ(A10(m), S(3));
        EXPECT_EQ(A11(m), S(-6));
        EXPECT_EQ(A12(m), S(3));
        EXPECT_EQ(A13(m), S(0));
        EXPECT_EQ(A20(m), S(-3));
        EXPECT_EQ(A21(m), S(3));
        EXPECT_EQ(A22(m), S(0));
        EXPECT_EQ(A23(m), S(0));
        EXPECT_EQ(A30(m), S(1));
        EXPECT_EQ(A31(m), S(0));
        EXPECT_EQ(A32(m), S(0));
        EXPECT_EQ(A33(m), S(0));
    }

    {
        constexpr auto m = CurveMatrix<S, 5>::get();
        EXPECT_EQ(A00(m), S(1));
        EXPECT_EQ(A01(m), S(-4));
        EXPECT_EQ(A02(m), S(6));
        EXPECT_EQ(A03(m), S(-4));
        EXPECT_EQ(A04(m), S(1));
        EXPECT_EQ(A10(m), S(-4));
        EXPECT_EQ(A11(m), S(12));
        EXPECT_EQ(A12(m), S(-12));
        EXPECT_EQ(A13(m), S(4));
        EXPECT_EQ(A14(m), S(0));
        EXPECT_EQ(A20(m), S(6));
        EXPECT_EQ(A21(m), S(-12));
        EXPECT_EQ(A22(m), S(6));
        EXPECT_EQ(A23(m), S(0));
        EXPECT_EQ(A24(m), S(0));
        EXPECT_EQ(A30(m), S(-4));
        EXPECT_EQ(A31(m), S(4));
        EXPECT_EQ(A32(m), S(0));
        EXPECT_EQ(A33(m), S(0));
        EXPECT_EQ(A34(m), S(0));
        EXPECT_EQ(A40(m), S(1));
        EXPECT_EQ(A41(m), S(0));
        EXPECT_EQ(A42(m), S(0));
        EXPECT_EQ(A43(m), S(0));
        EXPECT_EQ(A44(m), S(0));
    }
}

REGISTER_TYPED_TEST_SUITE_P(CurveMatrixGenerationTest, Generation);

INSTANTIATE_TYPED_TEST_SUITE_P(CurveMatrixGeneration, CurveMatrixGenerationTest, CurveMatrixScalars);