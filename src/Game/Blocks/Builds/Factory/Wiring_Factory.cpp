/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Smelter
*/
#include "Wiring_Factory.hpp"

Wiring_Factory::Wiring_Factory() : AFactory()
{
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("Wiring_Factory"), 0.0f);

    // Recette Conductive_Socket
    std::vector<Item> r_in1;
    r_in1.push_back(Item("Energy_Capacitor"));
    _AcceptedItems.push_back(Item("Energy_Capacitor"));
    r_in1.push_back(Item("Reinforced_Socket"));
    _AcceptedItems.push_back(Item("Reinforced_Socket"));
    r_in1.push_back(Item("CopperRaw"));
    _AcceptedItems.push_back(Item("CopperRaw"));
    std::vector<Item> r_out1;
    r_out1.push_back(Item("Conductive_Socket"));
    Recette r_Conductive_Socket(r_in1, r_out1, 15.f);

    _Recettes.push_back(r_Conductive_Socket);
}
