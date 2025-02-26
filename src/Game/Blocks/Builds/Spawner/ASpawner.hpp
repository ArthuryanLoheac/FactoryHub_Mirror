/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ASpawner
*/

#pragma once
#include <vector>
#include "Sprite.hpp"
#include "IBlock.hpp"

class ASpawner : public IBlock
{
    public:
        void update(float deltaTime);
        void NewWave();
        void draw(sdf::Renderer &renderer) override;
    protected:
        ASpawner();
        std::vector<float> coolDownWaves;
        std::vector<float> coolDownMobSpawn;
        size_t waveIndex;
        size_t nbWave;
        sdf::Sprite *_sprite;

};

