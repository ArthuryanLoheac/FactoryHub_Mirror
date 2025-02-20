#Set the minimum version of CMake that can be used
cmake_minimum_required(VERSION 3.17.0)

#Set the project name to hello_world
project(factoryHub)

#Set the required language to C11
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE HEADER_FILES "../include/**.hpp")
file(GLOB_RECURSE SRC "${CMAKE_CURRENT_SOURCE_DIR}/**.cpp")
foreach(HEADER_FILE ${HEADER_FILES})
    get_filename_component(HEADER_DIR ${HEADER_FILE} DIRECTORY)
    include_directories(${HEADER_DIR})
endforeach()

#create exectuable hello from hello_world.c
add_executable(${PROJECT_NAME} ${SRC})
