/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AEnemy
*/
#pragma once
#include "AEntity.hpp"
#include "ITurret.hpp"
#include <memory>

class AEnemy : public AEntity
{
    public:
        void update(float deltaTime, MapGrid map) override;
        std::shared_ptr<ITurret> getTurret() const;
        void setTurret(std::shared_ptr<ITurret> turret);
        void takeDamage(float damage);
        float getHealth() const;
        float getMaxHealth() const;
        void setHealth(float health);
        void setMaxHealth(float maxHealth);
        void setSpeed(float speed);
        float getSpeed() const;
    private:
        std::shared_ptr<ITurret> _turret;
        float _speed;
        float _health;
        float _maxHealth;
        AEnemy(std::shared_ptr<ITurret> turret, float speed, float health);
        AEnemy();
};

