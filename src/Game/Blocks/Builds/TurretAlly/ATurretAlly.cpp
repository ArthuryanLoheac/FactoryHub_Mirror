/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ATurretAlly
*/

#include "ATurretAlly.hpp"

ATurretAlly::ATurretAlly()
{
    _MaxIn = 100;
    _MaxOut = 0;
}

void ATurretAlly::setTurret(std::shared_ptr<ITurret> turret)
{
    _turret = turret;
}

std::shared_ptr<ITurret> ATurretAlly::getTurret() const
{
    return _turret;
}

bool ATurretAlly::addElement(Item item)
{
    if (_turret->getAmmos().size() >= _turret->getMaxStock())
        return false;
    if (_AllItemAccepted == false) {
        for (Item &it: _AcceptedItems) {
            if (it.getName() == item.getName()) {
                _turret.get()->AddAmmo(item);
                return true;
            }
        }
        return false;
    }
    _turret.get()->AddAmmo(item);
    return true;
}

void ATurretAlly::update(float deltaTime, MapGrid map)
{
    _turret->update(deltaTime);
}