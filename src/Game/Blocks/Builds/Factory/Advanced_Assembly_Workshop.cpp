/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Smelter
*/
#include "Advanced_Assembly_Workshop.hpp"
#include "GetterTextures.hpp"

Advanced_Assembly_Workshop::Advanced_Assembly_Workshop() : AFactory()
{
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("Advanced_Assembly_Workshop"), 0.0f);

    // Recette Radioactive_Ammo
    std::vector<Item> r_in1;
    r_in1.push_back(Item("Stabilized_Radioactive_Mater"));
    r_in1.push_back(Item("Gunpowder"));
    r_in1.push_back(Item("Reinforced_Socket"));
    std::vector<Item> r_out1;
    r_out1.push_back(Item("Radioactive_Ammo"));
    Recette r_Radioactive_Ammo(r_in1, r_out1, 15.f);

    _Recettes.push_back(r_Radioactive_Ammo);

    // Recette Plasma_Ammo
    std::vector<Item> r_in2;
    r_in2.push_back(Item("Condensed_Plasma"));
    r_in2.push_back(Item("Energy_Capacitor"));
    r_in2.push_back(Item("Conductive_Socket"));
    std::vector<Item> r_out2;
    r_out2.push_back(Item("Plasma_Ammo"));
    Recette r_Plasma_Ammo(r_in2, r_out2, 15.f);

    _Recettes.push_back(r_Plasma_Ammo);

    // Recette High_Power_EMP_Ammo
    std::vector<Item> r_in3;
    r_in3.push_back(Item("High_Power_EMP_Charge"));
    r_in3.push_back(Item("Energy_Capacitor"));
    r_in3.push_back(Item("Conductive_Socket"));
    std::vector<Item> r_out3;
    r_out3.push_back(Item("High_Power_EMP_Ammo"));
    Recette r_High_Power_EMP_Ammo(r_in3, r_out3, 15.f);

    _Recettes.push_back(r_High_Power_EMP_Ammo);
}
