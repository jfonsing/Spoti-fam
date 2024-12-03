#include <SFML/Graphics.hpp>
#include "Result.h"
#include "Login.h"
using namespace std;

bool Results::createWindowR(){
    sf::Font font;
    if (!font.loadFromFile("images/font.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
        return -1;  // Exit on error
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "Results Screen", sf::Style::Fullscreen);
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
    // my shit
    sf::Text recommendationText;
    recommendationText.setFont(font);
    recommendationText.setString("Your daily song recommendation is: ");
    recommendationText.setCharacterSize(18);
    recommendationText.setFillColor(sf::Color::White);
    recommendationText.setStyle(sf::Text::Bold);

    sf::FloatRect textBounds = recommendationText.getLocalBounds();
    recommendationText.setOrigin(textBounds.width / 2.f, textBounds.height / 2.f);
    recommendationText.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f - 100);

    sf::Text songText;
    songText.setFont(font);
    songText.setString("THIS IS THE SONG(REPLACE)");
    songText.setCharacterSize(18);
    songText.setFillColor(sf::Color::White);
    songText.setStyle(sf::Text::Bold);

    sf::FloatRect songBounds = songText.getLocalBounds();
    songText.setOrigin(songBounds.width / 2.f, songBounds.height / 2.f);
    songText.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f - 50);


    sf::Text recText;
    recText.setFont(font);
    recText.setString("Your recommended friend is:");
    recText.setCharacterSize(18);
    recText.setFillColor(sf::Color::White);
    recText.setStyle(sf::Text::Bold);

    sf::FloatRect recBounds = recText.getLocalBounds();
    recText.setOrigin(recBounds.width / 2.f, recBounds.height / 2.f);
    recText.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

    sf::Text friendText;
    friendText.setFont(font);
    friendText.setString("ACTUAL FRIEND (REPALCE WITH STRING)");
    friendText.setCharacterSize(18);
    friendText.setFillColor(sf::Color::White);
    friendText.setStyle(sf::Text::Bold);

    sf::FloatRect friendBounds = friendText.getLocalBounds();
    friendText.setOrigin(friendBounds.width / 2.f, friendBounds.height / 2.f);
    friendText.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f + 50);


    //jenna's shit
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
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
            // added from me
            window.draw(recommendationText);
            window.draw(songText);
            window.draw(recText);
            window.draw(friendText);
            window.display();
        }
    }
    return false;

}
