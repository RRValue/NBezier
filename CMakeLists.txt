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

    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        add_compile_options(/clang:-fconstexpr-depth=32)
        add_compile_options(/clang:-fconstexpr-backtrace-limit=32)
        add_compile_options(/clang:-fconstexpr-steps=2097152)
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        add_compile_options(/constexpr:depth32)
        add_compile_options(/constexpr:backtrace32)
        add_compile_options(/constexpr:steps2097152)
    endif()
endif(MSVC)

add_subdirectory(src/NBezier)
add_subdirectory(test)
add_subdirectory(benchmark)