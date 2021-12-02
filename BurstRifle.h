#pragma once
#include "Gun.h"
#include <Windows.h>
class BurstRifle :
    public Gun
{
public:
    BurstRifle(sf::Vector2f pos, sf::Vector2u size) : Gun(pos, size) {
        this->reload = 36;
        this->maxReload = 36;
    }
    void fire(sf::Vector2f go);
    int getReload();
    int getMaxReload();
};

