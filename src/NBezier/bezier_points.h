#pragma once

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_operations.hpp>

#include <concepts>

namespace NBezier
{
    using namespace boost::qvm;

    template<typename ScalarType, int Dimension>
        requires std::floating_point<ScalarType>
    class BezierPoints
    {
    private:
        typedef vec<ScalarType, Dimension> Point;

    public:
        BezierPoints() : m_points{}
        {
            set_zero(m_points[0]);
            set_zero(m_points[1]);
        }
        BezierPoints(const BezierPoints& other) :m_points{other.m_points}
        {

        }
        BezierPoints(BezierPoints&& other) :m_points{std::move(other.m_points)}
        {
        }

        bool operator==(const BezierPoints& other) const
        {
            return m_points[0] == other.m_points[0] &&  //
                   m_points[1] == other.m_points[1];
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
        Point m_points[2];
    };
}  // namespace NBezier