//
// Created by Camryn Whisenant on 6/14/21.
//
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

#include "Song.h"
#include "Playlist.h"

using namespace std;

Playlist::Playlist() {
    playlistName = "none";
}

Playlist::Playlist(string currPlaylistName) {
    playlistName = currPlaylistName;
}

string Playlist::ListPlaylists() const {
    return playlistName;
}


void Playlist::PlayPlaylist() {
    int i;
    for (i = 0; i < playlistSongs.size(); ++i) {
        cout << playlistSongs.at(i)->GetFirstLine() << endl;
        playlistSongs.at(i)->IncrementPlayCount();
    }
}

void Playlist::AddSongToPlaylist(vector<Song*> songlist) {
    int addSongIndex;
    int i;
    for (i = 0; i < songlist.size(); ++i) {
        cout << i << ": " << songlist.at(i)->GetName() << endl;
    }
    cout << "Pick a song index number: " << endl;
    cin >> addSongIndex;
    cin.ignore();

    playlistSongs.push_back(songlist.at(addSongIndex));
}

void Playlist::RemoveSongP() {
    int i;
    int songToRemoveP;
    for (i = 0; i < playlistSongs.size(); ++i) {
        cout << i << ": " << playlistSongs.at(i)->GetName();
    }
    cout << "Pick a song index number to remove: ";
    cin >> songToRemoveP;
    cin.ignore();
    playlistSongs.erase(playlistSongs.begin() + songToRemoveP);
}

void Playlist::RemoveSong(string removeSongName) {
    int i;
    for (i = 0; i < playlistSongs.size(); ++i) {
        if (playlistSongs.at(i)->GetName() == removeSongName) {
            playlistSongs.erase(playlistSongs.begin() + i);
        }

    }

}

string Playlist::GetName() {
    return playlistName;
}