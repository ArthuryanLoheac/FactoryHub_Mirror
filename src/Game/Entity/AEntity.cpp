/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AEntity
*/

#include "Entity/AEntity.hpp"



AEntity::~AEntity()
{}

void AEntity::update(float deltaTime)
{
    deltaTime = deltaTime;
}

std::pair<float, float> AEntity::getPositionPixel()
{
    return (_pos_pixel);
}

std::pair<std::size_t, std::size_t> AEntity::getPositionGrid()
{
    return (_pos_grid);
}
