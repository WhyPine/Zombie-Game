#include "Player.h"
#include <iostream>
#include <math.h>
#include <Windows.h> 


Player::Player(int health, double speed, double damageP, sf::Vector2u size) {
    this->health = health;
    this->maxHealth = health;
	this->speed = speed;
	this->damageP = damageP;
    this->canshoot = true;
    this->sprite.setPosition(500.f, 500.f);
    this->texture->loadFromFile("survivor-move_handgun_0.png");
    this->sprite.setTexture(*(this->texture));
    this->sprite.setTextureRect(sf::IntRect(39, 39, 250, 200));
    this->sprite.setScale((float)size.x / 6400, (float)size.y / 3600);
    this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
    this->gun = new Shotgun(this->sprite.getPosition(), size); 
    this->regenTimer = 0;
    this->regenDelay = 3;
}

void Player::checkMove(sf::Vector2i gP) {

    sf::Vector2f v = this->sprite.getPosition();
    sf::Vector2f p;

    p.x = gP.x - v.x;
    p.y = gP.y - v.y;

    long float result;
    long float param;
    if (p.x > 0) {
        param = p.y / p.x;
        result = atanf(param) * 180 / (3.141592653589793);
        result -= 360;
    }
    else if (p.x < 0) {
        param = p.y / p.x;
        result = atanf(param) * 180 / (3.141592653589793);
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        for (int i = 0; i < 3; i++) this->sprite.move(1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        for (int i = 0; i < 3; i++) this->sprite.move(-1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        for (int i = 0; i < 3; i++) this->sprite.move(0.f, 1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        for (int i = 0; i < 3; i++) this->sprite.move(0.f, -1.f);
    }
    this->gun->run(this->sprite.getPosition(), this->sprite.getRotation());
    if (this->gun->getReload() > 0 && canshoot) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->gun->fire(p);
        }
    }
    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
        std::thread t1(this->gun->changeReload(30));
        this->gun->changeReload(30);
    }*/

    //regenerating health
    if (this->health < this->maxHealth) {
        if (clock() - this->regenTimer > this->regenDelay * 1000) {
            this->health+=2;
            this->regenTimer = clock();
        }
        if (this->health > this->maxHealth) this->health = this->maxHealth;
    }


}

sf::Sprite Player::getSprite() {
    return this->sprite;
}

sf::Vector2f Player::getPosition() {
    return this->sprite.getPosition();
}

sf::Sprite Player::getGunSprite() {
    return this->gun->getSprite();
}

Gun* Player::getGun() {
    return this->gun;
}

int Player::getHealth() {
    return this->health;
}

void Player::setHealth(int health) {
    this->health = health;
    this->regenTimer = clock();
}

void Player::reload(int value) {
    Sleep(1500);
    this->gun->changeReload(this->gun->getMaxReload());
    this->canshoot = true;
}

int Player::getMaxHealth() {
    return this->maxHealth;
}

void Player::setPosition(sf::Vector2f v) {
    this->sprite.setPosition(v);
}