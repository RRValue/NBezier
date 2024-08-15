#pragma once

#include "NBezier/defines.h"

#include "NBezier/bezier_matrix.h"
#include "NBezier/bezier_requirements.h"

#include "boost/qvm/mat.hpp"
#include "boost/qvm/mat_access.hpp"
#include "boost/qvm/vec.hpp"
#include "boost/qvm/vec_access.hpp"
#include <boost/qvm/map_mat_vec.hpp>
#include <boost/qvm/mat_operations.hpp>

#include <concepts>

OpenNameSpace(NBezier);

template<size_t Index, size_t Indices>
concept PointIndexRequirement = Index < Indices;

template<size_t Degree, typename... PointsArgs>
concept ConstructionRequirement = sizeof...(PointsArgs) == Degree + 1;

template<size_t NewDegree, size_t Degree>
concept ReduceDegreeRequirement = NewDegree <= Degree;

template<typename Scalar, size_t Dimension, size_t Degree>
    requires BezierType<Scalar> &&  //
             BezierDimensionRequirement<Dimension>
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

    constexpr BezierPoints(const Points& points) : m_points{points}, m_derived_points{}
    {
        updateDerivedPoints();
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
    constexpr auto getPoint() const
    {
        return getPoint<Index>(std::make_index_sequence<Dimension>{});
    }

    template<size_t Index>
        requires PointIndexRequirement<Index, Degree + 1>
    constexpr void setPoint(const auto& p)
    {
        setPoint<Index>(p, std::make_index_sequence<Dimension>{});

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

    template<size_t NewDegree>
        requires ReduceDegreeRequirement<NewDegree, Degree>
    constexpr auto reduceFromLeft() const
    {
        return copyFromLeft<NewDegree>(std::make_index_sequence<NewDegree + 1>{});
    }

    template<size_t NewDegree>
        requires ReduceDegreeRequirement<NewDegree, Degree>
    constexpr auto reduceFromRight() const
    {
        return copyFromRight<NewDegree>(std::make_index_sequence<NewDegree + 1>{});
    }

    constexpr bool operator==(const BezierPoints& other) const
    {
        return m_points == other.m_points &&  //
               m_derived_points == other.m_derived_points;
    }

    constexpr bool operator!=(const BezierPoints& other) const
    {
        return !(*this == other);
    }

private:
    template<size_t NewDegree, size_t... Indices>
    NBInline constexpr auto copyFromLeft(std::index_sequence<Indices...>) const
    {
        boost::qvm::mat<Scalar, Dimension, NewDegree + 1> result = {};

        (copyFromLeft<Indices>(m_points, result), ...);

        return BezierPoints<Scalar, Dimension, NewDegree>{result};
    }

    template<size_t Index>
    NBInline constexpr void copyFromLeft(const auto& src, auto& dst) const
    {
        copyPoint<Index, Index>(src, dst, std::make_index_sequence<Dimension>{});
    }

    template<size_t NewDegree, size_t... Indices>
    NBInline constexpr auto copyFromRight(std::index_sequence<Indices...>) const
    {
        boost::qvm::mat<Scalar, Dimension, NewDegree + 1> result = {};

        (copyFromRight<NewDegree, Indices>(m_points, result), ...);

        return BezierPoints<Scalar, Dimension, NewDegree>{result};
    }

    template<size_t NewDegree, size_t Index>
    NBInline constexpr void copyFromRight(const auto& src, auto& dst) const
    {
        copyPoint<Degree - Index, NewDegree - Index>(src, dst, std::make_index_sequence<Dimension>{});
    }

    template<size_t SrcIndex, size_t DstIndex, size_t... Dimensions>
    NBInline constexpr void copyPoint(const auto& src, auto& dst, std::index_sequence<Dimensions...>) const
    {
        (copyValue<SrcIndex, DstIndex, Dimensions>(src, dst), ...);
    }

    template<size_t SrcIndex, size_t DstIndex, size_t D>
    NBInline constexpr void copyValue(const auto& src, auto& dst) const
    {
        A<D, DstIndex>(dst) = A<D, SrcIndex>(src);
    }

    template<size_t Index, size_t Dimension>
    NBInline constexpr void getPoint(auto& p) const
    {
        A<Dimension>(p) = A<Dimension, Index>(m_points);
    }

    template<size_t Index, size_t... Dimensions>
    NBInline constexpr auto getPoint(std::index_sequence<Dimensions...>) const
    {
        Point p = {};

        (getPoint<Index, Dimensions>(p), ...);

        return p;
    }

    template<size_t Index, size_t... Dimensions>
    NBInline constexpr void setPoint(const auto& p, std::index_sequence<Dimensions...>)
    {
        (setPoint<Index, Dimensions>(p), ...);
    }

    template<size_t Index, size_t Dimension>
    NBInline constexpr void setPoint(const auto& p)
    {
        A<Dimension, Index>(m_points) = A<Dimension>(p);
    }

    NBInline constexpr void updateDerivedPoints()
    {
        constexpr auto bezier_matrix = BezierMatrix::get<Scalar, Degree + 1>();

        m_derived_points = m_points * bezier_matrix;
    }

private:
    Points m_points = {};
    Points m_derived_points = {};
};

CloseNameSpace(NBezier);