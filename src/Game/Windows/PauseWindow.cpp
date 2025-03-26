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
    _spritesQuit.push_back(new sdf::UISprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("Quit")));
    _spritesQuit.push_back(new sdf::UISprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("QuitHover")));
    _spritesQuit.push_back(new sdf::UISprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("QuitClicked")));
    for (auto &sprite : _spritesQuit) {
        sprite->setSize(glm::vec2(300, 100));
        sprite->setPosition(glm::vec2(390, 500));
    }
}

void WindowsManager::drawPause(MapGrid map, sdf::Renderer &renderer)
{
    _spritesQuit[stateQuit]->draw(renderer);
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

    if (mouseInButton(window, _spritesQuit[stateQuit])) {
        stateQuit = ButtonState::HOVER;
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
            stateQuit = ButtonState::CLICKED;
        else if (lastButton == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);
        lastButton = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1);
    } else {
        stateQuit = ButtonState::NORMAL;
        lastButton = GLFW_RELEASE;
    }
}
