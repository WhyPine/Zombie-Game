#pragma once
#include "Gun.h"
class Rifle :
    public Gun
{
public:
    Rifle(sf::Vector2f pos, sf::Vector2u size);
    void fire(sf::Vector2f go);
    int getReload();
    int getMaxReload();
};
