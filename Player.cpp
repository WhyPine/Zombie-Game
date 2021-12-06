#include "Player.h"
#include <iostream>
#include <math.h>
#include <Windows.h> 


Player::Player(int newHealth, double newSpeedMultiplier, double newReloadMultiplier, sf::Vector2u newSize, int newBulletHealth, double newRegenMultiplier) {
    this->regenTimer = 0;
    this->bulletHealth = newBulletHealth;
    this->semiAuto = true;
    this->size = newSize;
    this->health = newHealth;
    this->maxHealth = newHealth;
    this->speedMultiplier = newSpeedMultiplier;
	this->reloadMultiplier = newReloadMultiplier;
    this->canshoot = true;
    this->duringReload = false;
    this->sprite.setPosition(15*32.f, 9*32.f);
    this->texture->loadFromFile("survivor-move_handgun_0.png");
    this->explosionTexture.loadFromFile("rpgshot.png");
    this->sprite.setTexture(*(this->texture));
    this->sprite.setTextureRect(sf::IntRect(39, 39, 250, 200));
    this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
    this->sprite.setScale((float)size.x / 6400, (float)size.y / 3600);
    this->gun = new BurstRifle(this->sprite.getPosition(), size, bulletHealth); 
    this->regenMultiplier = newRegenMultiplier;
    this->money = 10000;
    this->bottomlessClip = false;
    this->initialReload = 0;
    this->doubleDamage = false;
    this->extendedMag = false;
    this->secondWind = false;
    this->contingencyResponse = true;
}

void Player::checkMove(sf::Vector2i gP) {
    canshoot = true;
    if (duringReload || !this->gun->canShoot()) canshoot = false; //if on shot cooldown or reloading
    if ((!duringReload && this->gun->getMaxReload() == 30) || this->bottomlessClip) canshoot = true; //if not reloading and using auto rifle
    if (!this->gun->getReload()) canshoot = false; //if out of ammo 

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
        moveX += 1 * this->speedMultiplier;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        moveX -= 1 * this->speedMultiplier;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        moveY += 1 * this->speedMultiplier;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        moveY -= 1 * this->speedMultiplier;
    }
    if (moveX != 0 || moveY != 0) {
        if (moveX != 0 && moveY != 0) {
            moveX *= 0.71;
            moveY *= 0.71;
        }
        for (int i = 0; i < 3; i++) this->sprite.move(moveX, moveY);
    }
    //if rpg
    if (this->gun->getMaxReload() == 2 || this->gun->getMaxReload() == 5) {
        this->gun->run(this->sprite.getPosition(), this->sprite.getRotation(), sf::Mouse::isButtonPressed(sf::Mouse::Left));
    }
    //if burst fire
    else if (this->gun->getMaxReload()%36 == 0) {
        this->gun->run(this->sprite.getPosition(), this->sprite.getRotation(), p);
    }
    //if all other guns
    else {
        this->gun->run(this->sprite.getPosition(), this->sprite.getRotation());
    }
    if (this->gun->getReload() > 0 && !duringReload) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            int maxReloadCheck = this->gun->getMaxReload();
            if ((maxReloadCheck == 12 || maxReloadCheck == 4 || maxReloadCheck == 36 || maxReloadCheck == 6 || maxReloadCheck == 2) && !bottomlessClip) { //is pistol or sniper or burst or shotgun or rocket
                if (semiAuto == true) {
                    this->gun->fire(p, bottomlessClip, this->doubleDamage, this->extendedMag);
                    semiAuto = false;
                }
            }
            else {
                this->gun->fire(p, this->bottomlessClip, this->doubleDamage, this->extendedMag);
            }
        }
    }
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) semiAuto = true;
    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
        std::thread t1(this->gun->changeReload(30));
        this->gun->changeReload(30);
    }*/

    //regenerating health
    if (this->health < this->maxHealth) {
        if (clock() - this->regenTimer > 3000 * this->regenMultiplier) {
            this->health+=2;
            this->regenTimer = clock();
        }
        if (this->health > this->maxHealth) this->health = this->maxHealth;
    }

    //if reloading && enough time has passed
    if (duringReload && clock() - initialReload > this->gun->getReloadTime())
    {
        duringReload = false;
        this->gun->changeReload(this->gun->getMaxReload());
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

Gun*& Player::getGun() {
    return this->gun;
}

int Player::getHealth() {
    return this->health;
}

void Player::setHealth(int health) {
    this->health = health;
    this->regenTimer = clock();
}

void Player::reload() {
    this->duringReload = true;
    this->initialReload = clock();
    if (contingencyResponse && this->gun->getReload() == 0) {
        sf::Vector2f temp = this->sprite.getPosition();
        sf::Vector2f thisGo(1, 0);
        for (int x = 0; x < 10; x++) { //18 shots * 20 degrees apart = 360 degrees
            thisGo.x = cos(36 * 3.141592653 / 180) * temp.x - sin(36 * 3.141592653 / 180) * temp.y;
            thisGo.y = sin(36 * 3.141592653 / 180) * temp.x + cos(36 * 3.141592653 / 180) * temp.y;
            //adding the explosion bullets to the vector at boomspot + the opposite direction 
            Bullet* explosion = new Bullet(this->sprite.getPosition(), thisGo, this->size, 10, this->explosionTexture, 2 + this->bulletHealth, 15);
            this->gun->getShots()->push_back(explosion);
            temp.x = thisGo.x;
            temp.y = thisGo.y;
        }
    }
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

int Player::getBulletHealth() {
    return this->bulletHealth;
}

void Player::setBottomlessClip(bool newValue) {
    this->bottomlessClip = newValue;
}

void Player::setDoubleDamage(bool newValue) {
    this->doubleDamage = newValue;
}

bool Player::getDoubleDamage() {
    return this->doubleDamage;
}

void Player::setDoubleMag(bool newValue) {
    this->extendedMag = newValue;
}

bool Player::getDoubleMag() {
    return this->extendedMag;
}

void Player::setReloadBoom(bool newValue) {
    this->contingencyResponse = newValue;
}

bool Player::getReloadBoom() {
    return this->contingencyResponse;
}

void Player::setSecondWind(bool newValue) {
    this->secondWind = newValue;
}

bool Player::getSecondWind() {
    return this->secondWind;
}
