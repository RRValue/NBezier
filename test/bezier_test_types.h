#pragma once

#include <gtest/gtest.h>

#include <concepts>
#include <tuple>

// clang-format off
struct Zero{static constexpr int Value = 0;};
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

using CurveMatrixScalarDegreeCombinations = ::testing::Types<std::tuple<float, One>,          //
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

using CurveMatrixScalars = ::testing::Types<float,        //
                                            double,       //
                                            long double,  //
                                            int>;

using PolynomialCoefficientsScalarDegree = ::testing::Types<std::tuple<float, Zero, Zero>,         //
                                                            std::tuple<float, One, Zero>,          //
                                                            std::tuple<float, One, One>,           //
                                                            std::tuple<float, Two, Zero>,          //
                                                            std::tuple<float, Two, One>,           //
                                                            std::tuple<float, Two, Two>,           //
                                                            std::tuple<double, Zero, Zero>,        //
                                                            std::tuple<double, One, Zero>,         //
                                                            std::tuple<double, One, One>,          //
                                                            std::tuple<double, Two, Zero>,         //
                                                            std::tuple<double, Two, One>,          //
                                                            std::tuple<double, Two, Two>,          //
                                                            std::tuple<long double, Zero, Zero>,   //
                                                            std::tuple<long double, One, Zero>,    //
                                                            std::tuple<long double, One, One>,     //
                                                            std::tuple<long double, Two, Zero>,    //
                                                            std::tuple<long double, Two, One>,     //
                                                            std::tuple<long double, Two, Two>,     //
                                                            std::tuple<int, Zero, Zero>,           //
                                                            std::tuple<int, One, Zero>,            //
                                                            std::tuple<int, One, One>,             //
                                                            std::tuple<int, Two, Zero>,            //
                                                            std::tuple<int, Two, One>,             //
                                                            std::tuple<int, Two, Two>,             //
                                                            std::tuple<unsigned int, Zero, Zero>,  //
                                                            std::tuple<unsigned int, One, Zero>,   //
                                                            std::tuple<unsigned int, One, One>,    //
                                                            std::tuple<unsigned int, Two, Zero>,   //
                                                            std::tuple<unsigned int, Two, One>,    //
                                                            std::tuple<unsigned int, Two, Two>>;

using PolynomialCoefficientsScalars = ::testing::Types<float,        //
                                                       double,       //
                                                       long double,  //
                                                       int,          //
                                                       unsigned int>;

using PolynomialVariableScalarDegree = ::testing::Types<std::tuple<float, Zero>,         //
                                                        std::tuple<float, One>,          //
                                                        std::tuple<float, Two>,          //
                                                        std::tuple<double, Zero>,        //
                                                        std::tuple<double, One>,         //
                                                        std::tuple<double, Two>,         //
                                                        std::tuple<long double, Zero>,   //
                                                        std::tuple<long double, One>,    //
                                                        std::tuple<long double, Two>,    //
                                                        std::tuple<int, Zero>,           //
                                                        std::tuple<int, One>,            //
                                                        std::tuple<int, Two>,            //
                                                        std::tuple<unsigned int, Zero>,  //
                                                        std::tuple<unsigned int, One>,   //
                                                        std::tuple<unsigned int, Two>>;

using PolynomialVariableScalars = ::testing::Types<float,        //
                                                   double,       //
                                                   long double,  //
                                                   int,          //
                                                   unsigned int>;