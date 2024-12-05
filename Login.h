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
public:
    //struct of songs and its attriubutes
    struct SongData{
        string SongName;
        string ArtistName;
        double Danceability;
        double Energy;
        string Genre;

        SongData(string songName, string artistName, double danceability, double energy, string genre){
            this->SongName = songName;
            this->ArtistName = artistName;
            this->Danceability = danceability;
            this-> Energy = energy;
            this->Genre = genre;
        }

        SongData(){
            this->SongName = "";
            this->ArtistName = "";
            this->Danceability = 0;
            this-> Energy = 0;
            this->Genre = "";
        }

    public:
        SongData& operator=(const SongData& other) {
            if (this != &other) {
                SongName = other.SongName;
                ArtistName = other.ArtistName;
                Danceability = other.Danceability;
                Energy = other.Energy;
                Genre = other.Genre;
            }
            return *this;
        }
    };

    // struct of nodes to mode throughout tree
    struct Node{
        SongData song;
        Node* left;
        Node* right;


        Node(const SongData& songs){
            this->song = songs;
            this->left = nullptr;
            this->right = nullptr;
        }
    };
    bool makeLoginWindow();
    //function that parse file and makes the graph
    void parseFile();
    Node* insert(Node* node, const SongData& song);
    Node* makeTree(vector<SongData*> songVect);
    string name;
    Node* popTree;
    Node* countryTree;
    Node* rnbTree;
    Node* hiphopTree;

private:
    sf::Sprite sprite;
    map<string, vector<int>> nameData;
    vector<SongData*> popSongs;
    vector<SongData*> countrySongs;
    vector<SongData*> rnbSongs;
    vector<SongData*> hiphopSongs;
};
