#pragma once
#include "Zombie.h"
class heavyZombie :
    public Zombie
{
public:
    heavyZombie(int health, int speed, int damage, sf::Vector2u size, sf::Vector2f pos) : Zombie(health * 2, speed / 2, damage * 1.5, size, pos) {
        this->texture->loadFromFile("zombie0.png");
        this->sprite.setTexture(*(this->texture));
        this->sprite.setTextureRect(sf::IntRect(10, 5, 80, 55));
        this->sprite.setScale((float)size.x / 7200 * 2, (float)size.y / 7200 * 2);
        this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
        this->sprite.setPosition(pos.x + random, pos.y + random);
    }
};

