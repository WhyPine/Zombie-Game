/*****************************************************************************************
* Programmer: Josh Maloy, Aidan Gooding, Orion Green, Zach Fechko                        *
* Class: CptS 122, Fall 2021				                                             *
* Programming Assignment: PA9                                                            *
* Date: December 10, 2021                                                                *
* Description: This program defines the rpg object and all necessary methods             *
******************************************************************************************/


#pragma once
#include "Gun.h"
class RPG :
    public Gun
{
public:
    RPG(sf::Vector2f pos, sf::Vector2u size, int newBulletHealth);

    void run(sf::Vector2f pos, float rotation, bool hold);
    void fire(sf::Vector2f go, bool bottomlessClip, bool doubleDamage, bool doubleMag);
    int getReload();
    int getMaxReload();
    void mainHit(int zombieId);
    int getReloadTime();
    bool canShoot();
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

