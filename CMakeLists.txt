cmake_minimum_required(VERSION 3.17.0)

project(factoryHub)

include_directories(
    PUBLIC include/
    PUBLIC submodules/glfw/include/
)

link_directories(build/submodules/glfw/src/)

link_libraries(glfw3)

add_subdirectory(submodules/)

add_subdirectory(src/)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

