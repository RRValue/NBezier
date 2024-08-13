#pragma once

#include "NBezier/defines.h"

#include <concepts>

OpenNameSpace(NBezier);

template<typename Scalar>
concept BezierType = std::floating_point<Scalar>;

template<size_t Dimension>
concept BezierDimensionRequirement = Dimension > 0;

CloseNameSpace(NBezier);