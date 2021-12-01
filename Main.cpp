#include "Play.h"


int main()
{
    srand(time(NULL));
    sf::RenderWindow Menu(sf::VideoMode(1280, 720), "Horde Shooter Main Menu");
    sf::Sprite background1;
    sf::Sprite background2;
    sf::Sprite background3;
    sf::Sprite playbutton;
    sf::Sprite quitbutton;
    int x = rand() % 4;
    sf::Texture backTex;
    backTex.loadFromFile("back1.png");
    sf::Texture backTex2;
    backTex2.loadFromFile("back2.png");
    sf::Texture backTex3;
    backTex3.loadFromFile("back3.png");
    background1.setTexture(backTex);
    background2.setTexture(backTex2);
    background3.setTexture(backTex3);
    //background.setTextureRect(sf::IntRect(640, 360, 1920, 1080));
    //background.setPosition(0, 0);
    background1.setPosition(-2560, 0);
    background2.setPosition(-6400, 0);
    background3.setPosition(-8960, 0);
    sf::Texture playTex;
    playTex.loadFromFile("play.png");
    playbutton.setTexture(playTex);
    playbutton.setTextureRect(sf::IntRect(15, 10, 585, 185));
    playbutton.setOrigin(playbutton.getScale().x / 2, playbutton.getScale().y / 2);
    //playbutton.setScale(Menu.getSize().x / 1600, Menu.getSize().y / 900);
    //playbutton.setOrigin(playbutton.get)
    playbutton.setPosition(Menu.getSize().x / 2, Menu.getSize().y / 2);
    while (Menu.isOpen()) {
        sf::Event event;
        Menu.pollEvent(event);
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
        Menu.draw(background1);
        Menu.draw(playbutton);
        Menu.display();
    }
    return 0;
}