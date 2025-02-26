/*
** EPITECH PROJECT, 2025
** Test
** File description:
** main
*/

#include <iostream>
#include "MapGrid.hpp"
#include "Sdf.hpp"
#include "Texture.hpp"
#include "Sprite.hpp"
#include "Generation.hpp"

void processInputs(GLFWwindow *window, sdf::Renderer &renderer);

int main(void)
{
    sdf::Renderer renderer;
    MapGrid map(200, 200);
    sdf::Sprite sprite1(glm::vec3(0.0f, 0.0f, 0.0f), map.textureBg);

    generateAll(map);
    std::cout << map;

    while (!renderer.shouldClose())
    {
        processInputs(renderer.getWindow(), renderer);

        renderer.clear();

        sprite1.draw(renderer);

        renderer.swapBuffers();

        renderer.pollEvent();
    }
    return 0;
}

void processInputs(GLFWwindow *window, sdf::Renderer &renderer)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
