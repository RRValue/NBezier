cmake_minimum_required(VERSION 3.20)

set(PROJECT_BIN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(ProjectName NBezier)

# Set project name
project(${ProjectName})

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(src/NBezier)
add_subdirectory(test)