#pragma once
#include "wall.h"
#include <iostream>
#include "Player.h"
class buyBox :
    public wall
{
public:
    buyBox(float x, float y, int newPrice, int newType);
    bool canBuy(Player& p1);
    void buy(Player& p1);
    void drawBox(sf::RenderWindow& window);
    std::string getName();
    int getPrice();
private:
    std::string name;
    int type;
    sf::Texture boxTexture;
    sf::RectangleShape* box;
    int boxPrice;
    int lastBought;
};

