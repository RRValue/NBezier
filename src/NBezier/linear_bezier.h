#pragma once

#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_operations.hpp>

#include <concepts>

namespace NBezier
{
    using namespace boost::qvm;

    template<typename ScalarType, int Dimension>
        requires std::floating_point<ScalarType>
    class LinearBezier
    {
    private:
        typedef vec<ScalarType, Dimension> Point;

    public:
        LinearBezier() :
            m_start{},  //
            m_end{}
        {
            set_zero(m_start);
            set_zero(m_end);
        }
        LinearBezier(const LinearBezier& other) :
            m_start{other.m_start},  //
            m_end{other.m_end}
        {

        }
        LinearBezier(LinearBezier&& other) :
            m_start{std::move(other.m_start)},  //
            m_end{std::move(other.m_end)}
        {
        }

        bool operator==(const LinearBezier& other) const
        {
            return m_start == other.m_start &&  //
                   m_end == other.m_end;
        }

        inline bool operator!=(const LinearBezier& other) const
        {
            return !(*this == other);
        }

        LinearBezier& operator=(const LinearBezier& other)
        {
            if(this == &other)
                return *this;

            m_start = other.m_start;
            m_end = other.m_end;

            return *this;
        }

        LinearBezier& operator=(LinearBezier&& other)
        {
            if(this == &other)
                return *this;

            m_start = std::move(other.m_start);
            m_end = std::move(other.m_end);

            return *this;
        }

    private:
        Point m_start;
        Point m_end;
    };
}  // namespace NBezier