#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
#pragma once

class Quiz{
public:
    bool makeQuizWindow(string name, map<string, vector<int>> nameMap);
private:
    sf::Sprite sprite;
    //map<string, vector<int>> inputNameData(map<string, vector<int>> nameMap);;
};
//push