#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Quiz.h"
using namespace std;

bool Quiz::makeQuizWindow(){
    // used this for syntax: https://www.sfml-dev.org/tutorials/2.6/window-window.php
    sf::RenderWindow window(sf::VideoMode(), "Quiz Screen", sf::Style::Fullscreen);

    sf::Texture logo;
    if (!logo.loadFromFile("images/logo.png")) {
        return false;
    }
//seeing if pull worls
    sf::Sprite showLogo;
    sf::Vector2u windowSize = window.getSize();
    sf::FloatRect logoBounds = showLogo.getLocalBounds();
    sprite.setOrigin(logoBounds.width / 2.f, logoBounds.height / 2.f);

    showLogo.setTexture(logo);
    showLogo.setPosition((windowSize.x - logoBounds.width) / 2.f, -75);
    showLogo.setScale(0.70,0.70);

    sf::Texture logout;
    if (!logout.loadFromFile("images/logout.png")) {
        return false;
    }
    sf::Sprite showLogout;
    showLogout.setTexture(logout);
    showLogout.setPosition(-25, -65);
    //showLogout.setScale(0.40,0.40);

    sf::Texture profile;
    if (!profile.loadFromFile("images/profile.png")) {
        return false;
    }
    sf::Sprite showProfile;
    showProfile.setTexture(profile);
    showProfile.setPosition(1700, -65);
    //showProfile.setScale(0.40,0.40);

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

int main(){
    Quiz quizz = Quiz();
    quizz.makeQuizWindow();
}