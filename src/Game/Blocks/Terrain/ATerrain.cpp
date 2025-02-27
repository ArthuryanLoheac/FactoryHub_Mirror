/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ATerrain
*/

#include "ATerrain.hpp"

ATerrain::ATerrain()
{
    _isConstructible = false;
    _isBlocking = true;
    sdf::Texture textureStone = sdf::Texture("Assets/Stone.png");
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f), textureStone);
}

bool ATerrain::getIsConstructible() const
{
    return _isConstructible;
}

bool ATerrain::getIsBlocking() const
{
    return _isBlocking;
}

void ATerrain::setPosX(float posX)
{
    _pos.first = posX;
    _sprite->setPosition(glm::vec3(_pos.first, _pos.second, 0.0f));
}

void ATerrain::setPosY(float posY)
{
    _pos.second = posY;
    _sprite->setPosition(glm::vec3(_pos.first, _pos.second, 0.0f));
}

float ATerrain::getPosX() const
{
    return _pos.first;
}

float ATerrain::getPosY() const
{
    return _pos.second;
}

void ATerrain::setPosXGrid(size_t posX)
{
    posXGrid = posX;
}

void ATerrain::setPosYGrid(size_t posY)
{
    posYGrid = posY;
}

size_t ATerrain::getPosXGrid() const
{
    return posXGrid;
}

size_t ATerrain::getPosYGrid() const
{
    return posYGrid;
}

void ATerrain::update(float deltaTime, MapGrid map)
{
    (void)deltaTime;
    (void)map;
}

void ATerrain::draw(sdf::Renderer &renderer)
{
    _sprite->draw(renderer);
}
