#include "Shotgun.h"
#include <iostream>

Shotgun::Shotgun(sf::Vector2f pos, sf::Vector2u size) : Gun(pos, size) {
    this->power = 5;
    if (!texture.loadFromFile("rifle.png"))
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

void Shotgun::fire(sf::Vector2f go)
{
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
            this->shots->push_back(new Bullet(v, go, this->size, this->power, this->bulletTexture));
            temp.x = go.x;
            temp.y = go.y;
        }
        this->reload--;
        this->shottimer = 0;
    }
}

int Shotgun::getReload()
{
    return this->reload;
}

int Shotgun::getMaxReload()
{
    return 6;
}

