
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

    //The Lab(Right Side)
     walls.push_back(new wall(2112.f, -32.f, 480.f, 64.f));
     walls.push_back(new wall(2112.f, 160.f, 320.f, 32.f));
     walls.push_back(new wall(2112.f, 160.f, 32.f, 256.f));
     walls.push_back(new wall(2016.f, 384.f, 128.f, 32.f));
     walls.push_back(new wall(2016.f, 384.f, 192.f, 32.f));
    
     walls.push_back(new wall(2368.f, 320.f, 224.f, 32.f));
     walls.push_back(new wall(2368.f, 320.f, 32.f, 128.f));
     walls.push_back(new wall(2240.f, 288.f, 32.f, 192.f));
     walls.push_back(new wall(2400.f, 576.f, 32.f, 704.f));
     walls.push_back(new wall(2016.f, 576.f, 384.f, 32.f));

    //Hospital (bottom left)
    walls.push_back(new wall(1280.f, 704.f, 1152.f, 32.f));
    walls.push_back(new wall(1632.f, 768.f, 32.f, 384.f));
    walls.push_back(new wall(1792.f, 832.f, 480.f, 32.f));
    walls.push_back(new wall(1792.f, 1024.f, 96.f, 32.f));

    walls.push_back(new wall(1312.f, 1280.f, 1120.f, 32.f));
    walls.push_back(new wall(2176.f, 1216.f, 32.f, 96.f));
    walls.push_back(new wall(1632.f, 1216.f, 32.f, 96.f));
    walls.push_back(new wall(1856.f, 960.f, 32.f, 256.f));

    walls.push_back(new wall(1920.f, 1120.f, 352.f, 32.f));
    walls.push_back(new wall(2016.f, 960.f, 192.f, 32.f));
    walls.push_back(new wall(2176.f, 992.f, 96.f, 32.f));
    walls.push_back(new wall(2176.f, 960.f, 32.f, 192.f));
    
    //Military Base (Top Right - to the left)
    walls.push_back(new wall(1728.f, -32.f, 224.f, 32.f));
    walls.push_back(new wall(1728.f, -32.f, 32.f, 288.f));
    walls.push_back(new wall(1920.f, -32.f, 32.f, 288.f));
    walls.push_back(new wall(1408.f, -32.f, 32.f, 288.f));
    walls.push_back(new wall(1600.f, -32.f, 32.f, 288.f));
    walls.push_back(new wall(1408.f, -32.f, 224.f, 32.f));

    walls.push_back(new wall(1408.f, 384.f, 32.f, 96.f));
    walls.push_back(new wall(1600.f, 384.f, 32.f, 160.f));
    walls.push_back(new wall(1728.f, 384.f, 32.f, 160.f));
    walls.push_back(new wall(16000.f, 512.f, 160.f, 32.f));
    walls.push_back(new wall(1920.f, 384.f, 32.f, 256.f));
    walls.push_back(new wall(1408.f, 608.f, 544.f, 32.f));


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
        //std::cout << "Zombie " <<  i << std::endl;
        Sleep(500);
    }

}

