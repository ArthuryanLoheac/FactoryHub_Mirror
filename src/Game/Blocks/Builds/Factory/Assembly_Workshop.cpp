/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Smelter
*/
#include "Assembly_Workshop.hpp"
#include "GetterTextures.hpp"

Assembly_Workshop::Assembly_Workshop() : AFactory()
{
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("Assembly_Workshop"), 0.0f);

    std::vector<Item> r_in1;
    r_in1.push_back(Item("Perforating_Projectile"));
    r_in1.push_back(Item("Reinforced_Socket"));
    std::vector<Item> r_out1;
    r_out1.push_back(Item("ArmorPiercing_Ammo"));
    Recette r_ArmorPiercing_Ammo(r_in1, r_out1, 5.f);

    _Recettes.push_back(r_ArmorPiercing_Ammo);
}
