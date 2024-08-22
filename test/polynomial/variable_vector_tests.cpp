#include "NBezier/polynomial/variable_vector.h"

#include "polynomial_test_types.h"

#include <gtest/gtest.h>

UseNameSpace(NBezier::Polynomial);

template<typename T>
class VariableVectorGetTest : public testing::Test
{
public:
    typedef T Scalar;

    using VariableVector0 = VariableVector<Scalar, 0>;
    using VariableVector1 = VariableVector<Scalar, 1>;
    using VariableVector2 = VariableVector<Scalar, 2>;
    using VariableVector3 = VariableVector<Scalar, 3>;
    using VariableVector4 = VariableVector<Scalar, 4>;
    using VariableVector5 = VariableVector<Scalar, 5>;
};

TYPED_TEST_SUITE_P(VariableVectorGetTest);

TYPED_TEST_P(VariableVectorGetTest, Get)
{
    typedef TestFixture::Scalar Scalar;

    const auto fill_exp_variable = [](auto& vec, const size_t& degree, const size_t& derivative, const auto& variable) {
        for(size_t i = 0; i < degree + 1; i++)
            if(derivative + i <= degree)
                boost::qvm::write_vec_element_idx(i, vec, std::pow(variable, degree - derivative - i));
    };

    constexpr auto variable = Scalar(2);

    {
        constexpr auto v0 = TestFixture::VariableVector0::get<0>(variable);
        auto ex_v0 = boost::qvm::vec<Scalar, 1>{1};

        fill_exp_variable(ex_v0, 0, 0, variable);

        EXPECT_EQ(v0, ex_v0);
    }

    {
        constexpr auto v0 = TestFixture::VariableVector1::get<0>(variable);
        constexpr auto v1 = TestFixture::VariableVector1::get<1>(variable);

        auto ex_v0 = boost::qvm::vec<Scalar, 2>{};
        auto ex_v1 = boost::qvm::vec<Scalar, 2>{};

        fill_exp_variable(ex_v0, 1, 0, variable);
        fill_exp_variable(ex_v1, 1, 1, variable);

        EXPECT_EQ(v0, ex_v0);
        EXPECT_EQ(v1, ex_v1);
    }

    {
        constexpr auto v0 = TestFixture::VariableVector2::get<0>(variable);
        constexpr auto v1 = TestFixture::VariableVector2::get<1>(variable);
        constexpr auto v2 = TestFixture::VariableVector2::get<2>(variable);

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
        constexpr auto v0 = TestFixture::VariableVector3::get<0>(variable);
        constexpr auto v1 = TestFixture::VariableVector3::get<1>(variable);
        constexpr auto v2 = TestFixture::VariableVector3::get<2>(variable);
        constexpr auto v3 = TestFixture::VariableVector3::get<3>(variable);

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
        constexpr auto v0 = TestFixture::VariableVector4::get<0>(variable);
        constexpr auto v1 = TestFixture::VariableVector4::get<1>(variable);
        constexpr auto v2 = TestFixture::VariableVector4::get<2>(variable);
        constexpr auto v3 = TestFixture::VariableVector4::get<3>(variable);
        constexpr auto v4 = TestFixture::VariableVector4::get<4>(variable);

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
        constexpr auto v0 = TestFixture::VariableVector5::get<0>(variable);
        constexpr auto v1 = TestFixture::VariableVector5::get<1>(variable);
        constexpr auto v2 = TestFixture::VariableVector5::get<2>(variable);
        constexpr auto v3 = TestFixture::VariableVector5::get<3>(variable);
        constexpr auto v4 = TestFixture::VariableVector5::get<4>(variable);
        constexpr auto v5 = TestFixture::VariableVector5::get<5>(variable);

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

REGISTER_TYPED_TEST_SUITE_P(VariableVectorGetTest, Get);

INSTANTIATE_TYPED_TEST_SUITE_P(VariableVectorGeneration, VariableVectorGetTest, VariableVectorScalars);