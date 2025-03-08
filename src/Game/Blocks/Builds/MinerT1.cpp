/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** MinerT1
*/
#include "MinerT1.hpp"

MinerT1::MinerT1() : AMiner()
{
    sdf::Texture textureMiner = sdf::Texture("Assets/Miner.png");
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f), textureMiner);
    _speedMining = 1;
}