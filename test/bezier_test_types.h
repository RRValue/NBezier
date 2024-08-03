#pragma once

#include "helper/cardinalities.h"

#include <gtest/gtest.h>

#include <tuple>

using BezierTestTypes = ::testing::Types<std::tuple<float, One, One>,            //
                                         std::tuple<float, One, Two>,            //
                                         std::tuple<float, One, Three>,          //
                                         std::tuple<float, One, Four>,           //
                                         std::tuple<float, Two, One>,            //
                                         std::tuple<float, Two, Two>,            //
                                         std::tuple<float, Two, Three>,          //
                                         std::tuple<float, Two, Four>,           //
                                         std::tuple<float, Two, One>,            //
                                         std::tuple<float, Three, One>,          //
                                         std::tuple<float, Three, Two>,          //
                                         std::tuple<float, Three, Three>,        //
                                         std::tuple<float, Three, Four>,         //
                                         std::tuple<double, One, One>,           //
                                         std::tuple<double, One, Two>,           //
                                         std::tuple<double, One, Three>,         //
                                         std::tuple<double, One, Four>,          //
                                         std::tuple<double, Two, One>,           //
                                         std::tuple<double, Two, Two>,           //
                                         std::tuple<double, Two, Three>,         //
                                         std::tuple<double, Two, Four>,          //
                                         std::tuple<double, Three, One>,         //
                                         std::tuple<double, Three, Two>,         //
                                         std::tuple<double, Three, Three>,       //
                                         std::tuple<double, Three, Four>,        //
                                         std::tuple<long double, One, One>,      //
                                         std::tuple<long double, One, Two>,      //
                                         std::tuple<long double, One, Three>,    //
                                         std::tuple<long double, One, Four>,     //
                                         std::tuple<long double, Two, One>,      //
                                         std::tuple<long double, Two, Two>,      //
                                         std::tuple<long double, Two, Three>,    //
                                         std::tuple<long double, Two, Four>,     //
                                         std::tuple<long double, Three, One>,    //
                                         std::tuple<long double, Three, Two>,    //
                                         std::tuple<long double, Three, Three>,  //
                                         std::tuple<long double, Three, Four>>;

using CurveMatrixScalars = ::testing::Types<float,        //
                                            double,       //
                                            long double,  //
                                            int>;