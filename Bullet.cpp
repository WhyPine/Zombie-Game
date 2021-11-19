#include "Bullet.h"
#include <iostream>
#include <math.h>

Bullet::Bullet(sf::Vector2f start, sf::Vector2f go, sf::Vector2u size) {
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
    this->sprite.setColor(sf::Color(179, 170, 4));
    this->sprite.setPosition(start);
    this->go = go;
}

void Bullet::updatePosition() {
    /*float x;
    float y;
    std::cout << this->result;
    this->result = this->result * (3.141592653589) / 180;
    std::cout << this->result;
    x = cosf(this->result);
    y = sinf(this->result);*/
    //std::cout << go.x << ": " << go.y << std::endl;
    float z = sqrtf(go.x * go.x + go.y * go.y);
    for (int i = 0; i < this->projS; i++) {
        this->sprite.move(1.f * (go.x / z), 0.f);
    }
    for (int i = 0; i < this->projS; i++) {
        this->sprite.move(0.f, 1.f * (go.y / z));
    }
   /*if () {
        for (int i = 0; i < this->projS ; i++) {
            this->sprite.move(-1.f * x, 0.f);
        }
    }
    else {
        for (int i = 0; i < this->projS; i++) {
            this->sprite.move(1.f * x, 0.f);
        }
    }
   if (this->result > 0 && this->result < 180) {
        for (int i = 0; i < this->projS; i++) {
            this->sprite.move(0.f, 1.f * y);
        }
    }
    else {
        for (int i = 0; i < this->projS; i++) {
            this->sprite.move(0.f, -1.f  * y);
        }
    }*/
}

sf::Sprite Bullet::getSprite() {
    return this->sprite;
}