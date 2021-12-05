#pragma once
#include "Gun.h"
#include <Windows.h>
class BurstRifle :
    public Gun
{
public:
    BurstRifle(sf::Vector2f pos, sf::Vector2u size);
    void fire(sf::Vector2f go);
    int getReload();
    int getMaxReload();
    void run(sf::Vector2f pos, float rotation);

protected:
    bool fired;
    int lastShot;
    int numShots
};

