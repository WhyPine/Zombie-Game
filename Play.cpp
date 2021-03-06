
/*****************************************************************************************
* Programmer: Josh Maloy, Aidan Gooding, Orion Green, Zach Fechko                        *
* Class: CptS 122, Fall 2021				                                             *
* Programming Assignment: PA9                                                            *
* Date: December 10, 2021                                                                *
* Description: This program implements all methods used by the main run method that runs *
* the game - drawing the map, players, bullets, zombies, etc                             *
******************************************************************************************/
#include "Play.h"


clock_t start = 0;
int reloadDelayTimer = 0;
time_t end = 0;
int rounds = 1;
vector<Zombie*> zombies;
sf::Vector2f pasPos;
sf::Sprite backdrop;
vector<wall*> walls;
vector<Door*> doors;
vector<buyBox*> buyBoxes;

bool goldRush = false;

void loadWalls() {
    //boundaries
    walls.push_back(new wall(-32.f, -32.f, 32.f, 1504.f));
    walls.push_back(new wall(2560.f, -32.f, 32.f, 1504.f));
    walls.push_back(new wall(-32.f, -32.f, 2624.f, 32.f));
    walls.push_back(new wall(-32.f, 1440.f, 2624.f, 32.f));

    //motel (top left)
    walls.push_back(new wall(-32.f, 192.f, 96.f, 32.f));
    walls.push_back(new wall(160.f, 192.f, 256.f, 32.f));
    walls.push_back(new wall(384.f, 160.f, 32.f, 64.f));
    walls.push_back(new wall(384.f, -32.f, 32.f, 96.f));

    //Bar (top right)
    walls.push_back(new wall(608.f, -32.f, 32.f, 256.f));
    walls.push_back(new wall(608.f, 192.f, 96.f, 32.f));
    walls.push_back(new wall(832.f, 192.f, 448.f, 32.f));
    walls.push_back(new wall(1248.f, -32.f, 64.f, 288.f));

    //Cafe (bottom right)
    walls.push_back(new wall(992.f, 416.f, 64.f, 32.f));
    walls.push_back(new wall(960.f, 416.f, 32.f, 96.f));
    walls.push_back(new wall(960.f, 608.f, 32.f, 192.f));
    walls.push_back(new wall(960.f, 704.f, 352.f, 96.f));
    walls.push_back(new wall(1152.f, 416.f, 128.f, 32.f));
    walls.push_back(new wall(1248.f, 384.f, 64.f, 416.f));

    //Lobby (bottom left)
    walls.push_back(new wall(-32.f, 416.f, 640.f, 32.f));
    walls.push_back(new wall(480.f, 416.f, 32.f, 192.f));
    walls.push_back(new wall(288.f, 544.f, 32.f, 224.f));
    walls.push_back(new wall(736.f, 416.f, 96.f, 32.f));
    walls.push_back(new wall(800.f, 416.f, 32.f, 384.f));
    walls.push_back(new wall(128.f, 704.f, 704.f, 96.f));

    //The Lab(Right Side) GOOD
    walls.push_back(new wall(2112.f, -32.f, 480.f, 64.f));
    walls.push_back(new wall(2112.f, 160.f, 320.f, 32.f));
    walls.push_back(new wall(2112.f, 160.f, 32.f, 256.f));
    walls.push_back(new wall(2016.f, 384.f, 128.f, 32.f));
    walls.push_back(new wall(2016.f, 384.f, 32.f, 224.f));

    walls.push_back(new wall(2368.f, 320.f, 224.f, 32.f));
    walls.push_back(new wall(2368.f, 320.f, 32.f, 128.f));
    walls.push_back(new wall(2240.f, 288.f, 32.f, 192.f));
    walls.push_back(new wall(2400.f, 576.f, 32.f, 736.f));
    walls.push_back(new wall(2016.f, 576.f, 416.f, 32.f));

    //Hospital (bottom left) GOOD
    walls.push_back(new wall(1280.f, 704.f, 1152.f, 32.f));
    walls.push_back(new wall(1632.f, 704.f, 32.f, 384.f));
    walls.push_back(new wall(1792.f, 832.f, 480.f, 32.f));
    walls.push_back(new wall(1792.f, 1024.f, 96.f, 32.f));

    walls.push_back(new wall(1312.f, 1280.f, 1120.f, 32.f));
    walls.push_back(new wall(2176.f, 1216.f, 32.f, 96.f));
    walls.push_back(new wall(1632.f, 1216.f, 32.f, 96.f));
    walls.push_back(new wall(1856.f, 960.f, 32.f, 256.f));

    walls.push_back(new wall(1856.f, 1120.f, 352.f, 32.f));
    walls.push_back(new wall(2016.f, 960.f, 192.f, 32.f));
    walls.push_back(new wall(2176.f, 992.f, 96.f, 32.f));
    walls.push_back(new wall(2176.f, 960.f, 32.f, 192.f));

    //Military Base (Top Right - to the left) GOOD
    walls.push_back(new wall(1728.f, -32.f, 224.f, 64.f));
    walls.push_back(new wall(1728.f, -32.f, 32.f, 288.f));
    walls.push_back(new wall(1920.f, -32.f, 32.f, 288.f));
    walls.push_back(new wall(1408.f, -32.f, 32.f, 288.f));
    walls.push_back(new wall(1600.f, -32.f, 32.f, 288.f));
    walls.push_back(new wall(1408.f, -32.f, 224.f, 64.f));

    walls.push_back(new wall(1408.f, 384.f, 32.f, 256.f));
    walls.push_back(new wall(1600.f, 384.f, 32.f, 160.f));
    walls.push_back(new wall(1728.f, 384.f, 32.f, 160.f));
    walls.push_back(new wall(1600.f, 512.f, 160.f, 32.f));
    walls.push_back(new wall(1920.f, 384.f, 32.f, 256.f));
    walls.push_back(new wall(1408.f, 608.f, 544.f, 32.f));

    //The Garden GOOD
    walls.push_back(new wall(128.f, 800.f, 96.f, 256.f));
    walls.push_back(new wall(128.f, 1056.f, 32.f, 64.f));
    walls.push_back(new wall(-32.f, 1248.f, 192.f, 32.f));
    walls.push_back(new wall(288.f, 1152.f, 288.f, 64.f));
    walls.push_back(new wall(512.f, 1152.f, 64.f, 192.f));

    walls.push_back(new wall(448.f, 896.f, 64.f, 160.f));
    walls.push_back(new wall(448.f, 992.f, 544.f, 64.f));
    walls.push_back(new wall(928.f, 992.f, 64.f, 352.f));
    walls.push_back(new wall(1184.f, 736.f, 128.f, 320.f));
    walls.push_back(new wall(1248.f, 1184.f, 64.f, 128.f));

    // DOORS 
    // true means horizontal, false means vertical. doors are 32x128
    // only give it the coords of the top right of the door - right number is the cost 
    doors.push_back(new Door(19 * 32, 13 * 32, true, 150)); //city left 0
    doors.push_back(new Door(39.5 * 32, 8 * 32, false, 450)); //city right 1
    doors.push_back(new Door(26 * 32, 22 * 32, true, 300)); //city lower 2

    doors.push_back(new Door(4 * 32, 35 * 32, false, 250)); //garden left 3
    doors.push_back(new Door(39.5 * 32, 33 * 32, false, 500)); //garden right 4
    doors.push_back(new Door(39.5 * 32, 41 * 32, false, 350)); //garden lower 5

    doors.push_back(new Door(51*32, 34*32, false, 250)); //hospital left 6
    doors.push_back(new Door(59*32, 30*32, true, 250)); //hospital right 7
    //doors.push_back(new Door(52*32, 26*32, true, 350)); //hospital top left 8
    //doors.push_back(new Door(71*32, 26*32, true, 350)); //hospital top right 9

    doors.push_back(new Door(66 * 32, 1 * 32, false, 400)); //lab upper 10
    doors.push_back(new Door(76 * 32, 22 * 32, true, 400)); //lab lower 11

    //buy boxes
    // x coord, y coord, price, type
    //
    // 0 = pistol   1 = rifle   2 = shotgun   3 = RPG   4 = Burst Rifle   5 = Sniper
    // 11 = second wind    12 = reload boom   13 = double damage   14 = double mag
    
    buyBoxes.push_back(new buyBox(33 * 32, 0 * 32, 250, 1));
    buyBoxes.push_back(new buyBox(14 * 32, 38 * 32, 500, 2));
    buyBoxes.push_back(new buyBox(62 * 32, 23 * 32, 600, 3));
    buyBoxes.push_back(new buyBox(4 * 32 , 14 * 32, 350, 4));
    buyBoxes.push_back(new buyBox(78 * 32, 11 * 32, 500, 5));

    buyBoxes.push_back(new buyBox(20 * 32, 21 * 32, 400, 13));
    buyBoxes.push_back(new buyBox(27 * 32, 33 * 32, 300, 14));
    buyBoxes.push_back(new buyBox(61 * 32, 34 * 32, 600, 11));
    buyBoxes.push_back(new buyBox(48 * 32, 1 * 32, 500, 12));
    
    
}

