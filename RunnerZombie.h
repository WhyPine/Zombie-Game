/*****************************************************************************************
* Programmer: Josh Maloy, Aidan Gooding, Orion Green, Zach Fechko                        *
* Class: CptS 122, Fall 2021				                                             *
* Programming Assignment: PA9                                                            *
* Date: December 10, 2021                                                                *
* Description: This program defines the runnerZombie object and all necessary methods          *
******************************************************************************************/
#pragma once
#include "Zombie.h"
#include <iostream>
class RunnerZombie :
    public Zombie
{
public:
    RunnerZombie(int health, int speed, int damage, sf::Vector2u size, sf::Vector2f pos) : Zombie(health / 2, speed * 1.75, damage, size, pos) {
        this->texture->loadFromFile("zombie2.png");
        this->sprite.setTexture(*(this->texture));
        this->sprite.setTextureRect(sf::IntRect(10, 5, 80, 55));
        this->sprite.setScale((float)size.x / 7200*3, (float)size.y / 4400*3);
        this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
        this->sprite.setPosition(pos.x + random, pos.y + random);
    }
   
};