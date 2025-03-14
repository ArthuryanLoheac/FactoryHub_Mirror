/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** GameWindow
*/

#include "WindowsManager.hpp"
#include "Generation.hpp"

void WindowsManager::initGame(MapGrid map)
{
    generateAll(map);
}

void WindowsManager::drawGame(MapGrid map, sdf::Renderer &renderer)
{
    BuilderManager::instance->draw(renderer);
    map.draw(renderer);
}

void WindowsManager::updateGame(MapGrid map, float deltaTime)
{
    map.update(deltaTime);
}

void WindowsManager::processInputsGame(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        sdf::Camera::instance->move(sdf::Camera::Direction::UP, renderer.getDeltaTime(), map.getSizeX(), map.getSizeY());
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        sdf::Camera::instance->move(sdf::Camera::Direction::DOWN, renderer.getDeltaTime(), map.getSizeX(), map.getSizeY());
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        sdf::Camera::instance->move(sdf::Camera::Direction::RIGHT, renderer.getDeltaTime(), map.getSizeX(), map.getSizeY());
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        sdf::Camera::instance->move(sdf::Camera::Direction::LEFT, renderer.getDeltaTime(), map.getSizeX(), map.getSizeY());
     glfwSetScrollCallback(window, sdf::Renderer::scroll_callback);
    BuilderManager::instance->updateKeyState(window, map);
}
