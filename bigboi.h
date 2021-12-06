#pragma once
#include "Zombie.h"
class heavyZombie :
    public Zombie
{
public:
    heavyZombie(int health, int speed, int damage, sf::Vector2u size, sf::Vector2f pos) : Zombie(health * 2, speed * 0.5, damage * 2, sf::Vector2u(size.x * 2.5, size.y * 2.5), pos) {
        this->texture->loadFromFile("bigboi.png");
        this->sprite.setTexture(*(this->texture));
        this->sprite.setTextureRect(sf::IntRect(0, 0, 60, 60));
        this->sprite.setScale(sf::Vector2f(size.x * 0.000625, size.y * 0.001111));
        this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
        this->sprite.setPosition(pos.x + random, pos.y + random);
    }
};

