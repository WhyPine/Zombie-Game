
#include "Play.h"

clock_t start = 0;
int roundCountTimer = 0;
int reloadDelayTimer = 0;
time_t end = 0;
int rounds = 0;
vector<Zombie*> zombies;
sf::Vector2f pasPos;
sf::Sprite backdrop;
bool displayMenu = true;
vector<wall*> walls;
std::mutex mtx;

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
    walls.push_back(new wall(960.f, 416.f, 96.f, 32.f));
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

}

void makeTrue(sf::Vector2i& gP, Player* p1) {
    if (p1->getPosition().x >= 1280) {
        gP.x += 1280;
    }
    if (p1->getPosition().y >= 720) {
        gP.y += 720;
    }
}

void spawnZombies(sf::Vector2u size, Player* p1) {
    for (int i = 0; i < 3 * rounds + 5; i++) {

        sf::Vector2f v;
        int x = rand();
        if (p1->getPosition().x < 1280 && p1->getPosition().y > 720) { //bottom left
            if (x % 2 == 0){
                v.x = 1 * 32;
                v.y = 43 * 32;
            }
            else {
                v.x = 32 * 32;
                v.y = 44 * 32;
            }
        }
        else if (p1->getPosition().x > 1280 && p1->getPosition().y < 720) { //top right
            if (x % 2 == 0) {
                v.x = 58 * 32;
                v.y = 5 * 32;
            }
            else {
                v.x = 70 * 32;
                v.y = 3 * 32;
            }
        }
        else if (p1->getPosition().x > 1280 && p1->getPosition().y > 720) { //bottom right
            if (x % 2 == 0) {
                v.x = (40+5) * 32;
                v.y = (23+4) * 32;
            }
            else {
                v.x = (40+31) * 32;
                v.y = (23+13) * 32;
            }
        }
        else if (p1->getPosition().x < 1280 && p1->getPosition().y < 720) { //top left
            if (x % 2 == 0){
                v.x = 16 * 32;
                v.y = 1 * 32;
            }
            else{
                v.y = 10 * 32;
            }
        }
                v.x = 1 * 32;
        zombies.push_back(new Zombie(20, 1, 1, size, v));
        //std::cout << "Zombie " <<  i << std::endl;
        Sleep(500);
    }

}

