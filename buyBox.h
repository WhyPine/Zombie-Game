#pragma once
#include "wall.h"
#include <iostream>
#include "Player.h"
class buyBox :
    public wall
{
public:
    buyBox(float x, float y, int newPrice, int newType) : wall(x, y, 64, 32) {

        this->type = newType;
        if (this->type == 0) {
            this->name = "Pistol";
            if (!boxTexture.loadFromFile("pistolbox.png")) {
                std::cout << "Pistol Box texture failed to load" << std::endl;
            }
        }
        else if (this->type == 1) {
            this->name = "Rifle";
            if (!boxTexture.loadFromFile("riflebox.png")) {
                std::cout << "Rifle Box texture failed to load" << std::endl;
            }
        }
        else if (this->type == 2) {
            this->name = "Shotgun";
            if (!boxTexture.loadFromFile("shotgunbox.png")) {
                std::cout << "Shotgun Box texture failed to load" << std::endl;
            }
        }
        else if (this->type == 3) {
            this->name = "HellFire Launcher";
            if (!boxTexture.loadFromFile("shotgunbox.png")) {
                std::cout << "Hell Fire Launcher texture failed to load" << std::endl;
            }
        }
        
        this->box = new sf::RectangleShape(sf::Vector2f((float)this->walls->width / 4800, (float)this->walls->height / 4800));
        this->box->setPosition(x, y);
        this->box->setSize(sf::Vector2f(64, 32));
        this->boxPrice = newPrice;
        this->box->setTexture(&boxTexture);
        this->lastBought = 0;
    }
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

