#include "BuilderManager.hpp"
#include <Tapis.hpp>
/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** BuilderManager
*/

BuilderManager *BuilderManager::instance = nullptr;

int BuilderManager::updateLastKeyState(int Key, GLFWwindow *window, int lastKey)
{
    if (glfwGetKey(window, Key) == GLFW_RELEASE)
        return GLFW_RELEASE;
    if (glfwGetKey(window, Key) == GLFW_PRESS)
        return GLFW_PRESS;
    return lastKey;
}

int BuilderManager::updateLastMouseState(int Key, GLFWwindow *window, int lastKey)
{
    if (glfwGetMouseButton(window, Key) == GLFW_RELEASE)
        return GLFW_RELEASE;
    if (glfwGetMouseButton(window, Key) == GLFW_PRESS)
        return GLFW_PRESS;
    return lastKey;
}

static bool isKeyClicked(GLFWwindow *window, int key, int lastKeyState)
{
    return glfwGetKey(window, key) == GLFW_RELEASE && lastKeyState == GLFW_PRESS;
}

static bool isMouseClicked(GLFWwindow *window, int key, int lastKeyState)
{
    return glfwGetMouseButton(window, key) == GLFW_RELEASE && lastKeyState == GLFW_PRESS;
}

void BuilderManager::updateKeyState(GLFWwindow *window, MapGrid &map)
{
    if (isKeyClicked(window, GLFW_KEY_B, _lastKeyStates[GLFW_KEY_B]))
        set_isBuilding(!get_isBuilding());
    if (isMouseClicked(window, GLFW_MOUSE_BUTTON_2, _lastKeyStates[GLFW_MOUSE_BUTTON_2]) && _isBuilding)
        set_isBuilding(false);
    if (isMouseClicked(window, GLFW_MOUSE_BUTTON_1, _lastKeyStates[GLFW_MOUSE_BUTTON_1]) && _isBuilding){
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        xpos = (int)-sdf::Camera::instance->getPosition().x;
        ypos = (int)-sdf::Camera::instance->getPosition().y;
        blockBuilding = std::make_shared<Tapis>();
        map.addBlock(blockBuilding, (int)xpos, (int)ypos);
    }
    _lastKeyStates[GLFW_KEY_B] = updateLastKeyState(GLFW_KEY_B,
        window, _lastKeyStates[GLFW_KEY_B]);
    _lastKeyStates[GLFW_MOUSE_BUTTON_2] = updateLastMouseState(GLFW_MOUSE_BUTTON_2,
        window, _lastKeyStates[GLFW_MOUSE_BUTTON_2]);
    _lastKeyStates[GLFW_MOUSE_BUTTON_1] = updateLastMouseState(GLFW_MOUSE_BUTTON_1,
        window, _lastKeyStates[GLFW_MOUSE_BUTTON_1]);
}

BuilderManager::BuilderManager()
{
    if (instance == nullptr)
        instance = this;
    _lastKeyStates[GLFW_KEY_B] = GLFW_RELEASE;
    _lastKeyStates[GLFW_MOUSE_BUTTON_2] = GLFW_RELEASE;
    _lastKeyStates[GLFW_MOUSE_BUTTON_1] = GLFW_RELEASE;
    blockBuilding = std::make_shared<Tapis>();
}

bool BuilderManager::get_isBuilding() const
{
    return _isBuilding;
}

void BuilderManager::set_isBuilding(bool isBuilding)
{
    _isBuilding = isBuilding;
    printf("Building is %d\n", _isBuilding);
}
