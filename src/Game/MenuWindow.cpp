/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** MenuWindow
*/

#include "WindowsManager.hpp"

void WindowsManager::drawMenu(MapGrid map, sdf::Renderer &renderer)
{
}

void WindowsManager::updateMenu(MapGrid map, sdf::Renderer &renderer)
{
}

void WindowsManager::processInputsMenu(GLFWwindow *window, MapGrid &map)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
        _state = State::GAME;
}
