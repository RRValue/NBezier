#include "NBezier/polynomial_derivative_factors.h"

#include "bezier_test_types.h"

#include <boost/qvm/map_mat_vec.hpp>
#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_operations.hpp>

#include <gtest/gtest.h>

#include <concepts>
#include <tuple>

using namespace NBezier;

template<typename T>
class PolynomialDerivativeFactorsTypeTest : public testing::Test
{
public:
    typedef std::tuple_element_t<0, T> Scalar;
    static const int Degree = std::tuple_element_t<1, T>::Value;
    static const int Derivative = std::tuple_element_t<2, T>::Value;

    typedef PolynomialDerivativeFactors<Scalar, Degree, Derivative> PolynomialDerivativeFactorsType;
    typedef PolynomialDerivativeFactors<Scalar, Degree, Derivative>& PolynomialDerivativeFactorsTypeRef;
};

TYPED_TEST_SUITE_P(PolynomialDerivativeFactorsTypeTest);

TYPED_TEST_P(PolynomialDerivativeFactorsTypeTest, Requirements)
{
    ASSERT_TRUE(std::default_initializable<TestFixture::PolynomialDerivativeFactorsType>);
    ASSERT_TRUE(std::copy_constructible<TestFixture::PolynomialDerivativeFactorsType>);
    ASSERT_TRUE(std::move_constructible<TestFixture::PolynomialDerivativeFactorsType>);
    ASSERT_TRUE((std::assignable_from<TestFixture::PolynomialDerivativeFactorsTypeRef, TestFixture::PolynomialDerivativeFactorsType>));
    ASSERT_TRUE(std::equality_comparable<TestFixture::PolynomialDerivativeFactorsType>);
}

REGISTER_TYPED_TEST_SUITE_P(PolynomialDerivativeFactorsTypeTest, Requirements);

INSTANTIATE_TYPED_TEST_SUITE_P(PolynomialDerivativeFactorsRequirements, PolynomialDerivativeFactorsTypeTest, PolynomialDerivativeFactorsScalarDegree);

template<typename T>
class PolynomialDerivativeFactorsGetTest : public testing::Test
{
public:
    typedef T Scalar;

    template<size_t Derivative>
    using PolynomialDerivativeFactors0 = PolynomialDerivativeFactors<Scalar, 0, Derivative>;

    template<size_t Derivative>
    using PolynomialDerivativeFactors1 = PolynomialDerivativeFactors<Scalar, 1, Derivative>;

    template<size_t Derivative>
    using PolynomialDerivativeFactors2 = PolynomialDerivativeFactors<Scalar, 2, Derivative>;

    template<size_t Derivative>
    using PolynomialDerivativeFactors3 = PolynomialDerivativeFactors<Scalar, 3, Derivative>;

    template<size_t Derivative>
    using PolynomialDerivativeFactors4 = PolynomialDerivativeFactors<Scalar, 4, Derivative>;

    template<size_t Derivative>
    using PolynomialDerivativeFactors5 = PolynomialDerivativeFactors<Scalar, 5, Derivative>;
};

TYPED_TEST_SUITE_P(PolynomialDerivativeFactorsGetTest);

