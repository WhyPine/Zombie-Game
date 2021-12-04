#pragma once
#include <SFML/Graphics.hpp>
#include "Gun.h"
#include "Shotgun.h"
#include "RPG.h"
#include "BurstRifle.h"
#include "Rifle.h"
#include <thread>
#include "Sniper.h"

class Player : public sf::CircleShape, sf::Sprite
{
private:
	bool semiAuto; //used for making pistol semi automatic
	sf::Vector2u size; 
	int health;
	int maxHealth;
	int regenTimer;
	double regenMultiplier;
	double speedMultiplier;
	double reloadMultiplier; 
	int money;
	sf::Sprite sprite; 
	Gun* gun; 
	sf::Texture* texture = new sf::Texture;
	int bulletHealth;
	bool bottomlessClip;
public:
	int getBulletHealth();
	int getMaxHealth();
	bool canshoot;
	Player(int newHealth, double newSpeedMultiplier, double newReloadMultiplier, sf::Vector2u newSize, int newBulletHealth, double newRegenMultiplier);
	void checkMove(sf::Vector2i gP);
	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	sf::Sprite getGunSprite();
	Gun*& getGun();
	int getHealth();
	void setHealth(int health);
	void reload(Gun* myGun);
	int getMoney();
	void setMoney(int newMoney);
	void setMaxHealth(int newMaxHealth);
	//double getStrength();
	//void setStrength(double newStrength);
	//double getSpeed();
	//void setSpeed(double newSpeed);
	void setPosition(sf::Vector2f v);
	bool setGun(Gun* newGun);
	sf::Vector2u getSize();
	void setBottomlessClip(bool newValue);
};

