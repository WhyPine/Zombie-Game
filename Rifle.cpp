#include "Rifle.h"

Rifle::Rifle(sf::Vector2f pos, sf::Vector2u size) : Gun(pos, size) {
    this->power = 5;
    if (!this->texture.loadFromFile("rifle.png"))
    {
        std::cout << "Error occured" << std::endl;
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 256, 32));
    this->reload = 30;
    this->maxReload = 30;
    this->sprite.setPosition(pos);
    this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
}

void Rifle::fire(sf::Vector2f go) {
    if (this->shottimer > 6) {
        sf::Vector2f v = this->sprite.getPosition();
        this->shots->push_back(new Bullet(v, go, this->size, this->power));
        this->reload--;
        shottimer = 0;
    }
}

int Rifle::getReload() {
	return this->reload;
}

int Rifle::getMaxReload() {
	return 30;
}
