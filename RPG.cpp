#include "RPG.h"


RPG::RPG(sf::Vector2f pos, sf::Vector2u size) : Gun(pos, size) {
    this->reload = 3;
    this->maxReload = 3;
    this->shotbull = nullptr;
    explode = false;
    fired = false;
    if (!this->bulletTexture.loadFromFile("rpgshot.png"))
    {
        std::cout << "Failed to load rpgshot" << std::endl;
    }
    if (!this->rocketTexture.loadFromFile("rpgmainshot.png"))
    {
        std::cout << "Failed to load rpgmainshot" << std::endl;
    }
};

void RPG::run(sf::Vector2f pos, float rotation, bool hold) {
    this->power = 5;
    this->explode = !hold;
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
    if (!fired) boomSpot = pos;
    if (fired && hold && this->shots->size() > 0 && hold) {
        this->boomSpot = this->shots[0].at(0)->getSprite().getPosition();
    }

    //find the shot

    if (this->fired) {
        if (hitSomething(this->shotbull) || this->explode) {
            this->shotbull = nullptr;
            sf::Vector2f temp;
            sf::Vector2f go;
            temp.x = boomSpot.x;
            temp.y = boomSpot.y;
            for (int x = 0; x < 18; x++) {
                go.x = cos(20 * 3.141592653 / 180) * temp.x - sin(20 * 3.141592653 / 180) * temp.y;
                go.y = sin(20 * 3.141592653 / 180) * temp.x + cos(20 * 3.141592653 / 180) * temp.y;
                this->shots->push_back(new Bullet(boomSpot, go, this->size, this->power, this->bulletTexture));
                temp.x = go.x;
                temp.y = go.y;
            }
            this->fired = false;
        }        
    }
}

void RPG::fire(sf::Vector2f go)
{
    if (this->shottimer > 60 && this->shotbull == nullptr) { //if 45 frames since last shot and there isnt already been a shot
        this->fired = true;
        sf::Vector2f v = this->sprite.getPosition();
        this->shotbull = new Bullet(v, go, this->size, this->power, this->rocketTexture);
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

bool RPG::hitSomething(Bullet* bullet)
{
    bool result = true;
    for (int x = 0; x < this->shots->size(); x++) {
        if (this->shots->at(x) != nullptr) {
            if (bullet == shots->at(x)) {
                result = false;
            }
        }
    }
    return result;
}