#pragma once

#include "NBezier/defines.h"

#include "NBezier/bezier_points.h"
#include "NBezier/bezier_requirements.h"
#include "NBezier/polynomial/evaluation.h"

#include <boost/math/ccmath/sqrt.hpp>
#include <boost/qvm/mat_operations.hpp>
#include <boost/qvm/vec_operations.hpp>

#include <concepts>

OpenNameSpace(NBezier);

template<typename Scalar, size_t Dimension>
concept BezierRequirement = BezierType<Scalar> &&  //
                            BezierDimensionRequirement<Dimension>;

template<typename Scalar, size_t Dimension, size_t Degree>
concept CurvatureRequirement = BezierRequirement<Scalar, Dimension> &&  //
                               Dimension >= 2 &&                        //
                               Degree >= 2;

template<typename Scalar, size_t Dimension, size_t Degree>
concept TorsionRequirement = BezierRequirement<Scalar, Dimension> &&  //
                             Dimension == 3 &&                        //
                             Degree >= 3;

struct Bezier
{
    StaticClass(Bezier);

    template<typename Scalar, size_t Dimension, size_t Degree>
        requires BezierRequirement<Scalar, Dimension>
    static constexpr auto point(const BezierPoints<Scalar, Dimension, Degree>& p, const Scalar& a)
    {
        return Bezier::derivative<0>(p, a);
    }

    template<typename Scalar, size_t Dimension, size_t Degree>
        requires BezierRequirement<Scalar, Dimension>
    static constexpr auto tangent(const BezierPoints<Scalar, Dimension, Degree>& p, const Scalar& a)
    {
        return Bezier::derivativeNormalized<1>(p, a);
    }

    template<typename Scalar, size_t Dimension, size_t Degree>
        requires BezierRequirement<Scalar, Dimension>
    static constexpr auto normal(const BezierPoints<Scalar, Dimension, Degree>& p, const Scalar& a)
    {
        return Bezier::derivativeNormalized<2>(p, a);
    }

    template<typename Scalar, size_t Dimension, size_t Degree>
        requires CurvatureRequirement<Scalar, Dimension, Degree>
    static constexpr auto curvature(const BezierPoints<Scalar, Dimension, Degree>& p, const Scalar& a)
    {
        const auto g_1 = Bezier::derivative<1>(p, a);
        const auto g_2 = Bezier::derivative<2>(p, a);

        const auto g_1_mag_sqr = boost::qvm::mag_sqr(g_1);
        const auto g_2_mag_sqr = boost::qvm::mag_sqr(g_2);
        const auto g_1_dot_g_2 = boost::qvm::dot(g_1, g_2);
        const auto g_1_dot_g_2_pow_2 = g_1_dot_g_2 * g_1_dot_g_2;
        const auto g_1_mag = boost::math::ccmath::sqrt(g_1_mag_sqr);
        const auto g_1_mag_pow_3 = g_1_mag * g_1_mag * g_1_mag;

        return boost::math::ccmath::sqrt(g_1_mag_sqr * g_2_mag_sqr - g_1_dot_g_2_pow_2) / g_1_mag_pow_3;
    }

    template<typename Scalar, size_t Dimension, size_t Degree>
        requires TorsionRequirement<Scalar, Dimension, Degree>
    static constexpr auto torsion(const BezierPoints<Scalar, Dimension, Degree>& p, const Scalar& a)
    {
        const auto g_1 = Bezier::derivative<1>(p, a);
        const auto g_2 = Bezier::derivative<2>(p, a);
        const auto g_3 = Bezier::derivative<3>(p, a);

        const auto g_1_cross_g_2 = boost::qvm::cross(g_1, g_2);
        const auto g_1_cross_g_2_dot_g3 = boost::qvm::dot(g_1_cross_g_2, g_3);

        const auto g_1_cross_g_2_mag_sqr = boost::qvm::mag_sqr(g_1_cross_g_2);

        return g_1_cross_g_2_dot_g3 / g_1_cross_g_2_mag_sqr;
    }

    template<size_t Derivative, typename Scalar, size_t Dimension, size_t Degree>
        requires BezierRequirement<Scalar, Dimension>
    static constexpr auto derivative(const BezierPoints<Scalar, Dimension, Degree>& p, const Scalar& a)
    {
        return Polynomial::Evaluation::eval<Derivative>(p.getDerivedPoints(), a);
    }

    template<size_t Derivative, typename Scalar, size_t Dimension, size_t Degree>
        requires BezierRequirement<Scalar, Dimension>
    static constexpr auto derivativeNormalized(const BezierPoints<Scalar, Dimension, Degree>& p, const Scalar& a)
    {
        const auto derived = Bezier::derivative<Derivative>(p, a);

        return derived / boost::math::ccmath::sqrt(boost::qvm::dot(derived, derived));
    }
};

CloseNameSpace(NBezier);