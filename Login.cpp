//
// Created by Ria Rajpal on 11/29/24.
//
#include <SFML/Graphics.hpp>
#include "Login.h"
#include "Quiz.h"

bool Login::makeLoginWindow() {
    // used this for syntax: https://www.sfml-dev.org/tutorials/2.6/window-window.php
    sf::RenderWindow window(sf::VideoMode(800, 600), "Login Screen", sf::Style::Fullscreen);
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


    sf::Font font;
    if (!font.loadFromFile("images/font.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
        return -1;  // Exit on error
    }

    sf::Text nameText;
    nameText.setFont(font);
    nameText.setString("Enter your username: ");
    nameText.setCharacterSize(20);
    nameText.setFillColor(sf::Color::Black);
    nameText.setStyle(sf::Text::Bold);
    nameText.setPosition(window.getSize().x / 2.0f - nameText.getLocalBounds().width / 2.0f,
                         (window.getSize().y / 2.0f) - 75);

    // create user input text and string
    sf::Text userInput;
    userInput.setFont(font);
    userInput.setCharacterSize(18);
    userInput.setFillColor(sf::Color::Yellow);
    userInput.setStyle(sf::Text::Bold);
    userInput.setPosition(window.getSize().x / 2.0f - userInput.getLocalBounds().width / 2.0f,
                          (window.getSize().y / 2.0f) - 25);

    const int MAX_CHARS = 30;


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
            if(event.type == sf::Event::TextEntered){
                    if(name.size() < MAX_CHARS){
                        name += static_cast<char>(event.text.unicode);
//                        userInput.setString(name);
                    }

            }

            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Return && !name.empty()){
                    window.close();
                    Quiz quizz = Quiz();
                    quizz.makeQuizWindow();;

                } else if(event.key.code == sf::Keyboard::Backspace && name.size()>0){
                    name.pop_back();
                }
            }
//        userInput.setString(name);
            float x = (window.getSize().x / 2.0f) - (userInput.getGlobalBounds().width / 2.0f);
            float y = (window.getSize().y / 2.0f) - 45;

            userInput.setPosition(x, y);  // Set the position of the text

        string displayedName = name;
        if (name.size() < MAX_CHARS && name.size() >= 1) {
            displayedName += '|';
        }

        userInput.setString(displayedName);
        }
            window.clear(sf::Color(128, 128, 128));
            window.draw(showLogo);
            window.draw(nameText);
            window.draw(userInput);
            window.display();
    }

    return false;
}

int main(){
    Login quiz = Login();
    quiz.makeLoginWindow();
}
//push
//