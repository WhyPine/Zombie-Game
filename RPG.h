#pragma once
#include "Gun.h"
class RPG :
    public Gun
{
public:
    RPG(sf::Vector2f pos, sf::Vector2u size);

    void run(sf::Vector2f pos, float rotation, bool hold);
    void fire(sf::Vector2f go);
    int getReload();
    int getMaxReload();
    void mainHit(int zombieId);
    
protected:
    int zombieXploded;
    sf::Vector2f thisGo;
    bool hitSomething(Bullet* bullet);
    Bullet* shotbull;
    bool fired;
    bool explode;
    sf::Vector2f boomSpot;
    sf::Texture rocketTexture;
};

