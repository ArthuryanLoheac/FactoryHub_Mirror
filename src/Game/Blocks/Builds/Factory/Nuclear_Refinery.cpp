/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Smelter
*/
#include "Nuclear_Refinery.hpp"
#include "GetterTextures.hpp"

Nuclear_Refinery::Nuclear_Refinery() : AFactory()
{
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("Nuclear_Refinery"), 0.0f);

    std::vector<Item> r_in1;
    r_in1.push_back(Item("UraniunRaw"));
    r_in1.push_back(Item("WaterRaw"));
    r_in1.push_back(Item("Steel_BAR"));
    std::vector<Item> r_out1;
    r_out1.push_back(Item("Stabilized_Radioactive_Mater"));
    Recette r_Stabilized_Radioactive_Mater(r_in1, r_out1, 15.f);

    _Recettes.push_back(r_Stabilized_Radioactive_Mater);
}
