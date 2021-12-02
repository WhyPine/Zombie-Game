#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	int damage;
	int projS;
	int health;
	sf::Sprite sprite;
	sf::Vector2f go;
public:
	Bullet(sf::Vector2f start, sf::Vector2f go, sf::Vector2u size, int newDamage);
	~Bullet();
	void updatePosition();
	sf::Sprite getSprite();
	int getHealth();
	int getDamage();
	void setHealth(int value);
};

