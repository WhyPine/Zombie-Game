/*****************************************************************************************
* Programmer: Josh Maloy, Aidan Gooding, Orion Green, Zach Fechko                        *
* Class: CptS 122, Fall 2021				                                             *
* Programming Assignment: PA9                                                            *
* Date: December 10, 2021                                                                *
* Description: This program implements the sniper object and all necessary methods       *
******************************************************************************************/
#include "Sniper.h"

Sniper::Sniper(sf::Vector2f pos, sf::Vector2u size, int newBulletHealth) : Gun(pos, size, newBulletHealth) {
    this->reloadDelay = 1500;
    this->bulletHealth = newBulletHealth;
	this->reload = 4;
	this->maxReload = 4;
	this->shottimer = 0;
    this->power = 30;
    if (!this->texture.loadFromFile("sniper.png"))
    {
        std::cout << "Failed to load sniper" << std::endl;
    }
    if (!this->bulletTexture.loadFromFile("rifleshot.png"))
    {
        std::cout << "Failed to load rifleshot" << std::endl;
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 256, 32));
    this->sprite.setPosition(pos);
    this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
}

void Sniper::fire(sf::Vector2f go, bool bottomlessClip, bool doubleDamage, bool doubleMag) {
    if (doubleDamage && this->power == 30) this->power = 60;
    else if (!doubleDamage && this->power != 30) this->power = 30;
    if (doubleMag && this->maxReload == 4) this->maxReload = 10;
    else if (!doubleMag && this->maxReload != 4) this->maxReload = 4;
    if (this->shottimer > 75) {
        sf::Vector2f v = this->sprite.getPosition();
        this->shots->push_back(new Bullet(v, go, this->size, this->power, this->bulletTexture, 4 + this->bulletHealth, 30));
        if(!bottomlessClip) this->reload--;
        shottimer = 0;
    }
}

int Sniper::getReload() {
	return this->reload;
}

int Sniper::getMaxReload() {
	return this->maxReload;
}

int Sniper::getReloadTime() {
    return this->reloadDelay;
}

bool Sniper::canShoot() {
    return this->shottimer > 75;
}