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


#ifndef MAINLAB8_2_PLAYLIST_H
#define MAINLAB8_2_PLAYLIST_H


class Playlist {
public:
    Playlist();

    Playlist(string currPlaylistName);

    string ListPlaylists() const;

    void AddSongToPlaylist(vector<Song *> songlist);

    void RemoveSongP();

    void PlayPlaylist();

    void RemoveSong(string removeSongName);

    string GetName();

private:
    vector<Song *> playlistSongs;
    string playlistName;
};


#endif //MAINLAB8_2_PLAYLIST_H
