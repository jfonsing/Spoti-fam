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
    sf::Sprite showLogo;
    showLogo.setTexture(logo);
    showLogo.setPosition(850, 0);
    showLogo.setScale(0.4,0.4);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (window.isOpen()) {
            window.clear(sf::Color(128, 128, 128));
            window.draw(showLogo);
            window.display();
        }
    }

    return false;
}

int main(){
    Quiz quizz = Quiz();
    quizz.makeQuizWindow();
}