void movement(sf::RenderWindow& window, Player* p1) {
    //Moves things around the window
    sf::Vector2i gP = sf::Mouse::getPosition(window);
    makeTrue(gP, p1);
    p1->checkMove(gP);
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
    for (int x = 0; x < walls.size(); x++) {
        sf::FloatRect player = p1->getSprite().getGlobalBounds();
        sf::FloatRect wbounds = walls[x]->getWall();
        if (wbounds.intersects(player)) {
            if (player.top < wbounds.top && player.top + player.height < wbounds.top + wbounds.height && player.left < wbounds.left + wbounds.width && player.left + player.width > wbounds.left) { //bottom
                std::cout << "Top";
                v.x = p1->getPosition().x;
                v.y = wbounds.top - player.height / 2 - 2.f;
                p1->setPosition(v);
            }
            else if (player.top > wbounds.top && player.top + player.height > wbounds.top + wbounds.height && player.left < wbounds.left + wbounds.width && player.left + player.width > wbounds.left) { //top
                std::cout << "Bottom";
                v.x = p1->getPosition().x;
                v.y = wbounds.top + wbounds.height + player.height / 2 + 2.f;
                p1->setPosition(v);
            }
            if (player.left < wbounds.left && player.left + player.width < wbounds.left + wbounds.width && player.top < wbounds.top + wbounds.height && player.top + player.height > wbounds.top) { // right
                std::cout << "Left";
                v.x = wbounds.left - player.width / 2 - 2.f;
                v.y = p1->getPosition().y;
                p1->setPosition(v);
            }
            else if (player.left > wbounds.left && player.left + player.width > wbounds.left + wbounds.width && player.top < wbounds.top + wbounds.height && player.top + player.height > wbounds.top) { //left
                std::cout << "Right";
                v.x = wbounds.left + wbounds.width + player.width / 2 + 2.f;
                v.y = p1->getPosition().y;
                p1->setPosition(v);
            }
        }
        for (int i = 0; i < zombies.size(); i++) {
            if (zombies[i] != nullptr) {
                if (walls[x]->getWall().intersects(zombies[i]->getSprite().getGlobalBounds())) {
                    sf::FloatRect zbounds = zombies[i]->getSprite().getGlobalBounds();
                    if (zbounds.left < wbounds.left && zbounds.left + zbounds.width < wbounds.left + wbounds.width && zbounds.top < wbounds.top + wbounds.height && zbounds.top + zbounds.height > wbounds.top) { // right
                        v.x = wbounds.left - zbounds.width / 2;
                        v.y = zombies[i]->getSprite().getPosition().y;
                        zombies[i]->setPosition(v);
                    }
                    else if (zbounds.left > wbounds.left && zbounds.left + zbounds.width > wbounds.left + wbounds.width && zbounds.top < wbounds.top + wbounds.height && zbounds.top + zbounds.height > wbounds.top) { //left
                        v.x = wbounds.left + wbounds.width + zbounds.width / 2;
                        v.y = zombies[i]->getSprite().getPosition().y;
                        zombies[i]->setPosition(v);
                    }
                    else if (zbounds.top < wbounds.top && zbounds.top + zbounds.height < wbounds.top + wbounds.height && zbounds.left < wbounds.left + wbounds.width && zbounds.left + zbounds.width > wbounds.left) { //bottom
                        v.x = zombies[i]->getSprite().getPosition().x;
                        v.y = wbounds.top - zbounds.height / 2;
                        zombies[i]->setPosition(v);
                    }
                    else if (zbounds.top > wbounds.top && zbounds.top + zbounds.height > wbounds.top + wbounds.height && zbounds.left < wbounds.left + wbounds.width && zbounds.left + zbounds.width > wbounds.left) { //top
                        v.x = zombies[i]->getSprite().getPosition().x;
                        v.y = wbounds.top + wbounds.height + zbounds.height / 2;
                        zombies[i]->setPosition(v);
                    }
                }
            }
        }
        for (int j = 0; j < p1->getGun()->getShots()->size(); j++) {
            if (walls[x]->getWall().intersects(p1->getGun()->getShots()->at(j)->getSprite().getGlobalBounds())) {
                p1->getGun()->getShots()->erase(p1->getGun()->getShots()->begin() + j);
            }
        }
    }
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
        string ammo = std::to_string(p1->getGun()->getReload()) + "/" + std::to_string(p1->getGun()->getMaxReload());
        ammoCount.setString(ammo);
        ammoCount.setCharacterSize(50);
        ammoCount.setFillColor(sf::Color::White);
        ammoCount.setPosition(xPos + 1150, yPos-10);
        ammoCount.setOutlineColor(sf::Color::Black);
        ammoCount.setOutlineThickness(3);

        sf::Text ammoAlert;
        string alert = "Press R to Reload!";
        ammoAlert.setFont(font);
        ammoAlert.setString(alert);
        ammoAlert.setCharacterSize(40);
        ammoAlert.setFillColor(sf::Color(94, 1, 6));
        ammoAlert.setPosition(xPos + 1010, yPos - 50);
        ammoAlert.setOutlineColor(sf::Color::Black);
        ammoAlert.setOutlineThickness(3);

        sf::Text moneyCount;
        string moneyString = "Money $: " + std::to_string(p1->getMoney());
        moneyCount.setFont(font);
        moneyCount.setString(moneyString);
        moneyCount.setCharacterSize(30);
        moneyCount.setFillColor(sf::Color::White);
        moneyCount.setPosition(xPos + 10, yPos - 40);
        moneyCount.setOutlineColor(sf::Color::Black);
        moneyCount.setOutlineThickness(3);

        if (p1->getGun()->getReload() < 2) {
            window.draw(ammoAlert);
        }
        window.draw(moneyCount);
        window.draw(ammoCount);
        window.draw(healthBack);
        window.draw(healthFront);
       

        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M))
        {
            displaySkillPointMenu(p1, window);
        }*/
        
       
    }
}

