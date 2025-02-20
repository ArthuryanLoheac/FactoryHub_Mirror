cmake_minimum_required(VERSION 3.17.0)

project(factoryHub)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src/)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})