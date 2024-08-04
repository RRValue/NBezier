set(ComponentName NBezierBench)

# find and assert external libs (google benchmark)
find_package(benchmark REQUIRED)

file(GLOB_RECURSE Header ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE Sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${ComponentName} "")

target_sources(${ComponentName}
  PRIVATE ${Header}
  PRIVATE ${Sources})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX bench FILES ${Header} ${Sources})

# internal lib NBezier
target_link_libraries(${ComponentName}
    PRIVATE NBezier)

# external libs (google benchmark)
target_link_libraries(${ComponentName} PRIVATE benchmark::benchmark_main)

# properties
if(MSVC)
    set_target_properties(${ComponentName} PROPERTIES PDB_OUTPUT_DIRECTORY ${PROJECT_BIN_PATH})
    set_target_properties(${ComponentName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_PATH})
endif(MSVC)