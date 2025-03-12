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

void Unlockable::unlock_Advanced_Assembly_Workshop()
{
    _unlockedBuild.push_back("Advanced_Assembly_Workshop");
}

void Unlockable::unlock_Advanced_Smelter()
{
    _unlockedBuild.push_back("Advanced_Smelter");
}

void Unlockable::unlock_Assembly_Workshop()
{
    _unlockedBuild.push_back("Assembly_Workshop");
}

void Unlockable::unlock_Capacitor_Factory()
{
    _unlockedBuild.push_back("Capacitor_Factory");
}

void Unlockable::unlock_Chemical_Plant()
{
    _unlockedBuild.push_back("Chemical_Plant");
}

void Unlockable::unlock_Cutting_Machine()
{
    _unlockedBuild.push_back("Cutting_Machine");
}

void Unlockable::unlock_Foundry()
{
    _unlockedBuild.push_back("Foundry");
}

void Unlockable::unlock_High_Voltage_Generator()
{
    _unlockedBuild.push_back("High_Voltage_Generator");
}

void Unlockable::unlock_Molding_Workshop()
{
    _unlockedBuild.push_back("Molding_Workshop");
}

void Unlockable::unlock_Nuclear_Refinery()
{
    _unlockedBuild.push_back("Nuclear_Refinery");
}

void Unlockable::unlock_Smelter()
{
    _unlockedBuild.push_back("Smelter");
}

void Unlockable::unlock_Wiring_Factory()
{
    _unlockedBuild.push_back("Wiring_Factory");
}

void Unlockable::unlock_Auto_Turret()
{
    _unlockedBuild.push_back("Auto_Turret");
}

void Unlockable::unlock_Pump_Turret()
{
    _unlockedBuild.push_back("Pump_Turret");
}

void Unlockable::unlock_Gatling_Turret()
{
    _unlockedBuild.push_back("Gatling_Turret");
}

void Unlockable::unlock_Explosive_Turret()
{
    _unlockedBuild.push_back("Explosive_Turret");
}

void Unlockable::unlock_Eclipse_Turret()
{
    _unlockedBuild.push_back("Eclipse_Turret");
}

void Unlockable::unlock_Burst_Turret()
{
    _unlockedBuild.push_back("Burst_Turret");
}

void Unlockable::unlock_Sniper_Turret()
{
    _unlockedBuild.push_back("Sniper_Turret");
}

void Unlockable::unlock_Treadmill_T2()
{
    _unlockedBuild.push_back("Treadmill_T2");
}

void Unlockable::unlock_Treadmill_T3()
{
    _unlockedBuild.push_back("Treadmill_T3");
}

void Unlockable::unlock_Miner_T2()
{
    _unlockedBuild.push_back("Miner_T2");
}

void Unlockable::unlock_Miner_T3()
{
    _unlockedBuild.push_back("Miner_T3");
}
