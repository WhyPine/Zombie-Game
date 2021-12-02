#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
//#include "Player.h"
#include <vector>
using std::vector;

class Gun
{
protected:
	int maxReload;
	int reload;
	int shottimer;
	int power;
	int projS;
	vector<Bullet*>* shots;
	sf::Sprite sprite;
	sf::Vector2u size;
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

