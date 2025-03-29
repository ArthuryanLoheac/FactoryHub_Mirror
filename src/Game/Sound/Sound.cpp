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
    buffer_create.loadFromFile("Assets/Sound/create.wav");
    sound_effect_create.resize(10);
    for (auto& sound : sound_effect_create)
        sound.setBuffer(buffer_create);
    
    buffer_destroy.loadFromFile("Assets/Sound/destroy_final.wav");
    sound_effect_destroy.resize(10);
    for (auto& sound : sound_effect_destroy)
        sound.setBuffer(buffer_destroy);
    if (instance == nullptr)
        instance = this;
}

Sound::~Sound()
{
}

void Sound::playCreate(void)
{
    for (auto& sound : sound_effect_create) {
        if (sound.getStatus() != sf::Sound::Playing){
            sound.play();
            return;
        }
    }
}

void Sound::playDestroy(void)
{
    for (auto& sound : sound_effect_destroy) {
        if (sound.getStatus() != sf::Sound::Playing){
            sound.play();
            return;
        }
    }
}