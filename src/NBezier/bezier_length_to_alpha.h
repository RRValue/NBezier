#pragma once

#include "NBezier/bezier_length_result.h"
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
};

CloseNameSpace(NBezier);