#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
SongDatabase::SongDatabase() {
    this->songs.push_back("Penny Lane");
    this->songsInfo["Penny Lane"] = {"https://youtu.be/S-rB0pHI9fU", 8};

    this->songs.push_back("Trololo");
    this->songsInfo["Trololo"] = {"https://youtu.be/oavMtUWDBTM", 10};

    this->songs.push_back("Ob-La-Di, Ob-La-Da");
    this->songsInfo["Ob-La-Di, Ob-La-Da"] = {"https://youtu.be/_J9NpHKrKMw", 2};

    this->songs.push_back("Don't Worry, Be Happy");
    this->songsInfo["Don't Worry, Be Happy"] = {"https://youtu.be/d-diB65scQU", 3};

    this->songs.push_back("Leave My Kitten Alone");
    this->songsInfo["Leave My Kitten Alone"] = {"https://youtu.be/7BKsy9-Bvok", 5};
}

// Task 3(a).  Implement this method
void SongDatabase::display() {
    for (size_t i = 0; i < songs.size(); i++) {
        Info info = songsInfo[songs[i]];
        cout << "title=" << songs[i] << "; url=" << info.url << "; score=" << info.score << endl;
    }
}

// Task 3(b).  Implement this method
bool SongDatabase::addSong(string title, string url, unsigned int score) {
    if (songsInfo.find(title) != songsInfo.end()) {
        return false;
    } else if (score > 10 || score < 0) {
        return false;
    } else {
        songs.push_back(title);
        songsInfo[title] = {url, score};
        return true;
    }
}

// Task 3(a).  Implement this method
void SongDatabase::searchSongs(string howGood) {
    if (howGood == "abysmal") {
        for (size_t i = 0; i < songs.size(); i++) {
            Info info = songsInfo[songs[i]];
            if (0 <= info.score && info.score < 3)
                cout << "title=" << songs[i] << "; url=" << info.url << "; score=" << info.score << endl;
        }
    } else if (howGood == "lousy") {
        for (size_t i = 0; i < songs.size(); i++) {
            Info info = songsInfo[songs[i]];
            if (3 <= info.score && info.score < 5)
                cout << "title=" << songs[i] << "; url=" << info.url << "; score=" << info.score << endl;
        }
    } else if (howGood == "meh") {
        for (size_t i = 0; i < songs.size(); i++) {
            Info info = songsInfo[songs[i]];
            if (5 <= info.score && info.score < 7)
                cout << "title=" << songs[i] << "; url=" << info.url << "; score=" << info.score << endl;
        }
    }else if (howGood == "cool") {
        for (size_t i = 0; i < songs.size(); i++) {
            Info info = songsInfo[songs[i]];
            if (7 <= info.score && info.score < 9)
                cout << "title=" << songs[i] << "; url=" << info.url << "; score=" << info.score << endl;
        }
    } else if (howGood == "OMG") {
        for (size_t i = 0; i < songs.size(); i++) {
            Info info = songsInfo[songs[i]];
            if (info.score >= 9)
                cout << "title=" << songs[i] << "; url=" << info.url << "; score=" << info.score << endl;
        }
    }
}
