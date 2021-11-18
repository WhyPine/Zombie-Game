#include "Gun.h"
#include <iostream>

Gun::Gun(sf::Vector2f pos, sf::Vector2u size) {
	this->power = 5;
	this->projS = 10;
    this->size = size;
    sf::Texture texture;
    texture.loadFromFile("skeleton-attack_0.png");
    this->sprite.setTexture(texture);
    if (!texture.loadFromFile("image.png", sf::IntRect(10, 10, 32, 32)))
    {
        std::cout << "Error occured" << std::endl;
    }
    this->sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));
    this->sprite.setScale((float)size.x / 1600, (float)size.y / 900);
    this->sprite.setColor(sf::Color(24, 219, 34));
    this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2, this->sprite.getGlobalBounds().height / 2);
}

void Gun::run(Player* p1) {

}

void Gun::fire() {
	sf::Vector2i gP = sf::Mouse::getPosition();
    sf::Vector2f v = this->sprite.getPosition();
	this->shots.push_back(new Bullet(v, gP,this->size));
}

void Gun::