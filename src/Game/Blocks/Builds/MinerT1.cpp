/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** MinerT1
*/
#include "MinerT1.hpp"

MinerT1::MinerT1() : AMiner()
{
    _sprite = new sdf::Sprite(glm::vec3(0, 0, 30),
        sdf::GetterTextures::instance->getTexture("MinerT1"));
    _speedMining = 2.5f;
    _cost = {{"SteelRaw", 10}};
}
