#include "Shotgun.h"

void Shotgun::fire(sf::Vector2f go)
{
    if (this->shottimer > 30) {
        sf::Vector2f v = this->sprite.getPosition();
        int xMultiplier = 1, yMultiplier = 1;
        int xUnit; int yUnit;
        if (go.x > v.x) { // if shooting top right of player
            xMultiplier = -1;
        }
        if (go.y > v.y) {
            yMultiplier = -1;
        }
        xUnit = ((go.x - v.x) / sqrt((go.x - v.x) * (go.x - v.x) + (go.y - v.y) * (go.y - v.y)));
        yUnit = ((go.y - v.y) / sqrt((go.x - v.x) * (go.x - v.x) + (go.y - v.y) * (go.y - v.y)));
        go.x = (xUnit + cos(-10 * 3.141592653 / 180)) * go.x;
        go.y = (yUnit + cos(-10 * 3.141592653 / 180)) * go.y;
        this->shots->push_back(new Bullet(v, go, this->size));
        go.x = (xUnit + cos(-5 * 3.141592653 / 180)) * go.x;
        go.y = (yUnit + cos(-5 * 3.141592653 / 180)) * go.y;
        this->shots->push_back(new Bullet(v, go, this->size));
        go.x = (xUnit + cos(0 * 3.141592653 / 180)) * go.x;
        go.y = (yUnit + cos(0 * 3.141592653 / 180)) * go.y;
        this->shots->push_back(new Bullet(v, go, this->size));
        go.x = (xUnit + cos(5 * 3.141592653 / 180)) * go.x;
        go.y = (yUnit + cos(5 * 3.141592653 / 180)) * go.y;
        this->shots->push_back(new Bullet(v, go, this->size));
        go.x = (xUnit + cos(10 * 3.141592653 / 180)) * go.x;
        go.y = (yUnit + cos(10 * 3.141592653 / 180)) * go.y;
        this->shots->push_back(new Bullet(v, go, this->size));
        this->reload--;
        this->shottimer = 0;
    }
}

int Shotgun::getMaxReload() {
    return 6;
}
