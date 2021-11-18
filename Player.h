#pragma once
#include <SFML/Graphics.hpp>
#include "Gun.h"
class Player : public sf::CircleShape, sf::Sprite
{
private:
	int health;
	double speed;
	double damageP;
	sf::Sprite sprite;
	Gun* g;
	//sf::CircleShape shape;

public:
	Player(int health, double speed, double damageP, sf::Vector2u size);
	void checkMove(sf::RenderWindow& window);
	sf::Sprite getSprite();
	sf::Vector2f getPosition();
};

