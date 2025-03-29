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

        void playCreate(void);
        void playDestroy(void);

        sf::SoundBuffer buffer_create;
        std::vector<sf::Sound> sound_effect_create;
        sf::SoundBuffer buffer_destroy;
        std::vector<sf::Sound> sound_effect_destroy;
};
