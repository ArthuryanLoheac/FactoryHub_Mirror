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
    // Load textures materials
    textures["Copper"] = new sdf::Texture("Assets/Copper.png");
    textures["CopperRaw"] = new sdf::Texture("Assets/CopperRaw.png");
    textures["Zinc"] = new sdf::Texture("Assets/Zinc.png");
    textures["ZincRaw"] = new sdf::Texture("Assets/ZincRaw.png");
    textures["Steel"] = new sdf::Texture("Assets/Steel.png");
    textures["SteelRaw"] = new sdf::Texture("Assets/SteelRaw.png");
    textures["Saltpeter"] = new sdf::Texture("Assets/Saltpeter.png");
    textures["SaltpeterRaw"] = new sdf::Texture("Assets/SaltpeterRaw.png");
    textures["Uranium"] = new sdf::Texture("Assets/Uranium.png");
    textures["UraniumRaw"] = new sdf::Texture("Assets/UraniumRaw.png");
    textures["Water"] = new sdf::Texture("Assets/Water.png");
    textures["WaterRaw"] = new sdf::Texture("Assets/WaterRaw.png");
    textures["Coal"] = new sdf::Texture("Assets/Coal.png");
    textures["CoalRaw"] = new sdf::Texture("Assets/CoalRaw.png");
    // Load textures items
    textures["Copper_Wire"] = new sdf::Texture("Assets/Copper_Wire.png");
    textures["Zinc_Plate"] = new sdf::Texture("Assets/Zinc_Plate.png");
    textures["Steel_BAR"] = new sdf::Texture("Assets/Steel_BAR.png");
    textures["Black_Powder"] = new sdf::Texture("Assets/Black_Powder.png");
    textures["Copper_Balls"] = new sdf::Texture("Assets/Copper_Balls.png");
    textures["Reinforced_Brass"] = new sdf::Texture("Assets/Reinforced_Brass.png");
    textures["Gunpowder"] = new sdf::Texture("Assets/Gunpowder.png");
    textures["Reinforced_Socket"] = new sdf::Texture("Assets/Reinforced_Socket.png");
    textures["Energy_Capacitor"] = new sdf::Texture("Assets/Energy_Capacitor.png");
    textures["Rubber"] = new sdf::Texture("Assets/Rubber.png");
    textures["Stabilized_Radioactive_Mater"] = new sdf::Texture("Assets/Stabilized_Radioactive_Mater.png");
    textures["Condensed_Plasma"] = new sdf::Texture("Assets/Condensed_Plasma.png");
    textures["High_Power_EMP_Charge"] = new sdf::Texture("Assets/High_Power_EMP_Charge.png");
    textures["Conductive_Socket"] = new sdf::Texture("Assets/Conductive_Socket.png");
    // Load textures ammunitions
    textures["Perforating_Projectile"] = new sdf::Texture("Assets/Perforating_Projectile.png");
    textures["Black_Powder_Ammo"] = new sdf::Texture("Assets/Black_Powder_Ammo.png");
    textures["Steel_Darts"] = new sdf::Texture("Assets/Steel_Darts.png");
    textures["ArmorPiercing_Ammo"] = new sdf::Texture("Assets/ArmorPiercing_Ammo.png");
    textures["Electric_Pulse_Ammo"] = new sdf::Texture("Assets/Electric_Pulse_Ammo.png");
    textures["Rubber_Balls"] = new sdf::Texture("Assets/Rubber_Balls.png");
    textures["Radioactive_Ammo"] = new sdf::Texture("Assets/Radioactive_Ammo.png");
    textures["Plasma_Ammo"] = new sdf::Texture("Assets/Plasma_Ammo.png");
    textures["High_Power_EMP_Ammo"] = new sdf::Texture("Assets/High_Power_EMP_Ammo.png"); 
    // Load textures blocks
    textures["Stone"] = new sdf::Texture("Assets/Stone.png");
    textures["Tapis"] = new sdf::Texture("Assets/tapis.png");
    textures["MinerT1"] = new sdf::Texture("Assets/Miner.png");
}

sdf::Texture &sdf::GetterTextures::getTexture(const std::string &name)
{
    try {
        return *textures.at(name);
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Texture not found : " + name);
    }
}
