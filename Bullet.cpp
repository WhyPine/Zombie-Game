/*****************************************************************************************
* Programmer: Josh Maloy, Aidan Gooding, Orion Green, Zach Fechko                        *
* Class: CptS 122, Fall 2021				                                             *
* Programming Assignment: PA9                                                            *
* Date: December 10, 2021                                                                *
* Description: This program defines the bullet object and all necessary methods          *
******************************************************************************************/
#include "Bullet.h"
#include <iostream>
#include <math.h>

Bullet::Bullet(sf::Vector2f start, sf::Vector2f newGo, sf::Vector2u size, int newDamage, sf::Texture& newTexture, int newHealth, int newSpeed) : texture(newTexture) {
    this->damage = newDamage;
    this->projS = newSpeed;
    this->health = newHealth;
    //this->texture = newTexture;
    //sf::Texture texture;
    //texture.loadFromFile("zombie0.png");  //load texture in gun and then pass it in by reference
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, this->texture.getSize().x, this->texture.getSize().y));
    this->sprite.setScale(1, 1);
    this->sprite.setColor(sf::Color(179, 170, 4));
    this->sprite.setOrigin(this->sprite.getPosition().x / 2, this->sprite.getPosition().y / 2);
    this->sprite.setPosition(start);
    this->go = newGo;
    float rotate = atan2(this->go.y / sqrtf(this->go.x * this->go.x + this->go.y * this->go.y), this->go.x / sqrtf(this->go.x * this->go.x + this->go.y * this->go.y));
    this->sprite.setRotation(rotate * 180.0 / (float)3.141592653);
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
    //this->sprite.rotate(0.5);
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

bool Bullet::hasHit(int zombieId) {
    bool result = false;
    for (int x = 0; x < this->zombiesHit.size(); x++) {
        if (zombieId == this->zombiesHit[x]) result = true;
    }
    return result;
}

void Bullet::hit(int zombieId) {
    this->zombiesHit.push_back(zombieId);
}
