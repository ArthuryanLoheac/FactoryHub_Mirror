/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Base
*/

#include "Base.hpp"
#include "Unlockable.hpp"
#include <iostream>

Base::Base()
{
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 30.0f),
        sdf::GetterTextures::instance->getTexture("Base"), 0.0f);
    _AllItemAccepted = true;
    _noMax = true;
    _updatable = true;
    _items["SteelRaw"] = 100;
    _items["CopperRaw"] = 100;
    _items["CoalRaw"] = 0;
    _items["Steel_BAR"] = 0;
    _items["SaltpeterRaw"] = 0;
    _items["ZincRaw"] = 0;
    _items["Copper_Wire"] = 0;
    _items["Energy_Capacitor"] = 0;
    _items["UraniumRaw"] = 0;
    _items["Reinforced_Socket"] = 0;
    _items["Zinc_Plate"] = 0;
    _items["Rubber"] = 0;
    _items["WaterRaw"] = 0;
    _items["Reinforced_Brass"] = 0;
    _items["Copper_Balls"] = 0;
    _items["Black_Powder"] = 0;
    _items["Gunpowder"] = 0;
    //  DEVTOOL, START WITH ALL THE MATERIAL
    //_items["SteelRaw"] = 10000;
    //_items["CopperRaw"] = 10000;
    //_items["CoalRaw"] = 10000;
    //_items["Steel_BAR"] = 10000;
    //_items["SaltpeterRaw"] = 10000;
    //_items["ZincRaw"] = 10000;
    //_items["Copper_Wire"] = 10000;
    //_items["Energy_Capacitor"] = 10000;
    //_items["UraniumRaw"] = 10000;
    //_items["Reinforced_Socket"] = 10000;
    //_items["Zinc_Plate"] = 10000;
    //_items["Rubber"] = 10000;
    //_items["WaterRaw"] = 10000;
    //_items["Reinforced_Brass"] = 10000;
    //_items["Copper_Balls"] = 10000;
    //_items["Black_Powder"] = 10000;
    //_items["Gunpowder"] = 10000;
    setHp(1000);
}

void Base::update(float deltaTime, MapGrid map)
{
    (void)deltaTime;
    (void)map;
    unlockBuilds();
    // List all items in base for debug

    //printf("===== Base =====\n");
    //for (auto &item : _items)
    //    printf("%s: %d\n", item.first.c_str(), item.second);
}

bool Base::addElement(Item item)
{
    if (_items.find(item.getName()) == _items.end())
        _items[item.getName()] = 0;
    _items[item.getName()] += 1;
    return true;
}

