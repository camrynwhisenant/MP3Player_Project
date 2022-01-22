//
// Created by Camryn Whisenant on 6/14/21.
//
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;


#include "Song.h"

Song::Song() {
    name = "none";
    firstL = "none";
    int playCount = 0;
}

Song::Song(string songName, string firstLine) {
    name = songName;
    firstL = firstLine;
    int playCount = 0;
}

void Song::ListSong() const {
    cout << name << ": \"" << firstL << "\", " << playCount << " play(s)." << endl;
}

string Song::GetFirstLine() {
    return firstL;
}

void Song::IncrementPlayCount() {
    playCount = playCount + 1;
}

string Song::GetName() {
    return name;
}