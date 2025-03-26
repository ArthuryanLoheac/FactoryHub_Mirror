/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** WindowsManager
*/

#include "WindowsManager.hpp"

WindowsManager::WindowsManager()
{
    _state = State::MENU;
    _functs[State::GAME] = std::make_tuple( &WindowsManager::initGame,
                                            &WindowsManager::drawGame,
                                            &WindowsManager::updateGame,
                                            &WindowsManager::processInputsGame);
    _functs[State::MENU] = std::make_tuple( &WindowsManager::initMenu,
                                            &WindowsManager::drawMenu,
                                            &WindowsManager::updateMenu,
                                            &WindowsManager::processInputsMenu);
    _functs[State::HELP] = std::make_tuple( &WindowsManager::initHelp,
                                            &WindowsManager::drawHelp,
                                            &WindowsManager::updateHelp,
                                            &WindowsManager::processInputsHelp);
    _functs[State::PAUSE] = std::make_tuple(&WindowsManager::initPause,
                                            &WindowsManager::drawPause,
                                            &WindowsManager::updatePause,
                                            &WindowsManager::processInputsPause);
}

void WindowsManager::init(MapGrid &map)
{
    (this->*std::get<0>(_functs[_state]))(map);
}

void WindowsManager::draw(MapGrid map, sdf::Renderer &renderer)
{
    (this->*std::get<1>(_functs[_state]))(map, renderer);
}

void WindowsManager::update(MapGrid map, float deltaTime)
{
    (this->*std::get<2>(_functs[_state]))(map, deltaTime);
}

void WindowsManager::processInputs(GLFWwindow *window, sdf::Renderer &renderer, MapGrid &map)
{
    (this->*std::get<3>(_functs[_state]))(window, renderer, map);
}
