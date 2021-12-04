#pragma once
#include "Player.h"


class Zombie
{
protected:
	int reload;
	int health;
	int maxHealth;
	float speed;
	int damage;
	sf::Sprite sprite;
	sf::Texture* texture = new sf::Texture;
	int id;
	sf::RectangleShape healthFront;
	sf::RectangleShape healthBack;
public:
	sf::RectangleShape getHealthFront();
	sf::RectangleShape getHealthBack();
	float random;
	Zombie(int health, float speed, int damage, sf::Vector2u size, sf::Vector2f pos);
	~Zombie();
	void getMove(Player* p1, sf::Vector2f pos);
	sf::Sprite getSprite();
	int getDamage();
	int getReload();
	int getHealth();
	void setHealth(int health);
	void attack(Player* p1);
	void setPosition(sf::Vector2f v);
	void getOutDaWay(Player* p1, Zombie* z2);
	int getId();
	int getMaxHealth();
};

