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
#include "UISprite.hpp"

class WindowsManager
{
    public:
        enum ButtonState {
            NORMAL = 0,
            HOVER = 1,
            CLICKED = 2
        };

        enum class State {
            MENU,
            GAME,
            HELP,
            PAUSE,
        };
    
        WindowsManager();
        void init(MapGrid &map);
        void draw(MapGrid map, sdf::Renderer &renderer);
        void update(MapGrid map, float deltaTime);
        void processInputs(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map);

        std::map<State, std::tuple< void(WindowsManager::*)(MapGrid &map),// Init
                                    void(WindowsManager::*)(MapGrid map, sdf::Renderer &renderer),// Draw
                                    void(WindowsManager::*)(MapGrid map, float deltaTime),// Update
                                    void(WindowsManager::*)(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map) // ProcessInputs
                                >> _functs;
    private:
        State _state;
        sdf::Sprite *_startMenu;
        sdf::Sprite *_loadingMenu;

        void initGame(MapGrid &map);
        void drawGame(MapGrid map, sdf::Renderer &renderer);
        void updateGame(MapGrid map, float deltaTime);
        void processInputsGame(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map);

        void initMenu(MapGrid &map);
        void drawMenu(MapGrid map, sdf::Renderer &renderer);
        void updateMenu(MapGrid map, float deltaTime);
        void processInputsMenu(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map);

        void initHelp(MapGrid &map);
        void drawHelp(MapGrid map, sdf::Renderer &renderer);
        void updateHelp(MapGrid map, float deltaTime);
        void processInputsHelp(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map);

        std::vector<sdf::UISprite *> _spritesHelp;
        int stateHelp = 0;
        std::map<int, int> _lastKeyStates;
        float _saveZoom = 0;
        glm::vec2 _savePos = glm::vec2(0, 0);

        void initButton(std::string name, std::vector<sdf::UISprite *> &sprites, glm::vec2 pos);
        bool handleButton(GLFWwindow *window, sdf::UISprite *sprite, ButtonState &state);
        void initPause(MapGrid &map);
        void drawPause(MapGrid map, sdf::Renderer &renderer);
        void updatePause(MapGrid map, float deltaTime);
        void processInputsPause(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map);

        sdf::UISprite *_pauseMenu;
        std::vector<sdf::UISprite *> _spritesQuit;
        ButtonState stateQuit = ButtonState::NORMAL;
        std::vector<sdf::UISprite *> _spritesMenu;
        ButtonState stateMenu = ButtonState::NORMAL;
        int lastButton = GLFW_RELEASE;
};

