/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** PauseWindow
*/

#include "UISprite.hpp"
#include "WindowsManager.hpp"

void WindowsManager::initButton(std::string name, std::vector<sdf::UISprite *> &sprites, glm::vec2 pos)
{
    sprites.push_back(new sdf::UISprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture(name)));
    sprites.push_back(new sdf::UISprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture(name + "Hover")));
    sprites.push_back(new sdf::UISprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture(name + "Clicked")));
    for (auto &sprite : sprites) {
        sprite->setSize(glm::vec2(300, 100));
        sprite->setPosition(pos);
    }
}

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
    initButton("Quit", _spritesQuit, glm::vec2(390, 500));
    initButton("Menu", _spritesMenu, glm::vec2(390, 300));
}

void WindowsManager::drawPause(MapGrid map, sdf::Renderer &renderer)
{
    _spritesQuit[stateQuit]->draw(renderer);
    _spritesMenu[stateMenu]->draw(renderer);
    _pauseMenu->draw(renderer);
}

void WindowsManager::updatePause(MapGrid map, float deltaTime)
{
}

bool mouseInButton(GLFWwindow *window, sdf::UISprite *sprite)
{
    double mouseX, mouseY;

    glfwGetCursorPos(window, &mouseX, &mouseY);
    if (mouseX >= sprite->getPosition().x && mouseX <= sprite->getPosition().x + sprite->getSize().x &&
        mouseY >= sprite->getPosition().y && mouseY <= sprite->getPosition().y + sprite->getSize().y)
        return true;
    return false;
}

bool WindowsManager::handleButton(GLFWwindow *window, sdf::UISprite *sprite, ButtonState &state)
{
    if (mouseInButton(window, sprite)) {
        state = ButtonState::HOVER;
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
            state = ButtonState::CLICKED;
        else if (lastButton == GLFW_PRESS)
            return true;
    } else {
        state = ButtonState::NORMAL;
    }
    return false;
}

void WindowsManager::processInputsPause(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map)
{
    double mouseX, mouseY;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS && _lastKeyStates[GLFW_KEY_ESCAPE] != GLFW_PRESS){
        sdf::Camera::instance->setRawZoom(_saveZoom);
        sdf::Camera::instance->setPosition(_savePos);
        _state = State::GAME;
    }
    glfwGetCursorPos(window, &mouseX, &mouseY);
    _lastKeyStates[GLFW_KEY_ESCAPE] = glfwGetKey(window, GLFW_KEY_ESCAPE);

    if (handleButton(window, _spritesMenu[stateMenu], stateMenu))
        _state = State::MENU;
    if (handleButton(window, _spritesQuit[stateQuit], stateQuit))
        glfwSetWindowShouldClose(window, GL_TRUE);
    lastButton = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1);
}
