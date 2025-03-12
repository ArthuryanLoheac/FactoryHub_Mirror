#include "BuilderManager.hpp"
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

void BuilderManager::updateKeyState(GLFWwindow *window)
{
    if (isKeyClicked(window, GLFW_KEY_B, lastKeyStateB))
        set_isBuilding(!get_isBuilding());
    if (isMouseClicked(window, GLFW_MOUSE_BUTTON_2, lastKeyStateMouse1) && _isBuilding)
        set_isBuilding(false);
    lastKeyStateB = updateLastKeyState(GLFW_KEY_B, window, lastKeyStateB);
    lastKeyStateMouse1 = updateLastMouseState(GLFW_MOUSE_BUTTON_2, window, lastKeyStateMouse1);
}

BuilderManager::BuilderManager()
{
    if (instance == nullptr)
        instance = this;
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
