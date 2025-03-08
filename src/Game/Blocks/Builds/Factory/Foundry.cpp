/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Smelter
*/
#include "Foundry.hpp"

FoundryT1::FoundryT1() : AFactory()
{
    sdf::Texture textureFoundry = sdf::Texture("Assets/Foundry.png");
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f), textureFoundry);

    std::vector<Item> r_in1;
    r_in1.push_back(Item("SteelRaw"));
    std::vector<Item> r_out1;
    r_out1.push_back(Item("Steel_BAR"));
    Recette r_steel_bar(r_in1, r_out1, 2.f);

    _Recettes.push_back(r_steel_bar);
}
