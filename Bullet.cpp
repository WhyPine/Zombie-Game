#include "Bullet.h"
#include <iostream>
#include <math.h>

Bullet::Bullet(sf::Vector2f start, sf::Vector2f go, sf::Vector2u size, int newDamage, sf::Texture& newTexture) : texture(newTexture) {
    this->damage = newDamage;
    this->projS = 10;
    this->health = 1;
    //this->texture = newTexture;
    //sf::Texture texture;
    //texture.loadFromFile("zombie0.png");  //load texture in gun and then pass it in by reference
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, this->texture.getSize().x, this->texture.getSize().y));
    this->sprite.setScale(1, 1);
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

sf::Sprite& Bullet::getSprite() {
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
