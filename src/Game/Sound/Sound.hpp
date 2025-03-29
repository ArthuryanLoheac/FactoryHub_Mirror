/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Sound
*/

#pragma once
#include <map>
#include <string>
#include <stdexcept>
#include <SFML/Audio.hpp>

class Sound
{
    public:
        static Sound *instance;

        Sound();
        ~Sound();

        std::string getSound(const std::string &name);
        void playSound(const std::string &name);

        std::map<std::string, std::string> sounds;
        sf::SoundBuffer buffer;
        sf::Sound sound_effect;
};
