#include "NBezier/split_matrices.h"

#include "bezier_test_types.h"

#include <gtest/gtest.h>

#include <boost/qvm/mat_operations.hpp>

#include <concepts>
#include <tuple>

UseNameSpace(NBezier);

template<typename T>
class SplitMatricesGenerationTest : public testing::Test
{
public:
    typedef T Scalar;
};

TYPED_TEST_SUITE_P(SplitMatricesGenerationTest);

TYPED_TEST_P(SplitMatricesGenerationTest, Get)
{
    using S = TestFixture::Scalar;

    {
        constexpr auto m = SplitMatrices::get<S, 1>();
        constexpr auto l = boost::qvm::mat<S, 1, 1>{};
        constexpr auto r = boost::qvm::mat<S, 1, 1>{};

        EXPECT_EQ(m.m_left, l);
        EXPECT_EQ(m.m_left, r);
    }

    {
        constexpr auto m = SplitMatrices::get<S, 2>();
        constexpr auto l = boost::qvm::mat<S, 2, 2>{};
        constexpr auto r = boost::qvm::mat<S, 2, 2>{};

        EXPECT_EQ(m.m_left, l);
        EXPECT_EQ(m.m_left, r);
    }

    {
        constexpr auto m = SplitMatrices::get<S, 3>();
        constexpr auto l = boost::qvm::mat<S, 3, 3>{};
        constexpr auto r = boost::qvm::mat<S, 3, 3>{};

        EXPECT_EQ(m.m_left, l);
        EXPECT_EQ(m.m_left, r);
    }

    {
        constexpr auto m = SplitMatrices::get<S, 4>();
        constexpr auto l = boost::qvm::mat<S, 4, 4>{};
        constexpr auto r = boost::qvm::mat<S, 4, 4>{};

        EXPECT_EQ(m.m_left, l);
        EXPECT_EQ(m.m_left, r);
    }

    {
        constexpr auto m = SplitMatrices::get<S, 5>();
        constexpr auto l = boost::qvm::mat<S, 5, 5>{};
        constexpr auto r = boost::qvm::mat<S, 5, 5>{};

        EXPECT_EQ(m.m_left, l);
        EXPECT_EQ(m.m_left, r);
    }
}

REGISTER_TYPED_TEST_SUITE_P(SplitMatricesGenerationTest, Get);

INSTANTIATE_TYPED_TEST_SUITE_P(SplitMatricesGeneration, SplitMatricesGenerationTest, BezierScalars);