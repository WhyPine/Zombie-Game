/*****************************************************************************************
* Programmer: Josh Maloy, Aidan Gooding, Orion Green, Zach Fechko                        *
* Class: CptS 122, Fall 2021				                                             *
* Programming Assignment: PA9                                                            *
* Date: December 10, 2021                                                                *
* Description: This program defines the burstRifle object and all necessary methods          *
******************************************************************************************/
#pragma once
#include "Gun.h"
#include <Windows.h>
class BurstRifle :
    public Gun
{
public:
    BurstRifle(sf::Vector2f pos, sf::Vector2u size, int newBulletHealth);
    void fire(sf::Vector2f go, bool bottomlessClip, bool doubleDamage, bool doubleMag);
    int getReload();
    int getMaxReload();
    int getReloadTime();
    bool canShoot();
    void run(sf::Vector2f pos, float rotation, sf::Vector2f bulletDirection);

protected:
    //sf::Vector2f direction;
    bool fired;
    int lastShot;
    int numShots;
};