void makeTrue(sf::Vector2i& gP, Player* p1) {
    if (p1->getPosition().x >= 1280) {
        gP.x += 1280;
    }
    if (p1->getPosition().y >= 720) {
        gP.y += 720;
    }
}

sf::Vector2f getZombieSpawn(Player* p1)
{
    sf::Vector2f v;
    int x = rand();
    if (p1->getPosition().x < 1280 && p1->getPosition().y > 720) { //bottom left
        //doors 3 or 5 or 2
        // if any of the doors are open, zombies can spawn in garden
        //
        // if the doors are closed, zombies continue to spawn at the last location while the player is on this screen
        //
        //
        if (!doors[3]->isClosed() || !doors[5]->isClosed() || !doors[2]->isClosed()) {
            if (x % 2 == 0) {
                v.x = 1 * 32;
                v.y = 41 * 32;
            }
            else {
                v.x = 33 * 32;
                v.y = 41 * 32;
            }
        }
    }
    else if (p1->getPosition().x > 1280 && p1->getPosition().y < 720) { //top right
        //door 8 both
        //door 1 first
        //door 9 second
        if (!doors[8]->isClosed()) {
            if (x % 2 == 0) {
                v.x = 56 * 32;
                v.y = 2 * 32;
            }

            else {
                v.x = 77 * 32;
                v.y = 4 * 32;
            }
        }
        else if (!doors[1]->isClosed()) {
            v.x = 56 * 32;
            v.y = 2 * 32;
        }
        else if (!doors[9]->isClosed()) {
            v.x = 77 * 32;
            v.y = 4 * 32;
        }
    }
    else if (p1->getPosition().x >= 1280 && p1->getPosition().y >= 720) { //bottom right
        //door 6 both
        //door 4 first
        if (!doors[6]->isClosed()) {
            if (x % 2 == 0) {
                v.x = 43 * 32;
                v.y = 25 * 32;
            }
            else {
                v.x = 71 * 32;
                v.y = 36 * 32;
            }
        }
        else if (!doors[4]->isClosed()) {
            v.x = 43 * 32;
            v.y = 25 * 32;
        }


    }
    else if (p1->getPosition().x <= 1280 && p1->getPosition().y <= 720) { //top left
        if (x % 2 == 0) {
            v.x = 15 * 32;
            v.y = 1 * 32;
        }
        else {
            v.x = 1 * 32;
            v.y = 9 * 32;
        }
    }
    return v;
}

sf::Vector2f doorCollision(Door& door, sf::Vector2f pos, int type, bool& collided) {
    sf::Vector2f result = pos;
    int thisSize = 40;
    if (type == 0)  int thisSize = 30; //zombie
    else if (type == 1) int thisSize = 40; //player
    sf::FloatRect entity;
    sf::FloatRect thisWall;
    thisWall = door.getWall();
    entity.top = pos.y - thisSize / 2;
    entity.left = pos.x - thisSize / 2;
    entity.width = thisSize;
    entity.height = thisSize;
    int x = thisWall.left + door.getWall().width / 2;
    int y = thisWall.top + door.getWall().height/ 2;
    if (thisWall.intersects(entity)) {
        collided = true;
        if (door.getType() && door.isClosed()) { //horizontal door
            if (pos.y < y) result.y = thisWall.top - thisSize / 2;
            else if (pos.y > y) result.y = thisWall.top + thisWall.height + thisSize / 2;
        }
        else if (!door.getType() && door.isClosed()) { //vertical door
            if (pos.x < x) result.x = thisWall.left - thisSize / 2;
            else if (pos.x > x) result.x = thisWall.left + thisWall.width + thisSize / 2;
        }
    }
    else collided = false;
    return result;
}

