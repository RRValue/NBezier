#pragma once

#include "../helper/cardinalities.h"

#include <gtest/gtest.h>

using CoefficientVectorScalars = ::testing::Types<float,        //
                                                  double,       //
                                                  long double,  //
                                                  int,          //
                                                  unsigned int>;

using VariableVectorScalars = ::testing::Types<float,        //
                                               double,       //
                                               long double,  //
                                               int,          //
                                               unsigned int>;