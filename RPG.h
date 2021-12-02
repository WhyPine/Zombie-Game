#pragma once
#include "Gun.h"
class RPG :
    public Gun
{
public:
    RPG(sf::Vector2f pos, sf::Vector2u size) : Gun(pos, size) {
        this->reload = 3;
        this->maxReload = 3;
        this->shotbull = nullptr;
    };

    void run(sf::Vector2f pos, float rotation);
    void fire(sf::Vector2f go);
    int getReload();
    int getMaxReload();

protected:
    Bullet* shotbull;
};

