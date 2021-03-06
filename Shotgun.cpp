/*****************************************************************************************
* Programmer: Josh Maloy, Aidan Gooding, Orion Green, Zach Fechko                        *
* Class: CptS 122, Fall 2021				                                             *
* Programming Assignment: PA9                                                            *
* Date: December 10, 2021                                                                *
* Description: This program implements the shotgun object and all necessary methods      *
******************************************************************************************/

#include "Shotgun.h"
#include <iostream>

Shotgun::Shotgun(sf::Vector2f pos, sf::Vector2u size, int newBulletHealth) : Gun(pos, size, newBulletHealth) {
    this->power = 8;
    this->bulletHealth = newBulletHealth;
    this->reloadDelay = 1500;
    if (!texture.loadFromFile("shotgun.png"))
    {
        std::cout << "Failed to load shotgun" << std::endl;
    }
    if (!bulletTexture.loadFromFile("shotgunshot.png"))
    {
        std::cout << "Failed to load shotgunshot" << std::endl;
    }
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 256, 32));
    this->reload = 6;
    this->maxReload = 6;
    this->sprite.setPosition(pos);
    this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
}

void Shotgun::fire(sf::Vector2f go, bool bottomlessClip, bool doubleDamage, bool doubleMag)
{
    if (doubleDamage && this->power == 8) this->power = 16;
    else if (!doubleDamage && this->power != 8) this->power = 8;
    if (doubleMag && this->maxReload == 6) this->maxReload = 14;
    else if (!doubleMag && this->maxReload != 6) this->maxReload = 6;
    if (this->shottimer > 30) {
        sf::Vector2f v = this->sprite.getPosition();
        sf::Vector2f temp;
        temp.x = go.x;
        temp.y = go.y; 
        go.x = cos(-15 * 3.141592653 / 180) * temp.x - sin(-15 * 3.141592653 / 180) * temp.y;
        go.y = sin(-15 * 3.141592653 / 180) * temp.x + cos(-15 * 3.141592653 / 180) * temp.y;
        temp.x = go.x;
        temp.y = go.y;
        for (int x = 0; x < 5; x++) {
            go.x = cos(5 * 3.141592653 / 180) * temp.x - sin(5 * 3.141592653 / 180) * temp.y;
            go.y = sin(5 * 3.141592653 / 180) * temp.x + cos(5 * 3.141592653 / 180) * temp.y;
            this->shots->push_back(new Bullet(v, go, this->size, this->power, this->bulletTexture, 2 + this->bulletHealth, 20));
            temp.x = go.x;
            temp.y = go.y;
        }
        if (!bottomlessClip) this->reload--;
        this->shottimer = 0;
    }
}

int Shotgun::getReload()
{
    return this->reload;
}

int Shotgun::getMaxReload()
{
    return this->maxReload;
}

int Shotgun::getReloadTime() {
    return this->reloadDelay;
}

