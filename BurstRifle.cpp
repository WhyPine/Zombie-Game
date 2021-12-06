#include "BurstRifle.h"

BurstRifle::BurstRifle(sf::Vector2f pos, sf::Vector2u size, int newBulletHealth) : Gun(pos, size, newBulletHealth) {
	this->reloadDelay = 1250;
	this->bulletHealth = newBulletHealth;
	this->reload = 36;
	this->maxReload = 36;
	this->fired = false;
	this->lastShot = 0;
	this->numShots = 4;
	this->power = 5;
	if (!this->bulletTexture.loadFromFile("rifleshot.png"))
	{
		std::cout << "Failed to load Burst Rifle shot" << std::endl;
	}
}

void BurstRifle::fire(sf::Vector2f go, bool bottomelessClip, bool doubleDamage, bool doubleMag)
{
	if (doubleDamage && this->power == 5) this->power = 10;
	else if (!doubleDamage && this->power != 5) this->power = 10;
	if (doubleMag && this->maxReload == 36) this->maxReload = 72;
	else if (!doubleMag && this->maxReload != 36) this->maxReload = 36;

	if (this->shottimer > 40)
	{
		std::cout << "Updating fired to true" << std::endl;
		this->fired = true; //the gun has been fired
		this->shottimer = 0;
		this->numShots = 4;
		if (!bottomelessClip) this->reload -= 4;
	}
}

/*
How to do run:
when fired = true
for each shot decrease an iterator by 1 four times as well as setting fired to false
*/
void BurstRifle::run(sf::Vector2f pos, float rotation, sf::Vector2f bulletDirection)
{
	this->shottimer++;
	if (rotation < 0) rotation += 360;
	rotation += 30;
	sf::Vector2f newVector(pos.x + cos((3.141592653 / 180) * rotation) * 12, pos.y + sin((3.141592653 / 180) * rotation) * 12);
	sprite.setPosition(newVector);
	for (std::vector<Bullet*>::iterator it = this->shots->begin(); it != this->shots->end(); ++it) {
		if (*it != nullptr) {
			(*it)->updatePosition(); //moving all the bullets
		}
	}
	std::cout << "fired = " << fired << "  numShots = " << numShots << std::endl;
	if (this->fired)
	{
		std::cout << "in fired" << std::endl;
		if (clock() - lastShot > 62.5)
		{
			this->numShots--;
			this->shots->push_back(new Bullet(newVector, bulletDirection, this->size, this->power, this->bulletTexture, 1 + this->bulletHealth, 15));
			std::cout << "BOOM   shotsSize = " << this->shots->size() << std::endl;
			this->lastShot = clock();
		}
	}
	if (this->numShots == 0) this->fired = false;
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

bool BurstRifle::canShoot() {
	return this->shottimer > 40; //temp
}