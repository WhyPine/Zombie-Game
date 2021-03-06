/*****************************************************************************************
* Programmer: Josh Maloy, Aidan Gooding, Orion Green, Zach Fechko                        *
* Class: CptS 122, Fall 2021				                                             *
* Programming Assignment: PA9                                                            *
* Date: December 10, 2021                                                                *
* Description: This program implements the door object and all necessary methods         *
******************************************************************************************/

#include "Door.h"


bool Door::canOpen(Player& p1) {
	bool result = false;
	float x1 = this->walls->left + this->walls->width / 2;
	float y1 = this->walls->top + this->walls->height / 2;
	if (sqrt(pow(p1.getPosition().x - x1, 2) + pow(p1.getPosition().y - y1, 2)) < 64) {
		result = true;
	}
	return result;
}

void Door::open() {
	this->isOpen = true;
}

bool Door::isClosed() {
	return !this->isOpen;
}

void Door::drawDoor(sf::RenderWindow& window) {
	window.draw(*this->door);
}

int Door::getCost() {
	return this->doorPrice;
}

bool Door::getType() {
	return this->orientation;
}
