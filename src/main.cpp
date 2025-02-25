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

void processInputs(GLFWwindow *window);

int main(void)
{
    sdf::Renderer renderer;
    sdf::Texture texture("Assets/Base.png");
    sdf::Sprite sprite(glm::vec2(0, 0), glm::vec2(1, 1), texture);
    MapGrid map(200, 200);

    generateAll(map);
    std::cout << map;
    renderer.addSprite(sprite);

    while (!renderer.shouldClose())
    {
        processInputs(renderer.getWindow());

        renderer.clear();

        sprite.draw(renderer);

        renderer.swapBuffers();

        renderer.pollEvent();
    }
    return 0;
}

void processInputs(GLFWwindow *window)
{
    static unsigned int triangleDisplayFlavor = GL_FILL;
    static bool isPressed = false;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS && !isPressed) {
        isPressed = true;
        if (triangleDisplayFlavor == GL_FILL)
            triangleDisplayFlavor = GL_LINE;
        else
            triangleDisplayFlavor = GL_FILL;
        glPolygonMode(GL_FRONT_AND_BACK, triangleDisplayFlavor);
    } else if (glfwGetKey(window, GLFW_KEY_L) == GLFW_RELEASE)
        isPressed = false;
}
