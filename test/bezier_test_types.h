#pragma once

#include "helper/cardinalities.h"

#include <gtest/gtest.h>

#include <tuple>

using BezierScalars = ::testing::Types<float,   //
                                       double,  //
                                       long double>;

using CurveMatrixScalars = ::testing::Types<float,        //
                                            double,       //
                                            long double,  //
                                            int>;