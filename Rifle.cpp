#include "Rifle.h"

Rifle::Rifle(sf::Vector2f pos, sf::Vector2u size, int newBulletHealth) : Gun(pos, size, newBulletHealth) {
    this->reloadDelay = 1250; //1.25 second reload for rifle
    this->bulletHealth = newBulletHealth;
    this->power = 5;
    if (!this->texture.loadFromFile("rifle.png"))
    {
        std::cout << "Failed to load rifle" << std::endl;
    }
    if (!this->bulletTexture.loadFromFile("rifleshot.png"))
    {
        std::cout << "Failed to load rifleshot" << std::endl;
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 256, 32));
    this->reload = 30;
    this->maxReload = 30;
    this->sprite.setPosition(pos);
    this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
}

void Rifle::fire(sf::Vector2f go, bool bottomlessClip) {
    if (this->shottimer > 6) {
        sf::Vector2f v = this->sprite.getPosition();
        this->shots->push_back(new Bullet(v, go, this->size, this->power, this->bulletTexture, 1 + this->bulletHealth, 15));
        if(!bottomlessClip) this->reload--;
        shottimer = 0;
    }
}

int Rifle::getReload() {
	return this->reload;
}

int Rifle::getMaxReload() {
	return 30;
}

int Rifle::getReloadTime() {
    return this->reloadDelay;
}
