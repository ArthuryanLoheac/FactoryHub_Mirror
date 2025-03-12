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
        int lastKeyState = GLFW_RELEASE;
        bool _isBuilding = false;
        IBlock *blockBuilding;

    public:
        static BuilderManager *instance;

        int getLastKeyState() const;
        void updateKeyState(GLFWwindow *window);
        BuilderManager();
        bool get_isBuilding() const;
        void set_isBuilding(bool isBuilding);
};
