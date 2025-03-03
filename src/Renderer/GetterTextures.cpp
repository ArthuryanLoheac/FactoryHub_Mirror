/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** GetterTextures
*/

#include "GetterTextures.hpp"

sdf::GetterTextures *sdf::GetterTextures::instance = nullptr;

sdf::GetterTextures::GetterTextures()
{
    if (instance == nullptr)
        instance = this;
    else
        return;
    textures["Stone"] = new sdf::Texture("Assets/Stone.png");
    textures["Zinc"] = new sdf::Texture("Assets/Zinc.png");
    textures["Cuivre"] = new sdf::Texture("Assets/Cuivre.png");
    textures["Charbon"] = new sdf::Texture("Assets/Charbon.png");
    textures["Acier"] = new sdf::Texture("Assets/Acier.png");
    textures["Salpetre"] = new sdf::Texture("Assets/Salpetre.png");
    textures["Uranium"] = new sdf::Texture("Assets/Uranium.png");
    textures["Eau"] = new sdf::Texture("Assets/Eau.png");
    textures["Tapis"] = new sdf::Texture("Assets/tapis.png");
    textures["MinerT1"] = new sdf::Texture("Assets/Miner.png");
}

sdf::Texture &sdf::GetterTextures::getTexture(const std::string &name)
{
    return *textures.at(name);
}
