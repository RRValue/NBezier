#include "NBezier/linear_bezier.h"

#include <gtest/gtest.h>

#include <concepts>

using namespace NBezier;

// clang-format off
struct One{static const int Value = 1;};
struct Two{static const int Value = 2;};
struct Three{static const int Value = 3;};
struct Four{static const int Value = 4;};
// clang-format on

template<typename T>
class LinearBezierTest : public testing::Test
{
public:
    typedef T typename TypeContainer;
};

TYPED_TEST_SUITE_P(LinearBezierTest);

TYPED_TEST_P(LinearBezierTest, Requirements)
{
    typedef TypeParam::first_type Scalar;
    static const int Dimension = TypeParam::second_type::Value;

    typedef LinearBezier<Scalar, Dimension> LinearBezierType;

    ASSERT_TRUE((std::default_initializable<LinearBezierType>));
    ASSERT_TRUE((std::copy_constructible<LinearBezierType>));
    ASSERT_TRUE((std::move_constructible<LinearBezierType>));
    ASSERT_TRUE((std::assignable_from<LinearBezierType&, LinearBezierType>));
    ASSERT_TRUE((std::equality_comparable<LinearBezierType>));
}

REGISTER_TYPED_TEST_SUITE_P(LinearBezierTest, Requirements);

using LinearBezierTypes = ::testing::Types<std::pair<float, One>,          //
                                           std::pair<float, Two>,          //
                                           std::pair<float, Three>,        //
                                           std::pair<float, Four>,         //
                                           std::pair<double, One>,         //
                                           std::pair<double, Two>,         //
                                           std::pair<double, Three>,       //
                                           std::pair<double, Four>,        //
                                           std::pair<long double, One>,    //
                                           std::pair<long double, Two>,    //
                                           std::pair<long double, Three>,  //
                                           std::pair<long double, Four>>;

INSTANTIATE_TYPED_TEST_SUITE_P(LinearBezier, LinearBezierTest, LinearBezierTypes);
