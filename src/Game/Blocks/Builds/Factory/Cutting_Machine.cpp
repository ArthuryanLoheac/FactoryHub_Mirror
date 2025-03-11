/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Smelter
*/
#include "Cutting_Machine.hpp"

Cutting_Machine::Cutting_Machine() : AFactory()
{
    sdf::Texture textureMolding = sdf::Texture("Assets/Cutting_Machine.png");
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f), textureMolding);

    //recette Steel_Darts
    std::vector<Item> r_in1;
    r_in1.push_back(Item("Steel_BAR"));
    std::vector<Item> r_out1;
    r_out1.push_back(Item("Steel_Darts"));
    Recette r_Steel_Darts(r_in1, r_out1, 2.f);

    _Recettes.push_back(r_Steel_Darts);
}
