#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Quiz.h"
#include "Result.h"
#include "Login.h"
using namespace std;

//jennas screen updated



bool Quiz::makeQuizWindow(string name, map<string, vector<int>> nameMap){
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
    welcomeText.setCharacterSize(25);
    welcomeText.setFillColor(sf::Color::Black);
    welcomeText.setStyle(sf::Text::Bold);
    welcomeText.setPosition(window.getSize().x / 2.0f - welcomeText.getLocalBounds().width / 2.0f,
                            (window.getSize().y / 2.0f) - 300);

    sf::Text captionText;
    captionText.setFont(font);
    captionText.setString("Take this short quiz to meet a new friend and get recommended songs!");
    captionText.setCharacterSize(16);
    captionText.setFillColor(sf::Color::Black);
    //captionText.setStyle(sf::Text::Bold);
    captionText.setPosition(window.getSize().x / 2.0f - captionText.getLocalBounds().width / 2.0f,
                            (window.getSize().y / 2.0f) - 270);

    sf::Text q1Text;
    q1Text.setFont(font);
    q1Text.setString("1. What's your favorite genre?");
    q1Text.setCharacterSize(18);
    q1Text.setFillColor(sf::Color::Black);
    //q1Text.setStyle(sf::Text::Bold);
    q1Text.setPosition(30,
                       (window.getSize().y / 2.0f) - 230);

    sf::Text q11Text;
    q11Text.setFont(font);
    q11Text.setString("Pop");
    q11Text.setCharacterSize(16);
    q11Text.setFillColor(sf::Color::Black);
    //q11Text.setStyle(sf::Text::Bold);
    q11Text.setPosition(90,
                        (window.getSize().y / 2.0f) - 210);

    sf::Text q12Text;
    q12Text.setFont(font);
    q12Text.setString("Hip-Hop");
    q12Text.setCharacterSize(16);
    q12Text.setFillColor(sf::Color::Black);
    //q12Text.setStyle(sf::Text::Bold);
    q12Text.setPosition(90,
                        (window.getSize().y / 2.0f) - 190);

    sf::Text q13Text;
    q13Text.setFont(font);
    q13Text.setString("R&B");
    q13Text.setCharacterSize(16);
    q13Text.setFillColor(sf::Color::Black);
    //q13Text.setStyle(sf::Text::Bold);
    q13Text.setPosition(90,
                        (window.getSize().y / 2.0f) - 170);

    sf::Text q14Text;
    q14Text.setFont(font);
    q14Text.setString("Country");
    q14Text.setCharacterSize(16);
    q14Text.setFillColor(sf::Color::Black);
    //q14Text.setStyle(sf::Text::Bold);
    q14Text.setPosition(90,
                        (window.getSize().y / 2.0f) - 150);

    sf::Text q2Text;
    q2Text.setFont(font);
    q2Text.setString("2. How danceable is the music that you usually listen to?");
    q2Text.setCharacterSize(18);
    q2Text.setFillColor(sf::Color::Black);
    //q1Text.setStyle(sf::Text::Bold);
    q2Text.setPosition(30,
                       (window.getSize().y / 2.0f)-100);

    sf::Text q21Text;
    q21Text.setFont(font);
    q21Text.setString("Very Danceable");
    q21Text.setCharacterSize(16);
    q21Text.setFillColor(sf::Color::Black);
    //q11Text.setStyle(sf::Text::Bold);
    q21Text.setPosition(90,
                        (window.getSize().y / 2.0f) -80);

    sf::Text q22Text;
    q22Text.setFont(font);
    q22Text.setString("Somewhat Danceable");
    q22Text.setCharacterSize(16);
    q22Text.setFillColor(sf::Color::Black);
    //q12Text.setStyle(sf::Text::Bold);
    q22Text.setPosition(90,
                        (window.getSize().y / 2.0f) - 60);

    sf::Text q23Text;
    q23Text.setFont(font);
    q23Text.setString("Not Very Danceable");
    q23Text.setCharacterSize(16);
    q23Text.setFillColor(sf::Color::Black);
    //q13Text.setStyle(sf::Text::Bold);
    q23Text.setPosition(90,
                        (window.getSize().y / 2.0f) - 40);

    sf::Text q24Text;
    q24Text.setFont(font);
    q24Text.setString("Not Danceable at all");
    q24Text.setCharacterSize(16);
    q24Text.setFillColor(sf::Color::Black);
    //q14Text.setStyle(sf::Text::Bold);
    q24Text.setPosition(90,
                        (window.getSize().y / 2.0f) - 20);

    sf::Text q3Text;
    q3Text.setFont(font);
    q3Text.setString("3. How energetic is the music that you usually listen to?");
    q3Text.setCharacterSize(18);
    q3Text.setFillColor(sf::Color::Black);
    //q1Text.setStyle(sf::Text::Bold);
    q3Text.setPosition(30,
                       (window.getSize().y / 2.0f)+30);

    sf::Text q31Text;
    q31Text.setFont(font);
    q31Text.setString("Very Energetic");
    q31Text.setCharacterSize(16);
    q31Text.setFillColor(sf::Color::Black);
    //q11Text.setStyle(sf::Text::Bold);
    q31Text.setPosition(90,
                        (window.getSize().y / 2.0f) +50);

    sf::Text q32Text;
    q32Text.setFont(font);
    q32Text.setString("Somewhat Energetic");
    q32Text.setCharacterSize(16);
    q32Text.setFillColor(sf::Color::Black);
    //q12Text.setStyle(sf::Text::Bold);
    q32Text.setPosition(90,
                        (window.getSize().y / 2.0f) +70);

    sf::Text q33Text;
    q33Text.setFont(font);
    q33Text.setString("Not Very Energetic");
    q33Text.setCharacterSize(16);
    q33Text.setFillColor(sf::Color::Black);
    //q13Text.setStyle(sf::Text::Bold);
    q33Text.setPosition(90,
                        (window.getSize().y / 2.0f) +90);

    sf::Text q34Text;
    q34Text.setFont(font);
    q34Text.setString("Not Energetic");
    q34Text.setCharacterSize(16);
    q34Text.setFillColor(sf::Color::Black);
    //q14Text.setStyle(sf::Text::Bold);
    q34Text.setPosition(90,
                        (window.getSize().y / 2.0f) +110);

    sf::Text q4Text;
    q4Text.setFont(font);
    q4Text.setString("4. What traversal method would you like to use?");
    q4Text.setCharacterSize(18);
    q4Text.setFillColor(sf::Color::Black);
    //q1Text.setStyle(sf::Text::Bold);
    q4Text.setPosition(30,
                       (window.getSize().y / 2.0f) +150);

    sf::Text q41Text;
    q41Text.setFont(font);
    q41Text.setString("Method 1");
    q41Text.setCharacterSize(16);
    q41Text.setFillColor(sf::Color::Black);
    //q11Text.setStyle(sf::Text::Bold);
    q41Text.setPosition(90,
                        (window.getSize().y / 2.0f) +170);

    sf::Text q42Text;
    q42Text.setFont(font);
    q42Text.setString("Method 2");
    q42Text.setCharacterSize(16);
    q42Text.setFillColor(sf::Color::Black);
    //q12Text.setStyle(sf::Text::Bold);
    q42Text.setPosition(90,
                        (window.getSize().y / 2.0f) +190);

    sf::Texture enterButton;
    if (!enterButton.loadFromFile("images/next.png")) {
        return false;
    }

    sf::Sprite showButton;
    showButton.setTexture(enterButton);


    sf::FloatRect buttonBounds = showButton.getLocalBounds();
    showButton.setOrigin(buttonBounds.width / 2.f, buttonBounds.height / 2.f);


    showButton.setScale(0.50f, 0.50f);
    showButton.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f +300);

    sf::Texture mcButton;
    if (!mcButton.loadFromFile("images/unfilled.png")) {
        return false;
    }

    sf::Texture mcButtonFill;
    if (!mcButtonFill.loadFromFile("images/filled.png")){
        return false;
    }

    sf::Sprite fillButton;
    fillButton.setTexture(enterButton);

    sf::FloatRect buttonFillBounds = fillButton.getLocalBounds();
    fillButton.setOrigin(buttonFillBounds.width / 2.f, buttonFillBounds.height / 2.f);


    sf::Sprite showMCButton11;
    showMCButton11.setTexture(mcButton);

    sf::FloatRect buttonBoundsMC11 = showMCButton11.getLocalBounds();
    showMCButton11.setOrigin(buttonBoundsMC11.width / 2.f, buttonBoundsMC11.height / 2.f);

    showMCButton11.setScale(0.16f, 0.16f);
    showMCButton11.setPosition(72, window.getSize().y / 2.f -  200);


    sf::Sprite showMCButton12;
    showMCButton12.setTexture(mcButton);

    sf::FloatRect buttonBoundsMC12 = showMCButton12.getLocalBounds();
    showMCButton12.setOrigin(buttonBoundsMC12.width / 2.f, buttonBoundsMC12.height / 2.f);

    showMCButton12.setScale(0.16f, 0.16f);
    showMCButton12.setPosition(72, window.getSize().y / 2.f - 180);


    sf::Sprite showMCButton13;
    showMCButton13.setTexture(mcButton);

    sf::FloatRect buttonBoundsMC13 = showMCButton13.getLocalBounds();
    showMCButton13.setOrigin(buttonBoundsMC13.width / 2.f, buttonBoundsMC13.height / 2.f);

    showMCButton13.setScale(0.16f, 0.16f);
    showMCButton13.setPosition(72, window.getSize().y / 2.f - 160);


    sf::Sprite showMCButton14;
    showMCButton14.setTexture(mcButton);

    sf::FloatRect buttonBoundsMC14 = showMCButton14.getLocalBounds();
    showMCButton14.setOrigin(buttonBoundsMC14.width / 2.f, buttonBoundsMC14.height / 2.f);

    showMCButton14.setScale(0.16f, 0.16f);
    showMCButton14.setPosition(72, window.getSize().y / 2.f - 140);


    sf::Sprite showMCButton21;
    showMCButton21.setTexture(mcButton);

    sf::FloatRect buttonBoundsMC21 = showMCButton21.getLocalBounds();
    showMCButton21.setOrigin(buttonBoundsMC21.width / 2.f, buttonBoundsMC21.height / 2.f);


    showMCButton21.setScale(0.16f, 0.16f);
    showMCButton21.setPosition(72, window.getSize().y / 2.f - 70);


    sf::Sprite showMCButton22;
    showMCButton22.setTexture(mcButton);

    sf::FloatRect buttonBoundsMC22 = showMCButton22.getLocalBounds();
    showMCButton22.setOrigin(buttonBoundsMC22.width / 2.f, buttonBoundsMC22.height / 2.f);


    showMCButton22.setScale(0.16f, 0.16f);
    showMCButton22.setPosition(72, window.getSize().y / 2.f - 50);


    sf::Sprite showMCButton23;
    showMCButton23.setTexture(mcButton);

    sf::FloatRect buttonBoundsMC23 = showMCButton23.getLocalBounds();
    showMCButton23.setOrigin(buttonBoundsMC23.width / 2.f, buttonBoundsMC23.height / 2.f);


    showMCButton23.setScale(0.16f, 0.16f);
    showMCButton23.setPosition(72, window.getSize().y / 2.f - 30);


    sf::Sprite showMCButton24;
    showMCButton24.setTexture(mcButton);

    sf::FloatRect buttonBoundsMC24 = showMCButton24.getLocalBounds();
    showMCButton24.setOrigin(buttonBoundsMC24.width / 2.f, buttonBoundsMC24.height / 2.f);


    showMCButton24.setScale(0.16f, 0.16f);
    showMCButton24.setPosition(72, window.getSize().y / 2.f - 10);


    sf::Sprite showMCButton31;
    showMCButton31.setTexture(mcButton);

    sf::FloatRect buttonBoundsMC31 = showMCButton31.getLocalBounds();
    showMCButton31.setOrigin(buttonBoundsMC31.width / 2.f, buttonBoundsMC31.height / 2.f);


    showMCButton31.setScale(0.16f, 0.16f);
    showMCButton31.setPosition(72, window.getSize().y / 2.f +60);


    sf::Sprite showMCButton32;
    showMCButton32.setTexture(mcButton);

    sf::FloatRect buttonBoundsMC32 = showMCButton32.getLocalBounds();
    showMCButton32.setOrigin(buttonBoundsMC32.width / 2.f, buttonBoundsMC32.height / 2.f);


    showMCButton32.setScale(0.16f, 0.16f);
    showMCButton32.setPosition(72, window.getSize().y / 2.f +80);


    sf::Sprite showMCButton33;
    showMCButton33.setTexture(mcButton);

    sf::FloatRect buttonBoundsMC33 = showMCButton33.getLocalBounds();
    showMCButton33.setOrigin(buttonBoundsMC33.width / 2.f, buttonBoundsMC33.height / 2.f);


    showMCButton33.setScale(0.16f, 0.16f);
    showMCButton33.setPosition(72, window.getSize().y / 2.f +100);


    sf::Sprite showMCButton34;
    showMCButton34.setTexture(mcButton);

    sf::FloatRect buttonBoundsMC34 = showMCButton34.getLocalBounds();
    showMCButton34.setOrigin(buttonBoundsMC34.width / 2.f, buttonBoundsMC34.height / 2.f);


    showMCButton34.setScale(0.16f, 0.16f);
    showMCButton34.setPosition(72, window.getSize().y / 2.f +120);



    sf::Sprite showMCButton41;
    showMCButton41.setTexture(mcButton);

    sf::FloatRect buttonBoundsMC41 = showMCButton41.getLocalBounds();
    showMCButton41.setOrigin(buttonBoundsMC41.width / 2.f, buttonBoundsMC41.height / 2.f);


    showMCButton41.setScale(0.16f, 0.16f);
    showMCButton41.setPosition(72, window.getSize().y / 2.f +180);



    sf::Sprite showMCButton42;
    showMCButton42.setTexture(mcButton);

    sf::FloatRect buttonBoundsMC42 = showMCButton42.getLocalBounds();
    showMCButton42.setOrigin(buttonBoundsMC42.width / 2.f, buttonBoundsMC42.height / 2.f);


    showMCButton42.setScale(0.16f, 0.16f);
    showMCButton42.setPosition(72, window.getSize().y / 2.f +200);

    bool mouseClickedL = false;
    int MC1 = 0;
    int MC2 = 0;
    int MC3 = 0;
    int MC4 = 0;
    // SET BUTTONS AT 60 FOR X AXIS
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }

            //TIM AND JENNA WORK SPACE
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
                mouseClickedL = true;
            }
            if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
                if(mouseClickedL == true){
                    auto mouse = sf::Mouse::getPosition(window);
                    auto translated = window.mapPixelToCoords(mouse);
                    if(showMCButton11.getGlobalBounds().contains(translated)){
                        if(MC1 != 0){
                            showMCButton12.setTexture(mcButton);
                            showMCButton13.setTexture(mcButton);
                            showMCButton14.setTexture(mcButton);
                        }
                        showMCButton11.setTexture(mcButtonFill);
                        MC1 = 1;
                    }
                    else if(showMCButton12.getGlobalBounds().contains(translated)){
                        if(MC1 != 0){
                            showMCButton11.setTexture(mcButton);
                            showMCButton13.setTexture(mcButton);
                            showMCButton14.setTexture(mcButton);
                        }
                        showMCButton12.setTexture(mcButtonFill);
                        MC1 = 2;
                    }
                    else if(showMCButton13.getGlobalBounds().contains(translated)){
                        if(MC1 != 0){
                            showMCButton11.setTexture(mcButton);
                            showMCButton12.setTexture(mcButton);
                            showMCButton14.setTexture(mcButton);
                        }
                        showMCButton13.setTexture(mcButtonFill);
                        MC1 = 3;
                    }
                    else if(showMCButton14.getGlobalBounds().contains(translated)){
                        if(MC1 != 0){
                            showMCButton11.setTexture(mcButton);
                            showMCButton12.setTexture(mcButton);
                            showMCButton13.setTexture(mcButton);
                        }
                        showMCButton14.setTexture(mcButtonFill);
                        MC1 = 4;
                    }
                    else if(showMCButton21.getGlobalBounds().contains(translated)){
                        if(MC2 != 0){
                            showMCButton22.setTexture(mcButton);
                            showMCButton23.setTexture(mcButton);
                            showMCButton24.setTexture(mcButton);
                        }
                        showMCButton21.setTexture(mcButtonFill);
                        MC2 = 1;
                    }
                    else if(showMCButton22.getGlobalBounds().contains(translated)){
                        if(MC2 != 0){
                            showMCButton21.setTexture(mcButton);
                            showMCButton23.setTexture(mcButton);
                            showMCButton24.setTexture(mcButton);
                        }
                        showMCButton22.setTexture(mcButtonFill);
                        MC2 = 2;
                    }
                    else if(showMCButton23.getGlobalBounds().contains(translated)){
                        if(MC2 != 0){
                            showMCButton21.setTexture(mcButton);
                            showMCButton22.setTexture(mcButton);
                            showMCButton24.setTexture(mcButton);
                        }
                        showMCButton23.setTexture(mcButtonFill);
                        MC2 = 3;
                    }
                    else if(showMCButton24.getGlobalBounds().contains(translated)){
                        if(MC2 != 0){
                            showMCButton21.setTexture(mcButton);
                            showMCButton22.setTexture(mcButton);
                            showMCButton23.setTexture(mcButton);
                        }
                        showMCButton24.setTexture(mcButtonFill);
                        MC2 = 4;
                    }
                    else if(showMCButton31.getGlobalBounds().contains(translated)){
                        if(MC3 != 0){
                            showMCButton32.setTexture(mcButton);
                            showMCButton33.setTexture(mcButton);
                            showMCButton34.setTexture(mcButton);
                        }
                        showMCButton31.setTexture(mcButtonFill);
                        MC3 = 4;
                    }
                    else if(showMCButton32.getGlobalBounds().contains(translated)){
                        if(MC3 != 0){
                            showMCButton31.setTexture(mcButton);
                            showMCButton33.setTexture(mcButton);
                            showMCButton34.setTexture(mcButton);
                        }
                        showMCButton32.setTexture(mcButtonFill);
                        MC3 = 2;
                    }
                    else if(showMCButton33.getGlobalBounds().contains(translated)){
                        if(MC3 != 0){
                            showMCButton31.setTexture(mcButton);
                            showMCButton32.setTexture(mcButton);
                            showMCButton34.setTexture(mcButton);
                        }
                        showMCButton33.setTexture(mcButtonFill);
                        MC3 = 3;
                    }
                    else if(showMCButton34.getGlobalBounds().contains(translated)){
                        if(MC3 != 0){
                            showMCButton31.setTexture(mcButton);
                            showMCButton32.setTexture(mcButton);
                            showMCButton33.setTexture(mcButton);
                        }
                        showMCButton34.setTexture(mcButtonFill);
                        MC3 = 4;
                    }
                    else if(showMCButton41.getGlobalBounds().contains(translated)){
                        if(MC4 != 0){
                            showMCButton42.setTexture(mcButton);
                        }
                        showMCButton41.setTexture(mcButtonFill);
                        MC4 = 1;
                    }
                    else if(showMCButton42.getGlobalBounds().contains(translated)){
                        if(MC4 != 0){
                            showMCButton41.setTexture(mcButton);
                        }
                        showMCButton42.setTexture(mcButtonFill);
                        MC4 = 2;
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::FloatRect finalButtonBounds = showButton.getGlobalBounds();
                if (finalButtonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && MC1 != 0 && MC2 != 0 && MC3 != 0 && MC4 != 0) {
                    window.close();
                    Results res = Results();
                    res.createWindowR();
                    vector<int> val;
                    val.push_back(MC1);
                    val.push_back(MC2);
                    val.push_back(MC3);
                    val.push_back(MC3);
                    nameMap[name] = val;
                    for (const auto& [key, value] : nameMap) {
                        std::cout << key << ": ";
                        for (const int& i : value){
                            cout << i << ", ";
                        }
                    }
                }
                sf::FloatRect finalLogoutBounds = showLogout.getGlobalBounds();
                if (finalLogoutBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    window.close();
                    Login home = Login();
                    home.makeLoginWindow();

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
            window.draw(showMCButton11);
            window.draw(showMCButton12);
            window.draw(showMCButton13);
            window.draw(showMCButton14);
            window.draw(showMCButton21);
            window.draw(showMCButton22);
            window.draw(showMCButton23);
            window.draw(showMCButton24);
            window.draw(showMCButton31);
            window.draw(showMCButton32);
            window.draw(showMCButton33);
            window.draw(showMCButton34);
            window.draw(showMCButton41);
            window.draw(showMCButton42);
            window.display();
        }
    }

    return false;
}