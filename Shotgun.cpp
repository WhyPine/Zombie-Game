#include "Shotgun.h"
#include <iostream>

void Shotgun::fire(sf::Vector2f go)
{
    if (this->shottimer > 30) {
        sf::Vector2f v = this->sprite.getPosition();
        sf::Vector2f temp;
        temp.x = go.x;
        temp.y = go.y; 
        go.x = cos(-15 * 3.141592653 / 180) * temp.x - sin(-15 * 3.141592653 / 180) * temp.y;
        go.y = sin(-15 * 3.141592653 / 180) * temp.x + cos(-15 * 3.141592653 / 180) * temp.y;
        temp.x = go.x;
        temp.y = go.y;
        for (int x = 0; x < 7; x++) {
            go.x = cos(3 * 3.141592653 / 180) * temp.x - sin(3 * 3.141592653 / 180) * temp.y;
            go.y = sin(3 * 3.141592653 / 180) * temp.x + cos(3 * 3.141592653 / 180) * temp.y;
            this->shots->push_back(new Bullet(v, go, this->size));
            temp.x = go.x;
            temp.y = go.y;
        }
        std::cout << std::endl;
        this->reload--;
        this->shottimer = 0;
    }
}

int Shotgun::getMaxReload() {
    return 6;
}
