#pragma once
#include "Player.h"
#include "Zombie.h"
#include "RunnerZombie.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Windows.h"
#include "wall.h"
#include "Door.h"
#include <mutex>
#include "buyBox.h"

using std::vector;
using std::string;

	void spawnZombies(sf::Vector2u size, Player* p1);
	void run(sf::RenderWindow& window, sf::View& view);
	void movement(sf::RenderWindow& window, Player* p1);
	void drawing(sf::RenderWindow& window, Player* p1, sf::Font& font);
	void makeTrue(sf::Vector2i& gP, Player* p1);
	void displayGUI(Player* p1, sf::RenderWindow& window, sf::Font& font, int zombies);
	//void displaySkillPointMenu(Player* p1, sf::RenderWindow& window);
	void dropMoney(Player* p1);
	void loadWalls();
	void bullets(Player* p1);
	sf::Vector2f checkCollision(sf::FloatRect thisWall, sf::Vector2f pos, int type, bool& collided); // 0 = zombie 1 = player