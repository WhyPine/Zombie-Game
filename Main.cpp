#include "Player.h"
#include "Zombie.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>

using std::vector;
using std::string;

int rounds = 1;
vector<Zombie*> zombies;


void spawnZombies(sf::RenderWindow& window) {
    for (int i = 0; i < 3 * rounds + 5; i++) {
        sf::Vector2f v;
        v.x = 10.f;
        v.y = 10.f;
        zombies.push_back(new Zombie(20, 1, 1, window.getSize(), v));
        //zombies[i]->random = rand() % 5;
        //std::cout << "Zombie: " << i << " Spawned" << std::endl;
    }
}

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Horde Shooter");
    window.setFramerateLimit(60);
    Player* p1 = new Player(20, 1, 1, window.getSize());

    //Loading Font
    sf::Font font;
    bool loadFont = true;
    if(!font.loadFromFile("NexaRustSans-Black.otf"))
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
        //Moves things around the window
        p1->checkMove(window);
        for (std::vector<Zombie*>::iterator it = zombies.begin(); it != zombies.end(); ++it) {
            if (*it != nullptr) {
                (*it)->getMove(p1, p1->getPosition());
            }
        }
        //re-draws objects so it looks good
        window.clear();
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
        //Zombies alive checker
        if (zombies.size() == 0) 
        {
            rounds++;
            if(loadFont)
            {
                textDisplay.setFont(font);
                textDisplay.setString("Round " + rounds);
                textDisplay.setCharacterSize(100);
                textDisplay.setFillColor(sf::Color::Red);
                textDisplay.setStyle(sf::Text::Bold);
                //textDisplay.setPosition(sf::vector newVector())
                window.draw(textDisplay);
            }
            spawnZombies(window);
        }
        window.display();
    }

    return 0;
}