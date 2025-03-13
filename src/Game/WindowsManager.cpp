/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** WindowsManager
*/

#include "WindowsManager.hpp"

WindowsManager::WindowsManager()
{
    _startMenu = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("StartMenu"));
    _state = State::MENU;
    _functs[State::GAME] = std::make_tuple( &WindowsManager::drawGame,
                                            &WindowsManager::updateGame,
                                            &WindowsManager::processInputsGame);
    _functs[State::MENU] = std::make_tuple( &WindowsManager::drawMenu,
                                            &WindowsManager::updateMenu,
                                            &WindowsManager::processInputsMenu);
}

void WindowsManager::draw(MapGrid map, sdf::Renderer &renderer)
{
    (this->*std::get<0>(_functs[_state]))(map, renderer);
}

void WindowsManager::update(MapGrid map, sdf::Renderer &renderer)
{
    (this->*std::get<1>(_functs[_state]))(map, renderer);
}

void WindowsManager::processInputs(GLFWwindow *window, MapGrid &map)
{
    (this->*std::get<2>(_functs[_state]))(window, map);
}
