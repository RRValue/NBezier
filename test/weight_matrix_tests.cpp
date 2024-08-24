#include "NBezier/weight_matrix.h"

#include "bezier_test_types.h"

#include <gtest/gtest.h>

#include <boost/qvm/mat_operations.hpp>

#include <concepts>
#include <tuple>

UseNameSpace(NBezier);

template<typename T>
class WeightMatrixGenerationTest : public testing::Test
{
public:
    typedef T Scalar;
};

TYPED_TEST_SUITE_P(WeightMatrixGenerationTest);

TYPED_TEST_P(WeightMatrixGenerationTest, Generation)
{
    using S = TestFixture::Scalar;

    {
        constexpr auto m = WeightMatrix::get<S, 1>();
        constexpr auto e = boost::qvm::mat<S, 1, 1>{S(1)};

        EXPECT_EQ(m, e);
    }

    {
        constexpr auto m = WeightMatrix::get<S, 2>();
        constexpr auto e = boost::qvm::mat<S, 2, 2>{S(-1), S(1),  //
                                                    S(1), S(0)};
        EXPECT_EQ(m, e);
    }

    {
        constexpr auto m = WeightMatrix::get<S, 3>();
        constexpr auto e = boost::qvm::mat<S, 3, 3>{S(1),  S(-2), S(1),  //
                                                    S(-2), S(2),  S(0),  //
                                                    S(1),  S(0),  S(0)};

        EXPECT_EQ(m, e);
    }

    {
        constexpr auto m = WeightMatrix::get<S, 4>();
        constexpr auto e = boost::qvm::mat<S, 4, 4>{S(-1), S(3),  S(-3), S(1),  //
                                                    S(3),  S(-6), S(3),  S(0),  //
                                                    S(-3), S(3),  S(0),  S(0),  //
                                                    S(1),  S(0),  S(0),  S(0)};

        EXPECT_EQ(m, e);
    }

    {
        constexpr auto m = WeightMatrix::get<S, 5>();
        constexpr auto e = boost::qvm::mat<S, 5, 5>{S(1),  S(-4),  S(6),   S(-4), S(1),  //
                                                    S(-4), S(12),  S(-12), S(4),  S(0),  //
                                                    S(6),  S(-12), S(6),   S(0),  S(0),  //
                                                    S(-4), S(4),   S(0),   S(0),  S(0),  //
                                                    S(1),  S(0),   S(0),   S(0),  S(0)};

        EXPECT_EQ(m, e);
    }
}

REGISTER_TYPED_TEST_SUITE_P(WeightMatrixGenerationTest, Generation);

INSTANTIATE_TYPED_TEST_SUITE_P(WeightMatrixGeneration, WeightMatrixGenerationTest, BezierScalars);