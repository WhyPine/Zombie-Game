/*****************************************************************************************
* Programmer: Josh Maloy, Aidan Gooding, Orion Green, Zach Fechko                        *
* Class: CptS 122, Fall 2021				                                             *
* Programming Assignment: PA9                                                            *
* Date: December 10, 2021                                                                *
* Description: This program defines the bullet object and all necessary methods          *
******************************************************************************************/
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
	sf::Texture& texture;
	std::vector<int> zombiesHit;
public:
	Bullet(sf::Vector2f start, sf::Vector2f newGo, sf::Vector2u size, int newDamage, sf::Texture& newTexture, int newHealth, int newSpeed);
	~Bullet();
	void updatePosition();
	sf::Sprite& getSprite();
	int getHealth();
	int getDamage();
	void setHealth(int value);
	bool hasHit(int zombieId);
	void hit(int zombieId);
};

