/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AVein
*/

#include "AVein.hpp"

AVein::AVein(Item item)
    : _ressource(item)
{
    _isConstructible = true;
    _isBlocking = false;
}

Item AVein::getRessource() const
{
    return _ressource;
}

void AVein::setPosX(float posX)
{
    _posX = posX;
}

void AVein::setPosY(float posY)
{
    _posY = posY;
}

float AVein::getPosX() const
{
    return _posX;
}

float AVein::getPosY() const
{
    return _posY;
}

bool AVein::getIsConstructible() const
{
    return _isConstructible;
}

bool AVein::getIsBlocking() const
{
    return _isBlocking;
}
