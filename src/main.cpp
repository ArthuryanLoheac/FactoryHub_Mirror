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
#include "MinerT1.hpp"
#include "Acier.hpp"

void processInputs(GLFWwindow *window, sdf::Renderer &renderer);

int main(void)
{
    sdf::Renderer renderer;
    MapGrid map(100, 100);

    // FOR TEST TO REMOVE
    map.addBlock(std::make_shared<Acier>(), 4, 4);
    map.addBlock(std::make_shared<MinerT1>(), 4, 4);
    map.addBlock(std::make_shared<Tapis>(), 4, 5);
    map.addBlock(std::make_shared<Tapis>(), 4, 6);
    map.addBlock(std::make_shared<Tapis>(), 4, 7);
    map.addBlock(std::make_shared<Tapis>(), 4, 8);
    map.addBlock(std::make_shared<Tapis>(), 4, 9);

    generateAll(map);

    for (int i = 0; i < map.getAllBlocksAtPos(4, 4).size(); i++) {
        if (dynamic_cast<MinerT1 *>(map.getAllBlocksAtPos(4, 4)[i].get())) {
            std::cout << "MinerT1" << std::endl;
        }
        else if (dynamic_cast<Acier *>(map.getAllBlocksAtPos(4, 4)[i].get())) {
            std::cout << "Acier" << std::endl;
        }
        else
            std::cout << "else" << std::endl;
    }
    renderer.resetDeltaTime();
    while (!renderer.shouldClose()) {
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
