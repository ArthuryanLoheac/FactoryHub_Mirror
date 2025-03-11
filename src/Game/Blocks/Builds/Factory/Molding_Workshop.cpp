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

    //recette copper balls
    std::vector<Item> r_in1;
    r_in1.push_back(Item("CopperRaw"));
    _AcceptedItems.push_back(Item("CopperRaw"));
    std::vector<Item> r_out1;
    r_out1.push_back(Item("Copper_Balls"));
    Recette r_copper_balls(r_in1, r_out1, 2.f);

    _Recettes.push_back(r_copper_balls);

    //recette Black_Powder_Ammo
    std::vector<Item> r_in2;
    r_in2.push_back(Item("Black_Powder"));
    _AcceptedItems.push_back(Item("Black_Powder"));
    r_in2.push_back(Item("Copper_Balls"));
    _AcceptedItems.push_back(Item("Copper_Balls"));
    std::vector<Item> r_out2;
    r_out2.push_back(Item("Black_Powder_Ammo"));
    Recette r_black_powder_ammo(r_in2, r_out2, 2.f);

    _Recettes.push_back(r_black_powder_ammo);

    //recette Perforating_Projectile
    std::vector<Item> r_in3;
    r_in3.push_back(Item("Steel_BAR"));
    _AcceptedItems.push_back(Item("Steel_BAR"));
    std::vector<Item> r_out3;
    r_out3.push_back(Item("Perforating_Projectile"));
    Recette r_Perforating_Projectile(r_in3, r_out3, 2.f);

    _Recettes.push_back(r_Perforating_Projectile);
}
