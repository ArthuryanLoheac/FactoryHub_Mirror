/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** MinerT1
*/
#include "MinerT1.hpp"

MinerT1::MinerT1() : AMiner()
{
    _sprite = new sdf::Sprite(glm::vec3(0, 0, 0),
        sdf::GetterTextures::instance->getTexture("MinerT1"));
    _speedMining = 0.5;
}
