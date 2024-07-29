#pragma once

#include <gtest/gtest.h>

#include <concepts>
#include <tuple>

// clang-format off
struct One{static constexpr int Value = 1;};
struct Two{static constexpr int Value = 2;};
struct Three{static constexpr int Value = 3;};
struct Four{static constexpr int Value = 4;};
struct Five{static constexpr int Value = 5;};
struct Six{static constexpr int Value = 6;};
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

using ScalarDegreeCombinations = ::testing::Types<std::tuple<float, One>,          //
                                                  std::tuple<float, Two>,          //
                                                  std::tuple<float, Three>,        //
                                                  std::tuple<float, Four>,         //
                                                  std::tuple<float, Five>,         //
                                                  std::tuple<float, Six>,          //
                                                  std::tuple<double, One>,         //
                                                  std::tuple<double, Two>,         //
                                                  std::tuple<double, Three>,       //
                                                  std::tuple<double, Four>,        //
                                                  std::tuple<double, Five>,        //
                                                  std::tuple<double, Six>,         //
                                                  std::tuple<long double, One>,    //
                                                  std::tuple<long double, Two>,    //
                                                  std::tuple<long double, Three>,  //
                                                  std::tuple<long double, Four>,   //
                                                  std::tuple<long double, Five>,   //
                                                  std::tuple<long double, Six>>;

using Scalars = ::testing::Types<float,        //
                                 double,       //
                                 long double,  //
                                 int>;