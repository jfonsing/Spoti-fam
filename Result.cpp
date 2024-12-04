#include <SFML/Graphics.hpp>
#include "Result.h"
#include "Login.h"
#include "Quiz.h"
#include <queue>
using namespace std;

// new window
bool Results::createWindowR(string songName){
    if (songName.empty()) {
        return false;
    }

    sf::Font font;
    if (!font.loadFromFile("images/font.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
        return false;  // Exit on error
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
    songText.setString(songName);
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

string Results::generateReccSong(map<string, vector<int>>& nameMap, string name, Login::Node* popTree, Login::Node* hiphopTree, Login::Node* rnbTree, Login::Node* countryTree) {
    //cout << nameMap.size();

    if (nameMap.find(name) == nameMap.end()) {
        cout << "1" << endl;
        return "No song found 1";
    }
    vector<int>& values = nameMap[name];
    if (values.size() < 4) {
        cout << "2" << endl;
        return "No song found 2";
    }

    int element = values[0];
    float dance = (values[1]-1)*0.25;
    float enrg = (values[2]-1)*0.25;
    int search = values[3];
    cout << "3" << endl;
    string recSong = "No song found 3";

    // pop
    if(element == 1){
        if (popTree == nullptr) {
            cout << "4" << endl;
            return "No song found. 4";
        }
        // bfs
        if (search == 1){
            // search through tree, if meets dance and energy add songdata it is the song (end search)
            recSong = BFSResults(popTree, dance, enrg);
        }
        else{
            recSong = DFSResults(popTree, dance, enrg);
        }
    }
    // hip-hop
    else if (element == 2) {
        if (hiphopTree == nullptr) {
            std::cerr << "Error: popTree is uninitialized." << std::endl;
            return "No song found. 5";
        }
        // bfs
        if (search == 1) {
            recSong = BFSResults(hiphopTree, dance, enrg);

        }
        else{
            recSong = DFSResults(hiphopTree, dance, enrg);
        }
    }
    //rnb
    else if (element == 3) {
        if (rnbTree == nullptr) {
            std::cerr << "Error: popTree is uninitialized." << std::endl;
            return "No song found. 6";
        }
        // bfs
        if (search == 1) {
            recSong = BFSResults(rnbTree, dance, enrg);

            }
        else{
            recSong = DFSResults(rnbTree, dance, enrg);
        }
    }
    // country
    else if (element == 4){
        if (countryTree == nullptr) {
            std::cerr << "Error: popTree is uninitialized." << std::endl;
            return "No song found. 7";
        }
        if (search == 1){
            recSong = BFSResults(countryTree, dance, enrg);

        }
        else{
            recSong = DFSResults(countryTree, dance, enrg);
        }
    }
    return recSong;
}


string Results::BFSResults(Login::Node* songTree, float danceability, float energy){
    string finalSong;
    if(songTree == nullptr){
        return "no song found 8";
    }
    queue<Login::Node*> nQueue;
    nQueue.push(songTree);
    while(!nQueue.empty()){
        Login::Node* current = nQueue.front();
        nQueue.pop();
        if(current->song.Danceability > (danceability) && current->song.Danceability < (danceability + .25) && current->song.Energy > energy && current->song.Energy < (energy + .25)){
            finalSong = current->song.SongName + " by " + current->song.ArtistName;
            return finalSong;
        }
        if (current->left) {
            nQueue.push(current->left);
        }
        if (current->right) {
            nQueue.push(current->right);
        }
    }
    return finalSong;
}

string Results::DFSResults(Login::Node* songTree, float danceability, float energy) {
    if (songTree == nullptr) {
        return "";
    }

    string leftResult = DFSResults(songTree->left, danceability, energy);
    if (!leftResult.empty()) {
        return leftResult; // Return if a match is found in the left subtree
    }

    if (songTree->song.Danceability > danceability && songTree->song.Danceability < danceability + 0.25 && songTree->song.Energy > energy && songTree->song.Energy < energy + 0.25) {
        return songTree->song.SongName + " by " + songTree->song.ArtistName;
    }


    string rightResult = DFSResults(songTree->right, danceability, energy);
    if (!rightResult.empty()) {
        return rightResult; // Return if a match is found in the right subtree
    }
    return "";
}



