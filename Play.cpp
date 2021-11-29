
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

void makeTrue(sf::Vector2i& gP, Player* p1) {
    if (p1->getPosition().x >= 1280) {
        gP.x += 1280;
    }
    if (p1->getPosition().y >= 720) {
        gP.y += 720;
    }
}

void spawnZombies(sf::Vector2u size) {
    for (int i = 0; i < 3 * rounds + 5; i++) {
        sf::Vector2f v;
        v.x = 1000.f;
        v.y = 200.f;
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
    int x = zombies.size() - 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) 
    {
        if (clock() - reloadDelayTimer > 2000) //fixed spam reload bug
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
   // sf::View view1(sf::Vector2f(window.getSize().x / 2, window.getSize().y), sf::Vector2f(1280.f, 720.f));
    //window.setView(view1);
    //Loading Font
    sf::Font font;
    bool loadFont = true;
    if (!font.loadFromFile("NexaRustSans-Black.otf"))
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
            }
            if (loadFont)
            {
                //start = clock();
                textDisplay.setFont(font);
                string display = "Round " + std::to_string(rounds);
                textDisplay.setString(display);
                textDisplay.setCharacterSize(100);
                textDisplay.setFillColor(sf::Color::Red);
                textDisplay.setStyle(sf::Text::Bold);
                textDisplay.setOrigin(textDisplay.getLocalBounds().width / 2, textDisplay.getLocalBounds().height / 2);
                textDisplay.setPosition(window.getSize().x / 2, window.getSize().y / 2);
                window.draw(textDisplay);
            }
            if (clock() - roundCountTimer > 3000) // 3 seconds
            {
                std::thread t1(spawnZombies, window.getSize());
                t1.detach();
                displayMenu = true;
                std::cout << "Round " << rounds << std::endl;
                roundCountTimer = clock();
            }
        }
        //window.setView(view);
        window.display();
    }
}