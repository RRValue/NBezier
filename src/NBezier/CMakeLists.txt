set(ComponentName NBezier)

# find and assert external libs (boost)
find_package(Boost 1.85 REQUIRED COMPONENTS qvm)

file(GLOB_RECURSE Header ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE Sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(${ComponentName} STATIC)

target_sources(${ComponentName}
  PRIVATE ${Sources}
  PUBLIC FILE_SET HEADERS BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/.. FILES ${Header})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX src FILES ${Header} ${Sources})

# add boost include directories
target_include_directories(${ComponentName} PRIVATE ${Boost_INCLUDE_DIRS})

# properties
if(MSVC)
    set_target_properties(${ComponentName} PROPERTIES PDB_OUTPUT_DIRECTORY ${PROJECT_BIN_PATH})
    set_target_properties(${ComponentName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_PATH})
endif(MSVC)