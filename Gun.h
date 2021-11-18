#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Player.h"
#include <vector>
using std::vector;

class Gun
{
private:
	int power;
	int projS;
	vector<Bullet*> shots;
	sf::Sprite sprite;
	sf::Vector2u size;
public:
	Gun(sf::Vector2f pos, sf::Vector2u size);
	void run(Player* p1);
	void fire();
};

