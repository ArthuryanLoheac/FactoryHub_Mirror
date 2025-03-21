/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** HelpWindow
*/

#include "WindowsManager.hpp"
#include "Generation.hpp"
#include "Base.hpp"

void WindowsManager::initHelp(MapGrid &map)
{
    _savePos = sdf::Camera::instance->getPosition();
    _saveZoom = sdf::Camera::instance->getZoom();
    sdf::Camera::instance->setRawZoom(14.f);
    sdf::Camera::instance->setPosition(glm::vec2(0, 0));
    if (_spritesHelp.size() > 0)
        return;
    _spritesHelp.push_back(new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("Help1")));
}

void WindowsManager::drawHelp(MapGrid map, sdf::Renderer &renderer)
{
    _spritesHelp[0]->draw(renderer);
}

void WindowsManager::updateHelp(MapGrid map, float deltaTime)
{
}

void WindowsManager::processInputsHelp(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map)
{
    if (glfwGetKey(window, GLFW_KEY_F1) == GLFW_PRESS && _lastKeyStates[GLFW_KEY_F1] != GLFW_PRESS) {
        _state = State::GAME;
        sdf::Camera::instance->setRawZoom(_saveZoom);
        sdf::Camera::instance->setPosition(_savePos);
    }
    _lastKeyStates[GLFW_KEY_F1] = glfwGetKey(window, GLFW_KEY_F1);
}