sf::Vector2f checkCollision(sf::FloatRect& thisWall, sf::Vector2f pos, int type, bool& collided) {
    sf::Vector2f result = pos;
    int thisSize = 40;
    if (type == 0)  int thisSize = 30; //zombie
    else if (type == 1) int thisSize = 40; //player
    else if (type == 2) int thisSize = 5; //bullet
    sf::FloatRect entity;
    entity.top = pos.y - thisSize / 2;
    entity.left = pos.x - thisSize / 2;
    entity.width = thisSize;
    entity.height = thisSize;
    int x1 = thisWall.left;
    int x2 = thisWall.left + thisWall.width;
    int y1 = thisWall.top;
    int y2 = thisWall.top + thisWall.height;
    if (thisWall.intersects(entity)) {
        collided = true;
        if (pos.y < y1 && pos.x < x1) {
            //top left
            //std::cout << "TopLeft ";
            if (y2 - pos.y > x2 - pos.x) {
                //closer to x side
                result.x = thisWall.left - thisSize / 2;
                result.y = pos.y;
            }
            else if (y2 - pos.y < x2 - pos.x) {
                //closer to y side
                result.x = pos.x;
                result.y = thisWall.top - thisSize / 2;
            }
            else {
                result.x = pos.x;
                result.y = pos.y;
            }
        }
        else if (pos.y < y1 && pos.x >= x1 && pos.x <= x2) {
            //top middle
            //std::cout << "Top ";
            result.x = pos.x;
            result.y = thisWall.top - thisSize / 2;
        }
        else if (pos.y < y1 && pos.x > x2) {
            //top right
            //std::cout << "TopRight ";
            if (y2 - pos.y > x2 - pos.x) {
                //closer to x side
                result.x = thisWall.left + thisWall.width + thisSize / 2;
                result.y = pos.y;
            }
            else if (y2 - pos.y < x2 - pos.x) {
                //closer to y side
                result.x = pos.x;
                result.y = thisWall.top - thisSize / 2;
            }
            else {
                result.x = pos.x;
                result.y = pos.y;
            }
        }
        else if (pos.y >= y1 && pos.y <= y2 && pos.x > x2) {
            //mid right
            //std::cout << " Right";
            result.x = thisWall.left + thisWall.width + thisSize / 2;
            result.y = pos.y;
        }
        else if (pos.y > y2 && pos.x > x2) {
            //bottom right
            //std::cout << "BotRight ";
            if (y2 - pos.y > x2 - pos.x) {
                //closer to x side
                result.x = thisWall.left + thisWall.width + thisSize / 2;
                result.y = pos.y;
            }
            else if (y2 - pos.y < x2 - pos.x) {
                //closer to y side
                result.x = pos.x;
                result.y = thisWall.top + thisWall.height + thisSize / 2;
            }
            else {
                result.x = pos.x;
                result.y = pos.y;
            }
        }
        else if (pos.y > y2 && pos.x >= x1 && pos.x <= x2) {
            //bottom middle
            //std::cout << "Bottom ";
            result.x = pos.x;
            result.y = thisWall.top + thisWall.height + thisSize / 2;
        }
        else if (pos.y > y2 && pos.x < x1) {
            //bottom left
            //std::cout << "BotLeft ";
            if (y2 - pos.y > x2 - pos.x) {
                //closer to x side
                result.x = thisWall.left - thisSize / 2;
                result.y = pos.y;
            }
            else if (y2 - pos.y < x2 - pos.x) {
                //closer to y side
                result.x = pos.x;
                result.y = thisWall.top + thisWall.height + thisSize / 2;
            }
            else {
                result.x = pos.x;
                result.y = pos.y;
            }
        }
        else if (pos.y >= y1 && pos.y <= y2 && pos.x < x1) {
            //mid left
            //std::cout << " Left";
            result.x = thisWall.left - thisSize / 2;
            result.y = pos.y;
        }
        else { //player/object is inside!
            if (abs(pos.x - x1) <= abs(pos.x - x2) && abs(pos.x - x1) <= abs(pos.y - y1) && abs(pos.x - x1) <= abs(pos.y - y2)) { //if closer to the left side
                result.x = pos.x - abs(pos.x - x1) - thisSize / 2; //go up
                result.y = pos.y;
            }
            else if (abs(pos.x - x2) < abs(pos.y - y1) && abs(pos.x - x2) < abs(pos.y - y2)) { //if closer to the right side
                result.x = pos.x + abs(pos.x - x2) + thisSize / 2; //go right
            }
            else if (abs(pos.y - y1) < abs(pos.y - y2)) { //if closer to the top
                result.x = pos.x;
                result.y = pos.y - abs(pos.y - y1) - thisSize / 2; //go up
            }
            else {
                result.x = pos.x;
                result.y = pos.y + abs(pos.y - y2) + thisSize / 2;
            }
        }
    }
    else collided = false;
    return result;
}

