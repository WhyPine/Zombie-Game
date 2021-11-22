#include "Zombie.h"
#include <iostream>
#include <math.h>

Zombie::Zombie(int health, int speed, int damage, sf::Vector2u size, sf::Vector2f pos) {
    this->health = health;
    this->speed = speed;
    this->damage = damage;
    this->reload = 0;
    random = rand();
    std::cout << random << std::endl;
    this->texture->loadFromFile("zombie0.png");
    this->sprite.setTexture(*(this->texture));
    this->sprite.setTextureRect(sf::IntRect(10, 80, 240, 270));
    this->sprite.setScale((float)size.x / 7200, (float)size.y / 4400);
    //this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2, this->sprite.getGlobalBounds().height / 2);
    pos.x += random;
    pos.y += random;
    this->sprite.setPosition(10.f, 10.f);
}

Zombie::~Zombie() {
    //delete(this->texture);
}

void Zombie::getMove(Player* p1, sf::Vector2f pos) {
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
    sf::Vector2f v = this->sprite.getPosition();
    sf::Vector2f p;

    p.x = pos.x - v.x;
    p.y = pos.y - v.y;
    //std::cout << p.x << ": " << p.y << std::endl;
    long float result;
    long float param;
    if (p.x > 0) {
        param = p.y / p.x;
        result = atanf(param) * 180 / (3.141592653589793);
        //std::cout << result << std::endl;
        result -= 360;
    }
    else if (p.x < 0) {
        param = p.y / p.x;
        result = atanf(param) * 180 / (3.141592653589793);
        //std::cout << result << std::endl;
        result += 180;
    }
    else {
        if (p.y <= 0) {
            result = 270;
        }
        else {
            result = 90;
        }
    }
    this->sprite.setRotation(result);
    this->reload++;
}

sf::Sprite Zombie::getSprite() {
    return this->sprite;
}

int Zombie::getDamage() {
    return this->damage;
}

int Zombie::getReload() {
    return this->reload % 64;
}

int Zombie::getHealth() {
    return this->health;
}

void Zombie::setHealth(int health) {
    this->health = health;
}