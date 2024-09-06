cmake_minimum_required(VERSION 3.20)

set(PROJECT_BIN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(ProjectName NBezier)

# Set project name
project(${ProjectName})

# find and assert external libs (boost)
find_package(Boost 1.85 REQUIRED COMPONENTS qvm)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# properties
if(MSVC)
    # update __cplusplus macro
    add_compile_options(/Zc:__cplusplus)

    # treat warnings as errors
    add_compile_options(/WX)
endif(MSVC)

add_subdirectory(src/NBezier)
add_subdirectory(test)
add_subdirectory(benchmark)