void movement(sf::RenderWindow& window, Player* p1) {
    //Moves things around the window
    for (int z = 0; z < zombies.size(); z++) {
        sf::FloatRect zbounds;
        float zombieSize = 30;
        //std::cout << "before zbounds" << std::endl;
        zbounds.top = zombies[z]->getSprite().getPosition().y - zombieSize / 2;
        zbounds.left = zombies[z]->getSprite().getPosition().x - zombieSize / 2;;
        zbounds.width = zombieSize;
        zbounds.height = zombieSize;
        if (zombies[z] != nullptr) {
            bool normal = true;
            if (z + 1 < zombies.size()) {
                sf::FloatRect z2bounds;
                //std::cout << "before z2bounds" << std::endl;
                z2bounds.top = zombies[z + 1]->getSprite().getPosition().y - zombieSize / 2;
                z2bounds.left = zombies[z + 1]->getSprite().getPosition().x - zombieSize / 2;
                z2bounds.width = zombieSize;
                z2bounds.height = zombieSize;
                if (zbounds.intersects(z2bounds) == true) {
                    zombies[z]->getOutDaWay(p1, zombies[z + 1]);
                    normal = false;
                }
            }
            if (normal) {
                zombies[z]->getMove(p1, p1->getPosition());
            }
        }
    }
    sf::Vector2f v;
    bool collisionCheck;
    for (int x = 0; x < doors.size(); x++) {
        v = doorCollision(*doors[x], p1->getPosition(), 1, collisionCheck);
        if (collisionCheck) p1->setPosition(v);
        //std::cout << "before door collision" << std::endl;
        for (int i = 0; i < zombies.size(); i++) {
            if (zombies[i] != nullptr) {
                v = doorCollision(*doors[x], zombies[i]->getSprite().getPosition(), 0, collisionCheck);
                if (collisionCheck) zombies[i]->setPosition(v);
            }
        }
        if (doors[x]->isClosed()) {
            for (int j = 0; j < p1->getGun()->getShots()->size(); j++) {
                if (doors[x]->getWall().intersects(p1->getGun()->getShots()->at(j)->getSprite().getGlobalBounds())) {
                    //delete p1->getGun()->getShots()->at(j);
                    p1->getGun()->getShots()->erase(p1->getGun()->getShots()->begin() + j);
                }
            }
        }
    }
    for (int x = 0; x < walls.size(); x++) { //try unoverlapping corners and see what happens
        v = checkCollision(walls[x]->getWall(), p1->getPosition(), 1, collisionCheck);
        if (collisionCheck) p1->setPosition(v);
        //std::cout << "before wall collision" << std::endl;
        for (int i = 0; i < zombies.size(); i++) {
            if (zombies[i] != nullptr) {
                Zombie* zombieChecker = zombies[i]; ///zombies[i] exists, but zombieChecker does not sometimes wtf
                sf::Sprite zombieSprite = zombieChecker->getSprite();
                sf::Vector2f zombieLocation = zombieSprite.getPosition();
                v = checkCollision(walls[x]->getWall(), zombieLocation, 0, collisionCheck);
                if (collisionCheck) zombies[i]->setPosition(v);
            }
        }
        for (int j = 0; j < p1->getGun()->getShots()->size(); j++) {
            if (walls[x]->getWall().intersects(p1->getGun()->getShots()->at(j)->getSprite().getGlobalBounds())) {
                //delete p1->getGun()->getShots()->at(j);
                p1->getGun()->getShots()->erase(p1->getGun()->getShots()->begin() + j);
            }
        }
    }
    for (int x = 0; x < buyBoxes.size(); x++) {
        v = checkCollision(buyBoxes[x]->getWall(), p1->getPosition(), 1, collisionCheck);
        if (collisionCheck) p1->setPosition(v);
        //std::cout << "before box collision" << std::endl;
        for (int i = 0; i < zombies.size(); i++) {
            if (zombies[i] != nullptr) {
                v = checkCollision(buyBoxes[x]->getWall(), zombies[i]->getSprite().getPosition(), 0, collisionCheck);
                if (collisionCheck) zombies[i]->setPosition(v);
            }
        }
        for (int j = 0; j < p1->getGun()->getShots()->size(); j++) {
            if (buyBoxes[x]->getWall().intersects(p1->getGun()->getShots()->at(j)->getSprite().getGlobalBounds())) {
                //delete p1->getGun()->getShots()->at(j);
                p1->getGun()->getShots()->erase(p1->getGun()->getShots()->begin() + j);
            }
        }
    }
    sf::FloatRect playerBox;
    playerBox.top = p1->getPosition().y - 40 / 2;
    playerBox.left = p1->getPosition().x - 40 / 2;
    playerBox.width = 40;
    playerBox.height = 40;
    //std::cout << "before player collision" << std::endl;
    for (int x = 0; x < zombies.size(); x++) {
        if (zombies[x] != nullptr && x < zombies.size()) {
            v = checkCollision(playerBox, zombies[x]->getSprite().getPosition(), 1, collisionCheck);
                if (collisionCheck) zombies[x]->setPosition(v);
        }
    }

    sf::Vector2i gP = sf::Mouse::getPosition(window);
    makeTrue(gP, p1);
    p1->checkMove(gP);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) //add specific reload delays to guns. multiply time by reloadMultiplier to find how long reload should be
    {
        if (clock() - reloadDelayTimer > 2000 && p1->getGun()->getReload() < p1->getGun()->getMaxReload()) //fixed spam reload bug
        {
            reloadDelayTimer = clock();
            p1->canshoot = false;
            p1->reload();
        }
    }
}

void displayGUI(Player* p1, sf::RenderWindow& window, sf::Font& font, int zombies)
{
    if (p1->getHealth() > 0) {
        //health bar
        sf::RectangleShape healthBack(sf::Vector2f(300, 30));
        healthBack.setFillColor(sf::Color(50, 50, 50));
        sf::RectangleShape healthFront(sf::Vector2f(300 * p1->getHealth() / p1->getMaxHealth(), 30));
        healthFront.setFillColor(sf::Color(230, 45, 45));
        float xPos = 0;
        float yPos = 670;
        if (p1->getPosition().x >= 1280) xPos += 1280;
        if (p1->getPosition().y >= 720) yPos += 720;
        healthBack.setPosition(xPos, yPos);
        healthFront.setPosition(xPos, yPos);
        //ammo count
        sf::Text ammoCount;
        ammoCount.setFont(font);
        string ammo = std::to_string(p1->getGun()->getReload()) + "/" + std::to_string(p1->getGun()->getMaxReload());
        ammoCount.setString(ammo);
        ammoCount.setCharacterSize(50);
        ammoCount.setFillColor(sf::Color::White);
        ammoCount.setPosition(xPos + 1150, yPos-10);
        ammoCount.setOutlineColor(sf::Color::Black);
        ammoCount.setOutlineThickness(3);
        //cash display
        sf::Text moneyCount;
        string moneyString = "Money $: " + std::to_string(p1->getMoney());
        moneyCount.setFont(font);
        moneyCount.setString(moneyString);
        moneyCount.setCharacterSize(30);
        moneyCount.setFillColor(sf::Color::White);
        moneyCount.setPosition(xPos + 10, yPos - 40);
        moneyCount.setOutlineColor(sf::Color::Black);
        moneyCount.setOutlineThickness(3);
        //zombie counter
        sf::Text zombieCount;
        string zombieString = std::to_string(zombies) + " Left";
        zombieCount.setFont(font);
        zombieCount.setString(zombieString);
        zombieCount.setCharacterSize(30);
        zombieCount.setFillColor(sf::Color::White);
        zombieCount.setPosition(xPos + 1180, yPos - 650);
        zombieCount.setOutlineColor(sf::Color::Black);
        zombieCount.setOutlineThickness(3);

        //code for ammo indicator on mouse
        sf::RectangleShape ammoBack(sf::Vector2f(15, -45));
        sf::RectangleShape ammoFront(sf::Vector2f(15, -45* ((float)p1->getGun()->getReload()/ (float)p1->getGun()->getMaxReload())));
        ammoBack.setFillColor(sf::Color(32, 32, 32, 125));
        ammoBack.setOutlineColor(sf::Color(127, 127, 127, 100));
        ammoBack.setOutlineThickness(1);
        if (!p1->canshoot) ammoBack.setFillColor(sf::Color(200, 0, 20, 125));
        ammoFront.setFillColor(sf::Color(96, 96, 96, 175));
        ammoFront.setOutlineColor(sf::Color(0, 0, 0, 100));
        ammoFront.setOutlineThickness(1);
        sf::Vector2i gP = sf::Mouse::getPosition(window);
        makeTrue(gP, p1);
        ammoBack.setPosition(gP.x - 25, gP.y + 45);
        ammoFront.setPosition(gP.x - 25, gP.y + 45);
        //purchasing indicator for doors
        for (int x = 0; x < doors.size(); x++) {
            if (doors[x]->canOpen(*p1) && doors[x]->isClosed()) {
                sf::Text doorText;
                string openDoor = "Press E to open door $" + std::to_string(doors[x]->getCost());
                doorText.setFont(font);
                doorText.setString(openDoor);
                doorText.setCharacterSize(50);
                doorText.setFillColor(sf::Color::White);
                doorText.setOutlineColor(sf::Color::Black);
                doorText.setOutlineThickness(2);
                doorText.setOrigin(doorText.getLocalBounds().width / 2, doorText.getLocalBounds().height / 2);
                doorText.setPosition(xPos + 1280 / 2, yPos);
                window.draw(doorText);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
                    if (p1->getMoney() > doors[x]->getCost()) {
                        doors[x]->open();
                        p1->setMoney(p1->getMoney() - doors[x]->getCost());
                    }
                    
                }
            }
        }
        //purchasing indicator for buyboxes
        for (int x = 0; x < buyBoxes.size(); x++) {
            if (buyBoxes[x]->canBuy(*p1) && p1->getMoney() > buyBoxes[x]->getPrice()) {
                sf::Text doorText;
                string openDoor = "Press E to buy " + buyBoxes[x]->getName() + " $" + std::to_string(buyBoxes[x]->getPrice());
                doorText.setFont(font);
                doorText.setString(openDoor);
                doorText.setCharacterSize(50);
                doorText.setFillColor(sf::Color::White);
                doorText.setOutlineColor(sf::Color::Black);
                doorText.setOutlineThickness(2);
                doorText.setOrigin(doorText.getLocalBounds().width / 2, doorText.getLocalBounds().height / 2);
                doorText.setPosition(xPos + 1280 / 2, yPos);
                window.draw(doorText);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
                    if (p1->getMoney() > buyBoxes[x]->getPrice()) {
                        buyBoxes[x]->buy(*p1);
                    }

                }
            }
        }
        //reload indicator
        if ((double)p1->getGun()->getReload() / (double)p1->getGun()->getMaxReload() <= 0.35) {
            sf::Text ammoAlert;
            string alert = "Press R to Reload!";
            ammoAlert.setFont(font);
            ammoAlert.setString(alert);
            ammoAlert.setCharacterSize(40);
            ammoAlert.setFillColor(sf::Color(94, 1, 6));
            ammoAlert.setPosition(xPos + 1010, yPos - 50);
            ammoAlert.setOutlineColor(sf::Color::White);
            ammoAlert.setOutlineThickness(2);
            window.draw(ammoAlert);
        }
        //perks
        //setting up variables for perk locations
        


        window.draw(zombieCount);
        window.draw(moneyCount);
        window.draw(ammoCount);
        window.draw(healthBack);
        window.draw(healthFront); 
        window.draw(ammoBack);
        window.draw(ammoFront);
    }
}

