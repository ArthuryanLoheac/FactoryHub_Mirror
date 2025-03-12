/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Unlockable
*/

#pragma once
#include <vector>
#include <string>
#include <algorithm>

class Unlockable
{
    public:
        Unlockable();
        ~Unlockable();

        bool isUnlocked(std::string building);

        void unlockAdvanced_Assembly_Workshop();
        void unlockAdvanced_Smelter();
        void unlockAssembly_Workshop();
        void unlockCapacitor_Factory();
        void unlockChemical_Plant();
        void unlockCutting_Machine();
        void unlockFoundry();
        void unlockHigh_Voltage_Generator();
        void unlockMolding_Workshop();
        void unlockNuclear_Refinery();
        void unlockSmelter();
        void unlockWiring_Factory();

        void unlockAuto_Turret();
        void unlockPump_Turret();
        void unlockGatling_Turret();
        void unlockExplosive_Turret();
        void unlockEclipse_Turret();
        void unlockBurst_Turret();
        void unlockSniper_Turret();

        void unlockTreadmill_T2();
        void unlockTreadmill_T3();

        void unlockMiner_T2();
        void unlockMiner_T3();

        static Unlockable *instance;
    private:
    std::vector<std::string> _unlockedBuild;      
};


////Unlocked at the start
//
//tapis = Treadmill_T1
//mineur t1 = Miner_T1
//tourelle = Improvised_Turret
//base = Base
//
////FACTORY////
//
//Advanced_Assembly_Workshop
//Advanced_Smelter
//Assembly_Workshop
//Capacitor_Factory
//Chemical_Plant
//Cutting_Machine
//Foundry
//High_Voltage_Generator or Arthuryan_Module
//Molding_Workshop
//Nuclear_Refinery
//Smelter
//Wiring_Factory
//
////TURRET////
//
//Improvised_Turret --> Unlocked at the start
//Auto_Turret
//Pump_Turret  --> Tourelle à cartouche
//Gatling_Turret  --> Tourelle à chaine
//Explosive_Turret
//Eclipse_Turret
//Burst_Turret  --> Tourelle à rafale
//Sniper_Turret
//
////TREADMILL (Tapis) ////
//
//Treadmill_T1 --> Unlocked at the start
//Treadmill_T2
//Treadmill_T3
//
////Miner////
//
//Miner_T1 --> Unlocked at the start
//Miner_T2
//Miner_T3
//