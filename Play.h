#pragma once
#include "Player.h"
#include "Zombie.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Windows.h"

using std::vector;
using std::string;

	void spawnZombies(sf::Vector2u size);
	void run(sf::RenderWindow& window, sf::View& view);
	void movement(sf::RenderWindow& window, Player* p1);
	void drawing(sf::RenderWindow& window, Player* p1);
	void makeTrue(sf::Vector2i& gP, Player* p1);