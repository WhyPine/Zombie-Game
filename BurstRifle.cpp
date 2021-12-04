#include "BurstRifle.h"

BurstRifle::BurstRifle(sf::Vector2f pos, sf::Vector2u size, int newBulletHealth) : Gun(pos, size, newBulletHealth) {
	this->reloadDelay = 1250;
	this->bulletHealth = newBulletHealth;
	this->reload = 36;
	this->maxReload = 36;
	if (!this->bulletTexture.loadFromFile("rifleshot.png"))
	{
		std::cout << "Failed to load Burst Rifle shot" << std::endl;
	}
}

void BurstRifle::fire(sf::Vector2f go, bool bottomelessClip)
{
	if (this->shottimer > 28)
	{
		sf::Vector2f v = this->sprite.getPosition();
		sf::Vector2f spacing(go.x * 24 / sqrtf(go.x * go.x + go.y * go.y), go.y * 24 / sqrtf(go.x * go.x + go.y * go.y));
		for (int i = 0; i < 4; ++i)
		{
			this->shots->push_back(new Bullet(v, go, this->size, this->power, this->bulletTexture, 1 + this->bulletHealth, 15));
			this->reload--;
			v -= spacing;
		}
		shottimer = 0;
	}
}

int BurstRifle::getReload()
{
	return this->reload;
}

int BurstRifle::getMaxReload()
{
	return this->maxReload;
}

int BurstRifle::getReloadTime() {
	return this->reloadDelay;
}