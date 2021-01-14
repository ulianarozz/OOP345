
/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 7*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include"SongCollection.h"
namespace sdds {
    string& SongCollection::trim(std::string& str) {
        while (str.length() > 0 && str[0] == ' ') {
            str.erase(0, 1);
        }
        while (str.length() > 0 && str[str.length() - 1] == ' ') {
            str.erase(str.length() - 1, 1);
        }
        return str;
    }
    SongCollection::SongCollection(string fname) {
        fstream file(fname);
        if (!file) {
            throw "Error with the file";
        }
        while (file) {
            string str;
            getline(file, str);
            Song song;
            if (file) {

                trim(song.title = str.substr(0, 25));
                trim(song.artist = str.substr(25, 25));
                trim(song.album = str.substr(50, 25));

                try {
                    song.year = std::stoi(str.substr(75, 5));
                }
                catch (...) {
                    song.year = 0;
                }

                song.length = std::stoi(str.substr(80, 5));
                song.m_price = std::stod(str.substr(85, 5));

                m_song.push_back(song);

            }
        }
        file.close();
    }
    void SongCollection::cleanAlbum() {
       
        for_each(m_song.begin(), m_song.end(), [](Song& song) {
            if (song.album == "[None]") {
                song.album = " ";
            }

            });

    }
    bool SongCollection::inCollection(std::string artist_) const {
        bool found = false;
        for (auto& i : m_song) {
            if (artist_ == i.artist) {
                found = true;
            }
        }
        return found;
    }

    std::list<Song> SongCollection::getSongsForArtist(std::string artist_) const {
        auto count = std::count_if(m_song.begin(), m_song.end(), [&artist_](const Song& song) {
            return song.artist == artist_;
            });

        std::list <Song> theSongs(count);
        std::copy_if(m_song.begin(), m_song.end(), theSongs.begin(), [&artist_](const Song& song) {
            return song.artist == artist_;
            });
        return theSongs;
    }

    std::ostream& operator<<(std::ostream& os, const Song& song) {
        os << "| " << std::left << std::setw(20) << song.title << " | " << std::left << std::setw(15)
            << song.artist << " | " << std::left << std::setw(20) << song.album << " | " << std::right << std::setw(6);

        if (song.year == 0) {
            os << " ";
        }
        else {
            os << song.year;
        }

        os << " | " << song.length / 60 << ":" << std::setw(2) << std::setfill('0') << song.length % 60 
            << " | " << std::fixed << std::setprecision(2) << song.m_price << " |" << std::setfill(' ');

        return os;
    }
    void SongCollection::display(ostream& os) const {
        std::for_each(m_song.begin(), m_song.end(), [&](const Song& song) {
            os << song << std::endl;
            });
        os << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
   
        auto totalTime = std::accumulate(m_song.begin(), m_song.end(), 0u, [](const size_t& res, const Song item) {
            return res + item.length;
            });

        std::string str = "Total Listening Time: ";
        str += std::to_string(totalTime / 3600);
        str += ":";
        str += std::to_string((totalTime %= 3600) / 60);
        str += ":";
        str += std::to_string(totalTime % 60);
        os << "| " << std::setw(84) << str << " |" << std::endl;
    }
    void SongCollection::sort(std::string field) {
        if (field == "title") {
            std::sort(m_song.begin(), m_song.end(), [](const Song& a, const Song& b) {
                return a.title < b.title;
                });
        }
        else if (field == "album") {
            std::sort(m_song.begin(), m_song.end(), [](const Song& a, const Song& b) {
                return a.album < b.album;
                });
        }
        else if (field == "length") {
            std::sort(m_song.begin(), m_song.end(), [](const Song& a, const Song& b) {
                return a.length < b.length;
                });
        }
    }

}
