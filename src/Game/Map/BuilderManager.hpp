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
        std::map<int, int> _lastKeyStates;
        bool _isBuilding = false;
        std::shared_ptr<IBlock> blockBuilding;

    public:
        static BuilderManager *instance;

        int updateLastKeyState(int Key, GLFWwindow *window, int lastKey);
        int updateLastMouseState(int Key, GLFWwindow *window, int lastKey);
        void updateKeyState(GLFWwindow *window, MapGrid &map);
        BuilderManager();
        bool get_isBuilding() const;
        void set_isBuilding(bool isBuilding);
        void buildBlock(GLFWwindow *window, MapGrid &map);
};
