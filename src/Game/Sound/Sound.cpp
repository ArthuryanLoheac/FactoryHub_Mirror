/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Sound
*/

#include "Sound.hpp"

Sound::Sound(/* args */)
{
    sounds["Create"] = "Assets/Sound/create.mp3";
    sounds["DestroyGhost"] = "Assets/Sound/destroy_final.mp3";
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
    FMOD_RESULT result;
    FMOD::System *pSystem = nullptr;
    FMOD::Sound *pSound = nullptr;

    result = FMOD::System_Create(&pSystem);
    pSystem->init(32, FMOD_INIT_NORMAL, nullptr);
    //pSystem->createSound(getSound(name).c_str(), FMOD_DEFAULT, )
}