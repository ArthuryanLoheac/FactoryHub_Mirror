/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Unlockable
*/

#include "Unlockable.hpp"
#include <iostream>

Unlockable *Unlockable::instance = nullptr;

Unlockable::Unlockable()
{
    std::vector<std::string> list;
    _unlockedBuild = list; 
    _unlockedBuild.push_back("Conveyer_belt");
    _unlockedBuild.push_back("MinerT1");
    _unlockedBuild.push_back("Turret");
    _unlockedBuild.push_back("Base");
    if (instance == nullptr)
        instance = this;
}

Unlockable::~Unlockable()
{
}

bool Unlockable::isUnlocked(std::string building)
{
    int i = 0;

    while (i < _unlockedBuild.size()){
        if (_unlockedBuild[i] == building){
            return (true);
        }
        i += 1;
    }
    return (false);
}

void Unlockable::unlockAdvanced_Assembly_Workshop()
{
    _unlockedBuild.push_back("Advanced_Assembly_Workshop");
}

void Unlockable::unlockAdvanced_Smelter()
{
    _unlockedBuild.push_back("Advanced_Smelter");
}

void Unlockable::unlockAssembly_Workshop()
{
    _unlockedBuild.push_back("Assembly_Workshop");
}

void Unlockable::unlockCapacitor_Factory()
{
    _unlockedBuild.push_back("Capacitor_Factory");
}

void Unlockable::unlockChemical_Plant()
{
    _unlockedBuild.push_back("Chemical_Plant");
}

void Unlockable::unlockCutting_Machine()
{
    _unlockedBuild.push_back("Cutting_Machine");
}

void Unlockable::unlockFoundry()
{
    _unlockedBuild.push_back("Foundry");
}

void Unlockable::unlockHigh_Voltage_Generator()
{
    _unlockedBuild.push_back("High_Voltage_Generator");
    _unlockedBuild.push_back("Arthuryan_Module");
}

void Unlockable::unlockMolding_Workshop()
{
    _unlockedBuild.push_back("Molding_Workshop");
}

void Unlockable::unlockNuclear_Refinery()
{
    _unlockedBuild.push_back("Nuclear_Refinery");
}

void Unlockable::unlockSmelter()
{
    _unlockedBuild.push_back("Smelter");
}

void Unlockable::unlockWiring_Factory()
{
    _unlockedBuild.push_back("Wiring_Factory");
}

void Unlockable::unlockAuto_Turret()
{
    _unlockedBuild.push_back("Auto_Turret");
}

void Unlockable::unlockPump_Turret()
{
    _unlockedBuild.push_back("Pump_Turret");
}

void Unlockable::unlockGatling_Turret()
{
    _unlockedBuild.push_back("Gatling_Turret");
}

void Unlockable::unlockExplosive_Turret()
{
    _unlockedBuild.push_back("Explosive_Turret");
}

void Unlockable::unlockEclipse_Turret()
{
    _unlockedBuild.push_back("Eclipse_Turret");
}

void Unlockable::unlockBurst_Turret()
{
    _unlockedBuild.push_back("Burst_Turret");
}

void Unlockable::unlockSniper_Turret()
{
    _unlockedBuild.push_back("Sniper_Turret");
}

void Unlockable::unlockConveyer_belt_T2()
{
    _unlockedBuild.push_back("Conveyer_belt_T2");
}

void Unlockable::unlockConveyer_belt_T3()
{
    _unlockedBuild.push_back("Conveyer_belt_T3");
}

void Unlockable::unlockMiner_T2()
{
    _unlockedBuild.push_back("Miner_T2");
}

void Unlockable::unlockMiner_T3()
{
    _unlockedBuild.push_back("Miner_T3");
}
