/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** MenuWindow
*/

#include "UISprite.hpp"
#include "WindowsManager.hpp"

void WindowsManager::initMenu(MapGrid &map)
{
    _startMenu = new sdf::UISprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("StartMenu"));
    sdf::Camera::instance->setRawZoom(14.f);
}

void WindowsManager::drawMenu(MapGrid map, sdf::Renderer &renderer)
{
    _startMenu->draw(renderer);
}

void WindowsManager::updateMenu(MapGrid map, float deltaTime)
{
}

void WindowsManager::processInputsMenu(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS){
        _state = State::GAME;
        init(map);    
    }
}
