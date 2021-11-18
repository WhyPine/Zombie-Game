#include "Player.h"
#include <iostream>
#include <math.h>

Player::Player(int health, double speed, double damageP, sf::Vector2u size) {
	this->health = health;
	this->speed = speed;
	this->damageP = damageP;

   /* sf::Vector2f newSize;
    newSize.x =(float)size.x / 1600; 
    newSize.y = (float)size.y / 900;
    this->shape.setScale(newSize);
    this->shape.setFillColor(sf::Color(100, 250, 50));*/

    sf::Texture texture;
    texture.loadFromFile("skeleton-attack_0.png");
    this->sprite.setTexture(texture);
    if (!texture.loadFromFile("image.png", sf::IntRect(10, 10, 32, 32)))
    {
        std::cout << "Error occured" << std::endl;
    }
    this->sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));
    this->sprite.setScale((float)size.x / 1600, (float)size.y / 900);
    this->sprite.setColor(sf::Color(24, 219, 34));
    this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2, this->sprite.getGlobalBounds().height / 2);
    this->g = new Gun(this->sprite.getPosition(), size);
}
void Player::checkMove(sf::RenderWindow& window) {

    sf::Vector2i gP = sf::Mouse::getPosition();
    sf::Vector2f v = this->sprite.getPosition();
    //float r = this->sprite.getRotation();
    sf::Vector2f p;
    p.x = gP.x - v.x;
    p.y = gP.y - v.y;
    float param = p.y / p.x;
    float result = ((float)atan(param)) * 180 / (3.141592653589793);

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
    this->g->
}

sf::Sprite Player::getSprite() {
    return this->sprite;
}

sf::Vector2f Player::getPosition() {
    return this->sprite.getPosition();
}

