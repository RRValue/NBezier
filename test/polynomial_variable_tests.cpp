#include "NBezier/polynomial_variable.h"

#include "bezier_test_types.h"

#include <gtest/gtest.h>

using namespace NBezier;

template<typename T>
class PolynomialVariableTypeTest : public testing::Test
{
public:
    typedef std::tuple_element_t<0, T> Scalar;
    static const int Degree = std::tuple_element_t<1, T>::Value;

    typedef PolynomialVariable<Scalar, Degree> PolynomialVariableType;
    typedef PolynomialVariable<Scalar, Degree>& PolynomialVariableTypeRef;
};

TYPED_TEST_SUITE_P(PolynomialVariableTypeTest);

TYPED_TEST_P(PolynomialVariableTypeTest, Requirements)
{
    ASSERT_TRUE(std::default_initializable<TestFixture::PolynomialVariableType>);
    ASSERT_TRUE(std::copy_constructible<TestFixture::PolynomialVariableType>);
    ASSERT_TRUE(std::move_constructible<TestFixture::PolynomialVariableType>);
    ASSERT_TRUE((std::assignable_from<TestFixture::PolynomialVariableTypeRef, TestFixture::PolynomialVariableType>));
    ASSERT_TRUE(std::equality_comparable<TestFixture::PolynomialVariableType>);
}

REGISTER_TYPED_TEST_SUITE_P(PolynomialVariableTypeTest, Requirements);

INSTANTIATE_TYPED_TEST_SUITE_P(PolynomialVariableRequirements, PolynomialVariableTypeTest, PolynomialVariableScalarDegree);

template<typename T>
class PolynomialVariableGetTest : public testing::Test
{
public:
    typedef T Scalar;

    using PolynomialVariable0 = PolynomialVariable<Scalar, 0>;
    using PolynomialVariable1 = PolynomialVariable<Scalar, 1>;
    using PolynomialVariable2 = PolynomialVariable<Scalar, 2>;
    using PolynomialVariable3 = PolynomialVariable<Scalar, 3>;
    using PolynomialVariable4 = PolynomialVariable<Scalar, 4>;
    using PolynomialVariable5 = PolynomialVariable<Scalar, 5>;
};

TYPED_TEST_SUITE_P(PolynomialVariableGetTest);

