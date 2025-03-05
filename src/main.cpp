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
#include "GetterTextures.hpp"

void processInputs(GLFWwindow *window, sdf::Renderer &renderer);

int main(void)
{
    sdf::Renderer renderer;
    sdf::GetterTextures getterTextures;
    MapGrid map(100, 100);

    // FOR TEST TO REMOVE
    map.addBlock(std::make_shared<Acier>(), 10, 10);
    map.addBlock(std::make_shared<MinerT1>(), 10, 10, true);
    map.addBlock(std::make_shared<Tapis>(), 5, 10, true, Direction::LEFT);
    map.addBlock(std::make_shared<Tapis>(), 6, 10, true, Direction::LEFT);
    map.addBlock(std::make_shared<Tapis>(), 7, 10, true, Direction::LEFT);
    map.addBlock(std::make_shared<Tapis>(), 8, 10, true, Direction::LEFT);
    map.addBlock(std::make_shared<Tapis>(), 9, 10, true, Direction::LEFT);
    
    map.addBlock(std::make_shared<Tapis>(), 10, 5, true, Direction::DOWN);
    map.addBlock(std::make_shared<Tapis>(), 10, 6, true, Direction::DOWN);
    map.addBlock(std::make_shared<Tapis>(), 10, 7, true, Direction::DOWN);
    map.addBlock(std::make_shared<Tapis>(), 10, 8, true, Direction::DOWN);
    map.addBlock(std::make_shared<Tapis>(), 10, 9, true, Direction::DOWN);

    generateAll(map);

    renderer.resetDeltaTime();
    while (!renderer.shouldClose()) {
        processInputs(renderer.getWindow(), renderer);
        map.update(renderer.getDeltaTime());
        renderer.clear(glm::vec4(0.18f, 0.215f, 0.309f, 1.0f));
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
