/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Smelter
*/
#include "Chemical_Plant.hpp"

Chemical_PlantT1::Chemical_PlantT1() : AFactory()
{
    sdf::Texture textureChemical = sdf::Texture("Assets/Chemical_Plant.png");
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f), textureChemical);

    std::vector<Item> r_in1;
    r_in1.push_back(Item("SaltpeterRaw"));
    _AcceptedItems.push_back(Item("SaltpeterRaw"));
    std::vector<Item> r_out1;
    r_out1.push_back(Item("Black_Powder"));
    Recette r_black_powder(r_in1, r_out1, 2.f);

    _Recettes.push_back(r_black_powder);
}
