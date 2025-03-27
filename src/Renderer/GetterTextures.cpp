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
    // Load textures ghosts
    textures["BuildGhost"] = new sdf::Texture("Assets/BuildGhost.png");
    textures["DestroyGhost"] = new sdf::Texture("Assets/DestroyGhost.png");
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
    textures["Chemical_Plant"] = new sdf::Texture("Assets/Chemical_Plant.png");
    textures["Smelter"] = new sdf::Texture("Assets/Smelter.png");
    textures["Foundry"] = new sdf::Texture("Assets/Foundry.png");
    textures["Molding_Workshop"] = new sdf::Texture("Assets/Molding_Workshop.png");
    textures["Assembly_Workshop"] = new sdf::Texture("Assets/Assembly_Workshop.png");
    textures["Wiring_Factory"] = new sdf::Texture("Assets/Wiring_Factory.png");
    textures["Capacitor_Factory"] = new sdf::Texture("Assets/Capacitor_Factory.png");
    textures["High_Voltage_Generator"] = new sdf::Texture("Assets/High_Voltage_Generator.png");
    textures["Nuclear_Refinery"] = new sdf::Texture("Assets/Nuclear_Refinery.png");
    textures["Advanced_Smelter"] = new sdf::Texture("Assets/Advanced_Smelter.png");
    textures["Advanced_Assembly_Workshop"] = new sdf::Texture("Assets/Advanced_Assembly_Workshop.png");
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
    textures["Base"] = new sdf::Texture("Assets/Base.png");
    // Load textures UI
    textures["StartMenu"] = new sdf::Texture("Assets/UI/StartMenu.png");
    textures["LoadingMenu"] = new sdf::Texture("Assets/UI/LoadingPage.png");
    textures["PauseUI"] = new sdf::Texture("Assets/UI/PauseUI.png");
    textures["Help1"] = new sdf::Texture("Assets/UI/1.png");
    textures["Help2"] = new sdf::Texture("Assets/UI/2.png");
    textures["Help3"] = new sdf::Texture("Assets/UI/3.png");
    textures["Help4"] = new sdf::Texture("Assets/UI/4.png");
    textures["Help5"] = new sdf::Texture("Assets/UI/5.png");
    // Load textures buttons
    textures["Quit"] = new sdf::Texture("Assets/UI/Buttons/Quit1.png");
    textures["QuitHover"] = new sdf::Texture("Assets/UI/Buttons/Quit2.png");
    textures["QuitClicked"] = new sdf::Texture("Assets/UI/Buttons/Quit3.png");
    textures["Menu"] = new sdf::Texture("Assets/UI/Buttons/Menu1.png");
    textures["MenuHover"] = new sdf::Texture("Assets/UI/Buttons/Menu2.png");
    textures["MenuClicked"] = new sdf::Texture("Assets/UI/Buttons/Menu3.png");
    textures["Resume"] = new sdf::Texture("Assets/UI/Buttons/Resume1.png");
    textures["ResumeHover"] = new sdf::Texture("Assets/UI/Buttons/Resume2.png");
    textures["ResumeClicked"] = new sdf::Texture("Assets/UI/Buttons/Resume3.png");
}

sdf::Texture &sdf::GetterTextures::getTexture(const std::string &name)
{
    try {
        return *textures.at(name);
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Texture not found : " + name);
    }
}
