

#ifndef SPOTI_FAM_LOGIN_H
#define SPOTI_FAM_LOGIN_H

#endif //SPOTI_FAM_LOGIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
#pragma once

class Login{
public:
    bool makeLoginWindow();
    string name;
private:
    sf::Sprite sprite;
    map<string, vector<int>> nameData;
};
//push