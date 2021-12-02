#include "Player.h"
#include <iostream>
#include <math.h>
#include <Windows.h> 


Player::Player(int health, double speed, double damageP, sf::Vector2u newSize) {
    this->size = newSize;
    this->health = health;
    this->maxHealth = health;
	this->speed = speed;
	this->damageP = damageP;
    this->canshoot = true;
    this->sprite.setPosition(15*32.f, 9*32.f);
    this->texture->loadFromFile("survivor-move_handgun_0.png");
    this->sprite.setTexture(*(this->texture));
    this->sprite.setTextureRect(sf::IntRect(39, 39, 250, 200));
    this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
    this->sprite.setScale((float)size.x / 6400, (float)size.y / 3600);
    this->gun = new Gun(this->sprite.getPosition(), size); 
    this->regenTimer = 0;
    this->regenDelay = 3;
    this->money = 10000;
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
    float moveX = 0;
    float moveY = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        moveX += 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        moveX -= 1;;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        moveY += 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        moveY -= 1;
    }
    if (moveX != 0 || moveY != 0) {
        if (moveX != 0 && moveY != 0) {
            moveX *= 0.71;
            moveY *= 0.71;
        }
        for (int i = 0; i < 3; i++) this->sprite.move(moveX, moveY);
    }

    this->gun->run(this->sprite.getPosition(), this->sprite.getRotation());
    if (this->gun->getReload() > 0 && canshoot) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            //std::thread t2(&Gun::fire, this->gun, p);
            //t2.detach();
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


void Player::setMoney(int newMoney) {
    this->money = newMoney;
}

int Player::getMoney() {
    return this->money;
}

void Player::setMaxHealth(int newMaxHealth) {
    this->maxHealth = newMaxHealth;
}

double Player::getStrength() {
    return this->damageP;
}
void Player::setStrength(double newStrength) {
    this->damageP = newStrength;
}
double Player::getSpeed() {
    return this->speed;
}
void Player::setSpeed(double newSpeed) {
    this->speed = newSpeed;
}
bool Player::setGun(Gun* newGun) {
    bool result = false;
    if (newGun->getMaxReload() != this->gun->getMaxReload()) {
        Gun* temp = this->gun;
        delete temp;
        this->gun = newGun;
        result = true;
    }
    return result;
}

sf::Vector2u Player::getSize() {
    return this->size;
}