TYPED_TEST_P(PolynomialDerivativeFactorsGetTest, GetVector)
{
    typedef TestFixture::Scalar Scalar;

    {
        constexpr auto c0 = TestFixture::PolynomialDerivativeFactors0<0>::get();

        constexpr auto ex_c0 = boost::qvm::vec<Scalar, 1>{1};

        EXPECT_EQ(c0, ex_c0);
    }

    {
        constexpr auto c0 = TestFixture::PolynomialDerivativeFactors1<0>::get();
        constexpr auto c1 = TestFixture::PolynomialDerivativeFactors1<1>::get();

        constexpr auto ex_c0 = boost::qvm::vec<Scalar, 2>{1, 1};
        constexpr auto ex_c1 = boost::qvm::vec<Scalar, 2>{1, 0};

        EXPECT_EQ(c0, ex_c0);
        EXPECT_EQ(c1, ex_c1);
    }

    {
        constexpr auto c0 = TestFixture::PolynomialDerivativeFactors2<0>::get();
        constexpr auto c1 = TestFixture::PolynomialDerivativeFactors2<1>::get();
        constexpr auto c2 = TestFixture::PolynomialDerivativeFactors2<2>::get();

        constexpr auto ex_c0 = boost::qvm::vec<Scalar, 3>{1, 1, 1};
        constexpr auto ex_c1 = boost::qvm::vec<Scalar, 3>{2, 1, 0};
        constexpr auto ex_c2 = boost::qvm::vec<Scalar, 3>{2, 0, 0};

        EXPECT_EQ(c0, ex_c0);
        EXPECT_EQ(c1, ex_c1);
        EXPECT_EQ(c2, ex_c2);
    }

    {
        constexpr auto c0 = TestFixture::PolynomialDerivativeFactors3<0>::get();
        constexpr auto c1 = TestFixture::PolynomialDerivativeFactors3<1>::get();
        constexpr auto c2 = TestFixture::PolynomialDerivativeFactors3<2>::get();
        constexpr auto c3 = TestFixture::PolynomialDerivativeFactors3<3>::get();

        constexpr auto ex_c0 = boost::qvm::vec<Scalar, 4>{1, 1, 1, 1};
        constexpr auto ex_c1 = boost::qvm::vec<Scalar, 4>{3, 2, 1, 0};
        constexpr auto ex_c2 = boost::qvm::vec<Scalar, 4>{6, 2, 0, 0};
        constexpr auto ex_c3 = boost::qvm::vec<Scalar, 4>{6, 0, 0, 0};

        EXPECT_EQ(c0, ex_c0);
        EXPECT_EQ(c1, ex_c1);
        EXPECT_EQ(c2, ex_c2);
        EXPECT_EQ(c3, ex_c3);
    }

    {
        constexpr auto c0 = TestFixture::PolynomialDerivativeFactors4<0>::get();
        constexpr auto c1 = TestFixture::PolynomialDerivativeFactors4<1>::get();
        constexpr auto c2 = TestFixture::PolynomialDerivativeFactors4<2>::get();
        constexpr auto c3 = TestFixture::PolynomialDerivativeFactors4<3>::get();
        constexpr auto c4 = TestFixture::PolynomialDerivativeFactors4<4>::get();

        constexpr auto ex_c0 = boost::qvm::vec<Scalar, 5>{1, 1, 1, 1, 1};
        constexpr auto ex_c1 = boost::qvm::vec<Scalar, 5>{4, 3, 2, 1, 0};
        constexpr auto ex_c2 = boost::qvm::vec<Scalar, 5>{12, 6, 2, 0, 0};
        constexpr auto ex_c3 = boost::qvm::vec<Scalar, 5>{24, 6, 0, 0, 0};
        constexpr auto ex_c4 = boost::qvm::vec<Scalar, 5>{24, 0, 0, 0, 0};

        EXPECT_EQ(c0, ex_c0);
        EXPECT_EQ(c1, ex_c1);
        EXPECT_EQ(c2, ex_c2);
        EXPECT_EQ(c3, ex_c3);
        EXPECT_EQ(c4, ex_c4);
    }

    {
        constexpr auto c0 = TestFixture::PolynomialDerivativeFactors5<0>::get();
        constexpr auto c1 = TestFixture::PolynomialDerivativeFactors5<1>::get();
        constexpr auto c2 = TestFixture::PolynomialDerivativeFactors5<2>::get();
        constexpr auto c3 = TestFixture::PolynomialDerivativeFactors5<3>::get();
        constexpr auto c4 = TestFixture::PolynomialDerivativeFactors5<4>::get();
        constexpr auto c5 = TestFixture::PolynomialDerivativeFactors5<5>::get();

        constexpr auto ex_c0 = boost::qvm::vec<Scalar, 6>{1, 1, 1, 1, 1, 1};
        constexpr auto ex_c1 = boost::qvm::vec<Scalar, 6>{5, 4, 3, 2, 1, 0};
        constexpr auto ex_c2 = boost::qvm::vec<Scalar, 6>{20, 12, 6, 2, 0, 0};
        constexpr auto ex_c3 = boost::qvm::vec<Scalar, 6>{60, 24, 6, 0, 0, 0};
        constexpr auto ex_c4 = boost::qvm::vec<Scalar, 6>{120, 24, 0, 0, 0, 0};
        constexpr auto ex_c5 = boost::qvm::vec<Scalar, 6>{120, 0, 0, 0, 0, 0};

        EXPECT_EQ(c0, ex_c0);
        EXPECT_EQ(c1, ex_c1);
        EXPECT_EQ(c2, ex_c2);
        EXPECT_EQ(c3, ex_c3);
        EXPECT_EQ(c4, ex_c4);
        EXPECT_EQ(c5, ex_c5);
    }
}

