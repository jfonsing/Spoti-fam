


#define SPOTI_FAM_LOGIN_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>
using namespace std;
#pragma once

class Login{

private:
    sf::Sprite sprite;
    map<string, vector<int>> nameData;
    //struct of songs and its attriubutes
    struct SongData{
    public:
        string SongName;
        string ArtistName;
        double Danceability;
        double Energy;
        string Genre;

        SongData(const std::string& songName, const std::string& artistName, double danceability, double energy, const std::string& genre)
                : SongName(songName), ArtistName(artistName), Danceability(danceability), Energy(energy), Genre(genre) {}


    };

public:
    bool makeLoginWindow();
//function that parse file and makes the graph
    vector<SongData> parseFile();
    map<SongData, vector<SongData>> makeGraph(vector<SongData> songs);
    string name;
};
