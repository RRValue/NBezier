set(ComponentName NBezier)

file(GLOB_RECURSE Header ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE Sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(${ComponentName} INTERFACE)

target_sources(${ComponentName}
    PRIVATE ${Sources}
    PUBLIC FILE_SET HEADERS BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/.. FILES ${Header})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX src FILES ${Header} ${Sources})

# external libs (boost)
target_link_libraries(${ComponentName}
    INTERFACE Boost::qvm)

# properties
if(MSVC)
    set_target_properties(${ComponentName} PROPERTIES PDB_OUTPUT_DIRECTORY ${PROJECT_BIN_PATH})
    set_target_properties(${ComponentName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_PATH})
endif(MSVC)

add_custom_target(${ComponentName}_Format
    COMMAND clang-format --style=file -i ${Header} ${Sources}
)