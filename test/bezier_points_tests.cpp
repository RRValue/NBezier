#include "NBezier/bezier_points.h"

#include "bezier_test_types.h"

#include <gtest/gtest.h>

#include <concepts>
#include <tuple>

UseNameSpace(NBezier);

template<typename T>
class BezierTest : public testing::Test
{
public:
    typedef std::tuple_element_t<0, T> Scalar;
    static const int Dimension = std::tuple_element_t<1, T>::Value;
    static const int Degree = std::tuple_element_t<2, T>::Value;

    typedef BezierPoints<Scalar, Dimension, Degree> BezierPointsType;
    typedef BezierPoints<Scalar, Dimension, Degree>& BezierPointsTypeRef;
};

TYPED_TEST_SUITE_P(BezierTest);

TYPED_TEST_P(BezierTest, Requirements)
{
    ASSERT_TRUE(std::default_initializable<TestFixture::BezierPointsType>);
    ASSERT_TRUE(std::copy_constructible<TestFixture::BezierPointsType>);
    ASSERT_TRUE(std::move_constructible<TestFixture::BezierPointsType>);
    ASSERT_TRUE((std::assignable_from<TestFixture::BezierPointsTypeRef, TestFixture::BezierPointsType>));
    ASSERT_TRUE(std::equality_comparable<TestFixture::BezierPointsType>);
}

REGISTER_TYPED_TEST_SUITE_P(BezierTest, Requirements);

INSTANTIATE_TYPED_TEST_SUITE_P(BezierTestRequirements, BezierTest, BezierTestTypes);
