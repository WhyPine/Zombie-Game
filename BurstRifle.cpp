#include "BurstRifle.h"

void BurstRifle::fire(sf::Vector2f go)
{
	if (this->shottimer > 28)
	{
		sf::Vector2f v = this->sprite.getPosition();
		sf::Vector2f spacing(go.x * 24 / sqrtf(go.x * go.x + go.y * go.y), go.y * 24 / sqrtf(go.x * go.x + go.y * go.y));
		for (int i = 0; i < 4; ++i)
		{
			this->shots->push_back(new Bullet(v, go, this->size, this->power));
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