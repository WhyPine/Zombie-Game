#pragma once
#include "Zombie.h"
class RunnerZombie :
    public Zombie
{
public:
    RunnerZombie(int health, int speed, int damage, sf::Vector2u size, sf::Vector2f pos) : Zombie(health, speed, damage, size, pos) {
        this->speed = this->speed * 2;
        this->health = this->health - 10;
        this->reload = 0;
        random = rand() & 100;
        //std::cout << random << std::endl;
        this->texture->loadFromFile("zombie2.png");
        this->sprite.setTexture(*(this->texture));
        this->sprite.setTextureRect(sf::IntRect(10, 80, 240, 270));
        this->sprite.setScale((float)size.x / 7200, (float)size.y / 4400);
        this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
        this->sprite.setPosition(pos.x + random, pos.y + random);
    };

};