void dropMoney(Player* p1) {
    int points = rand() % 3 + 3;
    if (goldRush) points *= 2;
    p1->setMoney(p1->getMoney() + points);
}

void bullets(Player* p1) {
    for (int b = p1->getGun()->getShots()->size() - 1; b >= 0;  b--) { //iterates through the vector back to front
        //bullets can't be nullptr - they always get deleted and erased right away
        for (int z = zombies.size() - 1; z >= 0; z--) {
            sf::FloatRect zombieBox;
            zombieBox.top = zombies[z]->getSprite().getPosition().y - 30 / 2;
            zombieBox.left = zombies[z]->getSprite().getPosition().x - 30 / 2;
            zombieBox.width = 30;
            zombieBox.height = 30;
            if (z < zombies.size() && b < p1->getGun()->getShots()->size() && p1->getGun()->getShots()->at(b)->getSprite().getGlobalBounds().intersects(zombieBox) && !p1->getGun()->getShots()->at(b)->hasHit(zombies[z]->getId())) { //if bullet is touching zombie
                p1->getGun()->getShots()->at(b)->hit(zombies[z]->getId());
                if (p1->getGun()->getMaxReload() == 2 && p1->getGun()->getShots()->at(b)->getDamage() == 20) p1->getGun()->mainHit(zombies[z]->getId()); //if rpg rocket, make explosion not hit the zombie
                zombies[z]->setHealth(zombies[z]->getHealth() - p1->getGun()->getShots()->at(b)->getDamage()); //damage the zombie
                p1->getGun()->getShots()->at(b)->setHealth(-1); //damage the bullet
                if (zombies[z]->getHealth() < 1) { //if zombie has no more health
                    zombies.erase(zombies.begin() + z); //remove from vector
                    if (z > zombies.size()) z--; //making sure z stays in bounds
                    dropMoney(p1);
                }
                if (p1->getGun()->getShots()->at(b)->getHealth() < 1) { //if bullet has no more health
                    delete p1->getGun()->getShots()->at(b); //delete bullet
                    p1->getGun()->getShots()->erase(p1->getGun()->getShots()->begin() + b); //remove from vector
                    if (b >= p1->getGun()->getShots()->size()) {
                        b = p1->getGun()->getShots()->size() - 1; //making sure b stays in bounds
                    }
                }
            }
        }
    }
}


void drawing(sf::RenderWindow& window, Player* p1, sf::Font& font) {
    window.clear();
    window.draw(backdrop);
    for (int x = 0; x < doors.size(); x++) {
        if (doors[x]->isClosed()) doors[x]->drawDoor(window);
    }
    for (int x = 0; x < buyBoxes.size(); x++) {
        buyBoxes[x]->drawBox(window);
    }
    window.draw(p1->getSprite());
    for (std::vector<Bullet*>::iterator it = p1->getGun()->getShots()->begin(); it != p1->getGun()->getShots()->end(); ++it) {
        if (*it != nullptr) {
            window.draw((*it)->getSprite());
        }
    }
    window.draw(p1->getGunSprite());
    for (int i = 0; i < zombies.size(); i++)
    {
        //std::cout << "before draw" << std::endl;
        if (zombies[i] != nullptr && i < zombies.size()) {
            window.draw(zombies[i]->getSprite());
            window.draw(zombies[i]->getHealthBack());
            window.draw(zombies[i]->getHealthFront());
        }
    }
    for (int k = 0; k < zombies.size(); k++) {
        if (zombies[k] != nullptr) {
            if (zombies[k]->getSprite().getGlobalBounds().intersects(p1->getSprite().getGlobalBounds()) && zombies[k]->getReload() == 0) {
                zombies[k]->attack(p1);
            }
        }
    }

    //std::thread gui(displayGUI, p1, std::ref(window), std::ref(font), zombies.size());
    //gui.detach();
    displayGUI(p1, window, font, zombies.size());
}