TYPED_TEST_P(PolynomialDerivativeFactorsGetTest, GetDiagonal)
{
    typedef TestFixture::Scalar Scalar;

    {
        constexpr auto m0 = TestFixture::PolynomialDerivativeFactors0<0>::getDiagonal();

        constexpr auto ex_c0 = boost::qvm::vec<Scalar, 1>{1};

        EXPECT_EQ(boost::qvm::diag(m0), ex_c0);
    }

    {
        constexpr auto m0 = TestFixture::PolynomialDerivativeFactors1<0>::getDiagonal();
        constexpr auto m1 = TestFixture::PolynomialDerivativeFactors1<1>::getDiagonal();

        constexpr auto ex_c0 = boost::qvm::vec<Scalar, 2>{1, 1};
        constexpr auto ex_c1 = boost::qvm::vec<Scalar, 2>{1, 0};

        EXPECT_EQ(boost::qvm::diag(m0), ex_c0);
        EXPECT_EQ(boost::qvm::diag(m1), ex_c1);
    }

    {
        constexpr auto m0 = TestFixture::PolynomialDerivativeFactors2<0>::getDiagonal();
        constexpr auto m1 = TestFixture::PolynomialDerivativeFactors2<1>::getDiagonal();
        constexpr auto m2 = TestFixture::PolynomialDerivativeFactors2<2>::getDiagonal();

        constexpr auto ex_c0 = boost::qvm::vec<Scalar, 3>{1, 1, 1};
        constexpr auto ex_c1 = boost::qvm::vec<Scalar, 3>{2, 1, 0};
        constexpr auto ex_c2 = boost::qvm::vec<Scalar, 3>{2, 0, 0};

        EXPECT_EQ(boost::qvm::diag(m0), ex_c0);
        EXPECT_EQ(boost::qvm::diag(m1), ex_c1);
        EXPECT_EQ(boost::qvm::diag(m2), ex_c2);
    }

    {
        constexpr auto m0 = TestFixture::PolynomialDerivativeFactors3<0>::getDiagonal();
        constexpr auto m1 = TestFixture::PolynomialDerivativeFactors3<1>::getDiagonal();
        constexpr auto m2 = TestFixture::PolynomialDerivativeFactors3<2>::getDiagonal();
        constexpr auto m3 = TestFixture::PolynomialDerivativeFactors3<3>::getDiagonal();

        constexpr auto ex_c0 = boost::qvm::vec<Scalar, 4>{1, 1, 1, 1};
        constexpr auto ex_c1 = boost::qvm::vec<Scalar, 4>{3, 2, 1, 0};
        constexpr auto ex_c2 = boost::qvm::vec<Scalar, 4>{6, 2, 0, 0};
        constexpr auto ex_c3 = boost::qvm::vec<Scalar, 4>{6, 0, 0, 0};

        EXPECT_EQ(boost::qvm::diag(m0), ex_c0);
        EXPECT_EQ(boost::qvm::diag(m1), ex_c1);
        EXPECT_EQ(boost::qvm::diag(m2), ex_c2);
        EXPECT_EQ(boost::qvm::diag(m3), ex_c3);
    }

    {
        constexpr auto m0 = TestFixture::PolynomialDerivativeFactors4<0>::getDiagonal();
        constexpr auto m1 = TestFixture::PolynomialDerivativeFactors4<1>::getDiagonal();
        constexpr auto m2 = TestFixture::PolynomialDerivativeFactors4<2>::getDiagonal();
        constexpr auto m3 = TestFixture::PolynomialDerivativeFactors4<3>::getDiagonal();
        constexpr auto m4 = TestFixture::PolynomialDerivativeFactors4<4>::getDiagonal();

        constexpr auto ex_c0 = boost::qvm::vec<Scalar, 5>{1, 1, 1, 1, 1};
        constexpr auto ex_c1 = boost::qvm::vec<Scalar, 5>{4, 3, 2, 1, 0};
        constexpr auto ex_c2 = boost::qvm::vec<Scalar, 5>{12, 6, 2, 0, 0};
        constexpr auto ex_c3 = boost::qvm::vec<Scalar, 5>{24, 6, 0, 0, 0};
        constexpr auto ex_c4 = boost::qvm::vec<Scalar, 5>{24, 0, 0, 0, 0};

        EXPECT_EQ(boost::qvm::diag(m0), ex_c0);
        EXPECT_EQ(boost::qvm::diag(m1), ex_c1);
        EXPECT_EQ(boost::qvm::diag(m2), ex_c2);
        EXPECT_EQ(boost::qvm::diag(m3), ex_c3);
        EXPECT_EQ(boost::qvm::diag(m4), ex_c4);
    }

    {
        constexpr auto m0 = TestFixture::PolynomialDerivativeFactors5<0>::getDiagonal();
        constexpr auto m1 = TestFixture::PolynomialDerivativeFactors5<1>::getDiagonal();
        constexpr auto m2 = TestFixture::PolynomialDerivativeFactors5<2>::getDiagonal();
        constexpr auto m3 = TestFixture::PolynomialDerivativeFactors5<3>::getDiagonal();
        constexpr auto m4 = TestFixture::PolynomialDerivativeFactors5<4>::getDiagonal();
        constexpr auto m5 = TestFixture::PolynomialDerivativeFactors5<5>::getDiagonal();

        constexpr auto ex_c0 = boost::qvm::vec<Scalar, 6>{1, 1, 1, 1, 1, 1};
        constexpr auto ex_c1 = boost::qvm::vec<Scalar, 6>{5, 4, 3, 2, 1, 0};
        constexpr auto ex_c2 = boost::qvm::vec<Scalar, 6>{20, 12, 6, 2, 0, 0};
        constexpr auto ex_c3 = boost::qvm::vec<Scalar, 6>{60, 24, 6, 0, 0, 0};
        constexpr auto ex_c4 = boost::qvm::vec<Scalar, 6>{120, 24, 0, 0, 0, 0};
        constexpr auto ex_c5 = boost::qvm::vec<Scalar, 6>{120, 0, 0, 0, 0, 0};

        EXPECT_EQ(boost::qvm::diag(m0), ex_c0);
        EXPECT_EQ(boost::qvm::diag(m1), ex_c1);
        EXPECT_EQ(boost::qvm::diag(m2), ex_c2);
        EXPECT_EQ(boost::qvm::diag(m3), ex_c3);
        EXPECT_EQ(boost::qvm::diag(m4), ex_c4);
        EXPECT_EQ(boost::qvm::diag(m5), ex_c5);
    }
}

REGISTER_TYPED_TEST_SUITE_P(PolynomialDerivativeFactorsGetTest,  //
                            GetVector,                           //
                            GetDiagonal);

INSTANTIATE_TYPED_TEST_SUITE_P(PolynomialDerivativeFactorsGeneration, PolynomialDerivativeFactorsGetTest, PolynomialDerivativeFactorsScalars);