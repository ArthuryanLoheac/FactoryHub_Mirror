/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** GameWindow
*/

#include "WindowsManager.hpp"

void WindowsManager::drawGame(MapGrid map, sdf::Renderer &renderer)
{
    BuilderManager::instance->draw(renderer);
    map.draw(renderer);
}

void WindowsManager::updateGame(MapGrid map, sdf::Renderer &renderer)
{
    map.update(renderer.getDeltaTime());
}

void WindowsManager::processInputsGame(GLFWwindow *window, MapGrid &map)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    BuilderManager::instance->updateKeyState(window, map);
}
