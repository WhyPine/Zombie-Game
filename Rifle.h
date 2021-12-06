#pragma once
#include "Gun.h"
class Rifle :
    public Gun
{
public:
    Rifle(sf::Vector2f pos, sf::Vector2u size, int newBulletHealth);
    void fire(sf::Vector2f go, bool bottomlessClip, bool doubleDamage, bool doubleMag);
    int getReload();
    int getMaxReload();
    int getReloadTime();
    bool canShoot();
};

