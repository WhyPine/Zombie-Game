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
	bool doubleDamage;
	bool extendedMag;
	bool secondWind;
	bool contingencyResponse;
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
	sf::Texture explosionTexture;
	int bulletHealth;
	bool bottomlessClip;
	bool duringReload;
	int initialReload;
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
	void reload();
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
	void setDoubleDamage(bool newValue);
	bool getDoubleDamage();
	void setDoubleMag(bool newValue);
	bool getDoubleMag();
	void setReloadBoom(bool newValue);
	bool getReloadBoom();
	void setSecondWind(bool newValue);
	bool getSecondWind();
};

