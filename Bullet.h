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

