/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ASpawner
*/

#include "ASpawner.hpp"

void ASpawner::update(float deltaTime)
{
    coolDownWaves[waveIndex] -= deltaTime;
    if (coolDownWaves[waveIndex] <= 0)
        NewWave();
}

void ASpawner::NewWave()
{
    waveIndex++;
    if (waveIndex >= nbWave)
        waveIndex = nbWave;
}

void ASpawner::draw(sdf::Renderer &renderer)
{
    _sprite->draw(renderer);
}

ASpawner::ASpawner()
{
    sdf::Texture textureStone = sdf::Texture("Assets/Stone.png");
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f), textureStone);
}
