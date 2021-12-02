#include "Bullet.h"
#include <iostream>
#include <math.h>

Bullet::Bullet(sf::Vector2f start, sf::Vector2f go, sf::Vector2u size, int newDamage) {
    this->damage = newDamage;
    this->projS = 10;
    this->health = 1;
    sf::Texture texture;
    texture.loadFromFile("zombie0.png");
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));
    this->sprite.setScale((float)size.x / 16000, (float)size.y / 9000);
    this->sprite.setColor(sf::Color(179, 170, 4));
    this->sprite.setPosition(start);
    this->go = go;
}

Bullet::~Bullet() {

}

void Bullet::updatePosition() {

    float z = sqrtf(go.x * go.x + go.y * go.y);
    for (int i = 0; i < this->projS; i++) {
        this->sprite.move(1.f * (go.x / z), 0.f);
    }
    for (int i = 0; i < this->projS; i++) {
        this->sprite.move(0.f, 1.f * (go.y / z));
    }
}

sf::Sprite Bullet::getSprite() {
    return this->sprite;
}

int Bullet::getHealth() {
    return this->health;
}

int Bullet::getDamage() {
    return this->damage;
}

void Bullet::setHealth(int value) {
    this->health += value;
}
