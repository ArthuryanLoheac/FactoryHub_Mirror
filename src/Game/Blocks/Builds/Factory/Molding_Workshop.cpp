/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Smelter
*/
#include "Molding_Workshop.hpp"

Molding_WorkshopT1::Molding_WorkshopT1() : AFactory()
{
    sdf::Texture textureMolding = sdf::Texture("Assets/Molding_Workshop.png");
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f), textureMolding);

    std::vector<Item> r_in1;
    r_in1.push_back(Item("CopperRaw"));
    _AcceptedItems.push_back(Item("CopperRaw"));
    std::vector<Item> r_out1;
    r_out1.push_back(Item("Copper_Balls"));
    Recette r_copper_balls(r_in1, r_out1, 2.f);

    _Recettes.push_back(r_copper_balls);
}
