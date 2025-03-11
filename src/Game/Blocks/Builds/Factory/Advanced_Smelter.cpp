/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Smelter
*/
#include "Advanced_Smelter.hpp"
#include "GetterTextures.hpp"

Advanced_Smelter::Advanced_Smelter() : AFactory()
{
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("Advanced_Smelter"), 0.0f);

    std::vector<Item> r_in1;
    r_in1.push_back(Item("CopperRaw"));
    _AcceptedItems.push_back(Item("CopperRaw"));
    r_in1.push_back(Item("ZincRaw")); 
    _AcceptedItems.push_back(Item("ZincRaw"));
    std::vector<Item> r_out1;
    r_out1.push_back(Item("Reinforced_Brass"));
    Recette r_Reinforced_Brass(r_in1, r_out1, 5.f);

    _Recettes.push_back(r_Reinforced_Brass);
}
