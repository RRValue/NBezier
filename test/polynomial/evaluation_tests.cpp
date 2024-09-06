#include "../bezier_test_types.h"
#include "NBezier/defines.h"
#include "NBezier/polynomial/evaluation.h"

#include <gtest/gtest.h>

#include <boost/qvm/vec_access.hpp>

UseNameSpace(NBezier);
UseNameSpace(NBezier::Polynomial);

ClangDisableWarning(-Wmissing - braces);

template<typename T>
class EvaluationTest : public testing::Test
{
public:
    typedef T Scalar;
};

TYPED_TEST_SUITE_P(EvaluationTest);

TYPED_TEST_P(EvaluationTest, Eval)
{
    typedef typename TestFixture::Scalar Scalar;

    {
        constexpr auto p0 = boost::qvm::vec<Scalar, 1>{2};
        constexpr auto p1 = boost::qvm::vec<Scalar, 1>{7};
        constexpr auto p2 = boost::qvm::vec<Scalar, 1>{17};

        //                                  p0        p1        p2
        constexpr Points<Scalar, 1, 3> p = {A<0>(p0), A<0>(p1), A<0>(p2)};

        constexpr auto x = Scalar(0.5);
        constexpr auto derivative_0 = Evaluation::eval<0>(p, x);
        constexpr auto derivative_1 = Evaluation::eval<1>(p, x);
        constexpr auto derivative_2 = Evaluation::eval<2>(p, x);

        auto ex_derivative_0 = p0 * Scalar(1) * std::pow(x, 2) +  //
                               p1 * Scalar(1) * std::pow(x, 1) +  //
                               p2 * Scalar(1) * std::pow(x, 0);
        auto ex_derivative_1 = p0 * Scalar(2) * std::pow(x, 1) +  //
                               p1 * Scalar(1) * std::pow(x, 0);
        auto ex_derivative_2 = p0 * Scalar(2) * std::pow(x, 0);

        EXPECT_EQ(derivative_0, ex_derivative_0);
        EXPECT_EQ(derivative_1, ex_derivative_1);
        EXPECT_EQ(derivative_2, ex_derivative_2);
    }

    {
        constexpr auto p0 = boost::qvm::vec<Scalar, 2>{2, 3};
        constexpr auto p1 = boost::qvm::vec<Scalar, 2>{7, 11};
        constexpr auto p2 = boost::qvm::vec<Scalar, 2>{17, 19};

        //                                  p0        p1        p2
        constexpr Points<Scalar, 2, 3> p = {A<0>(p0), A<0>(p1), A<0>(p2),  //
                                            A<1>(p0), A<1>(p1), A<1>(p2)};

        constexpr auto x = Scalar(0.5);
        constexpr auto derivative_0 = Evaluation::eval<0>(p, x);
        constexpr auto derivative_1 = Evaluation::eval<1>(p, x);
        constexpr auto derivative_2 = Evaluation::eval<2>(p, x);

        auto ex_derivative_0 = p0 * Scalar(1) * std::pow(x, 2) +  //
                               p1 * Scalar(1) * std::pow(x, 1) +  //
                               p2 * Scalar(1) * std::pow(x, 0);
        auto ex_derivative_1 = p0 * Scalar(2) * std::pow(x, 1) +  //
                               p1 * Scalar(1) * std::pow(x, 0);
        auto ex_derivative_2 = p0 * Scalar(2) * std::pow(x, 0);

        EXPECT_EQ(derivative_0, ex_derivative_0);
        EXPECT_EQ(derivative_1, ex_derivative_1);
        EXPECT_EQ(derivative_2, ex_derivative_2);
    }

    {
        constexpr auto p0 = boost::qvm::vec<Scalar, 3>{2, 3, 5};
        constexpr auto p1 = boost::qvm::vec<Scalar, 3>{7, 11, 13};
        constexpr auto p2 = boost::qvm::vec<Scalar, 3>{17, 19, 23};

        //                                  p0        p1        p2
        constexpr Points<Scalar, 3, 3> p = {A<0>(p0), A<0>(p1), A<0>(p2),  //
                                            A<1>(p0), A<1>(p1), A<1>(p2),  //
                                            A<2>(p0), A<2>(p1), A<2>(p2)};

        constexpr auto x = Scalar(0.5);
        constexpr auto derivative_0 = Evaluation::eval<0>(p, x);
        constexpr auto derivative_1 = Evaluation::eval<1>(p, x);
        constexpr auto derivative_2 = Evaluation::eval<2>(p, x);

        auto ex_derivative_0 = p0 * Scalar(1) * std::pow(x, 2) +  //
                               p1 * Scalar(1) * std::pow(x, 1) +  //
                               p2 * Scalar(1) * std::pow(x, 0);
        auto ex_derivative_1 = p0 * Scalar(2) * std::pow(x, 1) +  //
                               p1 * Scalar(1) * std::pow(x, 0);
        auto ex_derivative_2 = p0 * Scalar(2) * std::pow(x, 0);

        EXPECT_EQ(derivative_0, ex_derivative_0);
        EXPECT_EQ(derivative_1, ex_derivative_1);
        EXPECT_EQ(derivative_2, ex_derivative_2);
    }
}

REGISTER_TYPED_TEST_SUITE_P(EvaluationTest, Eval);

INSTANTIATE_TYPED_TEST_SUITE_P(EvaluationTestEval, EvaluationTest, BezierScalars);

ClangEnableWarning();