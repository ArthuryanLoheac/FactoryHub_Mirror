cmake_minimum_required(VERSION 3.17.0)

project(factoryHub)

# Find and include SFML
find_package(SFML 2.5 COMPONENTS system audio REQUIRED)

include_directories(
    PUBLIC include/
    PUBLIC submodules/glfw/include/
    PUBLIC submodules/glm/
)

link_directories(
    ${CMAKE_BINARY_DIR}/submodules/glfw/src/
    ${CMAKE_BINARY_DIR}/submodules/glm/
)

# Link GLFW
link_libraries(glfw3)

# Add subdirectories
add_subdirectory(submodules/)
add_subdirectory(src/)

# Link SFML to your main target
target_link_libraries(factoryHub PRIVATE sfml-system sfml-audio)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
