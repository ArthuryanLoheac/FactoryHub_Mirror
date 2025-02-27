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
    int i = 30;

    // FOR TEST TO REMOVE
    std::shared_ptr<Tapis> tapis2 = std::make_shared<Tapis>();
    tapis2.get()->addElementTapis(Item("Zinc"));
    map.addBlock(tapis2, 4, 4);
    map.addBlock(std::make_shared<Tapis>(), 4, 5);
    map.addBlock(std::make_shared<Tapis>(), 4, 6);
    map.addBlock(std::make_shared<Tapis>(), 4, 7);
    map.addBlock(std::make_shared<Tapis>(), 4, 8);
    map.addBlock(std::make_shared<Tapis>(), 4, 9);

    generateAll(map);
    renderer.resetDeltaTime();
    while (!renderer.shouldClose()) {
        if (i > 0 && tapis2.get()->addElementTapis(Item("Zinc")))
            i--;
        processInputs(renderer.getWindow(), renderer);
        map.update(renderer.getDeltaTime());
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
