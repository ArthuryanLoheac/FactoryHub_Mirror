/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** PauseWindow
*/

#include "UISprite.hpp"
#include "WindowsManager.hpp"

void WindowsManager::initPause(MapGrid &map)
{
    _savePos = sdf::Camera::instance->getPosition();
    _saveZoom = sdf::Camera::instance->getZoom();
    sdf::Camera::instance->setRawZoom(14.f);
    sdf::Camera::instance->setPosition(glm::vec2(0, 0));

    _pauseMenu = new sdf::UISprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("PauseUI"));
    _pauseMenu->setSize(glm::vec2(1080, 720));
    _lastKeyStates[GLFW_KEY_ESCAPE] = GLFW_RELEASE;
}

void WindowsManager::drawPause(MapGrid map, sdf::Renderer &renderer)
{
    _pauseMenu->draw(renderer);
}

void WindowsManager::updatePause(MapGrid map, float deltaTime)
{
}

void WindowsManager::processInputsPause(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS && _lastKeyStates[GLFW_KEY_ESCAPE] != GLFW_PRESS){
        sdf::Camera::instance->setRawZoom(_saveZoom);
        sdf::Camera::instance->setPosition(_savePos);
        _state = State::GAME;
    }
    _lastKeyStates[GLFW_KEY_ESCAPE] = glfwGetKey(window, GLFW_KEY_ESCAPE);
}
