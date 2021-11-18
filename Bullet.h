#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	int damage;
	int projS;
	sf::Sprite sprite;
public:
	Bullet(sf::Vector2f start, sf::Vector2i go, sf::Vector2u size);
	void updatePosition();
};

