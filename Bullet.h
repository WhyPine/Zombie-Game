#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	int damage;
	int projS;
	sf::Sprite sprite;
	sf::Vector2f go;
public:
	Bullet(sf::Vector2f start, sf::Vector2f go, sf::Vector2u size);
	void updatePosition();
	sf::Sprite getSprite();
};

