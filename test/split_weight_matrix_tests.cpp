#include "NBezier/split_weight_matrix.h"

#include "bezier_test_types.h"

#include <gtest/gtest.h>

#include <boost/qvm/mat_operations.hpp>

#include <concepts>
#include <tuple>

// clang-format off
ClangDisableWarning(-Wmissing-braces);
// clang-format on

UseNameSpace(NBezier);

template<typename T>
class SplitWeightMatrixGenerationTest : public testing::Test
{
public:
    typedef T Scalar;
};

TYPED_TEST_SUITE_P(SplitWeightMatrixGenerationTest);

TYPED_TEST_P(SplitWeightMatrixGenerationTest, GetLeft)
{
    using S = TestFixture::Scalar;

    {
        constexpr auto m = SplitWeightMatrix::getLeft<S, 1>();
        constexpr auto e = boost::qvm::mat<S, 1, 1>{S(1)};

        EXPECT_EQ(m, e);
    }

    {
        constexpr auto m = SplitWeightMatrix::getLeft<S, 2>();
        constexpr auto e = boost::qvm::mat<S, 2, 2>{S(1), S(1),  //
                                                    S(0), S(1)};

        EXPECT_EQ(m, e);
    }

    {
        constexpr auto m = SplitWeightMatrix::getLeft<S, 3>();
        constexpr auto e = boost::qvm::mat<S, 3, 3>{S(1), S(1), S(1),  //
                                                    S(0), S(1), S(2),  //
                                                    S(0), S(0), S(1)};

        EXPECT_EQ(m, e);
    }

    {
        constexpr auto m = SplitWeightMatrix::getLeft<S, 4>();
        constexpr auto e = boost::qvm::mat<S, 4, 4>{S(1), S(1), S(1), S(1),  //
                                                    S(0), S(1), S(2), S(3),  //
                                                    S(0), S(0), S(1), S(3),  //
                                                    S(0), S(0), S(0), S(1)};

        EXPECT_EQ(m, e);
    }

    {
        constexpr auto m = SplitWeightMatrix::getLeft<S, 5>();
        constexpr auto e = boost::qvm::mat<S, 5, 5>{S(1), S(1), S(1), S(1), S(1),  //
                                                    S(0), S(1), S(2), S(3), S(4),  //
                                                    S(0), S(0), S(1), S(3), S(6),  //
                                                    S(0), S(0), S(0), S(1), S(4),  //
                                                    S(0), S(0), S(0), S(0), S(1)};

        EXPECT_EQ(m, e);
    }
}

TYPED_TEST_P(SplitWeightMatrixGenerationTest, GetRight)
{
    using S = TestFixture::Scalar;

    {
        constexpr auto m = SplitWeightMatrix::getRight<S, 1>();
        constexpr auto e = boost::qvm::mat<S, 1, 1>{S(1)};

        EXPECT_EQ(m, e);
    }

    {
        constexpr auto m = SplitWeightMatrix::getRight<S, 2>();
        constexpr auto e = boost::qvm::mat<S, 2, 2>{S(1), S(0),  //
                                                    S(1), S(1)};

        EXPECT_EQ(m, e);
    }

    {
        constexpr auto m = SplitWeightMatrix::getRight<S, 3>();
        constexpr auto e = boost::qvm::mat<S, 3, 3>{S(1), S(0), S(0),  //
                                                    S(2), S(1), S(0),  //
                                                    S(1), S(1), S(1)};

        EXPECT_EQ(m, e);
    }

    {
        constexpr auto m = SplitWeightMatrix::getRight<S, 4>();
        constexpr auto e = boost::qvm::mat<S, 4, 4>{S(1), S(0), S(0), S(0),  //
                                                    S(3), S(1), S(0), S(0),  //
                                                    S(3), S(2), S(1), S(0),  //
                                                    S(1), S(1), S(1), S(1)};

        EXPECT_EQ(m, e);
    }

    {
        constexpr auto m = SplitWeightMatrix::getRight<S, 5>();
        constexpr auto e = boost::qvm::mat<S, 5, 5>{S(1), S(0), S(0), S(0), S(0),  //
                                                    S(4), S(1), S(0), S(0), S(0),  //
                                                    S(6), S(3), S(1), S(0), S(0),  //
                                                    S(4), S(3), S(2), S(1), S(0),  //
                                                    S(1), S(1), S(1), S(1), S(1)};

        EXPECT_EQ(m, e);
    }
}

REGISTER_TYPED_TEST_SUITE_P(SplitWeightMatrixGenerationTest, GetLeft, GetRight);

INSTANTIATE_TYPED_TEST_SUITE_P(SplitWeightMatrixGeneration, SplitWeightMatrixGenerationTest, BezierScalars);

ClangEnableWarning();