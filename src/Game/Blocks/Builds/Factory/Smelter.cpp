/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Smelter
*/
#include "Smelter.hpp"

SmelterT1::SmelterT1() : AFactory()
{
    sdf::Texture textureSmelter = sdf::Texture("Assets/Smelter.png");
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f), textureSmelter);

    std::vector<Item> r_in1;
    r_in1.push_back(Item("CopperRaw"));
    _AcceptedItems.push_back(Item("CopperRaw"));
    std::vector<Item> r_out1;
    r_out1.push_back(Item("Copper_Wire"));
    Recette r_copper_wire(r_in1, r_out1, 2.f);

    std::vector<Item> r_in2;
    r_in2.push_back(Item("ZincRaw"));
    _AcceptedItems.push_back(Item("ZincRaw"));
    std::vector<Item> r_out2;
    r_out2.push_back(Item("Zinc_Plate"));
    Recette r_zinc_plate(r_in2, r_out2, 2.f);

    _Recettes.push_back(r_copper_wire);
    _Recettes.push_back(r_zinc_plate);
}
