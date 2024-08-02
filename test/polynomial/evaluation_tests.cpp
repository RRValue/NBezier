#include "NBezier/polynomial/evaluation.h"

#include <gtest/gtest.h>

using namespace NBezier::Polynomial;

TEST(Bla, Bla)
{
    constexpr boost::qvm::mat<float, 3, 3> p = {};
    constexpr auto v = Evaluation::eval<0>(p, 0.5f);

    int ii = 0;
    ii++;
}