#pragma once
#include "Zombie.h"
class heavyZombie :
    public Zombie
{
public:
    heavyZombie(int health, int speed, int damage, sf::Vector2u size, sf::Vector2f pos) : Zombie(health * 2, speed * 0.5, damage * 1.5, sf::Vector2u(size.x * 2.5, size.y * 2.5), pos) {
        this->texture->loadFromFile("zombie0.png");
        this->sprite.setTexture(*(this->texture));
        this->sprite.setTextureRect(sf::IntRect(10, 80, 240, 270));
        this->sprite.setScale((float)size.x / 7200 * 2.5, (float)size.y / 4400 * 2.5);
        this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
        this->sprite.setPosition(pos.x + random, pos.y + random);
    }
};

