#include "Sniper.h"

Sniper::Sniper(sf::Vector2f pos, sf::Vector2u size) : Gun(pos, size) {
	this->reload = 4;
	this->maxReload = 4;
	this->shottimer = 0;
	this->power = 30;
    if (!this->bulletTexture.loadFromFile("rifleshot.png"))
    {
        std::cout << "Failed to load rifleshot" << std::endl;
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 256, 32));
    this->sprite.setPosition(pos);
    this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
}

void Sniper::fire(sf::Vector2f go) {
    if (this->shottimer > 75) {
        sf::Vector2f v = this->sprite.getPosition();
        this->shots->push_back(new Bullet(v, go, this->size, this->power, this->bulletTexture, 4));
        this->reload--;
        shottimer = 0;
    }
}

int Sniper::getReload() {
	return this->reload;
}

int Sniper::getMaxReload() {
	return this->maxReload;
}