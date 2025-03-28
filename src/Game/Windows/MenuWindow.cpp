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
    _startMenu = new sdf::UISprite(glm::vec3(0.0f, 0.0f, 80.0f),
        sdf::GetterTextures::instance->getTexture("StartMenu"));
    _loadingMenu = new sdf::UISprite(glm::vec3(0.0f, 0.0f, 80.0f),
        sdf::GetterTextures::instance->getTexture("LoadingMenu"));
    _startMenu->setSize(glm::vec2(1080.0f, 720.0f));
    _loadingMenu->setSize(glm::vec2(1080.0f, 720.0f));
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
        renderer.clear();
        _loadingMenu->draw(renderer);
        renderer.swapBuffers();
        _state = State::GAME;
        init(map);    
    }
}
