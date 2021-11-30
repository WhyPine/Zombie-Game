#pragma once
#include "Gun.h"
class Shotgun :
    public Gun
{
public:
    Shotgun(sf::Vector2f pos, sf::Vector2u size) : Gun(pos, size) {
        this->reload = 6;
        this->maxReload = 6;
    };
    void fire(sf::Vector2f go);
    int getMaxReload();
};

