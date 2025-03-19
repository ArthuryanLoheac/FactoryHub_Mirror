/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Smelter
*/
#include "Capacitor_Factory.hpp"
#include "GetterTextures.hpp"

Capacitor_Factory::Capacitor_Factory() : AFactory()
{
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 30.0f),
        sdf::GetterTextures::instance->getTexture("Capacitor_Factory"));

    std::vector<Item> r_in1;
    r_in1.push_back(Item("CopperRaw"));
    _AcceptedItems.push_back(Item("CopperRaw"));
    r_in1.push_back(Item("ZincRaw")); 
    _AcceptedItems.push_back(Item("ZincRaw"));
    std::vector<Item> r_out1;
    r_out1.push_back(Item("Energy_Capacitor"));
    Recette r_Energy_Capacitor(r_in1, r_out1, 5.f);

    _Recettes.push_back(r_Energy_Capacitor);
}
