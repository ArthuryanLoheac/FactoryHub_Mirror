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
        void init(MapGrid map);
        void draw(MapGrid map, sdf::Renderer &renderer);
        void update(MapGrid map, float deltaTime);
        void processInputs(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map);

        std::map<State, std::tuple< void(WindowsManager::*)(MapGrid map),// Init
                                    void(WindowsManager::*)(MapGrid map, sdf::Renderer &renderer),// Draw
                                    void(WindowsManager::*)(MapGrid map, float deltaTime),// Update
                                    void(WindowsManager::*)(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map) // ProcessInputs
                                >> _functs;
    private:
        State _state;
        sdf::Sprite *_startMenu;

        void initGame(MapGrid map);
        void drawGame(MapGrid map, sdf::Renderer &renderer);
        void updateGame(MapGrid map, float deltaTime);
        void processInputsGame(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map);

        void initMenu(MapGrid map);
        void drawMenu(MapGrid map, sdf::Renderer &renderer);
        void updateMenu(MapGrid map, float deltaTime);
        void processInputsMenu(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map);
};

