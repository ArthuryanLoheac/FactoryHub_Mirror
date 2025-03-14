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
#include "WindowsManager.hpp"

void processInputs(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map);

int main(void)
{
    sdf::Renderer renderer;
    sdf::GetterTextures getterTextures;
    BuilderManager builderManager;
    WindowsManager windowsManager;
    MapGrid map(100, 100);

    windowsManager.init(map);
    renderer.resetDeltaTime();
    while (!renderer.shouldClose()) {
        windowsManager.processInputs(renderer.getWindow(), renderer, map);
        windowsManager.update(map, renderer.getDeltaTime());
        renderer.clear();
        windowsManager.draw(map, renderer);
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
