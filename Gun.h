#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
//#include "Player.h"
#include <vector>
#include <iostream>
using std::vector;

class Gun
{
protected:
	int maxReload; //max ammo capacity
	int reload; //current ammo ammount
	int shottimer; //frames between bullets
	int power; //how much damage it does
	int projS;
	int bulletHealth;
	int reloadDelay; //length of reload for the weapon in milliseconds
	vector<Bullet*>* shots;
	sf::Sprite sprite;
	sf::Vector2u size;
	sf::Texture texture;
	sf::Texture bulletTexture;
public:
	//virtual void fire(sf::Vector2f go, bool canShoot) = 0;
	virtual void run(sf::Vector2f pos, float rotation, bool hold) {};
	virtual void run(sf::Vector2f pos, float rotation, sf::Vector2f bulletDirection) {};
	virtual void mainHit(int zombieId) {};
	virtual int getMaxReload();
	Gun(sf::Vector2f pos, sf::Vector2u size, int newBulletHealth);
	virtual void run(sf::Vector2f pos, float rotation);
	virtual void fire(sf::Vector2f go, bool bottomlessClip);
	sf::Sprite getSprite();
	vector<Bullet*>* getShots();
	virtual int getReload();
	void changeReload(int add);
	void setReload(int value);
	virtual int getReloadTime();
	virtual bool canShoot(); //return false if shot delay
};

