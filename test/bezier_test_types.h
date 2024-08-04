#pragma once

#include "helper/cardinalities.h"

#include <gtest/gtest.h>

#include <tuple>

using CurveMatrixScalars = ::testing::Types<float,        //
                                            double,       //
                                            long double,  //
                                            int>;