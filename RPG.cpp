#include "RPG.h"

void RPG::run(sf::Vector2f pos, float rotation) {
    this->shottimer++;
    this->sprite.setRotation(rotation);
    double xPos, yPos;
    if (rotation < 0) rotation += 360;
    rotation += 30;
    sf::Vector2f newVector(pos.x + cos((3.141592653 / 180) * rotation) * 12, pos.y + sin((3.141592653 / 180) * rotation) * 12);
    this->sprite.setPosition(newVector);
    for (std::vector<Bullet*>::iterator it = this->shots->begin(); it != this->shots->end(); ++it) {
        if (*it != nullptr) {
            (*it)->updatePosition();
        }
    }

    if (shotbull != nullptr && shottimer == 30) {
        sf::Vector2f v = this->shotbull->getSprite().getPosition();
        shotbull = nullptr;
        sf::Vector2f temp;
        sf::Vector2f go;
        temp.x = v.x;
        temp.y = v.y;
        for (int x = 0; x < 18; x++) {
            go.x = cos(20 * 3.141592653 / 180) * temp.x - sin(20 * 3.141592653 / 180) * temp.y;
            go.y = sin(20 * 3.141592653 / 180) * temp.x + cos(20 * 3.141592653 / 180) * temp.y;
            this->shots->push_back(new Bullet(v, go, this->size));
            temp.x = go.x;
            temp.y = go.y;
        }
    }
}

void RPG::fire(sf::Vector2f go)
{
    if (this->shottimer > 30 && this->shotbull == nullptr) {
        sf::Vector2f v = this->sprite.getPosition();
        this->shotbull = new Bullet(v, go, this->size);
        this->shots->push_back(shotbull);
        this->reload--;
        shottimer = 0;
    }
}

int RPG::getReload()
{
    return this->reload;
}

int RPG::getMaxReload()
{
    return 3;
}