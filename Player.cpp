#include "Player.h"
#include <iostream>
#include <math.h>

Player::Player(int health, double speed, double damageP, sf::Vector2u size) {
	this->health = health;
	this->speed = speed;
	this->damageP = damageP;
    this->sprite.setPosition(0.f, 10.f);
    sf::Texture texture;
    texture.loadFromFile("skeleton-attack_0.png");
    this->sprite.setTexture(texture);
    if (!texture.loadFromFile("skeleton-attack_0.png", sf::IntRect(10, 10, 32, 32)))
    {
        std::cout << "Error occured - Player" << std::endl;
    }
    this->sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));
    this->sprite.setScale((float)size.x / 1600, (float)size.y / 900);
    this->sprite.setColor(sf::Color(24, 219, 34));
    this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2, this->sprite.getGlobalBounds().height / 2);
    this->gun = new Gun(this->sprite.getPosition(), size); 
}

void Player::checkMove(sf::RenderWindow& window) {

    sf::Vector2i gP = sf::Mouse::getPosition(window);
    sf::Vector2f v = this->sprite.getPosition();
    sf::Vector2f p;

    p.x = gP.x - v.x;
    p.y = gP.y - v.y;
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
   // std::cout << result;
    //float result = ((float)atan(param)) * 180 / (3.141592653589793);

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
    //window.clear();
    //window.draw(this->gun->getSprite());
    //window.display();
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
       this->gun->fire(p); 
    }

} //leave everything commented except the Gun* gun; does it still error? Yeah Ill ss i can see the error list

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
