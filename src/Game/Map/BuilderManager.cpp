#include "BuilderManager.hpp"
/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** BuilderManager
*/

BuilderManager *BuilderManager::instance = nullptr;

int BuilderManager::getLastKeyState() const
{
    return lastKeyState;
}

void BuilderManager::updateKeyState(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_RELEASE && lastKeyState == GLFW_PRESS)
        set_isBuilding(!get_isBuilding());
    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_RELEASE)
        lastKeyState = GLFW_RELEASE;
    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
        lastKeyState = GLFW_PRESS;
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
