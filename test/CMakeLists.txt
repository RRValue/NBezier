set(ComponentName NBezierTest)

# find and assert external libs (google test)
find_package(GTest REQUIRED)

file(GLOB_RECURSE Header ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE Sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${ComponentName} "")

target_sources(${ComponentName}
    PRIVATE ${Header}
    PRIVATE ${Sources})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX test FILES ${Header} ${Sources})

# include google test
target_include_directories(${ComponentName} PRIVATE ${GTest_DIR}/../../../include)

# internal lib NBezier
target_link_libraries(${ComponentName}
    PRIVATE NBezier)

# external libs (boost)
target_link_libraries(${ComponentName}
    PUBLIC Boost::qvm)

# external libs (google test)
target_link_libraries(${ComponentName}
    PRIVATE
    debug ${GTest_DIR}/../../gtest_main_d.lib
    debug ${GTest_DIR}/../../gtest_d.lib
    optimized ${GTest_DIR}/../../gtest_main.lib
    optimized ${GTest_DIR}/../../gtest.lib)

gtest_discover_tests(${ComponentName})

# properties
if(MSVC)
    set_target_properties(${ComponentName} PROPERTIES PDB_OUTPUT_DIRECTORY ${PROJECT_BIN_PATH})
    set_target_properties(${ComponentName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_PATH})
endif(MSVC)

add_custom_target(${ComponentName}_Format
    COMMAND clang-format --style=file -i ${Header} ${Sources}
)