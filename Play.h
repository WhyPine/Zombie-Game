/*****************************************************************************************
* Programmer: Josh Maloy, Aidan Gooding, Orion Green, Zach Fechko                        *
* Class: CptS 122, Fall 2021				                                             *
* Programming Assignment: PA9                                                            *
* Date: December 10, 2021                                                                *
* Description: This program defines all methods used by the main play file that runs the *
* game and also includes all necessary objects                                           *
******************************************************************************************/
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
#include "Sniper.h"
#include "bigboi.h"
#include "savefiles.h"

using std::vector;
using std::string;

	//void spawnZombies(sf::Vector2u size, Player* p1, int horde, float waitMultiplier);
	sf::Vector2f getZombieSpawn(Player* p1);
	void run(sf::RenderWindow& window, sf::View& view, save& saveFile, bool debug);
	void movement(sf::RenderWindow& window, Player* p1);
	void drawing(sf::RenderWindow& window, Player* p1, sf::Font& font);
	void makeTrue(sf::Vector2i& gP, Player* p1);
	void displayGUI(Player* p1, sf::RenderWindow& window, sf::Font& font, int zombies);
	//void displaySkillPointMenu(Player* p1, sf::RenderWindow& window);
	void dropMoney(Player* p1);
	void loadWalls();
	void bullets(Player* p1);
	sf::Vector2f doorCollision(Door& door, sf::Vector2f pos, int type, bool& collided);
	sf::Vector2f checkCollision(sf::FloatRect& thisWall, sf::Vector2f pos, int type, bool& collided); // 0 = zombie 1 = player


	