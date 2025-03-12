/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Enemy_Hth
*/

#include "Enemy_Hth.hpp"

Enemy_Hth::Enemy_Hth(std::shared_ptr<ITurret> turret, float speed, float health)
    :AEnemy(turret, speed, health)
{
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("Enemy_HtH"), 0.0f);;
}
