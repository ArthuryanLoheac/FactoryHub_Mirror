/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Sound
*/

#pragma once
#include "fmod.hpp"
#include <map>
#include <string>
#include <stdexcept>

class Sound
{
    public:
        static Sound *instance;

        Sound();
        ~Sound();

        std::string getSound(const std::string &name);
        void playSound(const std::string &name);

        std::map<std::string, std::string> sounds; 
};
