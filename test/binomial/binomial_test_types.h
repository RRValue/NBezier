#pragma once

#include <gtest/gtest.h>

using CoefficientTypes = ::testing::Types<unsigned int,        //
                                          int,                 //
                                          size_t,              //
                                          unsigned long long,  //
                                          long long,           //
                                          char,                //
                                          unsigned char,       //
                                          float,               //
                                          double>;