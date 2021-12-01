#pragma once
#include <SFML/Graphics.hpp>


class wall
{
protected:
	sf::FloatRect* walls;


public:
	wall(float x = 0, float y = 0, float width = 32, float length = 32);
	~wall();
	virtual sf::FloatRect getWall();
};

