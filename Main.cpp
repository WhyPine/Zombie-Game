#include "Play.h"
#include "savefiles.h"

int main()
{
    srand(time(NULL));
    sf::RenderWindow Menu(sf::VideoMode(1280, 720), "Horde Shooter Main Menu");
    //Menu.setFramerateLimit(60);
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
    sf::Texture quitTex;
    quitTex.loadFromFile("quit.png");
    quitbutton.setTexture(quitTex);
    quitbutton.setTextureRect(sf::IntRect(15, 10, 585, 185));
    quitbutton.setOrigin(quitbutton.getScale().x / 2, quitbutton.getScale().y / 2);
    //quitbutton.setScale(Menu.getSize().x / 1600, Menu.getSize().y / 900);
    //quitbutton.setOrigin(quitbutton.get)
    quitbutton.setPosition(Menu.getSize().x / 2, Menu.getSize().y / 2);



    savefiles r1;
    bool releasedMouse;
    while (Menu.isOpen()) {
        sf::Event event;
        Menu.pollEvent(event);
        /*background1.move(.8, 0.f);
        background2.move(.8, 0.f);
        background3.move(.8, 0.f);*/
        sf::Vector2i gP = sf::Mouse::getPosition(Menu);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&  (playbutton.getGlobalBounds().contains(gP.x, gP.y))) {
            releasedMouse = false;
            std::cout << "Yes" << std::endl;
            sf::Sprite save1;
            sf::Sprite save2;
            sf::Sprite save3;
            sf::Texture save1T;
            save1T.loadFromFile("save1.png");
            save1.setTexture(save1T);
            save1.setTextureRect(sf::IntRect(0, 0, 340, 135));
            save1.setPosition(50.f, 82.5);
            //save1.setOrigin(save1.getScale().x / 2, save1.getScale().y / 2);
            sf::Texture save2T;
            save2T.loadFromFile("save2.png");
            save2.setTexture(save2T);
            save2.setTextureRect(sf::IntRect(0, 0, 340, 135));
            save2.setPosition(50.f, 292.5);
            //save2.setOrigin(save2.getScale().x / 2, save2.getScale().y / 2);
            sf::Texture save3T;
            save3T.loadFromFile("save3.png");
            save3.setTexture(save3T);
            save3.setTextureRect(sf::IntRect(0, 0, 340, 135));
            save3.setPosition(50.f, 502.5);
            //save3.setOrigin(save3.getScale().x / 2, save3.getScale().y / 2);
            
            int choice = 3;
            while (Menu.isOpen()) {
                if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) releasedMouse = true;
                //std::cout << "Yes" << std::endl;
                sf::Vector2i gB = sf::Mouse::getPosition(Menu);
                if (releasedMouse) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (save1.getGlobalBounds().contains(gB.x, gB.y))) {
                        choice = 0;
                        releasedMouse = false;
                    }
                    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (save2.getGlobalBounds().contains(gB.x, gB.y))) {
                        choice = 1;
                        releasedMouse = false;
                    }
                    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (save3.getGlobalBounds().contains(gB.x, gB.y))) {
                        choice = 2;
                        releasedMouse = false;
                    }
                    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (quitbutton.getGlobalBounds().contains(gB.x, gB.y))) {
                        Menu.close();
                    }
                }
                if (choice != 3) {
                    std::cout << "yeppers";
                    while (Menu.isOpen()) {
                        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) releasedMouse = true;
                        int n = 0;
                        sf::Sprite launch;
                        sf::Sprite store;
                        sf::Sprite settings;
                        sf::Texture launchT;
                        launchT.loadFromFile("launch.png");
                        launch.setTexture(launchT);
                        launch.setTextureRect(sf::IntRect(0, 0, 340, 135));
                        launch.setPosition(50.f, 82.5);
                        sf::Texture storeT;
                        storeT.loadFromFile("store.png");
                        store.setTexture(storeT);
                        store.setTextureRect(sf::IntRect(0, 0, 340, 135));
                        store.setPosition(50.f, 292.5);
                        sf::Texture settingsT;
                        settingsT.loadFromFile("settings.png");
                        settings.setTexture(settingsT);
                        settings.setTextureRect(sf::IntRect(0, 0, 340, 135));
                        settings.setPosition(50.f, 502.5);
                        sf::Vector2i gC = sf::Mouse::getPosition(Menu);
                        if (releasedMouse) {
                            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (launch.getGlobalBounds().contains(gC.x, gC.y))) {
                                sf::RenderWindow window(sf::VideoMode(1280, 720), "Horde Shooter");
                                sf::View view(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), sf::Vector2f(1280.f, 720.f));
                                window.setView(view);
                                window.setFramerateLimit(60);
                                Menu.close();
                                run(window, view);
                            }
                            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (quitbutton.getGlobalBounds().contains(gC.x, gC.y))) {
                                Menu.close();
                            }
                        }
                        /*while (n != 1) {

                        }*/
                        Menu.clear();
                        Menu.draw(background1);
                        Menu.draw(background2);
                        Menu.draw(background3);
                        Menu.draw(quitbutton);
                        Menu.draw(launch);
                        Menu.draw(store);
                        Menu.draw(settings);
                        Menu.display();
                    }
                }
                Menu.clear();
                Menu.draw(background1);
                Menu.draw(background2);
                Menu.draw(background3);
                Menu.draw(quitbutton);
                Menu.draw(save1);
                Menu.draw(save2);
                Menu.draw(save3);
                Menu.display();
            }
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (quitbutton.getGlobalBounds().contains(gP.x, gP.y))) {
            Menu.close();
        }
        //run(window, view);
        Menu.clear();
        Menu.draw(background1);
        Menu.draw(background2);
        Menu.draw(background3);
        Menu.draw(playbutton);
        Menu.display();
    }
    return 0;
}