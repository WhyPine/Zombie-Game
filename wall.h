/*****************************************************************************************
* Programmer: Josh Maloy, Aidan Gooding, Orion Green, Zach Fechko                        *
* Class: CptS 122, Fall 2021				                                             *
* Programming Assignment: PA9                                                            *
* Date: December 10, 2021                                                                *
* Description: This program defines the wall object and all necessary methods            *
******************************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>


class wall
{
protected:
	sf::FloatRect* walls;


public:
	wall(float x = 0, float y = 0, float width = 32, float length = 32);
	~wall();
	sf::FloatRect& getWall();
};

