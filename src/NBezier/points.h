#pragma once

#include "NBezier/defines.h"

#include <boost/qvm/mat.hpp>

#include <concepts>

OpenNameSpace(NBezier);

template<typename Scalar>
concept PointType = std::floating_point<Scalar>;

template<size_t Dimentsion>
concept DimentsionRequirement = Dimentsion > 0;

template<typename Scalar, int Dimension, size_t Degree>
    requires PointType<Scalar> &&  //
                 DimentsionRequirement<Dimension>
using Points = boost::qvm::mat<Scalar, Dimension, Degree + 1>;

CloseNameSpace(NBezier);