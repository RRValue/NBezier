#pragma once

#include "NBezier/bezier_length_result.h"
#include "NBezier/bezier_split.h"
#include "NBezier/defines.h"

#include <boost/math/ccmath/ccmath.hpp>

#include <array>

OpenNameSpace(NBezier);

struct BezierLengthToAlpha
{
    StaticClass(BezierLengthToAlpha);

    template<typename BezierPointsType, typename Scalar, size_t CacheDepth>
    static constexpr auto get(const BezierPointsType& points, const Scalar& atLength, const LengthResult<Scalar, CacheDepth>& lengthData)
    {
        auto alpha = Scalar(0);
        auto alpha_factor = Scalar(1);
        auto length = atLength;
        auto cache_pos = size_t(0);

        const auto found = walk<Scalar, CacheDepth, size_t(0)>(alpha, lengthData.m_cache, length, cache_pos, alpha_factor);

        if(found)
            return alpha;

        const auto search_points = splitForSearch(points, alpha, alpha_factor);

        search<Scalar>(search_points, alpha, length, alpha_factor);

        return alpha;
    }

private:
    template<typename Scalar, size_t CacheDepth, size_t CacheLevel>
    static constexpr auto walk(Scalar& alpha, const auto& cache, Scalar& length, size_t& cachePos, Scalar& alphaFactor)
    {
        if constexpr(CacheLevel == CacheDepth)
        {
            return false;
        }
        else
        {
            const auto& cache_length = cache[cachePos];

            alphaFactor *= Scalar(0.5);

            if(length >= cache_length)
                alpha += alphaFactor;

            if(boost::math::ccmath::abs(cache_length - length) <= Scalar(1e-07))
                return true;

            if(length >= cache_length)
                length -= cache_length;

            if(length < cache_length)
                cachePos += 1;
            else
                cachePos += Math::Pow::get2<size_t, CacheDepth - CacheLevel - 1>();

            if(length < cache_length)
                return walk<Scalar, CacheDepth, CacheLevel + 1>(alpha, cache, length, cachePos, alphaFactor);
            else
                return walk<Scalar, CacheDepth, CacheLevel + 1>(alpha, cache, length, cachePos, alphaFactor);
        }
    }

    template<typename Scalar>
    static constexpr auto splitForSearch(const auto& points, const Scalar& alpha, const Scalar& alphaFactor)
    {
        if(alphaFactor == Scalar(1))
            return points;
        else if(alpha == Scalar(0))
            return BezierSplit::at(points, alphaFactor).m_left;
        else if(boost::math::ccmath::abs(alpha + alphaFactor - Scalar(1)) <= Scalar(1e-07))
            return BezierSplit::at(points, alpha).m_right;
        else
        {
            const auto& first_split_factor = alpha;
            const auto second_split_factor = alphaFactor / (Scalar(1) - alpha);

            const auto first_split = BezierSplit::at(points, first_split_factor).m_right;
            return BezierSplit::at(first_split, second_split_factor).m_left;
        }
    }

    template<typename Scalar>
    static constexpr void search(const auto& points, Scalar& alpha, Scalar& length, Scalar& alphaFactor)
    {
        const auto split = BezierSplit::at(points, Scalar(0.5));

        const auto length_left = BezierLength::get<0>(split.m_left).m_length;
        const auto length_right = BezierLength::get<0>(split.m_right).m_length;

        if(boost::math::ccmath::abs(length_left + length_right - length) <= Scalar(1e-07))
            return;

        alphaFactor *= Scalar(0.5);

        if (boost::math::ccmath::abs(length_left - length) <= Scalar(1e-07))
        {
            alpha += alphaFactor;

            return;
        }
        else if(length < length_left)
        {
            search<Scalar>(split.m_left, alpha, length, alphaFactor);
        }
        else
        {
            length -= length_left;
            alpha += alphaFactor;

            search<Scalar>(split.m_right, alpha, length, alphaFactor);
        }
     }
};

    CloseNameSpace(NBezier);