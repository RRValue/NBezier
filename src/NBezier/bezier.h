#pragma once

#include "NBezier/defines.h"

#include "NBezier/curve_matrix.h"
#include "NBezier/polynomial/evaluation.h"

#include "boost/qvm/mat.hpp"
#include "boost/qvm/vec.hpp"
#include <boost/qvm/map_mat_vec.hpp>
#include <boost/qvm/mat_operations.hpp>

#include <concepts>

OpenNameSpace(NBezier);

template<typename Scalar>
concept BezierType = std::floating_point<Scalar>;

template<size_t Dimension>
concept BezierDimensionRequirement = Dimension > 0;

template<size_t Index, size_t Indices>
concept PointIndexRequirement = Index < Indices;

template<typename Scalar, size_t Dimension, size_t Degree>
    requires BezierType<Scalar> &&  //
             BezierDimensionRequirement<Dimension>
struct Bezier
{
    typedef boost::qvm::mat<Scalar, Dimension, Degree + 1> Points;
    typedef boost::qvm::vec<Scalar, Dimension> Point;

public:
    template<size_t Index>
        requires PointIndexRequirement<Index, Degree + 1>
    constexpr Point getPoint()
    {
        return boost::qvm::col<Index>(m_points);
    }

    template<size_t Index>
        requires PointIndexRequirement<Index, Degree + 1>
    constexpr void setPoint(const Point& p)
    {
        boost::qvm::col<Index>(m_points) = p;
    }

    constexpr Point point(const Scalar& a) const
    {
        return Polynomial::Evaluation::eval<0>(m_points * CurveMatrix<Scalar, Degree + 1>::get(), a);
    }

private:
    Points m_points = {};
};

CloseNameSpace(NBezier);