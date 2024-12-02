#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Quiz.h"
#include "Result.h"
using namespace std;

//jennas screen update

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


    showLogo.setScale(0.30, 0.30);
    showLogo.setPosition(window.getSize().x / 2.f, (showLogo.getLocalBounds().height / 2.f)-195);

    sf::Texture logout;
    if (!logout.loadFromFile("images/logout.png")) {
        return false;
    }
    sf::Sprite showLogout;
    showLogout.setTexture(logout);
    showLogout.setScale(0.30,0.30);

    showLogout.setPosition(-40, (showLogout.getLocalBounds().height / 2.f)-280);



    sf::Texture profile;
    if (!profile.loadFromFile("images/profile.png")) {
        return false;
    }
    sf::Sprite showProfile;
    showProfile.setTexture(profile);
    showProfile.setScale(0.30,0.30);
    showProfile.setPosition(window.getSize().x - showProfile.getLocalBounds().width * 0.22f, (showProfile.getLocalBounds().height / 2.f)-280);

    sf::Font font;
    if (!font.loadFromFile("images/font.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
        return -1;  // Exit on error
    }

    sf::Text welcomeText;
    welcomeText.setFont(font);
    welcomeText.setString("Welcome to Spoti-fam!");
    welcomeText.setCharacterSize(20);
    welcomeText.setFillColor(sf::Color::Black);
    welcomeText.setStyle(sf::Text::Bold);
    welcomeText.setPosition(window.getSize().x / 2.0f - welcomeText.getLocalBounds().width / 2.0f,
                            (window.getSize().y / 2.0f) - 200);

    sf::Text captionText;
    captionText.setFont(font);
    captionText.setString("Take this short quiz to meet a new friend and get recommended songs!");
    captionText.setCharacterSize(14);
    captionText.setFillColor(sf::Color::Black);
    //captionText.setStyle(sf::Text::Bold);
    captionText.setPosition(window.getSize().x / 2.0f - captionText.getLocalBounds().width / 2.0f,
                            (window.getSize().y / 2.0f) - 170);

    sf::Text q1Text;
    q1Text.setFont(font);
    q1Text.setString("1. How popular are the songs that you usually listen to?");
    q1Text.setCharacterSize(16);
    q1Text.setFillColor(sf::Color::Black);
    //q1Text.setStyle(sf::Text::Bold);
    q1Text.setPosition(30,
                       (window.getSize().y / 2.0f) - 130);

    sf::Text q11Text;
    q11Text.setFont(font);
    q11Text.setString("Very Popular");
    q11Text.setCharacterSize(14);
    q11Text.setFillColor(sf::Color::Black);
    //q11Text.setStyle(sf::Text::Bold);
    q11Text.setPosition(90,
                        (window.getSize().y / 2.0f) - 110);

    sf::Text q12Text;
    q12Text.setFont(font);
    q12Text.setString("Somewhat Popular");
    q12Text.setCharacterSize(14);
    q12Text.setFillColor(sf::Color::Black);
    //q12Text.setStyle(sf::Text::Bold);
    q12Text.setPosition(90,
                        (window.getSize().y / 2.0f) - 90);

    sf::Text q13Text;
    q13Text.setFont(font);
    q13Text.setString("Not Very Popular");
    q13Text.setCharacterSize(14);
    q13Text.setFillColor(sf::Color::Black);
    //q13Text.setStyle(sf::Text::Bold);
    q13Text.setPosition(90,
                        (window.getSize().y / 2.0f) - 70);

    sf::Text q14Text;
    q14Text.setFont(font);
    q14Text.setString("Not Popular");
    q14Text.setCharacterSize(14);
    q14Text.setFillColor(sf::Color::Black);
    //q14Text.setStyle(sf::Text::Bold);
    q14Text.setPosition(90,
                        (window.getSize().y / 2.0f) - 50);

    sf::Text q2Text;
    q2Text.setFont(font);
    q2Text.setString("2. How danceable is the music that you usually listen to?");
    q2Text.setCharacterSize(16);
    q2Text.setFillColor(sf::Color::Black);
    //q1Text.setStyle(sf::Text::Bold);
    q2Text.setPosition(30,
                       (window.getSize().y / 2.0f) - 10);

    sf::Text q21Text;
    q21Text.setFont(font);
    q21Text.setString("Very Danceable");
    q21Text.setCharacterSize(14);
    q21Text.setFillColor(sf::Color::Black);
    //q11Text.setStyle(sf::Text::Bold);
    q21Text.setPosition(90,
                        (window.getSize().y / 2.0f) - (-10));

    sf::Text q22Text;
    q22Text.setFont(font);
    q22Text.setString("Somewhat Danceable");
    q22Text.setCharacterSize(14);
    q22Text.setFillColor(sf::Color::Black);
    //q12Text.setStyle(sf::Text::Bold);
    q22Text.setPosition(90,
                        (window.getSize().y / 2.0f) - (-30));

    sf::Text q23Text;
    q23Text.setFont(font);
    q23Text.setString("Not Very Danceable");
    q23Text.setCharacterSize(14);
    q23Text.setFillColor(sf::Color::Black);
    //q13Text.setStyle(sf::Text::Bold);
    q23Text.setPosition(90,
                        (window.getSize().y / 2.0f) - (-50));

    sf::Text q24Text;
    q24Text.setFont(font);
    q24Text.setString("Not Popular");
    q24Text.setCharacterSize(14);
    q24Text.setFillColor(sf::Color::Black);
    //q14Text.setStyle(sf::Text::Bold);
    q24Text.setPosition(90,
                        (window.getSize().y / 2.0f) - (-70));

    sf::Text q3Text;
    q3Text.setFont(font);
    q3Text.setString("3. How energetic is the music that you usually listen to?");
    q3Text.setCharacterSize(16);
    q3Text.setFillColor(sf::Color::Black);
    //q1Text.setStyle(sf::Text::Bold);
    q3Text.setPosition(30,
                       (window.getSize().y / 2.0f) - (-110));

    sf::Text q31Text;
    q31Text.setFont(font);
    q31Text.setString("Very Energetic");
    q31Text.setCharacterSize(14);
    q31Text.setFillColor(sf::Color::Black);
    //q11Text.setStyle(sf::Text::Bold);
    q31Text.setPosition(90,
                        (window.getSize().y / 2.0f) - (-130));

    sf::Text q32Text;
    q32Text.setFont(font);
    q32Text.setString("Somewhat Energetic");
    q32Text.setCharacterSize(14);
    q32Text.setFillColor(sf::Color::Black);
    //q12Text.setStyle(sf::Text::Bold);
    q32Text.setPosition(90,
                        (window.getSize().y / 2.0f) - (-150));

    sf::Text q33Text;
    q33Text.setFont(font);
    q33Text.setString("Not Very Energetic");
    q33Text.setCharacterSize(14);
    q33Text.setFillColor(sf::Color::Black);
    //q13Text.setStyle(sf::Text::Bold);
    q33Text.setPosition(90,
                        (window.getSize().y / 2.0f) - (-170));

    sf::Text q34Text;
    q34Text.setFont(font);
    q34Text.setString("Not Energetic");
    q34Text.setCharacterSize(14);
    q34Text.setFillColor(sf::Color::Black);
    //q14Text.setStyle(sf::Text::Bold);
    q34Text.setPosition(90,
                        (window.getSize().y / 2.0f) - (-190));

    sf::Text q4Text;
    q4Text.setFont(font);
    q4Text.setString("4. What traversal method would you like to use?");
    q4Text.setCharacterSize(16);
    q4Text.setFillColor(sf::Color::Black);
    //q1Text.setStyle(sf::Text::Bold);
    q4Text.setPosition(30,
                       (window.getSize().y / 2.0f) - (-230));

    sf::Text q41Text;
    q41Text.setFont(font);
    q41Text.setString("Method 1");
    q41Text.setCharacterSize(14);
    q41Text.setFillColor(sf::Color::Black);
    //q11Text.setStyle(sf::Text::Bold);
    q41Text.setPosition(90,
                        (window.getSize().y / 2.0f) - (-250));

    sf::Text q42Text;
    q42Text.setFont(font);
    q42Text.setString("Method 2");
    q42Text.setCharacterSize(14);
    q42Text.setFillColor(sf::Color::Black);
    //q12Text.setStyle(sf::Text::Bold);
    q42Text.setPosition(90,
                        (window.getSize().y / 2.0f) - (-270));

    sf::Texture enterButton;
    if (!enterButton.loadFromFile("images/next.png")) {
        return false;
    }

    sf::Sprite showButton;
    showButton.setTexture(enterButton);


    sf::FloatRect buttonBounds = showButton.getLocalBounds();
    showButton.setOrigin(buttonBounds.width / 2.f, buttonBounds.height / 2.f);


    showButton.setScale(0.50f, 0.50f);
    showButton.setPosition(window.getSize().x / 2.f + 310, window.getSize().y / 2.f +275);


    // SET BUTTONS AT 60 FOR X AXIS
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::FloatRect finalButtonBounds = showButton.getGlobalBounds();
                if (finalButtonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    window.close();
                    Results res = Results();
                    res.createWindowR();

                }
            }
        }
        if (window.isOpen()) {
            window.clear(sf::Color(128, 128, 128));
            window.draw(showLogo);
            window.draw(showLogout);
            window.draw(showProfile);
            window.draw(welcomeText);
            window.draw(captionText);
            window.draw(q1Text);
            window.draw(q11Text);
            window.draw(q12Text);
            window.draw(q13Text);
            window.draw(q14Text);
            window.draw(q2Text);
            window.draw(q21Text);
            window.draw(q22Text);
            window.draw(q23Text);
            window.draw(q24Text);
            window.draw(q3Text);
            window.draw(q31Text);
            window.draw(q32Text);
            window.draw(q33Text);
            window.draw(q34Text);
            window.draw(q4Text);
            window.draw(q41Text);
            window.draw(q42Text);
            window.draw(showButton);
            window.display();
        }
    }

    return false;
}