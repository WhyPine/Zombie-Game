/*****************************************************************************************
* Programmer: Josh Maloy, Aidan Gooding, Orion Green, Zach Fechko                        *
* Class: CptS 122, Fall 2021				                                             *
* Programming Assignment: PA9                                                            *
* Date: December 10, 2021                                                                *
* Description: This program creates the main menu screen, loads save files, and launches *
* the game                                                                               *
******************************************************************************************/
#include "Play.h"
//#include "savefiles.h"

int main()
{
    bool returnToMenu = false;
    srand(time(NULL));
    sf::RenderWindow Menu(sf::VideoMode(1280, 720), "Horde Shooter Main Menu", sf::Style::Titlebar | sf::Style::Close);
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
    background1.setPosition(-2560, 0);
    background2.setPosition(-6400, 0);
    background3.setPosition(-8960, 0);
    sf::Texture playTex;
    playTex.loadFromFile("play.png");
    playbutton.setTexture(playTex);
    playbutton.setTextureRect(sf::IntRect(15, 10, 585, 185));
    playbutton.setOrigin(playbutton.getScale().x / 2, playbutton.getScale().y / 2);
    playbutton.setPosition(Menu.getSize().x / 2, Menu.getSize().y / 2);
    sf::Texture quitTex;
    quitTex.loadFromFile("quit.png");
    quitbutton.setTexture(quitTex);
    quitbutton.setTextureRect(sf::IntRect(15, 10, 585, 185));
    quitbutton.setOrigin(quitbutton.getScale().x / 2, quitbutton.getScale().y / 2);
    quitbutton.setPosition(Menu.getSize().x / 2, Menu.getSize().y / 2);

    //store menu buttons
    sf::Sprite storeSaveExit;
    sf::Sprite storeReset;
    sf::Sprite storePoints;
    sf::Sprite storeMenu;
    sf::Texture saveT;
    sf::Texture resetT;
    sf::Texture pointsT;
    sf::Texture menuT;
    saveT.loadFromFile("storeSaveAndExit.png");
    resetT.loadFromFile("storeResetPoints.png");
    pointsT.loadFromFile("storePoints.png");
    menuT.loadFromFile("storeMenu.png");
    storeSaveExit.setTexture(saveT);
    storeReset.setTexture(resetT);
    storePoints.setTexture(pointsT);
    storeMenu.setTexture(menuT);
    storeSaveExit.setTextureRect(sf::IntRect(0, 0, 340, 135));
    storeReset.setTextureRect(sf::IntRect(0, 0, 340, 135));
    storePoints.setTextureRect(sf::IntRect(0, 0, 340, 135));
    storeMenu.setTextureRect(sf::IntRect(0, 0, 850, 390));
    storeSaveExit.setPosition(65, 65);
    storeReset.setPosition(875, 65);
    storePoints.setPosition(470, 65);
    storeMenu.setPosition(215, 265);

    //upgrade Buttons
    sf::Sprite storeHealth;
    sf::Texture HealthT;
    HealthT.loadFromFile("storeHealth.png");
    storeHealth.setTexture(HealthT);
    storeHealth.setTextureRect(sf::IntRect(0, 0, 202, 50));
    storeHealth.setPosition(242.5, 345);
    sf::Sprite storeRegen;
    sf::Texture RegenT;
    RegenT.loadFromFile("storeRegen.png");
    storeRegen.setTexture(RegenT);
    storeRegen.setTextureRect(sf::IntRect(0, 0, 202, 50));
    storeRegen.setPosition(242.5, 403);
    sf::Sprite storeSpeed;
    sf::Texture SpeedT;
    SpeedT.loadFromFile("storeSpeed.png");
    storeSpeed.setTexture(SpeedT);
    storeSpeed.setTextureRect(sf::IntRect(0, 0, 202, 50));
    storeSpeed.setPosition(242.5, 461);
    sf::Sprite storeReload;
    sf::Texture reloadT;
    reloadT.loadFromFile("storeReload.png");
    storeReload.setTexture(reloadT);
    storeReload.setTextureRect(sf::IntRect(0, 0, 202, 50));
    storeReload.setPosition(242.5, 519);
    sf::Sprite storeBullet;
    sf::Texture BulletT;
    BulletT.loadFromFile("storeBullet.png");
    storeBullet.setTexture(BulletT);
    storeBullet.setTextureRect(sf::IntRect(0, 0, 202, 50));
    storeBullet.setPosition(242.5, 577);
    sf::Font upgradeFont;
    upgradeFont.loadFromFile("ayar.ttf");
    sf::Text pointsCount;
    pointsCount.setFont(upgradeFont);
    pointsCount.setCharacterSize(40);
    pointsCount.setFillColor(sf::Color::Black);

    //upgradeTexts
    sf::Text Price1;
    sf::Text Price2;
    Price1.setFont(upgradeFont);
    Price2.setFont(upgradeFont);
    Price1.setCharacterSize(30);
    Price2.setCharacterSize(30);
    Price1.setFillColor(sf::Color::Black);
    Price2.setFillColor(sf::Color::Black);
    Price1.setString("1");
    Price2.setString("2");
    Price1.setOrigin(Price1.getLocalBounds().width / 2, Price1.getLocalBounds().height / 2);
    Price2.setOrigin(Price1.getLocalBounds().width / 2, Price1.getLocalBounds().height / 2);
    Price2.setPosition(sf::Vector2f(545, 592));
    sf::Text healthText;
    healthText.setFont(upgradeFont);
    healthText.setCharacterSize(30);
    healthText.setFillColor(sf::Color::Black);
    sf::Text regenText;
    regenText.setFont(upgradeFont);
    regenText.setCharacterSize(30);
    regenText.setFillColor(sf::Color::Black);
    sf::Text speedText;
    speedText.setFont(upgradeFont);
    speedText.setCharacterSize(30);
    speedText.setFillColor(sf::Color::Black);
    sf::Text reloadText;
    reloadText.setFont(upgradeFont);
    reloadText.setCharacterSize(30);
    reloadText.setFillColor(sf::Color::Black);
    sf::Text bulletText;
    bulletText.setFont(upgradeFont);
    bulletText.setCharacterSize(30);
    bulletText.setFillColor(sf::Color::Black);

    savefiles r1;
    bool releasedMouse;
    while (Menu.isOpen()) {
        sf::Event event;
        Menu.pollEvent(event);
        /*background1.move(.8, 0.f);
        background2.move(.8, 0.f);
        background3.move(.8, 0.f);*/
        sf::Vector2i gP = sf::Mouse::getPosition(Menu);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (playbutton.getGlobalBounds().contains(gP.x, gP.y))) {
            releasedMouse = false;
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
                Menu.pollEvent(event);
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
                    //if just closed, then save to files
                    if (returnToMenu) {
                        returnToMenu = false;
                        r1.saveToFile();
                    }
                    while (!returnToMenu && Menu.isOpen()) {
                        Menu.pollEvent(event);
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

                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                            returnToMenu = true;
                            choice = 3;
                        }
                        if (releasedMouse) {
                            //launch game button
                            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (launch.getGlobalBounds().contains(gC.x, gC.y))) {
                                sf::RenderWindow window(sf::VideoMode(1280, 720), "Horde Shooter", sf::Style::Titlebar | sf::Style::Close);
                                sf::View view(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), sf::Vector2f(1280.f, 720.f));
                                window.setView(view);
                                window.setFramerateLimit(60);
                                Menu.setVisible(false);
                                run(window, view, r1.files[choice], false);
                                Menu.setVisible(true);
                                returnToMenu = true;
                            }
                            //open store button
                            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (store.getGlobalBounds().contains(gC.x, gC.y))) {
                                releasedMouse = false;
                                bool inStore = true;
                                string points;
                                while (inStore) {
                                    Menu.pollEvent(event);
                                    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) releasedMouse = true;
                                    if (releasedMouse) {
                                        sf::Vector2i gD = sf::Mouse::getPosition(Menu);
                                        //save and exit
                                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && storeSaveExit.getGlobalBounds().contains(gD.x, gD.y)) {
                                            r1.saveToFile();
                                            releasedMouse = false;
                                            inStore = false;
                                        }
                                        //set all perks to normal and give all skill points back
                                        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && storeReset.getGlobalBounds().contains(gD.x, gD.y)) {
                                            r1.files[choice].resetSkillPoints();
                                            releasedMouse = false;
                                        }
                                        //else if each upgrade button
                                        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && storeHealth.getGlobalBounds().contains(gD.x, gD.y)) {
                                            if (r1.files[choice].skillPoints > 0) {
                                                r1.files[choice].skillPoints--;
                                                r1.files[choice].health += 2;
                                            }
                                            releasedMouse = false;
                                        }
                                        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && storeSpeed.getGlobalBounds().contains(gD.x, gD.y)) {
                                            if (r1.files[choice].skillPoints > 0) {
                                                r1.files[choice].skillPoints--;
                                                r1.files[choice].speedM += 0.1;
                                            }
                                            releasedMouse = false;
                                        }
                                        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && storeRegen.getGlobalBounds().contains(gD.x, gD.y)) {
                                            if (r1.files[choice].skillPoints > 0) {
                                                r1.files[choice].skillPoints--;
                                                r1.files[choice].regenM -= 0.05;
                                            }
                                            releasedMouse = false;
                                        }
                                        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && storeReload.getGlobalBounds().contains(gD.x, gD.y)) {
                                            if (r1.files[choice].skillPoints > 0) {
                                                r1.files[choice].skillPoints--;
                                                r1.files[choice].damageP -= 0.1;
                                            }
                                            releasedMouse = false;
                                        }
                                        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && storeBullet.getGlobalBounds().contains(gD.x, gD.y)) {
                                            if (r1.files[choice].skillPoints > 1) {
                                                r1.files[choice].skillPoints -= 2;
                                                r1.files[choice].bulletAdd++;
                                            }
                                            releasedMouse = false;
                                        }
                                    }
                                    points = "Points: " + std::to_string(r1.files[choice].skillPoints);
                                    pointsCount.setString(points);
                                    pointsCount.setPosition(storePoints.getGlobalBounds().left + storePoints.getGlobalBounds().width / 2 - pointsCount.getLocalBounds().width / 2,
                                        (storePoints.getGlobalBounds().top + storePoints.getGlobalBounds().height / 2 - pointsCount.getLocalBounds().height / 2) - 15);

                                    healthText.setString(std::to_string((int)(r1.files[choice].health)));
                                    regenText.setString(std::to_string((int)(r1.files[choice].regenM * 100)) + "%");
                                    speedText.setString(std::to_string((int)(r1.files[choice].speedM * 100)) + "%");
                                    reloadText.setString(std::to_string((int)(r1.files[choice].damageP * 100)) + "%");
                                    bulletText.setString(std::to_string((int)(r1.files[choice].bulletAdd)));
                                    healthText.setOrigin(healthText.getLocalBounds().width / 2, healthText.getLocalBounds().height / 2);
                                    regenText.setOrigin(regenText.getLocalBounds().width / 2, regenText.getLocalBounds().height / 2);
                                    speedText.setOrigin(speedText.getLocalBounds().width / 2, speedText.getLocalBounds().height / 2);
                                    reloadText.setOrigin(reloadText.getLocalBounds().width / 2, reloadText.getLocalBounds().height / 2);
                                    bulletText.setOrigin(bulletText.getLocalBounds().width / 2, bulletText.getLocalBounds().height / 2);
                                    healthText.setPosition(sf::Vector2f(735, 357));
                                    regenText.setPosition(sf::Vector2f(735, 415));
                                    speedText.setPosition(sf::Vector2f(735, 473));
                                    reloadText.setPosition(sf::Vector2f(735, 531));
                                    bulletText.setPosition(sf::Vector2f(735, 590));


                                    Price1.setPosition(sf::Vector2f(545, 358));
                                    //make sure to draw all the buttons
                                    Menu.clear();
                                    Menu.draw(background1);
                                    Menu.draw(background2);
                                    Menu.draw(background3);
                                    Menu.draw(storeSaveExit);
                                    Menu.draw(storeReset);
                                    Menu.draw(storePoints);
                                    Menu.draw(pointsCount);
                                    Menu.draw(storeMenu);
                                    Menu.draw(storeReload);
                                    Menu.draw(storeRegen);
                                    Menu.draw(storeSpeed);
                                    Menu.draw(storeBullet);
                                    Menu.draw(storeHealth);
                                    Menu.draw(Price1);
                                    Price1.setPosition(sf::Vector2f(545, 416));
                                    Menu.draw(Price1);
                                    Price1.setPosition(sf::Vector2f(545, 474));
                                    Menu.draw(Price1);
                                    Price1.setPosition(sf::Vector2f(545, 532));
                                    Menu.draw(Price1);
                                    Menu.draw(Price2);
                                    Menu.draw(healthText);
                                    Menu.draw(reloadText);
                                    Menu.draw(speedText);
                                    Menu.draw(regenText);
                                    Menu.draw(bulletText);
                                    healthText.setString(std::to_string((int)(r1.files[choice].health) + 2));
                                    regenText.setString(std::to_string((int)((r1.files[choice].regenM - 0.05) * 100)) + "%");
                                    speedText.setString(std::to_string((int)((r1.files[choice].speedM + 0.1) * 100)) + "%");
                                    reloadText.setString(std::to_string((int)((r1.files[choice].damageP - 0.1) * 100)) + "%");
                                    bulletText.setString(std::to_string((int)(r1.files[choice].bulletAdd) + 1));
                                    healthText.setOrigin(healthText.getLocalBounds().width / 2, healthText.getLocalBounds().height / 2);
                                    regenText.setOrigin(regenText.getLocalBounds().width / 2, regenText.getLocalBounds().height / 2);
                                    speedText.setOrigin(speedText.getLocalBounds().width / 2, speedText.getLocalBounds().height / 2);
                                    reloadText.setOrigin(reloadText.getLocalBounds().width / 2, reloadText.getLocalBounds().height / 2);
                                    bulletText.setOrigin(bulletText.getLocalBounds().width / 2, bulletText.getLocalBounds().height / 2);
                                    healthText.setPosition(sf::Vector2f(925, 357));
                                    regenText.setPosition(sf::Vector2f(925, 415));
                                    speedText.setPosition(sf::Vector2f(925, 473));
                                    reloadText.setPosition(sf::Vector2f(925, 531));
                                    bulletText.setPosition(sf::Vector2f(925, 590));
                                    Menu.draw(healthText);
                                    Menu.draw(reloadText);
                                    Menu.draw(speedText);
                                    Menu.draw(regenText);
                                    Menu.draw(bulletText);

                                    Menu.display();
                                }
                            }
                            //quit button
                            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (quitbutton.getGlobalBounds().contains(gC.x, gC.y))) {
                                Menu.close();
                            }
                            //tutorial button
                            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (settings.getGlobalBounds().contains(gC.x, gC.y))) {
                                releasedMouse == false;
                                sf::Texture tutorialT;
                                tutorialT.loadFromFile("tutorialImage.PNG");
                                sf::Sprite tutorial;
                                tutorial.setTexture(tutorialT);
                                tutorial.setTextureRect(sf::IntRect(0, 0, 1280, 720));
                                tutorial.setPosition(sf::Vector2f(0, 0));
                                bool showTutorial = true;
                                int tutorialTimer = clock();
                                while (showTutorial) {
                                    if (clock() - tutorialTimer > 5000 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) showTutorial = false;
                                    Menu.clear();
                                    Menu.draw(tutorial);
                                    Menu.display();
                                }
                                releasedMouse = false;
                            }
                            //debug mode: f1
                            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
                                sf::RenderWindow window(sf::VideoMode(1280, 720), "Horde Shooter", sf::Style::Titlebar | sf::Style::Close);
                                sf::View view(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), sf::Vector2f(1280.f, 720.f));
                                window.setView(view);
                                window.setFramerateLimit(60);
                                Menu.setVisible(false);
                                save debug(false, 0.1, 20000, 100, 0.1, 2.0, 0, 0);
                                run(window, view, debug, true);
                                Menu.setVisible(true);
                                returnToMenu = true;
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