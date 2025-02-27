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

    generateAll(map);

    while (!renderer.shouldClose())
    {
        processInputs(renderer.getWindow(), renderer);

        renderer.clear();

        map.draw(renderer);

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
