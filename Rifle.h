/*****************************************************************************************
* Programmer: Josh Maloy, Aidan Gooding, Orion Green, Zach Fechko                        *
* Class: CptS 122, Fall 2021				                                             *
* Programming Assignment: PA9                                                            *
* Date: December 10, 2021                                                                *
* Description: This program defines the rifle object and all necessary methods           *
******************************************************************************************/

#pragma once
#include "Gun.h"
class Rifle :
    public Gun
{
public:
    Rifle(sf::Vector2f pos, sf::Vector2u size, int newBulletHealth);
    void fire(sf::Vector2f go, bool bottomlessClip, bool doubleDamage, bool doubleMag);
    int getReload();
    int getMaxReload();
    int getReloadTime();
    bool canShoot();
};

