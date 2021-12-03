#include "Zombie.h"
#include <iostream>
#include <math.h>
#include <Windows.h>

Zombie::Zombie(int health, float speed, int damage, sf::Vector2u size, sf::Vector2f pos) {
    this->health = health;
    this->speed = speed;
    this->damage = damage;
    this->reload = 0;
    random = rand() & 64;
    this->texture->loadFromFile("zombie0.png");
    this->sprite.setTexture(*(this->texture));
    this->sprite.setTextureRect(sf::IntRect(10, 80, 240, 270));
    this->sprite.setScale((float)size.x / 7200, (float)size.y / 4400);
    this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
    this->sprite.setPosition(pos.x + random, pos.y + random);
}

Zombie::~Zombie() {
    //delete(this->texture);
}

void Zombie::getMove(Player* p1, sf::Vector2f pos) {
    sf::Vector2f v1 = p1->getPosition();
    sf::Vector2f v2 = this->sprite.getPosition();
    sf::Vector2f go = v1 - v2;
    float z = sqrtf(go.x * go.x + go.y * go.y);
    int randomMovement = (rand() % 100)+1;
    if (randomMovement % 2 == 0) randomMovement = -1 * randomMovement;
    for (int i = 0; i < 2; i++)
    {
        this->sprite.move((1 * ((go.x / z)) * this->speed + (double)randomMovement / 200), (1 * ((go.y / z)) * this->speed + (double)randomMovement / 200));
    }
    this->setPosition(this->sprite.getPosition()); // making sure that the zombie cannot go out of bounds

    sf::Vector2f v = this->sprite.getPosition();
    sf::Vector2f p;

    p.x = pos.x - v.x;
    p.y = pos.y - v.y;
    //std::cout << p.x << ": " << p.y << std::endl;
    float result;
    float param;
    if (p.x > 0) {
        param = p.y / p.x;
        result = atanf(param) * 180 / (float)(3.141592653589793);
        //std::cout << result << std::endl;
        result -= 360;
    }
    else if (p.x < 0) {
        param = p.y / p.x;
        result = atanf(param) * 180.0 / (float)(3.141592653589793);
        //std::cout << result << std::endl;
        result += 180;
    }
    else {
        result = this->sprite.getRotation();
    }
    this->sprite.setRotation(result);
}

sf::Sprite Zombie::getSprite() {
    return this->sprite;
}

int Zombie::getDamage() {
    return this->damage;
}

int Zombie::getReload() {
    int result = 1;
    if (clock() - reload > 950) {
        result = 0;
        this->reload = clock();
    }
    return result;
}

int Zombie::getHealth() {
    return this->health;
}

void Zombie::setHealth(int health) {
    this->health = health;
}

void Zombie::attack(Player* p1) {
    Sleep(900);
    double size = 0.75;
    //makes the collision box for the player change size by a factor of size
    /*sf::FloatRect pSafeZone = p1->getSprite().getGlobalBounds();
    pSafeZone.top += ((pSafeZone.height / 2) - (pSafeZone.height * size / 2));
    pSafeZone.left += ((pSafeZone.width / 2) - (pSafeZone.width * size / 2));
    pSafeZone.height = pSafeZone.height * size;
    pSafeZone.width = pSafeZone.width * size;*/
    if (this->sprite.getGlobalBounds().intersects(p1->getSprite().getGlobalBounds())) {
        p1->setHealth(p1->getHealth() - this->getDamage());
        std::cout << p1->getHealth() << std::endl;
    }
}

void Zombie::setPosition(sf::Vector2f v) {
    if (v.x > 2540) v.x = 2540;
    else if (v.x < 20) v.x = 20;
    if (v.y > 1420) v.y = 1420;
    else if (v.y < 20) v.y = 20;
    this->sprite.setPosition(v);
}

void Zombie::getOutDaWay(Player* p1, Zombie* z2) //this zombie is moving away from z2 is the one not moving
{
    int randomMovement = (rand() % 100) + 1;

    //getting distance to player and zombie
    float pxUnit = this->getSprite().getPosition().x - p1->getPosition().x;
    float pyUnit = this->getSprite().getPosition().y - p1->getPosition().y;
    float zxUnit = this->getSprite().getPosition().x - z2->getSprite().getPosition().x;
    float zyUnit = this->getSprite().getPosition().y - z2->getSprite().getPosition().y;

    float pDenom = sqrtf(pxUnit * pxUnit + pyUnit * pyUnit);
    float zDenom = sqrtf(zxUnit * zxUnit + zyUnit * zyUnit);
    if (zDenom == 0) zDenom = 1;
    if (pDenom == 0) pDenom = 1;

    //changing the coords to a unit vector
    pxUnit = pxUnit / pDenom;
    pyUnit = pyUnit / pDenom;
    zxUnit = zxUnit / zDenom;
    zyUnit = zyUnit / zDenom;
    //adding them together - player is weighted 1/3, other zombie is weighted 2/3
    zxUnit = (1 / 3) * pxUnit + (2) * zxUnit;
    zyUnit = (1 / 3) * pyUnit + (2) * zyUnit;

    //adding random movement
    
    if (randomMovement % 2 == 0) randomMovement = -1 * randomMovement;
    for (int i = 0; i < 2; i++)
    {
        this->sprite.move((zxUnit * this->speed + (double)randomMovement / 200), (zyUnit * this->speed + (double)randomMovement / 200));
    }
    this->setPosition(this->sprite.getPosition());


    sf::Vector2f v = this->sprite.getPosition();
    sf::Vector2f p;

    p.x = p1->getPosition().x - v.x;
    p.y = p1->getPosition().y - v.y;
    //std::cout << p.x << ": " << p.y << std::endl;
    long float result;
    long float param;
    if (p.x > 0) {
        param = p.y / p.x;
        result = atanf(param) * 180 / (float)(3.141592653589793);
        //std::cout << result << std::endl;
        result -= 360;
    }
    else if (p.x < 0) {
        param = p.y / p.x;
        result = atanf(param) * 180 / (float)(3.141592653589793);
        //std::cout << result << std::endl;
        result += 180;
    }
    else {
        result = this->sprite.getRotation();
    }
    this->sprite.setRotation(result);
}