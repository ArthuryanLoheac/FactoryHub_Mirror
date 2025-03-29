/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Sound
*/

#include "Sound.hpp"
#include <iostream>

Sound *Sound::instance = nullptr;

Sound::Sound()
{
    sounds["Create"] = "Assets/Sound/create.wav";
    sounds["Destroy"] = "Assets/Sound/destroy_final.wav";
    if (instance == nullptr)
        instance = this;
}

Sound::~Sound()
{
}

std::string Sound::getSound(const std::string &name)
{
    try {
        return sounds.at(name);
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Sound not found : " + name);
    }
}

void Sound::playSound(const std::string &name)
{
    if (!buffer.loadFromFile(name)) {
        std::cerr << "Failed to load sound file!" << std::endl;
        return;
    }
    sound_effect.setBuffer(buffer);
    sound_effect.play();
}