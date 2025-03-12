/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AEnemy
*/

#include "AEnemy.hpp"

void AEnemy::update(float deltaTime, MapGrid map)
{
    (void)deltaTime;
    (void)map;
}

std::shared_ptr<ITurret> AEnemy::getTurret() const
{
    return _turret;
}

void AEnemy::setTurret(std::shared_ptr<ITurret> turret)
{
    _turret = turret;
}

void AEnemy::takeDamage(float damage)
{
    _health -= damage;
}

float AEnemy::getHealth() const
{
    return _health;
}

float AEnemy::getMaxHealth() const
{
    return _maxHealth;
}

void AEnemy::setHealth(float health)
{
    _health = health;
}

void AEnemy::setMaxHealth(float maxHealth)
{
    _maxHealth = maxHealth;
}

void AEnemy::setSpeed(float speed)
{
    _speed = speed;
}

float AEnemy::getSpeed() const
{
    return _speed;
}

AEnemy::AEnemy(std::shared_ptr<ITurret> turret, float speed, float health)
{
    _turret = turret;
    _speed = speed;
    _health = health;
    _maxHealth = health;
    sdf::Texture textureError = sdf::Texture("Assets/Error.png");
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f), textureError);
}

AEnemy::AEnemy()
{
    _turret = nullptr;
    _speed = 0;
    _health = 0;
    _maxHealth = 0;
}
