
/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 7*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef _SDDS_SONGCOLLECTION_H_
#define _SDDS_SONGCOLLECTION_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <list>
#include <algorithm> 
#include<numeric>

using namespace std;

namespace sdds {
    struct Song {
        string artist, title, album;
        double m_price =0 ;
        int year = 0, length= 0 ;
    };
    class SongCollection {
        vector<sdds::Song> m_song;
    public:
        string& trim(string& );
        SongCollection(string);
        void display(ostream&) const;
        void sort(string);
        void cleanAlbum();
        bool inCollection(string) const;
        list<Song> getSongsForArtist(string) const;
    };
    ostream& operator<<(ostream&, const Song&);
}

#endif