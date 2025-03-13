/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** WindowsManager
*/

#pragma once
#include <vector>
#include <functional>
#include <map>
#include "MapGrid.hpp"
#include "BuilderManager.hpp"
#include "GetterTextures.hpp"

class WindowsManager
{
    public:
        enum class State {
            MENU,
            GAME
        };
    
        WindowsManager();
        void draw(MapGrid map, sdf::Renderer &renderer);
        void update(MapGrid map, sdf::Renderer &renderer);
        void processInputs(GLFWwindow *window, MapGrid &map);

        std::map<State, std::tuple< void(WindowsManager::*)(MapGrid map, sdf::Renderer &renderer),// Draw
                                    void(WindowsManager::*)(MapGrid map, sdf::Renderer &renderer),// Update
                                    void(WindowsManager::*)(GLFWwindow *window, MapGrid &map) // ProcessInputs
                                >> _functs;
    private:
        State _state;
        sdf::Sprite *_startMenu;

        void drawGame(MapGrid map, sdf::Renderer &renderer);
        void updateGame(MapGrid map, sdf::Renderer &renderer);
        void processInputsGame(GLFWwindow *window, MapGrid &map);

        void drawMenu(MapGrid map, sdf::Renderer &renderer);
        void updateMenu(MapGrid map, sdf::Renderer &renderer);
        void processInputsMenu(GLFWwindow *window, MapGrid &map);
};

