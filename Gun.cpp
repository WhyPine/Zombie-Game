#include "Gun.h"
#include <iostream>
sf::Texture texture;
Gun::Gun(sf::Vector2f pos, sf::Vector2u size) {
	this->power = 5;
	this->projS = 10;
    this->size = size;
    this->reload = 30;
    this->maxReload = 30;
    
    //texture.loadFromFile("rifle.png");
    
    if (!texture.loadFromFile("rifle.png"))
    {
        std::cout << "Error occured" << std::endl;
    }
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 256, 32));
    this->sprite.setScale((float)size.x / 4800, (float)size.y / 4800);
    //this->sprite.setColor(sf::Color(138, 86, 3));
    this->sprite.setPosition(pos);
    this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
    this->shots = new vector<Bullet*>();
    this->shottimer = 0;
} 

void Gun::run(sf::Vector2f pos, float rotation) {
    this->shottimer++;
    this->sprite.setRotation(rotation);
    double xPos, yPos;
    if (rotation < 0) rotation += 360;
    rotation += 30;
    sf::Vector2f newVector(pos.x + cos((3.141592653 / 180) * rotation) * 12, pos.y + sin((3.141592653 / 180) * rotation) * 12);
    this->sprite.setPosition(newVector);
    for (std::vector<Bullet*>::iterator it = this->shots->begin(); it != this->shots->end(); ++it) {
        if (*it != nullptr) {
            (*it)->updatePosition();
        }
    }
     
}

void Gun::fire(sf::Vector2f go) {
    if (this->shottimer > 6) {
        sf::Vector2f v = this->sprite.getPosition();
        this->shots->push_back(new Bullet(v, go, this->size));
        this->reload--;
        shottimer = 0;
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
    this->reload = add;
}

void Gun::setReload(int value) {
    this->reload = value;
}

int Gun::getMaxReload()
{
    return 30;
}