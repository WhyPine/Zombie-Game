#pragma once
#include "Player.h"


class Zombie
{
private:
	int health;
	int speed;
	int damage;
	sf::Sprite sprite;
	sf::Texture* texture = new sf::Texture;
public:
	float random;
	Zombie(int health, int speed, int damage, sf::Vector2u size, sf::Vector2f pos);
	void getMove(Player* p1, sf::Vector2f pos);
	sf::Sprite getSprite();
};

