
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
vector<wall> walls;

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
                v.x = 0 * 32;
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
                v.x = (40+33) * 32;
                v.y = (23+8) * 32;
            }
        }
        else if (p1->getPosition().x < 1280 && p1->getPosition().y < 720) { //top left
            if (x % 2 == 0){
                v.x = 16 * 32;
                v.y = 0 * 32;
            }
            else{
                v.x = 0 * 32;
                v.y = 10 * 32;
            }
        }
        zombies.push_back(new Zombie(20, 1, 1, size, v));
        std::cout << "Zombie " <<  i << std::endl;
        Sleep(500);
    }

}

void movement(sf::RenderWindow& window, Player* p1) {
    //Moves things around the window
    sf::Vector2i gP = sf::Mouse::getPosition(window);
    makeTrue(gP, p1);
    p1->checkMove(gP);
    sf::Vector2f v;
    for (auto& wall : walls) {
        sf::FloatRect player = p1->getSprite().getGlobalBounds();
        sf::FloatRect wbounds = wall.getWall();
        if (wbounds.intersects(player)) {
            if (player.left < wbounds.left + wbounds.width) { // right
                std::cout << "Right";
                v.x = wbounds.left + wbounds.width + player.width / 2;
                v.y = p1->getPosition().y;
                p1->setPosition(v);
            }
            if (player.left + player.width > wbounds.left) { //left
                std::cout << "Left";
                v.x = wbounds.left - player.width;
                v.y = p1->getPosition().y;
                p1->setPosition(v);
            }
            if (player.top < wbounds.top + wbounds.height) { //bottom
                std::cout << "Bottom";
                v.x = p1->getPosition().x;
                v.y = wbounds.top + wbounds.height + player.height;
                p1->setPosition(v);
            }
            if (player.top + player.height > wbounds.top) { //top
                std::cout << "Top";
                v.x = p1->getPosition().x;
                v.y = wbounds.top - player.height;
                p1->setPosition(v);
            }
        }
    }
    int x = zombies.size() - 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) 
    {
        if (clock() - reloadDelayTimer > 2000 && p1->getGun()->getReload() < 30) //fixed spam reload bug
        {
            reloadDelayTimer = clock();
            p1->canshoot = false;
            std::thread t1(&Player::reload, p1, 30);
            t1.detach();
        }
    }
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
}

void displayGUI(Player* p1, sf::RenderWindow& window)
{
    if (p1->getMaxHealth() > 0) {
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
        sf::Font font;
        font.loadFromFile("shlop rg.ttf");
        ammoCount.setFont(font);
        string ammo = std::to_string(p1->getGun()->getReload()) + "/30";
        ammoCount.setString(ammo);
        ammoCount.setCharacterSize(50);
        ammoCount.setFillColor(sf::Color::White);
        ammoCount.setPosition(xPos + 1150, yPos-10);
        ammoCount.setOutlineColor(sf::Color::Black);
   
        window.draw(ammoCount);
        window.draw(healthBack);
        window.draw(healthFront);
    }
}

void drawing(sf::RenderWindow& window, Player* p1) {
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
        window.draw(zombies[i]->getSprite());
    }
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
                                //i--;
                            }
                            if (p1->getGun()->getShots()->at(j)->getHealth() <= 0) {
                                p1->getGun()->getShots()->erase(p1->getGun()->getShots()->begin() + j);
                                j--;
                            }
                        }
                    }
                }
            }
            for (int k = 0; k < zombies.size(); k++) {
                if (zombies[k]->getSprite().getGlobalBounds().intersects(p1->getSprite().getGlobalBounds()) && zombies[k]->getReload() == 0) {
                    std::thread t2(&Zombie::attack, zombies[k], p1);
                    t2.detach();
                    //p1->setHealth(p1->getHealth() - zombies[k]->getDamage());
                    //std::cout << p1->getHealth() << std::endl;
                }
            }
        }
    }
    displayGUI(p1, window);
}

void run(sf::RenderWindow& window, sf::View& view){
    sf::Texture tex;
    tex.loadFromFile("firstMap.png");
    backdrop.setTexture(tex);
    sf::Vector2f v;
    v.x = 1000.f;
    v.y = 200.f;
    zombies.push_back(new Zombie(20, 1, 1, window.getSize(), v));
    sf::Vector2f z;
    z.x = 500.f;
    z.y = 500.f;
    Player* p1 = new Player(20, 1, 1, window.getSize());
    p1->getSprite().setPosition((float)z.x, (float)z.y);
    wall* w = new wall(-32, 0, 32, 1440);
    wall* x = new wall(2560, 0, 32, 1440);
    wall* y = new wall(0, -32, 2560, 32);
    wall* b = new wall(0, 1440, 2560, 32);
    walls.push_back(*w);
    walls.push_back(*x);
    walls.push_back(*y);
    walls.push_back(*b);
    // sf::View view1(sf::Vector2f(window.getSize().x / 2, window.getSize().y), sf::Vector2f(1280.f, 720.f));
    //window.setView(view1);
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
        /*while (p1->getPosition().x < view.getSize().x) {
            view.move(-1.f, 0.f);
        }*/
        /*if (p1->getPosition().x < view.getSize().x / 5000 && p1->getPosition().x < pasPos.x) {
            view.move(-1.f, 0.f);
            pasPos = p1->getPosition();
        }*/
        window.setView(view);
        movement(window, p1);

        //re-draws objects so it looks good      
        drawing(window, p1);

        //Zombies alive checker
        if (zombies.size() == 0)
        {
           // bool displayMenu = true;
            if (displayMenu && (clock() - roundCountTimer) > 1000)
            {
                roundCountTimer = clock();
                displayMenu = false;
                rounds++;
                p1->setHealth(p1->getHealth() + ((p1->getMaxHealth() - p1->getHealth())/2));
            }
            if (loadFont)
            {
                textDisplay.setFont(font);
                string display = "Round " + std::to_string(rounds);
                textDisplay.setString(display);
                textDisplay.setCharacterSize(100);
                textDisplay.setFillColor(sf::Color(94, 1, 6));
                textDisplay.setOutlineColor(sf::Color::Black);
                textDisplay.setOutlineThickness(4);
                textDisplay.setOrigin(textDisplay.getLocalBounds().width / 2, textDisplay.getLocalBounds().height / 2);
                textDisplay.setPosition(view.getCenter().x, view.getCenter().y-300);
                window.draw(textDisplay);
            }
            if (clock() - roundCountTimer > 3000) // 3 seconds
            {
                std::thread t1(spawnZombies, window.getSize(), p1);
                t1.detach();
                displayMenu = true;
                std::cout << "Round " << rounds << std::endl;
                roundCountTimer = clock();
            }
        }
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
        window.display();
    }
}