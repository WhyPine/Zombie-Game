#pragma once
#include "Player.h"

class Zombie
{
private:
	int health;
	int speed;
	int damage;
	sf::Sprite sprite;
public:
	Zombie(int health, int speed, int damage, sf::Vector2u size);
	void getMove(Player* p1);
	sf::Sprite getSprite();
};

