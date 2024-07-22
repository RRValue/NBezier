set(ComponentName NBezier)

file(GLOB_RECURSE Header ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE Sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(${ComponentName} STATIC ${Header} ${Sources})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX src FILES ${Header} ${Sources})

target_include_directories(${ComponentName} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# properties
if(MSVC)
    set_target_properties(${ComponentName} PROPERTIES PDB_OUTPUT_DIRECTORY ${PROJECT_BIN_PATH})
    set_target_properties(${ComponentName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_PATH})
endif(MSVC)