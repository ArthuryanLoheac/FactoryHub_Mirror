/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** GameWindow
*/

#include "WindowsManager.hpp"
#include "Generation.hpp"
#include "Base.hpp"

void WindowsManager::initGame(MapGrid &map)
{   
    generateAll(map);
    sdf::Camera::instance->setZoom(0.5f);
    sdf::Camera::instance->setPosition(glm::vec2((-(float)map.getSizeX() / 2), (-(float)map.getSizeY()) / 2));
    BuilderManager::instance->setBlockBuilding(std::make_shared<Base>(), true);
    BuilderManager::instance->set_isBuilding(BuilderManager::typeBuild::BUILD);
    _lastKeyStates[GLFW_KEY_F1] = GLFW_RELEASE;
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
    if (glfwGetKey(window, GLFW_KEY_F1) == GLFW_PRESS && _lastKeyStates[GLFW_KEY_F1] != GLFW_PRESS) {
        initHelp(map);
        _state = State::HELP;
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        sdf::Camera::instance->move(sdf::Camera::Direction::UP, renderer.getDeltaTime(), map.getSizeX(), map.getSizeY());
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        sdf::Camera::instance->move(sdf::Camera::Direction::DOWN, renderer.getDeltaTime(), map.getSizeX(), map.getSizeY());
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        sdf::Camera::instance->move(sdf::Camera::Direction::LEFT, renderer.getDeltaTime(), map.getSizeX(), map.getSizeY());
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        sdf::Camera::instance->move(sdf::Camera::Direction::RIGHT, renderer.getDeltaTime(), map.getSizeX(), map.getSizeY());
     glfwSetScrollCallback(window, sdf::Renderer::scroll_callback);
    _lastKeyStates[GLFW_KEY_F1] = glfwGetKey(window, GLFW_KEY_F1);
    BuilderManager::instance->updateKeyState(window, map);
}
