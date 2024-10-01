#pragma once

#include "NBezier/bezier_requirements.h"
#include "NBezier/defines.h"
#include "NBezier/math/pow.h"

#include <array>
#include <concepts>
#include <type_traits>

OpenNameSpace(NBezier);

template<typename Scalar, size_t CacheDepth>
concept LengthResultRequirement = BezierType<Scalar> &&  //
                                  CacheDepth >= 1 && CacheDepth < 16;

template<typename Scalar, size_t CacheDepth>
    requires LengthResultRequirement<Scalar, CacheDepth>
struct LengthResult
{
    static const size_t Depth = CacheDepth;
    static const size_t CacheSize = Math::Pow::get2<size_t, CacheDepth + 1>() - 2;

    typedef std::array<Scalar, CacheSize> CacheType;
    
    Scalar m_length = Scalar(0);
    CacheType m_cache = {};
};

CloseNameSpace(NBezier);