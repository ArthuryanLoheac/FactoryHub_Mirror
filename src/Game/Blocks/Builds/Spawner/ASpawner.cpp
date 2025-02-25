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

ASpawner::ASpawner()
{
}
