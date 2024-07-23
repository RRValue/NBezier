set(ComponentName NBezierTest)

# find and assert external libs (google test)
find_package(GTest REQUIRED)

file(GLOB_RECURSE Header ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE Sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${ComponentName} ${Header} ${Sources})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX test FILES ${Header} ${Sources})

# include google test
target_include_directories(${ComponentName} PRIVATE ${GTEST_INCLUDE_DIR})

# external libs (google test)
target_link_libraries(${ComponentName} PRIVATE 
    GTest::GTest
    NBezier)

# properties
if(MSVC)
    set_target_properties(${ComponentName} PROPERTIES PDB_OUTPUT_DIRECTORY ${PROJECT_BIN_PATH})
    set_target_properties(${ComponentName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_PATH})
endif(MSVC)