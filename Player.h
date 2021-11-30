#pragma once
#include <SFML/Graphics.hpp>
#include "Gun.h"
#include <thread>

class Player : public sf::CircleShape, sf::Sprite
{
private:
	int health;
	int maxHealth;
	int regenTimer;
	int regenDelay;
	double speed;
	double damageP;
	int money;
	sf::Sprite sprite; 
	Gun* gun; 
	sf::Texture* texture = new sf::Texture;
public:
	int getMaxHealth();
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
	int getMoney();
	void setMoney(int newMoney);
	void setMaxHealth(int newMaxHealth);
	double getStrength();
	void setStrength(double newStrength);
	double getSpeed();
	void setSpeed(double newSpeed);
};