TYPED_TEST_P(PolynomialVariableGetTest, GetVector)
{
    typedef TestFixture::Scalar Scalar;

    const auto fill_exp_variable = [](auto& vec, const size_t& degree, const size_t& derivative, const auto& variable) {
        for (size_t i = 0; i < degree + 1; i++)
            if(derivative + i <= degree)
                boost::qvm::write_vec_element_idx(i, vec, std::pow(variable, degree - derivative - i));
    };

    constexpr auto variable = Scalar(2);

    {
        constexpr auto v0 = TestFixture::PolynomialVariable0::variableVector<0>(variable);
        auto ex_v0 = boost::qvm::vec<Scalar, 1>{1};

        fill_exp_variable(ex_v0, 0, 0, variable);

        EXPECT_EQ(v0, ex_v0);
    }

    {
        constexpr auto v0 = TestFixture::PolynomialVariable1::variableVector<0>(variable);
        constexpr auto v1 = TestFixture::PolynomialVariable1::variableVector<1>(variable);
        
        auto ex_v0 = boost::qvm::vec<Scalar, 2>{};
        auto ex_v1 = boost::qvm::vec<Scalar, 2>{};

        fill_exp_variable(ex_v0, 1, 0, variable);
        fill_exp_variable(ex_v1, 1, 1, variable);

        EXPECT_EQ(v0, ex_v0);
        EXPECT_EQ(v1, ex_v1);
    }

    {
        constexpr auto v0 = TestFixture::PolynomialVariable2::variableVector<0>(variable);
        constexpr auto v1 = TestFixture::PolynomialVariable2::variableVector<1>(variable);
        constexpr auto v2 = TestFixture::PolynomialVariable2::variableVector<2>(variable);

        auto ex_v0 = boost::qvm::vec<Scalar, 3>{};
        auto ex_v1 = boost::qvm::vec<Scalar, 3>{};
        auto ex_v2 = boost::qvm::vec<Scalar, 3>{};

        fill_exp_variable(ex_v0, 2, 0, variable);
        fill_exp_variable(ex_v1, 2, 1, variable);
        fill_exp_variable(ex_v2, 2, 2, variable);

        EXPECT_EQ(v0, ex_v0);
        EXPECT_EQ(v1, ex_v1);
        EXPECT_EQ(v2, ex_v2);
    }

    {
        constexpr auto v0 = TestFixture::PolynomialVariable3::variableVector<0>(variable);
        constexpr auto v1 = TestFixture::PolynomialVariable3::variableVector<1>(variable);
        constexpr auto v2 = TestFixture::PolynomialVariable3::variableVector<2>(variable);
        constexpr auto v3 = TestFixture::PolynomialVariable3::variableVector<3>(variable);

        auto ex_v0 = boost::qvm::vec<Scalar, 4>{};
        auto ex_v1 = boost::qvm::vec<Scalar, 4>{};
        auto ex_v2 = boost::qvm::vec<Scalar, 4>{};
        auto ex_v3 = boost::qvm::vec<Scalar, 4>{};

        fill_exp_variable(ex_v0, 3, 0, variable);
        fill_exp_variable(ex_v1, 3, 1, variable);
        fill_exp_variable(ex_v2, 3, 2, variable);
        fill_exp_variable(ex_v3, 3, 3, variable);

        EXPECT_EQ(v0, ex_v0);
        EXPECT_EQ(v1, ex_v1);
        EXPECT_EQ(v2, ex_v2);
        EXPECT_EQ(v3, ex_v3);
    }

    {
        constexpr auto v0 = TestFixture::PolynomialVariable4::variableVector<0>(variable);
        constexpr auto v1 = TestFixture::PolynomialVariable4::variableVector<1>(variable);
        constexpr auto v2 = TestFixture::PolynomialVariable4::variableVector<2>(variable);
        constexpr auto v3 = TestFixture::PolynomialVariable4::variableVector<3>(variable);
        constexpr auto v4 = TestFixture::PolynomialVariable4::variableVector<4>(variable);

        auto ex_v0 = boost::qvm::vec<Scalar, 5>{};
        auto ex_v1 = boost::qvm::vec<Scalar, 5>{};
        auto ex_v2 = boost::qvm::vec<Scalar, 5>{};
        auto ex_v3 = boost::qvm::vec<Scalar, 5>{};
        auto ex_v4 = boost::qvm::vec<Scalar, 5>{};

        fill_exp_variable(ex_v0, 4, 0, variable);
        fill_exp_variable(ex_v1, 4, 1, variable);
        fill_exp_variable(ex_v2, 4, 2, variable);
        fill_exp_variable(ex_v3, 4, 3, variable);
        fill_exp_variable(ex_v4, 4, 4, variable);

        EXPECT_EQ(v0, ex_v0);
        EXPECT_EQ(v1, ex_v1);
        EXPECT_EQ(v2, ex_v2);
        EXPECT_EQ(v3, ex_v3);
        EXPECT_EQ(v4, ex_v4);
    }

    {
        constexpr auto v0 = TestFixture::PolynomialVariable5::variableVector<0>(variable);
        constexpr auto v1 = TestFixture::PolynomialVariable5::variableVector<1>(variable);
        constexpr auto v2 = TestFixture::PolynomialVariable5::variableVector<2>(variable);
        constexpr auto v3 = TestFixture::PolynomialVariable5::variableVector<3>(variable);
        constexpr auto v4 = TestFixture::PolynomialVariable5::variableVector<4>(variable);
        constexpr auto v5 = TestFixture::PolynomialVariable5::variableVector<5>(variable);

        auto ex_v0 = boost::qvm::vec<Scalar, 6>{};
        auto ex_v1 = boost::qvm::vec<Scalar, 6>{};
        auto ex_v2 = boost::qvm::vec<Scalar, 6>{};
        auto ex_v3 = boost::qvm::vec<Scalar, 6>{};
        auto ex_v4 = boost::qvm::vec<Scalar, 6>{};
        auto ex_v5 = boost::qvm::vec<Scalar, 6>{};

        fill_exp_variable(ex_v0, 5, 0, variable);
        fill_exp_variable(ex_v1, 5, 1, variable);
        fill_exp_variable(ex_v2, 5, 2, variable);
        fill_exp_variable(ex_v3, 5, 3, variable);
        fill_exp_variable(ex_v4, 5, 4, variable);
        fill_exp_variable(ex_v5, 5, 5, variable);

        EXPECT_EQ(v0, ex_v0);
        EXPECT_EQ(v1, ex_v1);
        EXPECT_EQ(v2, ex_v2);
        EXPECT_EQ(v3, ex_v3);
        EXPECT_EQ(v4, ex_v4);
        EXPECT_EQ(v5, ex_v5);
    }
}

REGISTER_TYPED_TEST_SUITE_P(PolynomialVariableGetTest, GetVector);

INSTANTIATE_TYPED_TEST_SUITE_P(PolynomialVariableGeneration, PolynomialVariableGetTest, PolynomialVariableScalars);