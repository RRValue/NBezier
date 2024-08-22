#pragma once

#include "../helper/cardinalities.h"

#include <gtest/gtest.h>

using CoefficientVectorScalars = ::testing::Types<float,        //
                                                  double,       //
                                                  long double,  //
                                                  int,          //
                                                  unsigned int>;

using VariableScalars = ::testing::Types<float,        //
                                         double,       //
                                         long double,  //
                                         int,          //
                                         unsigned int>;