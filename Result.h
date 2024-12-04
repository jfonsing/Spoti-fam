#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Login.h"
#include "Quiz.h"
using namespace std;
#pragma once
//
class Results{
public:
    //bool createWindowR(string songName);
    bool createWindowR(string songName);
    string generateReccSong(map<string, vector<int>>& nameMap, string name, Login::Node* popTree, Login::Node* hiphopTree, Login::Node* rnbTree, Login::Node* countryTree);
    string BFSResults(Login::Node* songTree, float danceability, float energy);
    string DFSResults(Login::Node* songTree, float danceability, float energy);
    string recSong;

private:
    sf::Sprite sprite;
};
