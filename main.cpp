#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Song.h"
#include "Playlist.h"


// TODO: clean up memory when it is no longer used
//  (you need to find the appropriate places in the code to do this)

std::string GetUserString(const std::string& prompt);

void AddSongsMenuOption(vector<Song*>& songlist);
void ListSongsMenuOption(vector<Song*> songlist);
void AddPlaylistMenuOption(vector<Playlist*>& playlists);
void AddSongToPlaylistMenuOption(vector<Playlist*>& playlists, vector<Song*> songlist);
void ListPlaylistsMenuOption(vector<Playlist*> playlists);
void PlayPlaylistMenuOption(vector<Playlist*>& playlists);
void RemovePlaylistMenuOption(vector<Playlist*>& playlists);
void RemoveSongFromPlaylistMenuOption(vector<Playlist*>& playlists);
void RemoveSongFromLibraryMenuOption(vector<Playlist*>& playlists,vector<Song*>& songlist);
void OptionsMenuOption();
void QuitMenuOption();

int main() {
    std::cout << "Welcome to the Firstline Player!  Enter options to see menu options." << std::endl << std::endl;

    vector<Song *> songlist;
    vector<Playlist *> playlists;

    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {
            AddSongsMenuOption(songlist);
        } else if (userMenuChoice == "list") {
            ListSongsMenuOption(songlist);
        } else if (userMenuChoice == "addp") {
            AddPlaylistMenuOption(playlists);
        } else if (userMenuChoice == "addsp") {
            AddSongToPlaylistMenuOption(playlists, songlist);
        } else if (userMenuChoice == "listp") {
            ListPlaylistsMenuOption(playlists);
        } else if (userMenuChoice == "play") {
            PlayPlaylistMenuOption(playlists);
        } else if (userMenuChoice == "remp") {
            RemovePlaylistMenuOption(playlists);
        } else if (userMenuChoice == "remsp") {
            RemoveSongFromPlaylistMenuOption(playlists);
        } else if (userMenuChoice == "remsl") {
            RemoveSongFromLibraryMenuOption(playlists, songlist);
        } else if (userMenuChoice == "options") {
            OptionsMenuOption();
        } else if (userMenuChoice == "quit") {
            QuitMenuOption();
            continueMenuLoop = false;
        } else {
            OptionsMenuOption();
        }
    }

    return 0;
}


std::string GetUserString(const std::string& prompt) {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}
int GetUserInt(const std::string& prompt) {
    int userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}

void AddSongsMenuOption(vector<Song*>& songlist) {
    const std::string DONE_KEYWORD = "DONE";
    std::cout << "Enter songs' names and first lines"
              << " (type \"" << DONE_KEYWORD << "\" when done):" << std::endl;

    std::string songName = "none";
    std::string firstLine = "none";

    songName = GetUserString("Song Name: ");
    while (songName != DONE_KEYWORD) {
        firstLine = GetUserString("Song's first line: ");

        Song *currSong = new Song(songName, firstLine);
        songlist.push_back(currSong);

        songName = GetUserString("Song Name: ");
    }
}

void ListSongsMenuOption(vector<Song*> songlist) {
    int i;
    for (i = 0; i < songlist.size(); ++i) {
        songlist.at(i)->ListSong();
    }
}

void AddPlaylistMenuOption(vector<Playlist*>& playlists) {
    string currPlaylistName;
    cout << "Playlist name: " << endl;
    getline(cin, currPlaylistName);

    Playlist *currPlaylist = new Playlist(currPlaylistName);
    playlists.push_back(currPlaylist);
}

void AddSongToPlaylistMenuOption(vector<Playlist*>& playlists, vector<Song*> songlist) {
    int addPlaylistIndex;
    int i;
    for (i = 0; i < playlists.size(); ++i) {
        cout << i << ": " << playlists.at(i)->ListPlaylists();
    }
    cout << "Pick a playlist index number: " << endl;
    cin >> addPlaylistIndex;
    cin.ignore();
    playlists.at(addPlaylistIndex)->AddSongToPlaylist(songlist);
}

void ListPlaylistsMenuOption(vector<Playlist*> playlists) {
    int i;
    for (i = 0; i < playlists.size(); ++i) {
        cout << i << ": " << playlists.at(i)->ListPlaylists() << endl;
    }
}

void PlayPlaylistMenuOption(vector<Playlist*>& playlists) {
    int playlistIndex;
    ListPlaylistsMenuOption(playlists);
    cout << "Pick a playlist index number: ";
    cin >> playlistIndex;
    cin.ignore();
    cout << endl << "Playing songs from playlist: " << playlists.at(playlistIndex)->GetName() << endl;
    playlists.at(playlistIndex)->PlayPlaylist();
}

void RemovePlaylistMenuOption(vector<Playlist*>& playlists) {
    int removePlaylistIndex;
    int i;
    for (i = 0; i < playlists.size(); ++i) {
        cout << i << ": " << playlists.at(i)->ListPlaylists() << endl;
    }
    cout << "Pick a playlist index number to remove: ";
    cin >> removePlaylistIndex;
    cin.ignore();
    delete playlists.at(removePlaylistIndex); //delete and free memory
    playlists.erase(playlists.begin() + removePlaylistIndex);
}


void RemoveSongFromPlaylistMenuOption(vector<Playlist*>& playlists) {
    int playlistIndex;
    int i;
    for (i = 0; i < playlists.size(); ++i) {
        cout << i << ": " << playlists.at(i)->ListPlaylists() << endl;
    }
    cout << "Pick a playlist index number: " << endl;
    cin >> playlistIndex;
    cin.ignore();
    playlists.at(playlistIndex)->RemoveSongP();
}


void RemoveSongFromLibraryMenuOption(vector<Playlist*>& playlists,vector<Song*>& songlist) {
    int removeSongIndex;
    int i;
    string removeSongName;
    for (i = 0; i < songlist.size(); ++i) {
        cout << i << ": " << songlist.at(i)->GetName();
    }
    cout << "Pick a song index number to remove: " << endl;
    cin >> removeSongIndex;
    cin.ignore();
    removeSongName = songlist.at(removeSongIndex)->GetName();

    for (i = 0; i < playlists.size(); ++i) {
        playlists.at(i)->RemoveSong(removeSongName);
    }
    delete songlist.at(removeSongIndex); //delete and free memory
    songlist.erase(songlist.begin() + removeSongIndex);
}

void OptionsMenuOption() {
    std::cout << "add      Adds a list of songs to the library" << std::endl
              << "list     Lists all the songs in the library" << std::endl
              << "addp     Adds a new playlist" << std::endl
              << "addsp    Adds a song to a playlist" << std::endl
              << "listp    Lists all the playlists" << std::endl
              << "play     Plays a playlist" << std::endl
              << "remp     Removes a playlist" << std::endl
              << "remsp    Removes a song from a playlist" << std::endl
              << "remsl    Removes a song from the library (and all playlists)" << std::endl
              << "options  Prints this options menu" << std::endl
              << "quit     Quits the program" << std::endl << std::endl;
}

void QuitMenuOption() {
    std::cout << "Goodbye!" << std::endl;
}

