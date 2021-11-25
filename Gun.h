#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
//#include "Player.h"
#include <vector>
using std::vector;

class Gun
{
private:
	int reload;
	int shottimer;
	int power;
	int projS;
	vector<Bullet*>* shots;
	sf::Sprite sprite;
	sf::Vector2u size;
public:
	Gun(sf::Vector2f pos, sf::Vector2u size);
	void run(sf::Vector2f pos, float rotation);
	void fire(sf::Vector2f go);
	sf::Sprite getSprite();
	vector<Bullet*>* getShots();
	int getReload();
	void changeReload(int add);
	void setReload(int value);
};

