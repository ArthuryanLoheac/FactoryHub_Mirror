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
#include "Chemical_Plant.hpp"
#include "MinerT1.hpp"
#include "Salpetre.hpp"
#include "GetterTextures.hpp"
#include "BuilderManager.hpp"

void processInputs(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map);

int main(void)
{
    sdf::Renderer renderer;
    sdf::GetterTextures getterTextures;
    BuilderManager builderManager;
    MapGrid map(100, 100);

    // FOR TEST TO REMOVE
    map.addBlock(std::make_shared<Salpetre>(), 10, 4);
    map.addBlock(std::make_shared<MinerT1>(), 10, 4, true);
    map.addBlock(std::make_shared<Tapis>(), 10, 5, true, Direction::UP);
    map.addBlock(std::make_shared<Tapis>(), 10, 7, true, Direction::UP);
    map.addBlock(std::make_shared<Chemical_PlantT1>(), 10, 6, true);

    generateAll(map);

    renderer.resetDeltaTime();
    while (!renderer.shouldClose()) {
        processInputs(renderer.getWindow(), renderer, map);
        map.update(renderer.getDeltaTime());
        renderer.clear();
        map.draw(renderer);
        renderer.swapBuffers();
        renderer.pollEvent(map);
    }
    return 0;
}

void processInputs(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    BuilderManager::instance->updateKeyState(window, map);
}
