#include "AProjectile.hpp"

AProjectile::AProjectile(float velocityX, float velocityY, int damage, float lifeTime)
{
    this->velocity = std::make_pair(velocityX, velocityY);
    this->damage = damage;
    this->lifeTime = lifeTime;
}

void AProjectile::update(float deltaTime, MapGrid map)
{
    this->_pos_pixel.first += this->velocity.first * deltaTime;
    this->_pos_pixel.second += this->velocity.second * deltaTime;
    this->lifeTime -= deltaTime;
    if (this->lifeTime <= 0)
        delete this;
}

int AProjectile::getDamage()
{
    return this->damage;
}

float AProjectile::getLifeTime()
{
    return this->lifeTime;
}

std::pair<float, float> AProjectile::getVelocity()
{
    return this->velocity;
}

void AProjectile::setVelocity(std::pair<float, float> velocity)
{
    this->velocity = velocity;
}

void AProjectile::setDamage(int damage)
{
    this->damage = damage;
}

void AProjectile::setLifeTime(float lifeTime)
{
    this->lifeTime = lifeTime;
}

