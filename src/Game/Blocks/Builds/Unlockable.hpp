/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Unlockable
*/

#pragma once
#include <vector>
#include <string>

class Unlockable
{
    public:
        Unlockable();
        ~Unlockable();

        void unlock_Advanced_Assembly_Workshop();
        void unlock_Advanced_Smelter();
        void unlock_Assembly_Workshop();
        void unlock_Capacitor_Factory();
        void unlock_Chemical_Plant();
        void unlock_Cutting_Machine();
        void unlock_Foundry();
        void unlock_High_Voltage_Generator();
        void unlock_Molding_Workshop();
        void unlock_Nuclear_Refinery();
        void unlock_Smelter();
        void unlock_Wiring_Factory();

        void unlock_Auto_Turret();
        void unlock_Pump_Turret();
        void unlock_Gatling_Turret();
        void unlock_Explosive_Turret();
        void unlock_Eclipse_Turret();
        void unlock_Burst_Turret();
        void unlock_Sniper_Turret();

        void unlock_Treadmill_T2();
        void unlock_Treadmill_T3();

        void unlock_Miner_T2();
        void unlock_Miner_T3();

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
//High_Voltage_Generator
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