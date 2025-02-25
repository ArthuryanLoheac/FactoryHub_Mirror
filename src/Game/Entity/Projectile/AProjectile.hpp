/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AProjectile
*/

#pragma once
#include "AEntity.hpp"
#include "AEnemy.hpp"
#include "IBlock.hpp"

class AProjectile : public AEntity
{
    public:
        virtual void OnImpact(AEnemy *enemy) = 0;
        virtual void OnImpact(IBlock *enemy) = 0;
        AProjectile(float velocityX, float velocityY, int damage, float lifeTime);
        virtual void update(float deltaTime, MapGrid map) override;

        int getDamage();
        float getLifeTime();
        std::pair<float, float> getVelocity();
        void setVelocity(std::pair<float, float> velocity);
        void setDamage(int damage) ;
        void setLifeTime(float lifeTime);
    private:
        std::pair<float, float> velocity;
        int damage;
        float lifeTime;
};
