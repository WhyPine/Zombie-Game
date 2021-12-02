#pragma once
#include "Gun.h"

class Shotgun :
    public Gun
{
public:
    Shotgun(sf::Vector2f pos, sf::Vector2u size);
    void fire(sf::Vector2f go);
    int getReload();
    int getMaxReload();
};

