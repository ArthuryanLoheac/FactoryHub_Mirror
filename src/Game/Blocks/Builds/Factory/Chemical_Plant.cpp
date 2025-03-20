/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Smelter
*/
#include "Chemical_Plant.hpp"

Chemical_PlantT1::Chemical_PlantT1() : AFactory()
{
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("Chemical_Plant"), 0.0f);
    _cost = {{"SaltpeterRaw", 25}, {"WaterRaw", 20}};

    // Recette black_powder
    std::vector<Item> r_in1;
    r_in1.push_back(Item("SaltpeterRaw"));
    _AcceptedItems.push_back(Item("SaltpeterRaw"));
    std::vector<Item> r_out1;
    r_out1.push_back(Item("Black_Powder"));
    Recette r_black_powder(r_in1, r_out1, 2.f);
 
    _Recettes.push_back(r_black_powder);

    // Recette Gunpowder
    std::vector<Item> r_in2;
    r_in2.push_back(Item("SaltpeterRaw"));
    _AcceptedItems.push_back(Item("SaltpeterRaw"));
    r_in2.push_back(Item("CoalRaw"));
    _AcceptedItems.push_back(Item("CoalRaw"));
    std::vector<Item> r_out2;
    r_out2.push_back(Item("Gunpowder"));
    Recette r_gunpowder(r_in2, r_out2, 5.f);

    _Recettes.push_back(r_gunpowder);

    // Recette Rubber
    std::vector<Item> r_in3;
    r_in3.push_back(Item("CoalRaw"));
    _AcceptedItems.push_back(Item("CoalRaw"));
    r_in3.push_back(Item("WaterRaw"));
    _AcceptedItems.push_back(Item("WaterRaw"));
    std::vector<Item> r_out3;
    r_out3.push_back(Item("Rubber"));
    Recette r_Rubber(r_in3, r_out3, 5.f);

    _Recettes.push_back(r_Rubber);
}
