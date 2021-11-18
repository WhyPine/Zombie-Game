#include "Zombie.h"
#include <iostream>

Zombie::Zombie(int health, int speed, int damage, sf::Vector2u size) {
    this->health = health;
    this->speed = speed;
    this->damage = damage;

    /* sf::Vector2f newSize;
     newSize.x =(float)size.x / 1600;
     newSize.y = (float)size.y / 900;
     this->shape.setScale(newSize);
     this->shape.setFillColor(sf::Color(100, 250, 50));*/

    sf::Texture texture;
    texture.loadFromFile("");
    this->sprite.setTexture(texture);
    if (!texture.loadFromFile("image.png", sf::IntRect(10, 10, 32, 32)))
    {
        std::cout << "Error occured" << std::endl;
    }
    this->sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));
    this->sprite.setScale((float)size.x / 1600, (float)size.y / 900);
    this->sprite.setColor(sf::Color(240, 5, 5));
}

void Zombie::getMove(Player* p1) {
    sf::Vector2f v1 = p1->getPosition();
    sf::Vector2f v2 = this->sprite.getPosition();
    if (v2.x < v1.x) {
        this->sprite.move(1.f, 0.f);
    }
    if (v2.x > v1.x) {
        this->sprite.move(-1.f, 0.f);
    }
    if (v2.y < v1.y) {
        this->sprite.move(0.f, 1.f);
    }
    if (v2.y > v1.y) {
        this->sprite.move(0.f, -1.f);
    }

}

sf::Sprite Zombie::getSprite() {
    return this->sprite;
}