#pragma once

#include "NBezier/defines.h"

#include "NBezier/bezier_matrix.h"

#include "boost/qvm/mat.hpp"
#include "boost/qvm/mat_access.hpp"
#include "boost/qvm/vec.hpp"
#include "boost/qvm/vec_access.hpp"
#include <boost/qvm/map_mat_vec.hpp>
#include <boost/qvm/mat_operations.hpp>

#include <concepts>

OpenNameSpace(NBezier);

template<typename Scalar>
concept BezierPointsType = std::floating_point<Scalar>;

template<size_t Dimension>
concept BezierPointsDimensionRequirement = Dimension > 0;

template<size_t Index, size_t Indices>
concept PointIndexRequirement = Index < Indices;

template<size_t Degree, typename... PointsArgs>
concept ConstructionRequirement = sizeof...(PointsArgs) == Degree + 1;

template<typename Scalar, size_t Dimension, size_t Degree>
    requires BezierPointsType<Scalar> &&  //
             BezierPointsDimensionRequirement<Dimension>
struct BezierPoints
{
    typedef boost::qvm::mat<Scalar, Dimension, Degree + 1> Points;
    typedef boost::qvm::vec<Scalar, Dimension> Point;

private:
    template<size_t Index, typename PointArg>
    constexpr void construct(PointArg point)
    {
        setPoint<Index>(point, std::make_index_sequence<Dimension>{});
    }

    template<size_t Index, typename PointArg, typename... PointsArgs>
    constexpr void construct(PointArg point, PointsArgs... args)
    {
        setPoint<Index>(point, std::make_index_sequence<Dimension>{});
        construct<Index + 1>(args...);
    }

public:
    constexpr BezierPoints() : m_points{}, m_derived_points{}
    {
    }

    template<typename... PointsArgs>
        requires ConstructionRequirement<Degree, PointsArgs...>
    constexpr BezierPoints(PointsArgs... args) : BezierPoints()
    {
        construct<0>(args...);

        updateDerivedPoints();
    }

    template<size_t Index>
        requires PointIndexRequirement<Index, Degree + 1>
    constexpr Point getPoint() const
    {
        return getPoint<Index>(std::make_index_sequence<Dimension>{});
    }

    template<size_t Index>
        requires PointIndexRequirement<Index, Degree + 1>
    constexpr void setPoint(const Point& p)
    {
        boost::qvm::col<Index>(m_points) = p;

        updateDerivedPoints();
    }

    constexpr const Points& getPoints() const
    {
        return m_points;
    }

    constexpr const Points& getDerivedPoints() const
    {
        return m_derived_points;
    }

private:
    template<size_t Index, size_t Dimension>
    constexpr void getPoint(Point& p) const
    {
        A<Dimension>(p) = A<Dimension, Index>(m_points);
    }

    template<size_t Index, size_t... Dimensions>
    constexpr Point getPoint(std::index_sequence<Dimensions...>) const
    {
        Point p = {};

        (getPoint<Index, Dimensions>(p), ...);
        
        return p;
    }

    template<size_t Index, size_t Dimension>
    constexpr void setPoint(const Point& p)
    {
        A<Dimension, Index>(m_points) = A<Dimension>(p);
    }

    template<size_t Index, size_t... Dimensions>
    constexpr void setPoint(const Point& p, std::index_sequence<Dimensions...>)
    {
        (setPoint<Index, Dimensions>(p), ...);
    }

    constexpr void updateDerivedPoints()
    {
        m_derived_points = m_points * BezierMatrix<Scalar, Degree + 1>::get();
    }

private:
    Points m_points = {};
    Points m_derived_points = {};
};

CloseNameSpace(NBezier);