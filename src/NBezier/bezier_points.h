#pragma once

#include "NBezier/defines.h"

#include <boost/qvm/vec.hpp>

#include <algorithm>
#include <concepts>

OpenNameSpace(NBezier);

template<typename ScalarType, int Dimension, size_t Degree>
    requires std::floating_point<ScalarType>
class BezierPoints
{
private:
    typedef boost::qvm::vec<ScalarType, Dimension> Point;

public:
    bool operator==(const BezierPoints& other) const
    {
        std::equal(std::cbegin(m_points), std::cend(m_points),  //
                   std::cbegin(other.m_points), std::cend(other.m_points));
    }

    inline bool operator!=(const BezierPoints& other) const
    {
        return !(*this == other);
    }

private:
    Point m_points[Degree];
};

CloseNameSpace(NBezier);