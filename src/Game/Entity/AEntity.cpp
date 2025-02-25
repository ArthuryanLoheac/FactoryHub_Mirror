/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AEntity
*/

#include "AEntity.hpp"



AEntity::~AEntity()
{}

void AEntity::update(float deltaTime, MapGrid map)
{
    deltaTime = deltaTime;
    map = map;
}

std::pair<float, float> AEntity::getPositionPixel()
{
    return (_pos_pixel);
}

std::pair<std::size_t, std::size_t> AEntity::getPositionGrid()
{
    return (_pos_grid);
}
