/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ATurretAlly
*/

#pragma once
#include "ABuilds.hpp"
#include "ITurret.hpp"
#include <memory>

class ATurretAlly : public ABuilds
{
    public:
        void setTurret(std::shared_ptr<ITurret> turret);
        std::shared_ptr<ITurret> getTurret() const;
        bool addElement(Item item) override;
        void update(float deltaTime, MapGrid map) override;
    protected:
        ATurretAlly();

        std::shared_ptr<ITurret> _turret;
};

