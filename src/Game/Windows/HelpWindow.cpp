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

    _lastKeyStates[GLFW_KEY_F1] = GLFW_RELEASE;
    _lastKeyStates[GLFW_KEY_RIGHT] = GLFW_RELEASE;
    _lastKeyStates[GLFW_KEY_LEFT] = GLFW_RELEASE;
    _lastKeyStates[GLFW_KEY_ESCAPE] = GLFW_RELEASE;
    if (_spritesHelp.size() > 0)
        return;
    for (int i = 1; i <= 5; i++){
        _spritesHelp.push_back(new sdf::UISprite(glm::vec3(0.0f, 0.0f, 0.0f),
            sdf::GetterTextures::instance->getTexture("Help" + std::to_string(i))));
        _spritesHelp[i - 1]->setSize(glm::vec2(1080, 720));
    }
}

void WindowsManager::drawHelp(MapGrid map, sdf::Renderer &renderer)
{
    _spritesHelp[stateHelp]->draw(renderer);
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
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS && _lastKeyStates[GLFW_KEY_ESCAPE] != GLFW_PRESS) {
        _state = State::GAME;
        sdf::Camera::instance->setRawZoom(_saveZoom);
        sdf::Camera::instance->setPosition(_savePos);
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS && _lastKeyStates[GLFW_KEY_RIGHT] != GLFW_PRESS) {
        stateHelp++;
        if (stateHelp >= _spritesHelp.size())
            stateHelp = _spritesHelp.size() - 1;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS && _lastKeyStates[GLFW_KEY_LEFT] != GLFW_PRESS) {
        stateHelp--;
        if (stateHelp < 0)
            stateHelp = 0;
    }
    _lastKeyStates[GLFW_KEY_F1] = glfwGetKey(window, GLFW_KEY_F1);
    _lastKeyStates[GLFW_KEY_RIGHT] = glfwGetKey(window, GLFW_KEY_RIGHT);
    _lastKeyStates[GLFW_KEY_LEFT] = glfwGetKey(window, GLFW_KEY_LEFT);
    _lastKeyStates[GLFW_KEY_ESCAPE] = glfwGetKey(window, GLFW_KEY_ESCAPE);
}
