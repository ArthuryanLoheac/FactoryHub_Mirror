/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ASpawner
*/

#pragma once
#include <vector>

class ASpawner
{
    public:
        void update(float deltaTime);
        void NewWave();
    protected:
        ASpawner();
        std::vector<float> coolDownWaves;
        std::vector<float> coolDownMobSpawn;
        size_t waveIndex;
        size_t nbWave;
};

