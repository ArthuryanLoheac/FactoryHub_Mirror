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
}

void ATerrain::setPosY(float posY)
{
    _pos.second = posY;
}

float ATerrain::getPosX() const
{
    return _pos.first;
}

float ATerrain::getPosY() const
{
    return _pos.second;
}

void ATerrain::update(float deltaTime, MapGrid map)
{
    (void)deltaTime;
    (void)map;
}
