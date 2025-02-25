cmake_minimum_required(VERSION 3.17.0)

project(factoryHub)

include_directories(
    PUBLIC include/
    PUBLIC submodules/glfw/include/
    PUBLIC submodules/glm/glm/
)

link_directories(
    ${CMAKE_BINARY_DIR}/submodules/glfw/src/
    ${CMAKE_BINARY_DIR}/submodules/glm/glm/
)

link_libraries(glfw3)

add_subdirectory(submodules/)

add_subdirectory(src/)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
