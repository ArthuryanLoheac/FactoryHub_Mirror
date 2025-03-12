/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** BuilderManager
*/

#pragma once
#include "MapGrid.hpp"

class BuilderManager
{
    private:
        int lastKeyStateB = GLFW_RELEASE;
        int lastKeyStateMouse1 = GLFW_RELEASE;
        bool _isBuilding = false;
        IBlock *blockBuilding;

    public:
        static BuilderManager *instance;

        int updateLastKeyState(int Key, GLFWwindow *window, int lastKey);
        int updateLastMouseState(int Key, GLFWwindow *window, int lastKey);
        void updateKeyState(GLFWwindow *window);
        BuilderManager();
        bool get_isBuilding() const;
        void set_isBuilding(bool isBuilding);
};
