#pragma once

#include "NBezier/defines.h"

#include "NBezier/bezier_matrix.h"
#include "NBezier/bezier_points.h"
#include "NBezier/polynomial/evaluation.h"

#include <boost/qvm/mat_operations.hpp>
#include <boost/qvm/vec_operations.hpp>

#include <concepts>

OpenNameSpace(NBezier);

template<typename Scalar>
concept BezierType = std::floating_point<Scalar>;

template<size_t Dimension>
concept BezierDimensionRequirement = Dimension > 0;

struct Bezier
{
    StaticClass(Bezier);

    template<typename Scalar, size_t Dimension, size_t Degree>
        requires BezierType<Scalar> &&  //
                 BezierDimensionRequirement<Dimension>
    static constexpr auto point(const BezierPoints<Scalar, Dimension, Degree>& p, const Scalar& a)
    {
        return Polynomial::Evaluation::eval<0>(p.getPoints() * BezierMatrix<Scalar, Degree + 1>::get(), a);
    }

    template<typename Scalar, size_t Dimension, size_t Degree>
        requires BezierType<Scalar> &&  //
                 BezierDimensionRequirement<Dimension>
    static constexpr auto tangent(const BezierPoints<Scalar, Dimension, Degree>& p, const Scalar& a)
    {
        auto result = Polynomial::Evaluation::eval<1>(p.getPoints() * BezierMatrix<Scalar, Degree + 1>::get(), a);

        normalize(result);

        return result;
    }

    template<typename Scalar, size_t Dimension, size_t Degree>
        requires BezierType<Scalar> &&  //
                 BezierDimensionRequirement<Dimension>
    static constexpr auto normal(const BezierPoints<Scalar, Dimension, Degree>& p, const Scalar& a)
    {
        auto result = Polynomial::Evaluation::eval<2>(p.getPoints() * BezierMatrix<Scalar, Degree + 1>::get(), a);

        normalize(result);

        return result; 
    }
};

CloseNameSpace(NBezier);