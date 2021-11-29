#include "Play.h"



int main()
{
    srand(time(NULL));
    sf::RenderWindow Menu(sf::VideoMode(1280, 720), "Horde Shooter Main Menu");
    sf::Sprite background;
    sf::Sprite playbutton;
    sf::Sprite quitbutton;
    int x = rand() % 4;
    while (Menu.isOpen()) {
        sf::Event event;
        Menu.pollEvent(event);
        sf::Texture backTex;
        if (x == 0) backTex.loadFromFile("War.png");
        else if (x == 1) backTex.loadFromFile("War2.png");
        else if (x == 2) backTex.loadFromFile("War3.png");
        else if (x == 3) backTex.loadFromFile("War4.png");
        background.setTexture(backTex);
        //background.setTextureRect(sf::IntRect(640, 360, 1920, 1080));
        //background.setPosition(0, 0);
        sf::Texture playTex;
        playTex.loadFromFile("play.png");
        playbutton.setTexture(playTex);
        playbutton.setTextureRect(sf::IntRect(15, 10, 585, 185));
        playbutton.setOrigin(playbutton.getScale().x / 2, playbutton.getScale().y / 2);
        //playbutton.setScale(Menu.getSize().x / 1600, Menu.getSize().y / 900);
        //playbutton.setOrigin(playbutton.get)
        playbutton.setPosition(Menu.getSize().x / 2, Menu.getSize().y / 2);
        sf::Vector2i gP = sf::Mouse::getPosition(Menu);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&  (playbutton.getGlobalBounds().contains(gP.x, gP.y))) {
            sf::RenderWindow window(sf::VideoMode(1280, 720), "Horde Shooter");
            sf::View view(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), sf::Vector2f(1280.f, 720.f));
            window.setView(view);
            window.setFramerateLimit(60);
            run(window, view);
            Menu.close();
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (quitbutton.getGlobalBounds().contains(gP.x, gP.y))) {
            Menu.close();
        }
        Menu.clear();
        Menu.draw(background);
        Menu.draw(playbutton);
        Menu.display();
    }
    return 0;
}