void movement(sf::RenderWindow& window, Player* p1) {
    //Moves things around the window
    int x = zombies.size() - 1;
    for (int z = 0; z < x; z++) {
        if (zombies[z] != nullptr) {
            if (zombies[z]->getSprite().getGlobalBounds().intersects(zombies[z + 1]->getSprite().getGlobalBounds()) != true) {
                zombies[z]->getMove(p1, p1->getPosition());
            }
        }
    }
    if (x > 0 && zombies[x] != nullptr) {
        zombies[x]->getMove(p1, p1->getPosition());
    }
    else if (x == 0) {
        zombies[0]->getMove(p1, p1->getPosition());
    }
    sf::Vector2f v;
    p1->up = true;
    p1->down = true;
    p1->left = true;
    p1->right = true;
    for (int x = 0; x < walls.size(); x++) {
        sf::FloatRect player = p1->getSprite().getGlobalBounds();
        float playerSize = 50;
        player.top = p1->getPosition().y - playerSize/2;
        player.left = p1->getPosition().x - playerSize / 2;
        player.width = playerSize;
        player.height = playerSize;
        sf::FloatRect wbounds = walls[x]->getWall();
        int x1 = wbounds.left;
        int x2 = wbounds.left + wbounds.width;
        int y1 = wbounds.top;
        int y2 = wbounds.top + wbounds.height;

        if (wbounds.intersects(player)) {
            if (p1->getPosition().y < y1 && p1->getPosition().x < x1) {
                //top left
                //std::cout << "TopLeft ";
                if (y2 - p1->getPosition().y > x2 - p1->getPosition().x) {
                    //closer to x side
                    v.x = wbounds.left - playerSize/2;
                    v.y = p1->getPosition().y;
                }
                else {
                    //closer to y side
                    v.x = p1->getPosition().x;
                    v.y = wbounds.top - playerSize/2;
                }
            }
            else if (p1->getPosition().y < y1 && p1->getPosition().x >= x1 && p1->getPosition().x <= x2) {
                //top middle
                //std::cout << "Top ";
                v.x = p1->getPosition().x;
                v.y = wbounds.top - playerSize/2;
            }
            else if (p1->getPosition().y < y1 && p1->getPosition().x > x2) {
                //top right
                //std::cout << "TopRight ";
                if (y2 - p1->getPosition().y > x2 - p1->getPosition().x) {
                    //closer to x side
                    v.x = wbounds.left + wbounds.width + playerSize/2;
                    v.y = p1->getPosition().y;
                }
                else {
                    //closer to y side
                    v.x = p1->getPosition().x;
                    v.y = wbounds.top - playerSize/2;
                }
            }
            else if (p1->getPosition().y >= y1 && p1->getPosition().y <= y2 && p1->getPosition().x > x2) {
                //mid right
                //std::cout << " Right";
                v.x = wbounds.left + wbounds.width + playerSize/2;
                v.y = p1->getPosition().y;
            }
            else if (p1->getPosition().y > y2 && p1->getPosition().x > x2) {
                //bottom right
                //std::cout << "BotRight ";
                if (y2 - p1->getPosition().y > x2 - p1->getPosition().x) {
                    //closer to x side
                    v.x = wbounds.left + wbounds.width + playerSize/2;
                    v.y = p1->getPosition().y;
                }
                else {
                    //closer to y side
                    v.x = p1->getPosition().x;
                    v.y = wbounds.top + wbounds.height + playerSize/2;
                }
            }
            else if (p1->getPosition().y > y2 && p1->getPosition().x >= x1 && p1->getPosition().x <= x2) {
                //bottom middle
                //std::cout << "Bottom ";
                v.x = p1->getPosition().x;
                v.y = wbounds.top + wbounds.height + playerSize/2;
            }
            else if (p1->getPosition().y > y2 && p1->getPosition().x < x1) {
                //bottom left
                //std::cout << "BotLeft ";
                if (y2 - p1->getPosition().y > x2 - p1->getPosition().x) {
                    //closer to x side
                    v.x = wbounds.left - playerSize/2;
                    v.y = p1->getPosition().y;
                }
                else {
                    //closer to y side
                    v.x = p1->getPosition().x;
                    v.y = wbounds.top + wbounds.height + playerSize/2;
                }
            }
            else if (p1->getPosition().y >= y1 && p1->getPosition().y <= y2 && p1->getPosition().x < x1) {
                //mid left
                //std::cout << " Left";
                v.x = wbounds.left - playerSize/2;
                v.y = p1->getPosition().y;
            }
            p1->setPosition(v);
        }
        for (int i = 0; i < zombies.size(); i++) {
            if (zombies[i] != nullptr) {
                sf::FloatRect zbounds;
                float zombieSize = 50;
                zbounds.top = zombies[i]->getSprite().getPosition().y - zombieSize/2;
                zbounds.left = zombies[i]->getSprite().getPosition().x - zombieSize / 2;;
                zbounds.width = zombieSize;
                zbounds.height = zombieSize;
                if (wbounds.intersects(zbounds)) {
                    if (zombies[i]->getSprite().getPosition().y < y1 && zombies[i]->getSprite().getPosition().x < x1) {
                        //top left
                        //std::cout << "TopLeft ";
                        if (y2 - zombies[i]->getSprite().getPosition().y > x2 - zombies[i]->getSprite().getPosition().x) {
                            //closer to x side
                            v.x = wbounds.left - zombieSize / 2;
                            v.y = zombies[i]->getSprite().getPosition().y;
                        }
                        else {
                            //closer to y side
                            v.x = zombies[i]->getSprite().getPosition().x;
                            v.y = wbounds.top - zombieSize / 2;
                        }
                    }
                    else if (zombies[i]->getSprite().getPosition().y < y1 && zombies[i]->getSprite().getPosition().x >= x1 && zombies[i]->getSprite().getPosition().x <= x2) {
                        //top middle
                        //std::cout << "Top ";
                        v.x = zombies[i]->getSprite().getPosition().x;
                        v.y = wbounds.top - zombieSize / 2;
                    }
                    else if (zombies[i]->getSprite().getPosition().y < y1 && zombies[i]->getSprite().getPosition().x > x2) {
                        //top right
                        //std::cout << "TopRight ";
                        if (y2 - zombies[i]->getSprite().getPosition().y > x2 - zombies[i]->getSprite().getPosition().x) {
                            //closer to x side
                            v.x = wbounds.left + wbounds.width + zombieSize / 2;
                            v.y = zombies[i]->getSprite().getPosition().y;
                        }
                        else {
                            //closer to y side
                            v.x = zombies[i]->getSprite().getPosition().x;
                            v.y = wbounds.top - zombieSize / 2;
                        }
                    }
                    else if (zombies[i]->getSprite().getPosition().y >= y1 && zombies[i]->getSprite().getPosition().y <= y2 && zombies[i]->getSprite().getPosition().x > x2) {
                        //mid right
                        //std::cout << " Right";
                        v.x = wbounds.left + wbounds.width + zombieSize / 2;
                        v.y = zombies[i]->getSprite().getPosition().y;
                    }
                    else if (zombies[i]->getSprite().getPosition().y > y2 && zombies[i]->getSprite().getPosition().x > x2) {
                        //bottom right
                        //std::cout << "BotRight ";
                        if (y2 - zombies[i]->getSprite().getPosition().y > x2 - zombies[i]->getSprite().getPosition().x) {
                            //closer to x side
                            v.x = wbounds.left + wbounds.width + zombieSize / 2;
                            v.y = zombies[i]->getSprite().getPosition().y;
                        }
                        else {
                            //closer to y side
                            v.x = zombies[i]->getSprite().getPosition().x;
                            v.y = wbounds.top + wbounds.height + zombieSize / 2;
                        }
                    }
                    else if (zombies[i]->getSprite().getPosition().y > y2 && zombies[i]->getSprite().getPosition().x >= x1 && zombies[i]->getSprite().getPosition().x <= x2) {
                        //bottom middle
                        //std::cout << "Bottom ";
                        v.x = zombies[i]->getSprite().getPosition().x;
                        v.y = wbounds.top + wbounds.height + zombieSize / 2;
                    }
                    else if (zombies[i]->getSprite().getPosition().y > y2 && zombies[i]->getSprite().getPosition().x < x1) {
                        //bottom left
                        //std::cout << "BotLeft ";
                        if (y2 - zombies[i]->getSprite().getPosition().y > x2 - zombies[i]->getSprite().getPosition().x) {
                            //closer to x side
                            v.x = wbounds.left - zombieSize / 2;
                            v.y = zombies[i]->getSprite().getPosition().y;
                        }
                        else {
                            //closer to y side
                            v.x = zombies[i]->getSprite().getPosition().x;
                            v.y = wbounds.top + wbounds.height + zombieSize / 2;
                        }
                    }
                    else if (zombies[i]->getSprite().getPosition().y >= y1 && zombies[i]->getSprite().getPosition().y <= y2 && zombies[i]->getSprite().getPosition().x < x1) {
                        //mid left
                        //std::cout << " Left";
                        v.x = wbounds.left - zombieSize / 2;
                        v.y = zombies[i]->getSprite().getPosition().y;
                    }
                    zombies[i]->setPosition(v);
                }
            }
        }
        for (int j = 0; j < p1->getGun()->getShots()->size(); j++) {
            if (walls[x]->getWall().intersects(p1->getGun()->getShots()->at(j)->getSprite().getGlobalBounds())) {
                p1->getGun()->getShots()->erase(p1->getGun()->getShots()->begin() + j);
            }
        }
    }
    sf::Vector2i gP = sf::Mouse::getPosition(window);
    makeTrue(gP, p1);
    p1->checkMove(gP);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
    {
        if (clock() - reloadDelayTimer > 2000 && p1->getGun()->getReload() < p1->getGun()->getMaxReload()) //fixed spam reload bug
        {
            reloadDelayTimer = clock();
            p1->canshoot = false;
            std::thread t1(&Player::reload, p1, p1->getGun()->getMaxReload());
            t1.detach();
        }
    }
}

