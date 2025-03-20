/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Smelter
*/
#include "Assembly_Workshop.hpp"
#include "GetterTextures.hpp"

Assembly_Workshop::Assembly_Workshop() : AFactory()
{
    _cost = {{"Steel_BAR", 60}, {"Copper_Wire", 15}};
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 30.0f),
        sdf::GetterTextures::instance->getTexture("Assembly_Workshop"));

    // Recette ArmorPiercing_Ammo
    std::vector<Item> r_in1;
    r_in1.push_back(Item("Perforating_Projectile"));
    _AcceptedItems.push_back(Item("Perforating_Projectile"));
    r_in1.push_back(Item("Reinforced_Socket"));
    _AcceptedItems.push_back(Item("Reinforced_Socket"));
    std::vector<Item> r_out1;
    r_out1.push_back(Item("ArmorPiercing_Ammo"));
    Recette r_ArmorPiercing_Ammo(r_in1, r_out1, 5.f);

    _Recettes.push_back(r_ArmorPiercing_Ammo);

    // Recette Electric_Pulse_Ammo
    std::vector<Item> r_in2;
    r_in2.push_back(Item("Energy_Capacitor"));
    _AcceptedItems.push_back(Item("Energy_Capacitor"));
    r_in2.push_back(Item("Reinforced_Socket"));
    _AcceptedItems.push_back(Item("Reinforced_Socket"));
    std::vector<Item> r_out2;
    r_out2.push_back(Item("Electric_Pulse_Ammo"));
    Recette r_Electric_Pulse_Ammo(r_in2, r_out2, 5.f);

    _Recettes.push_back(r_Electric_Pulse_Ammo);

    // Recette Rubber_Balls
    std::vector<Item> r_in3;
    r_in3.push_back(Item("Rubber"));
    _AcceptedItems.push_back(Item("Rubber"));
    r_in3.push_back(Item("Reinforced_Socket"));
    _AcceptedItems.push_back(Item("Reinforced_Socket"));
    std::vector<Item> r_out3;
    r_out3.push_back(Item("Rubber_Balls"));
    Recette r_Rubber_Balls(r_in3, r_out3, 5.f);

    _Recettes.push_back(r_Rubber_Balls);
}
