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

# include for google benchmark
target_include_directories(${ComponentName} PRIVATE ${benchmark_DIR}/../../../include)

# internal lib NBezier
target_link_libraries(${ComponentName}
    PRIVATE NBezier)

# external libs (google benchmark)
target_link_libraries(${ComponentName}
    PRIVATE
      debug ${benchmark_DIR}/../../benchmark_d.lib 
      debug ${benchmark_DIR}/../../benchmark_main_d.lib
      optimized ${benchmark_DIR}/../../benchmark.lib
      optimized ${benchmark_DIR}/../../benchmark_main.lib)

# define for (google benchmark)
target_compile_options(${ComponentName} PRIVATE -DBENCHMARK_STATIC_DEFINE)

# properties
if(MSVC)
    # dependency for (google benchmark)
    target_link_libraries(${ComponentName} PRIVATE shlwapi.lib)
    
    set_target_properties(${ComponentName} PROPERTIES PDB_OUTPUT_DIRECTORY ${PROJECT_BIN_PATH})
    set_target_properties(${ComponentName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_PATH})
endif(MSVC)