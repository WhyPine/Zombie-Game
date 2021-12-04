#pragma once
#include "Gun.h"

class Shotgun :
    public Gun
{
public:
    Shotgun(sf::Vector2f pos, sf::Vector2u size, int newBulletHealth);
    void fire(sf::Vector2f go, bool bottomlessClip);
    int getReload();
    int getMaxReload();
    int getReloadTime();
};

