#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Login.h"
using namespace std;
#pragma once

class Quiz{
public:
    bool makeQuizWindow(string name, Login::Node* popTree, Login::Node* hiphopTree, Login::Node* rnbTree, Login::Node* countryTree);
    map<string, vector<int>> nameMap;
private:
    sf::Sprite sprite;
};
