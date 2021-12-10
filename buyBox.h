/*****************************************************************************************
* Programmer: Josh Maloy, Aidan Gooding, Orion Green, Zach Fechko                        *
* Class: CptS 122, Fall 2021				                                             *
* Programming Assignment: PA9                                                            *
* Date: December 10, 2021                                                                *
* Description: This program defines the buybox object and all necessary methods          *
******************************************************************************************/
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

