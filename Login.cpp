//
// Created by Ria Rajpal on 11/29/24.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Quiz.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "Login.h"
//ria screen updated
// jenna was here


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
    userInput.setFillColor(sf::Color::White);
    userInput.setStyle(sf::Text::Bold);
    userInput.setPosition(window.getSize().x / 2.0f - userInput.getLocalBounds().width / 2.0f,
                          (window.getSize().y / 2.0f) - 25);

    const int MAX_CHARS = 30;
    sf::Texture enterButton;
    if (!enterButton.loadFromFile("images/next.png")) {
        return false;
    }

    sf::Sprite showButton;
    showButton.setTexture(enterButton);


    sf::FloatRect buttonBounds = showButton.getLocalBounds();
    showButton.setOrigin(buttonBounds.width / 2.f, buttonBounds.height / 2.f);


    showButton.setScale(0.50f, 0.50f);
    showButton.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f +30);

    parseFile();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
            if (event.type == sf::Event::TextEntered) {
                // Ignore control characters, including backspace
                if (event.text.unicode < 128 && event.text.unicode != '\b') {
                    if (name.size() < MAX_CHARS) {
                        name += static_cast<char>(event.text.unicode);
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::FloatRect finalButtonBounds = showButton.getGlobalBounds();
                if (finalButtonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && !name.empty()) {
                    window.close();
                    nameData[name] = {0, 0, 0};
                    Quiz quizz = Quiz();
                    quizz.makeQuizWindow(name, popTree, hiphopTree, rnbTree, countryTree);

                }
            }


            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Return && !name.empty()) {
                    window.close();
                    Quiz quizz = Quiz();
                    quizz.makeQuizWindow(name, popTree, hiphopTree, rnbTree, countryTree);

                }
                else if (event.key.code == sf::Keyboard::Backspace && !name.empty()) {
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
        window.draw(showButton);
        window.draw(nameText);
        window.draw(userInput);
        window.display();
    }

    return false;
}




void Login::parseFile(){
    ifstream inputFile;
    inputFile.open("images/dataset4.csv");
    if (!inputFile.is_open()) {
        return;
    }
    string line = "";
    vector<SongData> songs;

    while(getline(inputFile, line)){
        if (line.empty()) continue;
        stringstream inputString(line);

        string songName;
        string artistName;
        double danceability = 0.0;
        double energy = 0.0;
        string genre;
        string tempString;
        string number;
        string trackid;
        string album;
        string popular;
        string duration;
        string explicitt;
        string key;
        string loudness;
        string mode;
        string speech;
        string acoustic;
        string instrument;
        string live;
        string valence;
        string tempo;
        string time;

        getline(inputString, number, ',');
        getline(inputString, trackid, ',');
        getline(inputString,artistName, ',' );
        getline(inputString,album, ',' );
        getline(inputString,songName, ',' );
        getline(inputString,popular, ',' );
        getline(inputString,duration, ',' );
        getline(inputString,explicitt, ',' );
        getline(inputString,tempString, ',' );


        try {
            danceability = std::stod(tempString);
        } catch (const std::invalid_argument& e) {
            continue;
        }
        getline(inputString,tempString, ',' );
        try {
            energy = std::stod(tempString);
        } catch (const std::invalid_argument& e) {
            continue;
        }
        getline(inputString,key, ',' );
        getline(inputString,loudness, ',' );
        getline(inputString,mode, ',' );
        getline(inputString,speech, ',' );
        getline(inputString,acoustic, ',' );
        getline(inputString,instrument, ',' );
        getline(inputString,live, ',' );
        getline(inputString,valence, ',' );
        getline(inputString,tempo, ',' );
        getline(inputString,time, ',' );
        getline(inputString,genre, ',' );

        SongData* element = new SongData(songName,artistName, danceability, energy, genre);

        if(element->Genre == "pop"){
            cout << element->Genre << endl;
            popSongs.push_back(element);
        }
        else if(element->Genre == "country"){
            cout << element->Genre << endl;
            countrySongs.push_back(element);
        }
        else if(element->Genre == "r-n-b"){
            cout << element->Genre << endl;
            rnbSongs.push_back(element);
        }
        else if(element->Genre == "hip-hop"){
            cout << element->Genre << endl;
            hiphopSongs.push_back(element);
        }
        line = "";
    }
//    if (!popSongs.empty()) {
//        cout << popSongs[0]->ArtistName << endl;
//    }
    popTree = makeTree(popSongs);
    countryTree = makeTree(countrySongs);
    rnbTree = makeTree(rnbSongs);
    hiphopTree = makeTree(hiphopSongs);
}

Login::Node* Login::insert(Node* node, const SongData& song) {
    //cout << "entered" << endl;
    if(node == nullptr){
        Node* newNode = new Node(song);
        //cout << "Inserting song: " << song.SongName << " (Danceability: " << song.Danceability << ")" << endl;
        return newNode;
    }
    if(song.Danceability < node->song.Danceability){
        //cout << "Going left: " << song.SongName << " (Danceability: " << song.Danceability << ")" << endl;
        node->left = insert(node->left, song);
    }
    else if(song.Danceability > node->song.Danceability){
        //cout << "Going right: " << song.SongName << " (Danceability: " << song.Danceability << ")" << endl;
        node->right = insert(node->right, song);
    }
    else {
        //cout << "Duplicate found, inserting in left subtree: " << song.SongName << endl;
        node->left = insert(node->left, song);  // Insert duplicates in the left subtree (or handle them differently)
    }
//    cout << node << endl;
    return node;
}

Login::Node* Login::makeTree(vector<SongData*> songVect){
    if (songVect.empty()) {
        return nullptr;
    }

    Login::Node* root = new Login::Node(*songVect[0]);
    for(int i = 1; i < songVect.size(); i++){
        insert(root, *songVect[i]);
    }
    return root;
}


int main(){
    Login quiz = Login();
    quiz.makeLoginWindow();
}
//push
//