void displayGUI(Player* p1, sf::RenderWindow& window, sf::Font& font, int zombies)
{
    if (p1->getHealth() > 0) {
        sf::RectangleShape healthBack(sf::Vector2f(300, 30));
        healthBack.setFillColor(sf::Color(50, 50, 50));
        sf::RectangleShape healthFront(sf::Vector2f(300 * p1->getHealth() / p1->getMaxHealth(), 30));
        healthFront.setFillColor(sf::Color(230, 45, 45));
        int xPos = 0;
        int yPos = 670;
        if (p1->getPosition().x >= 1280) xPos += 1280;
        if (p1->getPosition().y >= 720) yPos += 720;
        healthBack.setPosition(xPos, yPos);
        healthFront.setPosition(xPos, yPos);

        sf::Text ammoCount;
        ammoCount.setFont(font);
        string ammo = std::to_string(p1->getGun()->getReload()) + "/" + std::to_string(p1->getGun()->getMaxReload());
        ammoCount.setString(ammo);
        ammoCount.setCharacterSize(50);
        ammoCount.setFillColor(sf::Color::White);
        ammoCount.setPosition(xPos + 1150, yPos-10);
        ammoCount.setOutlineColor(sf::Color::Black);
        ammoCount.setOutlineThickness(3);

        sf::Text moneyCount;
        string moneyString = "Money $: " + std::to_string(p1->getMoney());
        moneyCount.setFont(font);
        moneyCount.setString(moneyString);
        moneyCount.setCharacterSize(30);
        moneyCount.setFillColor(sf::Color::White);
        moneyCount.setPosition(xPos + 10, yPos - 40);
        moneyCount.setOutlineColor(sf::Color::Black);
        moneyCount.setOutlineThickness(3);

        sf::Text zombieCount;
        string zombieString = std::to_string(zombies) + " Left";
        zombieCount.setFont(font);
        zombieCount.setString(zombieString);
        zombieCount.setCharacterSize(30);
        zombieCount.setFillColor(sf::Color::White);
        zombieCount.setPosition(xPos + 1180, yPos - 650);
        zombieCount.setOutlineColor(sf::Color::Black);
        zombieCount.setOutlineThickness(3);

        if ((double)p1->getGun()->getReload() / (double)p1->getGun()->getMaxReload() <= 0.35) {
            sf::Text ammoAlert;
            string alert = "Press R to Reload!";
            ammoAlert.setFont(font);
            ammoAlert.setString(alert);
            ammoAlert.setCharacterSize(40);
            ammoAlert.setFillColor(sf::Color(94, 1, 6));
            ammoAlert.setPosition(xPos + 1010, yPos - 50);
            ammoAlert.setOutlineColor(sf::Color::Black);
            ammoAlert.setOutlineThickness(3);
            window.draw(ammoAlert);
        }
        window.draw(zombieCount);
        window.draw(moneyCount);
        window.draw(ammoCount);
        window.draw(healthBack);
        window.draw(healthFront);         
    }
}

