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
    _cost = {{"UraniumRaw", 220}, {"Reinforced_Brass", 100}, {"Steel_BAR", 50}, {"Black_Powder", 40}, {"Gunpowder", 30}};

    std::vector<Item> r_in1;
    r_in1.push_back(Item("UraniunRaw"));
    _AcceptedItems.push_back(Item("UraniunRaw"));
    r_in1.push_back(Item("WaterRaw"));
    _AcceptedItems.push_back(Item("WaterRaw"));
    r_in1.push_back(Item("Steel_BAR"));
    _AcceptedItems.push_back(Item("Steel_BAR"));
    std::vector<Item> r_out1;
    r_out1.push_back(Item("Stabilized_Radioactive_Mater"));
    Recette r_Stabilized_Radioactive_Mater(r_in1, r_out1, 15.f);

    _Recettes.push_back(r_Stabilized_Radioactive_Mater);
}
