/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Unlockable
*/

#include "Unlockable.hpp"

Unlockable *Unlockable::instance = nullptr;

Unlockable::Unlockable(/* args */)
{
    if (instance == nullptr)
        instance = this;
    else
        return;
    _unlockedBuild.push_back("treadmill");
    _unlockedBuild.push_back("MinerT1");
    _unlockedBuild.push_back("Turret");
    _unlockedBuild.push_back("Base");
}

Unlockable::~Unlockable()
{
}
