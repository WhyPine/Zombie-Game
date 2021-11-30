#include "wall.h"


wall::wall(float x, float y, float width, float length) {
	this->walls = new sf::FloatRect(x, y, width, length);
}

wall::~wall() {

}

sf::FloatRect wall::getWall() {
	return (*this->walls);
}