//void displaySkillPointMenu(Player* p1, sf::RenderWindow& window) {
//    /*
//    int maxHealth;
//    double speed;
//    double damageP;*/
//    sf::RectangleShape skillpointBack(sf::Vector2f(100, 300));
//    skillpointBack.setFillColor(sf::Color(50, 50, 50));
//    skillpointBack.setPosition(10, 20);
//
//    sf::Sprite healthbtn;
//    sf::Texture healthTex;
//    healthTex.loadFromFile("healthbtn.png");
//    healthbtn.setTexture(healthTex);
//    
//    //playbutton.setScale(Menu.getSize().x / 1600, Menu.getSize().y / 900);
//    //playbutton.setOrigin(playbutton.get)
//    healthbtn.setPosition(15,25);
//    sf::Vector2i gP = sf::Mouse::getPosition(window);
//    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (healthbtn.getGlobalBounds().contains(gP.x, gP.y)) && p1->getSkillPoints() > 10) {
//        p1->setMaxHealth(p1->getMaxHealth() + 2);
//    }
//
//    sf::Sprite strengthbtn;
//    sf::Texture strengthTex;
//    strengthTex.loadFromFile("strengthbutton.png");
//    strengthbtn.setTexture(strengthTex);
//
//    //playbutton.setScale(Menu.getSize().x / 1600, Menu.getSize().y / 900);
//    //playbutton.setOrigin(playbutton.get)
//    strengthbtn.setPosition(15, 130);
//   
//    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (strengthbtn.getGlobalBounds().contains(gP.x, gP.y)) && p1->getSkillPoints() > 10) {
//        p1->setStrength(p1->getStrength() + .1);
//    }
//
//    sf::Sprite speedbtn;
//    sf::Texture speedTex;
//    speedTex.loadFromFile("speedbtn.png");
//    speedbtn.setTexture(speedTex);
//
//    //playbutton.setScale(Menu.getSize().x / 1600, Menu.getSize().y / 900);
//    //playbutton.setOrigin(playbutton.get)
//    speedbtn.setPosition(15, 235);
//   
//    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (speedbtn.getGlobalBounds().contains(gP.x, gP.y)) && p1->getSkillPoints() > 10) {
//        p1->setSpeed(p1->getSpeed() + .1);
//    }
//
//    window.draw(skillpointBack);
//    window.draw(healthbtn);
//    window.draw(strengthbtn);
//    window.draw(speedbtn);
//}

void dropMoney(Player* p1, sf::RenderWindow& window) {
    int randDecide = rand() % 3;
    if (randDecide == 0) {
        int points = rand() % 3;
        p1->setMoney(p1->getMoney() + points);
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
                                dropMoney(p1, window);
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
    tex.loadFromFile("mapv2.png");
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
    loadWalls();
    //wall* w = new wall(-32, -32, 32, 1504);
    //wall* x = new wall(2560, -32, 32, 1504);
    //wall* y = new wall(-32, -32, 2624, 32);
    //wall* b = new wall(-32, 1440, 2624, 32);
    ////wall* a = new wall(500, 500, 32, 32);
    //walls.push_back(*w);
    //walls.push_back(*x);
    //walls.push_back(*y);
    //walls.push_back(*b);
    //walls.push_back(*a);
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

        //Round counter & advancer
        if (zombies.size() == 0)
        {
            //advances round and heals player
            if (displayMenu && (clock() - roundCountTimer) > 1000)
            {
                roundCountTimer = clock();
                displayMenu = false;
                rounds++;
                p1->setHealth(p1->getHealth() + ((p1->getMaxHealth() - p1->getHealth())/2));
                if (p1->getHealth() > p1->getMaxHealth()) p1->setHealth(p1->getMaxHealth());
            }
            //displays round counter on screen
            if (loadFont)
            {
                textDisplay.setFont(font);
                string display = "Round " + std::to_string(rounds);
                textDisplay.setString(display);
                textDisplay.setCharacterSize(100);
                textDisplay.setFillColor(sf::Color(94, 1, 6));
                textDisplay.setOutlineColor(sf::Color::Black);
                textDisplay.setOutlineThickness(3);
                textDisplay.setOrigin(textDisplay.getLocalBounds().width / 2, textDisplay.getLocalBounds().height / 2);
                textDisplay.setPosition(view.getCenter().x, view.getCenter().y-300);
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
        window.display();
    }
}