void dropMoney(Player* p1) {
    int points = rand() % 7 + 1;
    p1->setMoney(p1->getMoney() + points);
}

void bullets(Player* p1) {
    for (int j = 0; j < p1->getGun()->getShots()->size(); j++) {
        if (p1->getGun()->getShots()->at(j) != nullptr) {
            for (int i = 0; i < zombies.size(); i++) {
                if (zombies[i] != nullptr) {
                    if (j > 0) {
                        if (p1->getGun()->getShots()->at(j)->getSprite().getGlobalBounds().intersects(zombies[i]->getSprite().getGlobalBounds())) {
                            zombies[i]->setHealth(zombies[i]->getHealth() - p1->getGun()->getShots()->at(j)->getDamage());
                            p1->getGun()->getShots()->at(j)->setHealth(-1);
                            std::cout << zombies[i]->getHealth() << std::endl;
                            if (zombies[i]->getHealth() <= 0) {
                                zombies.erase(zombies.begin() + i);
                                dropMoney(p1);
                                i--;
                            }
                            if (p1->getGun()->getShots()->at(j)->getHealth() <= 0) {
                                p1->getGun()->getShots()->erase(p1->getGun()->getShots()->begin() + j);
                                j--;
                            }
                        }
                    }
                }
            }
        }
    }
}


void drawing(sf::RenderWindow& window, Player* p1, sf::Font& font) {
    window.clear();
    window.draw(backdrop);
    window.draw(p1->getSprite());
    for (std::vector<Bullet*>::iterator it = p1->getGun()->getShots()->begin(); it != p1->getGun()->getShots()->end(); ++it) {
        if (*it != nullptr) {
            window.draw((*it)->getSprite());
        }
    }
    window.draw(p1->getGunSprite());
    for (int i = 0; i < zombies.size(); i++)
    {
        if (zombies[i] != nullptr) {
            window.draw(zombies[i]->getSprite());
        }
    }
    for (int k = 0; k < zombies.size(); k++) {
        if (zombies[k] != nullptr) {
            if (zombies[k]->getSprite().getGlobalBounds().intersects(p1->getSprite().getGlobalBounds()) && zombies[k]->getReload() == 0) {
                std::thread t2(&Zombie::attack, zombies[k], p1);
                t2.detach();
            }
        }
    }

    //std::thread gui(displayGUI, p1, std::ref(window), std::ref(font), zombies.size());
    //gui.detach();
    displayGUI(p1, window, font, zombies.size());
}

