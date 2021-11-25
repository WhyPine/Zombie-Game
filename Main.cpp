#include "Play.h"



int main()
{
    srand(time(NULL));
    sf::RenderWindow Menu(sf::VideoMode(1280, 720), "Horde Shooter Main Menu");
    sf::Sprite background;
    sf::Sprite playbutton;
    sf::Sprite quitbutton;

    while (Menu.isOpen()) {
        sf::Event event;
        Menu.pollEvent(event);
        sf::Texture playTex;
        playTex.loadFromFile("play.png");
        playbutton.setTexture(playTex);
        playbutton.setTextureRect(sf::IntRect(15, 10, 585, 185));
        //playbutton.setOrigin(playbutton.getScale().x / 2, playbutton.getScale().y / 2);
        //playbutton.setScale(Menu.getSize().x / 1600, Menu.getSize().y / 900);
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
        Menu.draw(playbutton);
        Menu.display();
    }
    return 0;
}