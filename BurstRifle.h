#pragma once
#include "Gun.h"
#include <Windows.h>
class BurstRifle :
    public Gun
{
public:
    BurstRifle(sf::Vector2f pos, sf::Vector2u size, int newBulletHealth);
    void fire(sf::Vector2f go, bool bottomlessClip);
    int getReload();
    int getMaxReload();
    int getReloadTime();
};

