#include "NBezier/polynomial_evaluation.h"

#include <gtest/gtest.h>

using namespace NBezier;

TEST(Bla, Bla)
{
    constexpr boost::qvm::mat<float, 2, 2> p = {};
    constexpr auto v = PolynomialEvaluation::eval<0>(p, 0.0f);
}