#pragma once

#include <gtest/gtest.h>

#include <concepts>
#include <tuple>

// clang-format off
struct One{static const int Value = 1;};
struct Two{static const int Value = 2;};
struct Three{static const int Value = 3;};
struct Four{static const int Value = 4;};
// clang-format on

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