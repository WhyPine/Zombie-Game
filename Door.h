#pragma once
#include "wall.h"
#include "Player.h"
#include <iostream>

class Door :
    public wall
{
public:
    Door(float x, float y, bool isFlat, int newPrice) : wall(x, y, 128, 32) {
        if (!doorTexture.loadFromFile("Door.png")) {
            std::cout << "Door texture failed to load" << std::endl;
        }
        this->door = new sf::RectangleShape(sf::Vector2f((float)this->walls->width / 4800, (float)this->walls->height / 4800));
        this->door->setPosition(x, y);
        this->door->setSize(sf::Vector2f(128, 32));
        if (!isFlat) {
            this->walls->width = 32;
            this->walls->height = 128;
            if (!doorTexture.loadFromFile("Door2.png")) {
                std::cout << "Door texture failed to load" << std::endl;
            }
            this->door->setSize(sf::Vector2f(32, 128));
        }
        this->doorPrice = newPrice;
        this->isOpen = false;
        this->door->setTexture(&doorTexture);
    }
    bool canOpen(Player& p1);
    void open();
    void drawDoor(sf::RenderWindow& window);
    bool isClosed();
    int getCost();
private:
    int doorPrice;
    sf::Texture doorTexture;
    sf::RectangleShape* door;
    bool isOpen;
    
};

