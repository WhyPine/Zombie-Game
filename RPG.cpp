#include "RPG.h"


RPG::RPG(sf::Vector2f pos, sf::Vector2u size, int newBulletHealth) : Gun(pos, size, newBulletHealth) {
    this->reloadDelay = 1750;
    this->bulletHealth = newBulletHealth;
    this->reload = 2;
    this->maxReload = 2;
    this->shotbull = nullptr;
    this->explode = false;
    this->fired = false;
    this->zombieXploded = 0;
    if (!this->texture.loadFromFile("RPGSprite.png")) //explosion
    {
        std::cout << "Failed to load rpgsprite" << std::endl;
    }
    if (!this->bulletTexture.loadFromFile("rpgshot.png")) //explosion
    {
        std::cout << "Failed to load rpgshot" << std::endl;
    }
    if (!this->rocketTexture.loadFromFile("rpgmainshot.png")) //rocket
    {
        std::cout << "Failed to load rpgmainshot" << std::endl;
    }
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 256, 32));
    this->sprite.setPosition(pos);
    this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
};

void RPG::run(sf::Vector2f pos, float rotation, bool hold) {
    this->power = 10;
    this->explode = !hold; //explode = true if mouse left is let go
    this->shottimer++;
    this->sprite.setRotation(rotation);
    if (rotation < 0) rotation += 360;
    rotation += 30;
    sf::Vector2f newVector(pos.x + cos((3.141592653 / 180) * rotation) * 12, pos.y + sin((3.141592653 / 180) * rotation) * 12);
    this->sprite.setPosition(newVector);
    for (std::vector<Bullet*>::iterator it = this->shots->begin(); it != this->shots->end(); ++it) {
        if (*it != nullptr) {
            (*it)->updatePosition(); //moving all the bullets
        }
    }
    if (!fired) this->boomSpot = pos; //updating explosion location to the last position of the character before it is fired -> incase you click fast it should explode on character
    if (fired && hold && this->shots->size() > 0 && !this->hitSomething(this->shotbull)) { //if you shot, holding mouse, and there still is a bullet out there
        this->boomSpot = this->shotbull->getSprite().getPosition(); //set explosion location to the location of the rocket
    }

    //find the shot

    if (this->fired) { //if you have shot
        if (hitSomething(this->shotbull) || this->explode) { //if the rocket hits something or you let go of left mouse
            sf::Vector2f temp;
            temp.x = this->boomSpot.x;
            temp.y = this->boomSpot.y;
            sf::Vector2f backTrack; //opposite direction of the rocket to prevent the explosion from happening inside walls
            if (this->thisGo.x == 0 && this->thisGo.y == 0) { //making sure that the denominator of the below equation is not 0
                this->thisGo.x = -1;
                this->thisGo.y = 0;
            }
            backTrack.x = -3 * this->thisGo.x / sqrtf(this->thisGo.x * this->thisGo.x + this->thisGo.y * this->thisGo.y);
            backTrack.y = -3 * this->thisGo.y / sqrtf(this->thisGo.x * this->thisGo.x + this->thisGo.y * this->thisGo.y);

            if (!hitSomething(this->shotbull)) { //if you triggered the explosion
                for (int x = 0; x < this->shots->size(); x++) { //go through all bullets
                    if (this->shots->at(x) == this->shotbull) { //find the rocket
                        delete this->shots->at(x);
                        this->shots->erase(this->shots->begin() + x); //delete the rocket
                        x = this->shots->size();
                    }
                }
            }
            for (int x = 0; x < 18; x++) { //18 shots * 20 degrees apart = 360 degrees
                this->thisGo.x = cos(20 * 3.141592653 / 180) * temp.x - sin(20 * 3.141592653 / 180) * temp.y;
                this->thisGo.y = sin(20 * 3.141592653 / 180) * temp.x + cos(20 * 3.141592653 / 180) * temp.y;
                //adding the explosion bullets to the vector at boomspot + the opposite direction 
                Bullet* explosion = new Bullet(this->boomSpot + backTrack, this->thisGo, this->size, this->power, this->bulletTexture, 2 + this->bulletHealth, 15);
                explosion->hit(this->zombieXploded);
                this->shots->push_back(explosion);
                temp.x = this->thisGo.x;
                temp.y = this->thisGo.y;
            }
            this->shotbull = nullptr; //setting rocket pointer to nullpointer because the rocket is deleted
            this->fired = false; //no longer fired
        }        
    }
}

void RPG::fire(sf::Vector2f go, bool bottomlessClip, bool doubleDamage, bool doubleMag)
{
    this->thisGo = go;
    if (doubleDamage && this->power == 10) this->power = 20;
    else if (!doubleDamage && this->power != 10) this->power = 10;
    if (doubleMag && this->maxReload == 2) this->maxReload = 5;
    else if (!doubleMag && this->maxReload != 2) this->maxReload = 2;
    if (this->shottimer > 60 && this->shotbull == nullptr) { //if 60 frames since last shot and there isnt already been a shot
        this->fired = true; //fired
        sf::Vector2f v = this->sprite.getPosition();
        this->shotbull = new Bullet(v, thisGo, this->size, this->power*4, this->rocketTexture, 2, 10); //setting shotbull pointer to the rocket
        this->shots->push_back(this->shotbull); //sending the rocket out
        if(!bottomlessClip) this->reload--;
        shottimer = 0;
    }
}

int RPG::getReload()
{
    return this->reload;
}

int RPG::getMaxReload()
{
    return this->maxReload;
}

bool RPG::hitSomething(Bullet* bullet)
{
    bool result = true;
    for (int x = 0; x < this->shots->size(); x++) { //going through the bullet vector
        if (this->shots->at(x) != nullptr) {  
            if (bullet == shots->at(x)) { //if the bullet is in the vecotr, it did not hit anything
                result = false;
            }
        }
    }
    return result;
}

void RPG::mainHit(int zombieId) {
    this->zombieXploded = zombieId;
}

int RPG::getReloadTime() {
    return this->reloadDelay;
}

bool RPG::canShoot() {
    return this->shottimer > 60;
}