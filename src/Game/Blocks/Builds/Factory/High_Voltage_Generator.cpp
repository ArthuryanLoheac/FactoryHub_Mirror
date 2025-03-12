/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Smelter
*/
#include "High_Voltage_Generator.hpp"
#include "GetterTextures.hpp"

High_Voltage_Generator::High_Voltage_Generator() : AFactory()
{
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("High_Voltage_Generator"), 0.0f);

    // Recette Condensed_Plasma
    std::vector<Item> r_in1;
    r_in1.push_back(Item("Gunpowder"));
    _AcceptedItems.push_back(Item("Gunpowder"));
    r_in1.push_back(Item("WaterRaw"));
    _AcceptedItems.push_back(Item("WaterRaw"));
    r_in1.push_back(Item("Reinforced_Brass")); 
    _AcceptedItems.push_back(Item("Reinforced_Brass")); 
    std::vector<Item> r_out1;
    r_out1.push_back(Item("Condensed_Plasma"));
    Recette r_Condensed_Plasma(r_in1, r_out1, 15.f);

    _Recettes.push_back(r_Condensed_Plasma);

    // Recette High_Power_EMP_Charge
    std::vector<Item> r_in2;
    r_in2.push_back(Item("Energy_Capacitor"));
    _AcceptedItems.push_back(Item("Energy_Capacitor"));
    r_in2.push_back(Item("WaterRaw"));
    _AcceptedItems.push_back(Item("WaterRaw"));
    r_in2.push_back(Item("Reinforced_Brass"));
    _AcceptedItems.push_back(Item("Reinforced_Brass"));
    std::vector<Item> r_out2;
    r_out2.push_back(Item("High_Power_EMP_Charge"));
    Recette r_High_Power_EMP_Charge(r_in2, r_out2, 15.f);

    _Recettes.push_back(r_High_Power_EMP_Charge);
}
