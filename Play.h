#pragma once
#include "Player.h"
#include "Zombie.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Windows.h"
#include "wall.h"

using std::vector;
using std::string;

	void spawnZombies(sf::Vector2u size, Player* p1);
	void run(sf::RenderWindow& window, sf::View& view);
	void movement(sf::RenderWindow& window, Player* p1);
	void drawing(sf::RenderWindow& window, Player* p1);
	void makeTrue(sf::Vector2i& gP, Player* p1);
	void displayGUI(Player* p1, sf::RenderWindow& window);