void run(sf::RenderWindow& window, sf::View& view){
    sf::Texture tex;
    tex.loadFromFile("mapv2.png");
    backdrop.setTexture(tex);
    sf::Vector2f v;
    v.x = 32*40.f;
    v.y = 32*10.f;
    zombies.push_back(new Zombie(20, 1, 1, window.getSize(), v));
    Player* p1 = new Player(20, 1, 1, window.getSize());
    loadWalls();
    //Loading Font
    sf::Font font;
    bool loadFont = true;
    if (!font.loadFromFile("shlop rg.ttf"))
    {
        std::cout << "Font Read Error" << std::endl;
        loadFont = false;
    }
    sf::Text textDisplay;
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
        
        std::thread bull(bullets, p1);
        bull.join();

        //std::thread move(movement, std::ref(window), p1);
        //move.join();

        //std::thread draw(drawing, std::ref(window), p1, std::ref(font));
        //draw.join();

        window.setView(view);

        movement(window, p1);

        //re-draws objects so it looks good      
        drawing(window, p1, font);

        //Round counter & advancer
        if (zombies.size() == 0)
        {
            //advances rou
            if (displayMenu && (clock() - roundCountTimer) > 1000) {
                roundCountTimer = clock();
                displayMenu = false;
                rounds++;
                p1->setHealth(p1->getHealth() + ((p1->getMaxHealth() - p1->getHealth())/2));
                if (p1->getHealth() > p1->getMaxHealth()) p1->setHealth(p1->getMaxHealth());
                textDisplay.setFont(font);
                string display = "Round " + std::to_string(rounds);
                textDisplay.setString(display);
                textDisplay.setCharacterSize(100);
                textDisplay.setFillColor(sf::Color(94, 1, 6));
                textDisplay.setOutlineColor(sf::Color::Black);
                textDisplay.setOutlineThickness(3);
                textDisplay.setOrigin(textDisplay.getLocalBounds().width / 2, textDisplay.getLocalBounds().height / 2);
                textDisplay.setPosition(view.getCenter().x, view.getCenter().y - 300);
            }
            //displays round counter on screen
            if (loadFont)
            {
                window.draw(textDisplay);
            }
            //after 3 seconds, starts next round
            if (clock() - roundCountTimer > 3000) // 3 seconds
            {
                std::thread t1(spawnZombies, window.getSize(), p1);
                t1.detach();
                displayMenu = true;
                std::cout << "Round " << rounds << std::endl;
                roundCountTimer = clock();
            }
        }
        //DEATH MESSAGE
        if (p1->getHealth() < 1)
        {
            textDisplay.setFont(font);
            textDisplay.setString("YOU DIED!");
            textDisplay.setCharacterSize(400);
            textDisplay.setFillColor(sf::Color(94, 1, 6));
            textDisplay.setOutlineColor(sf::Color::Black);
            textDisplay.setOutlineThickness(5);
            textDisplay.setOrigin(textDisplay.getLocalBounds().width/2, textDisplay.getLocalBounds().height/2);
            if (p1->getPosition().x < 1280 && p1->getPosition().y > 720) {//bottom left
                textDisplay.setPosition(1280 / 2, 720 + 720 / 2);
            }
            else if (p1->getPosition().x > 1280 && p1->getPosition().y < 720) {//top right
                textDisplay.setPosition(1280 + 1280 / 2, 720 / 2);
            }
            else if (p1->getPosition().x > 1280 && p1->getPosition().y > 720) {//bottom right
                textDisplay.setPosition(1280 + 1280 / 2, 720 + 720 / 2);
            }
            else if (p1->getPosition().x < 1280 && p1->getPosition().y < 720) {//top left
                textDisplay.setPosition(1280 / 2, 720 / 2);
            }
            window.draw(textDisplay);

        }
        //window.setView(view);
        //move.join();
        //draw.join();
        window.display();
    }
}