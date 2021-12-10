/*****************************************************************************************
* Programmer: Josh Maloy, Aidan Gooding, Orion Green, Zach Fechko                        *
* Class: CptS 122, Fall 2021				                                             *
* Programming Assignment: PA9                                                            *
* Date: December 10, 2021                                                                *
* Description: This program implements the wall object and all necessary methods          *
******************************************************************************************/

#include "wall.h"


wall::wall(float x, float y, float width, float length) {
	this->walls = new sf::FloatRect(x, y, width, length);
}

wall::~wall() {

}

sf::FloatRect& wall::getWall() {
	return (*this->walls);
}