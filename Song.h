//
// Created by Camryn Whisenant on 6/14/21.
//
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;


#ifndef MAINLAB8_2_SONG_H
#define MAINLAB8_2_SONG_H


class Song {
public:
    Song();

    Song(string currSong, string currFirstLine);

    void ListSong() const;

    string GetFirstLine();

    void IncrementPlayCount();

    string GetName();

private:
    string name;
    string firstL;
    int playCount = 0;
};


#endif //MAINLAB8_2_SONG_H
