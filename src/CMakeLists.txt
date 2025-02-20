#Set the minimum version of CMake that can be used
cmake_minimum_required(VERSION 3.17.0)

#Set the project name to hello_world
project(factoryHub)

#Set the required language to C11
set(CMAKE_CXX_STANDARD 20)

set(INCROOT ${CMAKE_SOURCE_DIR}/include)
file(GLOB_RECURSE SRC "${CMAKE_CURRENT_SOURCE_DIR}/**.cpp")

#create exectuable hello from hello_world.c
add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${INCROOT}
)