void run(sf::RenderWindow& window, sf::View& view, save& saveFile, bool debug){
    bool test1 = false;
    bool test2 = false;
    bool test3 = false;
    bool test4 = false;
    bool test5 = false;
    bool test5Start = false;
    int startTime = clock();
    sf::Texture bulletTexture;
    bulletTexture.loadFromFile("rifleshot.png");
    sf::Texture tex;
    tex.loadFromFile("mapv2.png");
    backdrop.setTexture(tex);
    sf::Vector2f v;
    v.x = 32*1.f;
    v.y = 32*1.f;
    Player* p1 = new Player(saveFile.health, saveFile.speedM, saveFile.damageP, window.getSize(), saveFile.bulletAdd, saveFile.regenM);
    //normal
    if (!debug) zombies.push_back(new Zombie(15, 1, 1, window.getSize(), v));
    //if debug spawn zombie in hospital so rounds do not advance
    else {
        //zombies.push_back(new Zombie(100000, -10, -10, window.getSize(), sf::Vector2f(32 * 63, 32 * 33)));
        p1->setMoney(100000);
        p1->setBottomlessClip(true);

        zombies.push_back(new Zombie(1, 0, 0, window.getSize(), sf::Vector2f(4 * 32, 3 * 32)));
        zombies.at(0)->setPosition(sf::Vector2f(4 * 32, 3 * 32));
        p1->getGun()->getShots()->push_back(new Bullet(sf::Vector2f(17 * 32, 3 * 32), sf::Vector2f(-1, 0), sf::Vector2u(0, 0), 10, bulletTexture, 1, 10));
    }
    
    loadWalls();
    //Loading Font
    sf::Font font;
    bool loadFont = true;
    if (!font.loadFromFile("shlop rg.ttf"))
    {
        std::cout << "Font Read Error" << std::endl;
        loadFont = false;
    }
    sf::Text roundText;
    sf::Text deathText;
    deathText.setFont(font);
    deathText.setString("YOU DIED!");
    deathText.setCharacterSize(400);
    deathText.setFillColor(sf::Color(94, 1, 6));
    deathText.setOutlineColor(sf::Color::Black);
    deathText.setOutlineThickness(5);
    deathText.setOrigin(deathText.getLocalBounds().width / 2, deathText.getLocalBounds().height / 2);

    std::vector<megaZombieManager> mzManager;
    int lastSpawnTime = 0;
    int zombiesSpawned = 0;
    int spawnCount = 0;
    int bossSpawns = 0;
    int bossCount = 0;

    bool nextRound = false;
    bool displayRound = false;
    int displayTimer = 0;

    int secondWindCounter = 0;
    int deathTimer = 0;
    int skillPointsEarned = 0;

    //special round variables
    float zombieSpawnMultiplier = 1.0;
    int checkComplete = 0;
    bool roundComplete = false;
    bool horde = false;
    bool ambush = false;
    bool megaZombie = false;
    int megaZombieHp = 0;
    bool siege = false;
    //loading badges
    sf::RectangleShape swBadge(sf::Vector2f(27, 40));
    sf::Texture* swTexture = new sf::Texture;
    swTexture->loadFromFile("secondWindBadge.png");
    swBadge.setOrigin(swBadge.getLocalBounds().width / 2, swBadge.getLocalBounds().height / 2);
    swBadge.setTexture(swTexture, true);

    sf::RectangleShape cpBadge(sf::Vector2f(27, 40));
    sf::Texture* cpTexture = new sf::Texture;
    cpTexture->loadFromFile("reloadBoomBadge.png");
    cpBadge.setOrigin(cpBadge.getLocalBounds().width / 2, cpBadge.getLocalBounds().height / 2);
    cpBadge.setTexture(cpTexture, true);

    sf::RectangleShape ddBadge(sf::Vector2f(27, 40));
    sf::Texture* ddTexture = new sf::Texture;
    ddTexture->loadFromFile("doubleDamageBadge.png");
    ddBadge.setOrigin(ddBadge.getLocalBounds().width / 2, ddBadge.getLocalBounds().height / 2);
    ddBadge.setTexture(ddTexture, true);

    sf::RectangleShape dmBadge(sf::Vector2f(27, 40));
    sf::Texture* dmTexture = new sf::Texture;
    dmTexture->loadFromFile("doubleMagBadge.png");
    dmBadge.setOrigin(dmBadge.getLocalBounds().width / 2, dmBadge.getLocalBounds().height / 2);
    dmBadge.setTexture(dmTexture, true);
    
    while (window.isOpen())
    {
        //Checks for changes in events
        sf::Event event;
        window.pollEvent(event);
        if (event.type == sf::Event::Closed) window.close();
        if (p1->getPosition().x < 1280 && p1->getPosition().y > 720) {
            view.setCenter(640,  1080);
        }
        else if (p1->getPosition().x > 1280 && p1->getPosition().y < 720) {
            view.setCenter(1920, 360);
        }
        else if (p1->getPosition().x > 1280 && p1->getPosition().y > 720) {
            view.setCenter(1920, 1080);
        }
        else if (p1->getPosition().x < 1280 && p1->getPosition().y < 720) {
            view.setCenter(640, 360);
        }
        window.setView(view);

        if (debug) {
            //bullet collision test
            if (!test1) {
                if (zombies.size() == 0) {
                    test1 = true;
                    std::cout << "Bullet Collision Test SUCCESS" << std::endl;
                }
            }
            //out of bounds test
            else if (!test2 && (clock() - startTime) > 5000 && zombies.size() == 0) {
                zombies.push_back(new Zombie(1, 0, 0, window.getSize(), sf::Vector2f(-100, -100)));
            }
            else if (!test2 && (clock() - startTime) > 5000 && zombies.size() == 1) {
                if (zombies.at(0)->getSprite().getPosition().x > 0 && zombies.at(0)->getSprite().getPosition().y > 0) {
                    zombies.erase(zombies.begin());
                    test2 = true;
                    std::cout << "Out of Bounds Test SUCCESS" << std::endl;
                }
            }
            //wall collision test
            else if (!test3 && (clock() - startTime) > 10000 && zombies.size() == 0) {
                zombies.push_back(new Zombie(1, 0, 0, window.getSize(), sf::Vector2f(8 * 32, 6 * 32)));
            }
            else if (!test3 && (clock() - startTime) > 10000 && zombies.size() == 1) {
                //checking if zombie was moved
                if (zombies.at(0)->getSprite().getPosition().y > 6*32 || zombies.at(0)->getSprite().getPosition().y < 6 * 32) {
                    zombies.erase(zombies.begin());
                    test3 = true;
                    std::cout << "Wall Collision Test SUCCESS" << std::endl;
                }
            }
            //bullet pass through test
            else if (!test4 && (clock() - startTime) > 15000 && zombies.size() == 0) {
                zombies.push_back(new Zombie(1, 0, 0, window.getSize(), sf::Vector2f(4 * 32, 3 * 32)));
                zombies.at(0)->setPosition(sf::Vector2f(4 * 32, 3 * 32));
                Bullet* testBullet = new Bullet(sf::Vector2f(17 * 32, 3 * 32), sf::Vector2f(-1, 0), sf::Vector2u(0, 0), 10, bulletTexture, 1, 10);
                testBullet->hit(zombies.at(0)->getId());
                p1->getGun()->getShots()->push_back(testBullet);
            }
            else if (!test4 && (clock() - startTime) > 17000 && zombies.size() == 1) {
                std::cout << "Bullet Pass Through Test SUCCESS" << std::endl;
                zombies.erase(zombies.begin());
                test4 = true;
            }
            //second Wind test
            else if (!test5Start && (clock() - startTime) > 20000) {
                test5Start = true;
                p1->setSecondWind(true);
                p1->setHealth(0);
            }
            else if (!test5 && (clock() - startTime) > 23000) {
                if (p1->getHealth() != 0) {
                    std::cout << "Second Wind Test SUCCESS" << std::endl;
                    test5 = true;
                }
            }
            else if (((clock() - startTime) - startTime > 25000 && test1 && test2 && test3 && test4 && test5)) {
                std::cout << "All Tests SUCCESSFUL" << std::endl;
                window.close();
            }
        }

        //zombie management
        if (!roundComplete) {
            //if there are more zombies to spawn
            if (zombiesSpawned < spawnCount) {
                //if not megaZombie Round
                if (!megaZombie) {
                    //setting up delay between zombie spawns based on how many zombies have already spawned
                    int delay = 300;
                    for (int i = 0; i < zombies.size() / (10 + rounds / 5); i++) delay += delay;
                    //if enough time has passed
                    if (clock() - lastSpawnTime > zombieSpawnMultiplier * delay) {
                        //choosing which zombie and spawning
                        sf::Vector2f spawnLocation = getZombieSpawn(p1);
                        //checking if bosses need to be spawned
                        if (zombiesSpawned > (spawnCount / 2) && bossSpawns < bossCount) {
                            //if more than one boss to spawn, random 
                            if (bossSpawns == 1) {
                                if (clock() % 3 == 0) {
                                    zombies.push_back(new heavyZombie((15 + rounds / 5) * 10, 1, 1, sf::Vector2u(p1->getSize().x * 2, p1->getSize().y * 2), spawnLocation));
                                }
                                else if (clock() % 3 == 1) {
                                    zombies.push_back(new RunnerZombie((15 + rounds / 5) * 10, 1, 1, sf::Vector2u(p1->getSize().x * 2, p1->getSize().y * 2), spawnLocation));
                                }
                                else {
                                    zombies.push_back(new Zombie((15 + rounds / 5) * 10, 1, 1, sf::Vector2u(p1->getSize().x * 2, p1->getSize().y * 2), spawnLocation));
                                }
                            }
                            //if one boss to spawn, pick the correct one
                            else if (rounds - 1 % 30 == 0) {
                                zombies.push_back(new heavyZombie((15 + rounds/5) * 10, 1, 1, sf::Vector2u(p1->getSize().x * 2, p1->getSize().y * 2), spawnLocation));
                            }
                            else if (rounds - 1 % 30 == 10) {
                                zombies.push_back(new Zombie((15 + rounds / 5) * 10, 1, 1, sf::Vector2u(p1->getSize().x * 2, p1->getSize().y * 2), spawnLocation));
                            }
                            else if (rounds - 1 % 30 == 20) {
                                zombies.push_back(new RunnerZombie((15 + rounds / 5) * 10, 1, 1, sf::Vector2u(p1->getSize().x * 2, p1->getSize().y * 2), spawnLocation));
                            }
                            bossSpawns++;
                            spawnCount++;
                        }
                        else if (rounds > 21 && zombiesSpawned % 6 == 1) {
                            zombies.push_back(new heavyZombie((15 + rounds / 5) * zombieSpawnMultiplier, 1, 1, p1->getSize(), spawnLocation));
                            std::cout << "New heavy zombie spawned" << std::endl;
                        }
                        else if (rounds > 11 && zombiesSpawned % 3 == 2) {
                            std::cout << "Round: " << rounds << std::endl;
                            zombies.push_back(new RunnerZombie((15 + rounds / 5) * zombieSpawnMultiplier, 1, 1, p1->getSize(), spawnLocation));
                        }
                        else {
                            zombies.push_back(new Zombie((15 + rounds / 5) * zombieSpawnMultiplier, 1, 1, p1->getSize(), spawnLocation));
                        }
                        //updating last spawnTime and number of zombies spawned
                        lastSpawnTime = clock();
                        zombiesSpawned++;
                    }
                }
                //else it is a megaZombie Round
                else {
                    //if first zombie
                    if (zombiesSpawned == 0) {
                        Zombie* newZombie = new Zombie(megaZombieHp, 1, 1, sf::Vector2u(p1->getSize().x * 2, p1->getSize().y*2), getZombieSpawn(p1));
                        mzManager.push_back(megaZombieManager(0, newZombie->getId(), newZombie->getSprite().getPosition()));
                        zombies.push_back(newZombie);
                        zombiesSpawned++;
                        //create zombie
                        //add zombie to vector of megaZombieManagers
                        //level = 0;
                    }
                    else {
                        //iterate through all zombies that have spawned
                        for (int m = 0; m < mzManager.size(); m++) {
                            //initially setting all zombies to dead
                            mzManager[m].setAlive(false);
                            //for each zombie that has spawend, check it with the mzManager
                                for (int z = 0; z < zombies.size(); z++) {
                                    //if found a zombie
                                    if (mzManager[m].getID() == zombies[z]->getId()) {
                                        //update their position & set alive
                                        mzManager[m].setLastPos(zombies[z]->getSprite().getPosition());
                                        mzManager[m].setAlive(true);
                                    }
                                }
                            //if the zombie is dead
                            if(mzManager[m].getAlive() == false) {
                                //if there are divisions remaining
                                if (mzManager[m].getLevel() + 1 < 4) {
                                    //add a new zombie with 1/2 the health of the previous one and a bit smaller
                                    double sizeScalar = 2.0 - ((double)(mzManager[m].getLevel() + 1) / 3.0);
                                    sf::Vector2u size(p1->getSize().x * sizeScalar, p1->getSize().y * sizeScalar);
                                    Zombie* newZombie = new Zombie(megaZombieHp / (2 * (mzManager[m].getLevel() + 1)), 1, 1, size, mzManager[m].getLastPos());
                                    mzManager.push_back(megaZombieManager(mzManager[m].getLevel() + 1, newZombie->getId(), newZombie->getSprite().getPosition()));
                                    zombies.push_back(newZombie);
                                    zombiesSpawned++;
                                    //add a second new zombie with 1/2 the health of the previous one
                                    newZombie = new Zombie(megaZombieHp / (2 * (mzManager[m].getLevel() + 1)), 1, 1, size, mzManager[m].getLastPos());
                                    mzManager.push_back(megaZombieManager(mzManager[m].getLevel() + 1, newZombie->getId(), newZombie->getSprite().getPosition()));
                                    zombies.push_back(newZombie);
                                    zombiesSpawned++;
                                }
                                //removing the killed zombie from the mzManager
                                mzManager.erase(mzManager.begin() + m);
                                //updating m because the item in the vector at m no longer exists
                                m--;
                            }   
                        }
                    }
                }
            }
            //else if all the zombies are dead, round is complete
            else if (zombies.size() == 0 && debug == false) {
                roundComplete = true;
                if (megaZombie) mzManager.clear();
            }

        }

        //moving objects
        bullets(p1);
        movement(window, p1);   
        drawing(window, p1, font);

        //Round counter & advancer
        if (roundComplete)
        {
            
            if(!nextRound) { //setting up next round
                if (!displayRound) {
                    //if you completed the round, updates skill point counter
                    skillPointsEarned += bossCount;
                    bossCount = 0;
                    bossSpawns = 0;
                    //updating player health
                    p1->setHealth(p1->getHealth() + ((p1->getMaxHealth() - p1->getHealth()) / 2));
                    if (p1->getHealth() > p1->getMaxHealth()) p1->setHealth(p1->getMaxHealth());
                    //reseting round modifiers
                    siege = horde = goldRush = ambush = megaZombie = false;
                    p1->setBottomlessClip(false);
                    //setting up next round modifiers
                    int picker = rand() % 100 + 1;
                    if (picker % 50 == 0) goldRush = true; //2% chance for 2x money each round
                    if (rounds % 10 == 0) {
                        bossCount = (rounds / 30) + 1;
                    }
                    else if (rounds % 5 == 0) { //only for 5's rounds - 5 15 25 35...
                        if (picker < 25) horde = true;
                        else if (picker >= 25 && picker < 50) ambush = true;
                        else if (picker >= 50 && picker < 75) siege = true;
                        else if (picker >= 75) megaZombie = true; //replace with megaZombie when that is done
                    }
                    //setting appropriate values for zombie spawning
                    zombieSpawnMultiplier = 1;
                    spawnCount = 3 * rounds + 5;
                    if (horde) {
                        zombieSpawnMultiplier = 0.3;
                        p1->setBottomlessClip(true);
                        spawnCount *= 3;
                    }
                    if (siege) zombieSpawnMultiplier = 2.0;
                    if (ambush) zombieSpawnMultiplier = 0.5;
                    if (megaZombie) {
                        megaZombieHp = spawnCount * 4;
                        spawnCount = 15;
                    }
                    //setting up next round display text
                    roundText.setFont(font);
                    string display = "Round " + std::to_string(rounds);
                    if (horde) display += ": HORDE";
                    if (siege) display += ": SIEGE";
                    if (megaZombie) display += ": MEGAZOMBIE";
                    if (ambush) display += ": AMBUSH";
                    if (goldRush) display += ": GOLD RUSH";
                    std::cout << display << " - " << spawnCount << " Zombies" << std::endl;
                    roundText.setString(display);
                    roundText.setCharacterSize(100);
                    roundText.setFillColor(sf::Color(94, 1, 6));
                    roundText.setOutlineColor(sf::Color::Black);
                    roundText.setOutlineThickness(3);
                    roundText.setOrigin(roundText.getLocalBounds().width / 2, roundText.getLocalBounds().height / 2);
                    displayTimer = clock();
                    displayRound = true;
                }
                else { //displaying round counter
                    if (clock() - displayTimer > 1000 && clock() - displayTimer < 4500) { //waits 1 secound then displays for 3.5 seconds
                        roundText.setPosition(view.getCenter().x, view.getCenter().y - 300);
                        window.draw(roundText);
                    }
                    else if (clock() - displayTimer > 5000) { //after 5 seconds nextRound begins
                        displayRound = false;
                        nextRound = true;
                    }
                }
            }
            else { //beginning next round
                nextRound = false;
                zombiesSpawned = 0;
                rounds ++;
                roundComplete = false;
            }
        }
        //if player health is below 0 & they dont have second wind perk
        if (p1->getHealth() < 1 && !p1->getSecondWind())
        {
            p1->setHealth(-1000);
            //begin timer
            if (!deathTimer) {
                deathTimer = clock();
            }
            //after 2 seconds
            else if (clock() - deathTimer > 2000) {
                window.close();
            }
            //display YOU DIED for 2 seconds
            else {
                deathText.setPosition(view.getCenter().x, view.getCenter().y + 100);
                window.draw(deathText);
            }
        }
        //if player dies with second wind perk
        else if (p1->getHealth() < 1 && p1->getSecondWind()) {
            roundText.setFont(font);
            roundText.setString("Second Wind");
            roundText.setCharacterSize(100);
            roundText.setFillColor(sf::Color(94, 1, 6));
            roundText.setOutlineColor(sf::Color(0, 0, 0));
            roundText.setOutlineThickness(2);
            roundText.setOrigin(roundText.getLocalBounds().width / 2, roundText.getLocalBounds().height / 2);
            secondWindCounter = clock();
            p1->setSecondWind(false);
            p1->setHealth(p1->getMaxHealth());
            p1->getGun()->setReload(p1->getGun()->getMaxReload());
        }
        //if second wind activated
        if (secondWindCounter) {
            //display text for 1.5 seconds 
            if (clock() - secondWindCounter > 1500) {
                secondWindCounter = 0;
            }
            else {
                roundText.setPosition(view.getCenter().x, view.getCenter().y + 200);
                window.draw(roundText);
            }
        }
        int xPos = 1120;
        int yPos = 695;
        if (p1->getPosition().x >= 1280) xPos += 1280;
        if (p1->getPosition().y >= 720) yPos += 720;
        if (p1->getSecondWind()) {
            swBadge.setPosition(xPos, yPos);
            window.draw(swBadge);
            xPos -= 40;
        }
        if (p1->getReloadBoom()) {
            cpBadge.setPosition(xPos, yPos);
            window.draw(cpBadge);
            xPos -= 40;
        }
        if (p1->getDoubleDamage()) {
            ddBadge.setPosition(xPos, yPos);
            window.draw(ddBadge);
            xPos -= 40;
        }
        if (p1->getDoubleMag()) {
            dmBadge.setPosition(xPos, yPos);
            window.draw(dmBadge);
        }
        window.display();
    }
    saveFile.skillPoints += skillPointsEarned;
    saveFile.totalSkillPoints += skillPointsEarned;
    rounds = 1;
    zombies.clear();
    walls.clear();
    walls.clear();
    buyBoxes.clear();
}