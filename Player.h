#pragma once
#include <SFML/Graphics.hpp>
#include "Gun.h"
#include <thread>

class Player : public sf::CircleShape, sf::Sprite
{
private:
	int health;
	double speed;
	double damageP;
	sf::Sprite sprite; 
	Gun* gun; 
	sf::Texture* texture = new sf::Texture;
public:
	bool canshoot;
	Player(int health, double speed, double damageP, sf::Vector2u size);
	void checkMove(sf::Vector2i gP);
	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	sf::Sprite getGunSprite();
	Gun* getGun();
	int getHealth();
	void setHealth(int health);
	void reload(int value);
};

