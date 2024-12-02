#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Quiz.h"
using namespace std;

bool Quiz::makeQuizWindow(){
    // used this for syntax: https://www.sfml-dev.org/tutorials/2.6/window-window.php
    sf::RenderWindow window(sf::VideoMode(800, 600), "Quiz Screen", sf::Style::Fullscreen);
    sf::Texture logo;
    if (!logo.loadFromFile("images/logo.png")) {
        return false;
    }

    sf::Sprite showLogo;
    showLogo.setTexture(logo);


    sf::FloatRect logoBounds = showLogo.getLocalBounds();
    showLogo.setOrigin(logoBounds.width / 2.f, logoBounds.height / 2.f);


    showLogo.setScale(0.50f, 0.50f);
    showLogo.setPosition(window.getSize().x / 2.f, (showLogo.getLocalBounds().height / 2.f)-150);

    sf::Texture logout;
    if (!logout.loadFromFile("images/logout.png")) {
        return false;
    }
    sf::Sprite showLogout;
    showLogout.setTexture(logout);
    showLogout.setScale(0.30,0.30);

    showLogout.setPosition(0.f, (showLogo.getLocalBounds().height / 2.f)-150);



    sf::Texture profile;
    if (!profile.loadFromFile("images/profile.png")) {
        return false;
    }
    sf::Sprite showProfile;
    showProfile.setTexture(profile);
    showProfile.setScale(0.50,0.50);
    showProfile.setPosition(window.getSize().x - showLogo.getLocalBounds().width * 0.50f, 10.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }
        if (window.isOpen()) {
            window.clear(sf::Color(128, 128, 128));
            window.draw(showLogo);
            window.draw(showLogout);
            window.draw(showProfile);
            window.display();
        }
    }

    return false;
}

//int main(){
//    Quiz quizz = Quiz();
//    quizz.makeQuizWindow();
//}