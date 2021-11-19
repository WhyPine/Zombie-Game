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
	float random;
	Zombie(int health, int speed, int damage, sf::Vector2u size, sf::Vector2f pos);
	void getMove(Player* p1);
	sf::Sprite getSprite();
};

