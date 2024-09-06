#include "NBezier/split_matrices.h"

#include "bezier_test_types.h"

#include <gtest/gtest.h>

#include <boost/qvm/mat_operations.hpp>

#include <concepts>
#include <tuple>

ClangDisableWarning(-Wmissing - braces);

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
        // clang-format off
        constexpr auto m = SplitMatrices::get<S, 1>(S(3));
        constexpr auto l = boost::qvm::mat<S, 1, 1>{1};
        constexpr auto r = boost::qvm::mat<S, 1, 1>{1};
        // clang-format on

        EXPECT_EQ(m.m_left, l);
        EXPECT_EQ(m.m_right, r);
    }

    {
        // clang-format off
        constexpr auto m = SplitMatrices::get<S, 2>(S(3));
        constexpr auto l = boost::qvm::mat<S, 2, 2>{1, 1 * -2, //
                                                    0, 1 *  3};
        constexpr auto r = boost::qvm::mat<S, 2, 2>{1 * -2, 0,  //
                                                    1 *  3, 1};
        // clang-format on

        EXPECT_EQ(m.m_left, l);
        EXPECT_EQ(m.m_right, r);
    }

    {
        // clang-format off
        constexpr auto m = SplitMatrices::get<S, 3>(S(3));
        constexpr auto l = boost::qvm::mat<S, 3, 3>{1, 1 * -2, 1 * -2 * -2, //
                                                    0, 1 *  3, 2 * -2 *  3, //
                                                    0, 0     , 1 *  3 *  3};
        constexpr auto r = boost::qvm::mat<S, 3, 3>{1 * -2 * -2, 0     , 0,  //
                                                    2 * -2 * 3 , 1 * -2, 0,  //
                                                    1 *  3 * 3 , 1 *  3, 1};
        // clang-format on

        EXPECT_EQ(m.m_left, l);
        EXPECT_EQ(m.m_right, r);
    }

    {
        // clang-format off
        constexpr auto m = SplitMatrices::get<S, 4>(S(3));
        constexpr auto l = boost::qvm::mat<S, 4, 4>{1, 1 * -2, 1 * -2 * -2, 1 * -2 * -2 * -2, //
                                                    0, 1 *  3, 2 * -2 *  3, 3 * -2 * -2 *  3, //
                                                    0, 0     , 1 *  3 *  3, 3 * -2 *  3 *  3, //
                                                    0, 0     , 0          , 1 *  3 *  3 *  3};
        constexpr auto r = boost::qvm::mat<S, 4, 4>{1 * -2 * -2 * -2, 0          , 0     , 0,  //
                                                    3 * -2 * -2 *  3, 1 * -2 * -2, 0     , 0,  //
                                                    3 * -2 *  3 *  3, 2 * -2 * 3 , 1 * -2, 0,  //
                                                    1 *  3 *  3 *  3, 1 *  3 * 3 , 1 *  3, 1};
        // clang-format on

        EXPECT_EQ(m.m_left, l);
        EXPECT_EQ(m.m_right, r);
    }

    {
        // clang-format off
        constexpr auto m = SplitMatrices::get<S, 5>(S(3));
        constexpr auto l = boost::qvm::mat<S, 5, 5>{1, 1 * -2, 1 * -2 * -2, 1 * -2 * -2 * -2, 1 * -2 * -2 * -2 * -2, //
                                                    0, 1 *  3, 2 * -2 *  3, 3 * -2 * -2 *  3, 4 * -2 * -2 * -2 *  3, //
                                                    0, 0     , 1 *  3 *  3, 3 * -2 *  3 *  3, 6 * -2 * -2 *  3 *  3, //
                                                    0, 0     , 0          , 1 *  3 *  3 *  3, 4 * -2 *  3 *  3 *  3, //
                                                    0, 0     , 0          , 0               , 1 *  3 *  3 *  3 *  3};
        constexpr auto r = boost::qvm::mat<S, 5, 5>{1 * -2 * -2 * -2 * -2, 0               , 0          , 0     , 0,  //
                                                    4 * -2 * -2 * -2 *  3, 1 * -2 * -2 * -2, 0          , 0     , 0,  //
                                                    6 * -2 * -2 *  3 *  3, 3 * -2 * -2 *  3, 1 * -2 * -2, 0     , 0,  //
                                                    4 * -2 *  3 *  3 *  3, 3 * -2 *  3 *  3, 2 * -2 * 3 , 1 * -2, 0,  //
                                                    1 *  3 *  3 *  3 *  3, 1 *  3 *  3 *  3, 1 *  3 * 3 , 1 *  3, 1};
        // clang-format on

        EXPECT_EQ(m.m_left, l);
        EXPECT_EQ(m.m_right, r);
    }
}

REGISTER_TYPED_TEST_SUITE_P(SplitMatricesGenerationTest, Get);

INSTANTIATE_TYPED_TEST_SUITE_P(SplitMatricesGeneration, SplitMatricesGenerationTest, BezierScalars);

ClangEnableWarning();