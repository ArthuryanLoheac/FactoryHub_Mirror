/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Enemy_Hth
*/
#pragma once
#include "AEnemy.hpp"

class Enemy_Hth : public AEntity
{
    public:
    protected:
        Enemy_Hth(std::shared_ptr<ITurret> turret, float speed, float health);
};

