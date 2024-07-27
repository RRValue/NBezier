#pragma once

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_operations.hpp>

#include <algorithm>
#include <concepts>

namespace NBezier
{
    using namespace boost::qvm;

    template<typename ScalarType, int Dimension, size_t Degree>
        requires std::floating_point<ScalarType>
    class BezierPoints
    {
    private:
        typedef vec<ScalarType, Dimension> Point;

    public:
        BezierPoints() : m_points{}
        {
            std::for_each(std::begin(m_points), std::end(m_points),  //
                          [](Point& point) { set_zero(point); });
        }
        BezierPoints(const BezierPoints& other) : m_points{other.m_points}
        {
        }
        BezierPoints(BezierPoints&& other) : m_points{std::move(other.m_points)}
        {
        }

        bool operator==(const BezierPoints& other) const
        {
            std::equal(std::cbegin(m_points), std::cend(m_points),  //
                       std::cbegin(other.m_points), std::cend(other.m_points));
        }

        inline bool operator!=(const BezierPoints& other) const
        {
            return !(*this == other);
        }

        BezierPoints& operator=(const BezierPoints& other)
        {
            if(this == &other)
                return *this;

            m_points = other.m_points;

            return *this;
        }

        BezierPoints& operator=(BezierPoints&& other)
        {
            if(this == &other)
                return *this;

            m_points = std::move(other.m_points);

            return *this;
        }

    private:
        Point m_points[Degree];
    };
}  // namespace NBezier