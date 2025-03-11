/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Smelter
*/
#include "Arthuryan_Module.hpp"
#include "GetterTextures.hpp"

Arthuryan_Module::Arthuryan_Module() : AFactory()
{
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("Arthuryan_Module"), 0.0f);

    std::vector<Item> r_in1;
    r_in1.push_back(Item("Gunpowder"));
    r_in1.push_back(Item("WaterRaw"));
    r_in1.push_back(Item("Reinforced_Brass"));  
    std::vector<Item> r_out1;
    r_out1.push_back(Item("Condensed_Plasma"));
    Recette r_Condensed_Plasma(r_in1, r_out1, 15.f);

    _Recettes.push_back(r_Condensed_Plasma);
}
