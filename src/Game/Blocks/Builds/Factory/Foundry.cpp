/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Smelter
*/
#include "Foundry.hpp"

FoundryT1::FoundryT1() : AFactory()
{
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("Foundry"), 0.0f);

    // Recette steel_bar
    std::vector<Item> r_in1;
    r_in1.push_back(Item("SteelRaw"));
    _AcceptedItems.push_back(Item("SteelRaw"));
    std::vector<Item> r_out1;
    r_out1.push_back(Item("Steel_BAR"));
    Recette r_steel_bar(r_in1, r_out1, 2.f);

    _Recettes.push_back(r_steel_bar);

    // Recette Reinforced_Socket
    std::vector<Item> r_in2;
    r_in2.push_back(Item("Reinforced_Brass"));
    _AcceptedItems.push_back(Item("Reinforced_Brass"));
    r_in2.push_back(Item("SteelRaw"));
    _AcceptedItems.push_back(Item("SteelRaw"));
    std::vector<Item> r_out2;
    r_out2.push_back(Item("Reinforced_Socket"));
    Recette r_Reinforced_Socket(r_in2, r_out2, 2.f);

    _Recettes.push_back(r_Reinforced_Socket);
}
