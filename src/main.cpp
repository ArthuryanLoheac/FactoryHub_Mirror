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
    sdf::Texture textureBase("Assets/Base.png");
    sdf::Texture textureBelt("Assets/tapis.png");
    sdf::Texture textureMine("Assets/Miner.png");
    sdf::Sprite sprite1(glm::vec3(0.0f, 0.0f, 0.0f), textureBase);
    sdf::Sprite sprite2(glm::vec3(1.0f, 0.0f, 0.0f), textureBelt, SDF_RIGHT);
    sdf::Sprite sprite3(glm::vec3(2.0f, 0.0f, 0.0f), textureBelt, SDF_DOWN);
    sdf::Sprite sprite4(glm::vec3(2.0f, -1.0f, 0.0f), textureMine);
    MapGrid map(200, 200);

    generateAll(map);
    std::cout << map;

    while (!renderer.shouldClose())
    {
        processInputs(renderer.getWindow());

        renderer.clear();

        sprite1.draw(renderer);
        sprite2.draw(renderer);
        sprite3.draw(renderer);
        sprite4.draw(renderer);

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
