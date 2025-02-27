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

#include "Tapis.hpp"

void processInputs(GLFWwindow *window, sdf::Renderer &renderer);

int main(void)
{
    sdf::Renderer renderer;
    MapGrid map(200, 200);

    map.addBlock(std::make_shared<Tapis>(), 10, 10);
    map.addBlock(std::make_shared<Tapis>(), 10, 11);
    map.addBlock(std::make_shared<Tapis>(), 10, 12);
    map.addBlock(std::make_shared<Tapis>(), 10, 13);
    std::shared_ptr<Tapis> tapis = std::make_shared<Tapis>();
    tapis.get()->setDirection(ATapis::Direction::RIGHT);
    map.addBlock(tapis, 10, 14);

    generateAll(map);
    while (!renderer.shouldClose()) {
        processInputs(renderer.getWindow(), renderer);
        renderer.clear();
        map.draw(renderer);
        renderer.swapBuffers();
        renderer.pollEvent(map);
    }
    return 0;
}

void processInputs(GLFWwindow *window, sdf::Renderer &renderer)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
