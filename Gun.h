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
	vector<Bullet*>* shots;
	sf::Sprite sprite;
	sf::Vector2u size;
	sf::Texture texture;
public:
	virtual int getMaxReload();
	Gun(sf::Vector2f pos, sf::Vector2u size);
	virtual void run(sf::Vector2f pos, float rotation);
	virtual void fire(sf::Vector2f go);
	sf::Sprite getSprite();
	vector<Bullet*>* getShots();
	virtual int getReload();
	void changeReload(int add);
	void setReload(int value);
};

