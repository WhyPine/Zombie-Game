#include "Bullet.h"
#include <iostream>

Bullet::Bullet(sf::Vector2f start, sf::Vector2i go, sf::Vector2u size) {
    this->damage = 5;
    this->projS = 10;
    sf::Texture texture;
    texture.loadFromFile("skeleton-attack_0.png");
    this->sprite.setTexture(texture);
    if (!texture.loadFromFile("image.png", sf::IntRect(10, 10, 32, 32)))
    {
        std::cout << "Error occured" << std::endl;
    }
    this->sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));
    this->sprite.setScale((float)size.x / 16000, (float)size.y / 9000);
    this->sprite.setColor(sf::Color(24, 219, 34));
    //this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2, this->sprite.getGlobalBounds().height / 2);
}

