#pragma once

#include "NBezier/defines.h"

#include <boost/qvm/mat.hpp>
#include <boost/qvm/vec.hpp>

#include <concepts>

OpenNameSpace(NBezier);

template<typename Scalar>
concept PointType = std::floating_point<Scalar>;

template<size_t Dimentsion>
concept DimentsionRequirement = Dimentsion > 0;

template<typename Scalar, int Dimension, size_t Count>
    requires PointType<Scalar> &&  //
                 DimentsionRequirement<Dimension>
using Points = boost::qvm::mat<Scalar, Dimension, Count>;

template<typename Scalar, int Dimension>
    requires PointType<Scalar> &&  //
                 DimentsionRequirement<Dimension>
using Point = boost::qvm::vec<Scalar, Dimension>;

CloseNameSpace(NBezier);