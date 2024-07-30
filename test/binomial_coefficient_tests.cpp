#include "NBezier/polynomial_coefficients.h"

#include "bezier_test_types.h"

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_operations.hpp>

#include <gtest/gtest.h>

#include <concepts>
#include <tuple>

using namespace NBezier;

template<typename T>
class PolynomialCoefficientsTypeTest : public testing::Test
{
public:
    typedef std::tuple_element_t<0, T> Scalar;
    static const int Degree = std::tuple_element_t<1, T>::Value;

    typedef PolynomialCoefficients<Scalar, Degree> PolynomialCoefficientsType;
    typedef PolynomialCoefficients<Scalar, Degree>& PolynomialCoefficientsTypeRef;
};

TYPED_TEST_SUITE_P(PolynomialCoefficientsTypeTest);

TYPED_TEST_P(PolynomialCoefficientsTypeTest, Requirements)
{
    ASSERT_TRUE(std::default_initializable<TestFixture::PolynomialCoefficientsType>);
    ASSERT_TRUE(std::copy_constructible<TestFixture::PolynomialCoefficientsType>);
    ASSERT_TRUE(std::move_constructible<TestFixture::PolynomialCoefficientsType>);
    ASSERT_TRUE((std::assignable_from<TestFixture::PolynomialCoefficientsTypeRef, TestFixture::PolynomialCoefficientsType>));
    ASSERT_TRUE(std::equality_comparable<TestFixture::PolynomialCoefficientsType>);
}

REGISTER_TYPED_TEST_SUITE_P(PolynomialCoefficientsTypeTest, Requirements);

INSTANTIATE_TYPED_TEST_SUITE_P(PolynomialCoefficientsRequirements, PolynomialCoefficientsTypeTest, PolynomialCoefficientsScalarDegree);

TEST(PolynomialCoefficientsGeneration, GetVector)
{
    {
        constexpr auto c0 = PolynomialCoefficients<float, 0>::get<0>();

        constexpr auto ex_c0 = boost::qvm::vec<float, 1>{1};

        EXPECT_EQ(c0, ex_c0);
    }

    {
        constexpr auto c0 = PolynomialCoefficients<float, 1>::get<0>();
        constexpr auto c1 = PolynomialCoefficients<float, 1>::get<1>();

        constexpr auto ex_c0 = boost::qvm::vec<float, 2>{1, 1};
        constexpr auto ex_c1 = boost::qvm::vec<float, 2>{1, 0};

        EXPECT_EQ(c0, ex_c0);
        EXPECT_EQ(c1, ex_c1);
    }

    {
        constexpr auto c0 = PolynomialCoefficients<float, 2>::get<0>();
        constexpr auto c1 = PolynomialCoefficients<float, 2>::get<1>();
        constexpr auto c2 = PolynomialCoefficients<float, 2>::get<2>();

        constexpr auto ex_c0 = boost::qvm::vec<float, 3>{1, 1, 1};
        constexpr auto ex_c1 = boost::qvm::vec<float, 3>{2, 1, 0};
        constexpr auto ex_c2 = boost::qvm::vec<float, 3>{2, 0, 0};

        EXPECT_EQ(c0, ex_c0);
        EXPECT_EQ(c1, ex_c1);
        EXPECT_EQ(c2, ex_c2);
    }

    {
        constexpr auto c0 = PolynomialCoefficients<float, 3>::get<0>();
        constexpr auto c1 = PolynomialCoefficients<float, 3>::get<1>();
        constexpr auto c2 = PolynomialCoefficients<float, 3>::get<2>();
        constexpr auto c3 = PolynomialCoefficients<float, 3>::get<3>();

        constexpr auto ex_c0 = boost::qvm::vec<float, 4>{1, 1, 1, 1};
        constexpr auto ex_c1 = boost::qvm::vec<float, 4>{3, 2, 1, 0};
        constexpr auto ex_c2 = boost::qvm::vec<float, 4>{6, 2, 0, 0};
        constexpr auto ex_c3 = boost::qvm::vec<float, 4>{6, 0, 0, 0};

        EXPECT_EQ(c0, ex_c0);
        EXPECT_EQ(c1, ex_c1);
        EXPECT_EQ(c2, ex_c2);
        EXPECT_EQ(c3, ex_c3);
    }

    {
        constexpr auto c0 = PolynomialCoefficients<float, 4>::get<0>();
        constexpr auto c1 = PolynomialCoefficients<float, 4>::get<1>();
        constexpr auto c2 = PolynomialCoefficients<float, 4>::get<2>();
        constexpr auto c3 = PolynomialCoefficients<float, 4>::get<3>();
        constexpr auto c4 = PolynomialCoefficients<float, 4>::get<4>();

        constexpr auto ex_c0 = boost::qvm::vec<float, 5>{1, 1, 1, 1, 1};
        constexpr auto ex_c1 = boost::qvm::vec<float, 5>{4, 3, 2, 1, 0};
        constexpr auto ex_c2 = boost::qvm::vec<float, 5>{12, 6, 2, 0, 0};
        constexpr auto ex_c3 = boost::qvm::vec<float, 5>{24, 6, 0, 0, 0};
        constexpr auto ex_c4 = boost::qvm::vec<float, 5>{24, 0, 0, 0, 0};

        EXPECT_EQ(c0, ex_c0);
        EXPECT_EQ(c1, ex_c1);
        EXPECT_EQ(c2, ex_c2);
        EXPECT_EQ(c3, ex_c3);
    }

    {
        constexpr auto c0 = PolynomialCoefficients<float, 5>::get<0>();
        constexpr auto c1 = PolynomialCoefficients<float, 5>::get<1>();
        constexpr auto c2 = PolynomialCoefficients<float, 5>::get<2>();
        constexpr auto c3 = PolynomialCoefficients<float, 5>::get<3>();
        constexpr auto c4 = PolynomialCoefficients<float, 5>::get<4>();
        constexpr auto c5 = PolynomialCoefficients<float, 5>::get<5>();

        constexpr auto ex_c0 = boost::qvm::vec<float, 6>{1, 1, 1, 1, 1, 1};
        constexpr auto ex_c1 = boost::qvm::vec<float, 6>{5, 4, 3, 2, 1, 0};
        constexpr auto ex_c2 = boost::qvm::vec<float, 6>{20, 12, 6, 2, 0, 0};
        constexpr auto ex_c3 = boost::qvm::vec<float, 6>{60, 24, 6, 0, 0, 0};
        constexpr auto ex_c4 = boost::qvm::vec<float, 6>{120, 24, 0, 0, 0, 0};
        constexpr auto ex_c5 = boost::qvm::vec<float, 6>{120, 0, 0, 0, 0, 0};

        EXPECT_EQ(c0, ex_c0);
        EXPECT_EQ(c1, ex_c1);
        EXPECT_EQ(c2, ex_c2);
        EXPECT_EQ(c3, ex_c3);
    }
}