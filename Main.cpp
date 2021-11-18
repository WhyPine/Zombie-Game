#include "Player.h"
#include "Zombie.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Horde Shooter");
    window.setFramerateLimit(60);
    Player* p1 = new Player(20, 1, 1, window.getSize());
    Zombie* z1 = new Zombie(10, 1, 1, window.getSize());
    while (window.isOpen())
    {
        sf::Event event;
        window.pollEvent(event);
        if (event.type == sf::Event::Closed) window.close();
        p1->checkMove(window);
        z1->getMove(p1);

        window.clear();
        window.draw(p1->getSprite());
        window.draw(z1->getSprite());
        window.display();
    }

    return 0;
}