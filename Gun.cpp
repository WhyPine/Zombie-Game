#include "Gun.h"
#include <iostream>

Gun::Gun(sf::Vector2f pos, sf::Vector2u size) {
	this->power = 5;
	this->projS = 10;
    this->size = size;
    this->reload = 30;
    sf::Texture texture;
    texture.loadFromFile("skeleton-attack_0.png");
    this->sprite.setTexture(texture);
    if (!texture.loadFromFile("image.png", sf::IntRect(10, 10, 32, 32)))
    {
        std::cout << "Error occured" << std::endl;
    }
    this->sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));
    this->sprite.setScale((float)size.x / 1600, (float)size.y / 1600);
    this->sprite.setColor(sf::Color(138, 86, 3));
    this->sprite.setPosition(pos);
    this->shots = new vector<Bullet*>();
    this->shottimer = 0;
} 

void Gun::run(sf::Vector2f pos, float rotation) {
    this->shottimer++;
    this->sprite.setPosition(pos);
    this->sprite.setRotation(rotation);
    for (std::vector<Bullet*>::iterator it = this->shots->begin(); it != this->shots->end(); ++it) {
        if (*it != nullptr) {
            (*it)->updatePosition();
        }
    }
     
}

void Gun::fire(sf::Vector2f go) {
    if (this->shottimer % 6 == 0) {
        sf::Vector2f v = this->sprite.getPosition();
        this->shots->push_back(new Bullet(v, go, this->size));
        this->reload--;
    }
}

sf::Sprite Gun::getSprite() {
    return this->sprite;
}

vector<Bullet*>* Gun::getShots() {
    return this->shots;
}

int Gun::getReload() {
    return this->reload;
}

void Gun::changeReload(int add) {
    this->reload += add;
}

void Gun::setReload(int value) {
    this->reload = value;
}