void Base::unlockBuilds()
{
    if (Unlockable::instance->isUnlocked("Smelter") == false &&
        _items.at("CopperRaw") >= 200 && _items.at("CoalRaw") >= 200){
        std::cout << "Smelter unlocked" << std::endl;
        Unlockable::instance->unlockSmelter();
    }
    if (Unlockable::instance->isUnlocked("Advanced_Smelter") == false &&
        _items.at("Steel_BAR") >= 500 && _items.at("CoalRaw") >= 75){
        std::cout << "Advanced_Smelter unlocked" << std::endl;
        Unlockable::instance->unlockAdvanced_Smelter();
    }
    if (Unlockable::instance->isUnlocked("Foundry") == false &&
        _items.at("SteelRaw") >= 200 && _items.at("CoalRaw") >= 50){
        std::cout << "Foundry unlocked" << std::endl;
        Unlockable::instance->unlockFoundry();
    }
    if (Unlockable::instance->isUnlocked("Chemical_Plant") == false &&
        _items.at("WaterRaw") >= 125 && _items.at("SaltpeterRaw") >= 100){
        std::cout << "Chemical_Plant unlocked" << std::endl;
        Unlockable::instance->unlockChemical_Plant();
    }
    if (Unlockable::instance->isUnlocked("Molding_Workshop") == false &&
        _items.at("ZincRaw") >= 75 && _items.at("CopperRaw") >= 175){
        std::cout << "Molding_Workshop unlocked" << std::endl;
        Unlockable::instance->unlockMolding_Workshop();
    }
    if (Unlockable::instance->isUnlocked("Cutting_Machine") == false &
         _items.at("CopperRaw") >= 300){
        std::cout << "Cutting_Machine unlocked" << std::endl;
        Unlockable::instance->unlockCutting_Machine();
    }
    if (Unlockable::instance->isUnlocked("Assembly_Workshop") == false &&
        _items.at("Steel_BAR") >= 500 && _items.at("Copper_Wire") >= 75){
        std::cout << "Assembly_Workshop unlocked" << std::endl;
        Unlockable::instance->unlockAssembly_Workshop();
    }
    if (Unlockable::instance->isUnlocked("Advanced_Assembly_Workshop") == false &&
        _items.at("Reinforced_Socket") >= 200 && _items.at("Copper_Balls") >= 150){
        std::cout << "Advanced_Assembly_Workshop unlocked" << std::endl;
        Unlockable::instance->unlockAdvanced_Assembly_Workshop();
    }
    if (Unlockable::instance->isUnlocked("Capacitor_Factory") == false &&
        _items.at("Copper_Wire") >= 200 && _items.at("Zinc_Plate") >= 250){
        std::cout << "Capacitor_Factory unlocked" << std::endl;
        Unlockable::instance->unlockCapacitor_Factory();
    }
    if (Unlockable::instance->isUnlocked("Arthuryan_Module") == false &&
        _items.at("Copper_Wire") >= 250 && _items.at("Zinc_Plate") >= 500 &&
        _items.at("Energy_Capacitor") >= 375 && _items.at("Rubber") >= 1000){
        std::cout << "High voltage generator unlocked" << std::endl;
        Unlockable::instance->unlockHigh_Voltage_Generator();
    }
    if (Unlockable::instance->isUnlocked("Wiring_Factory") == false &&
        _items.at("Copper_Wire") >= 300 && _items.at("Steel_BAR") >= 200 &&
        _items.at("Zinc_Plate") >= 125){
        std::cout << "Wiring_Factory unlocked" << std::endl;
        Unlockable::instance->unlockWiring_Factory();
    }
    if (Unlockable::instance->isUnlocked("Nuclear_Refinery") == false &&
        _items.at("Gunpowder") >= 150 && _items.at("Black_Powder") >= 200 &&
        _items.at("Reinforced_Brass") >= 500 && _items.at("Steel_BAR") >= 250 &&
        _items.at("UraniumRaw") >= 1100){
        std::cout << "Nuclear_Refinery unlocked" << std::endl;
        Unlockable::instance->unlockNuclear_Refinery();
    }
}


////    COST TO UNLOCK    ////
//Smelter = CopperRaw 200 CoalRaw 75
//Advanced_Smelter = Steel_BAR 500 CoalRaw 75
//Foundry = SteelRaw 200 CoalRaw 50
//Chemical_Plant = WaterRaw 125 SaltpeterRaw 100
//Molding_Workshop = ZincRaw 75 CopperRaw 175
//Cutting_Machine = CopperRaw 300
//Assembly_Workshop = Steel_BAR 500 Copper_Wire 75
//Advanced_Assembly_Workshop = Reinforced_Socket 200 Copper_Balls 150
//Capacitor_Factory = Copper_Wire 200 Zinc_Plate 250
//High voltage capacitor = Copper_Wire 250 Zinc_Plate 500 Energy_Capacitor 375 Rubber 1000
//Wiring_Factory = Copper_Wire 300 Steel_BAR 200 Zinc_Plate 125
//Nuclear_Refinery = Gunpowder 150 Black_Powder 200 Reinforced_Brass 500 Steel_BAR 250 UraniumRaw 1100
