#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Song
{
private:
    string title;
    int min;
    int sec;

public:
    Song(/* args */) {}
    Song(string _title) : title(_title) {}
    Song(string _title, int _min, int _sec) : title(_title), min(_min), sec(_sec) {}
    string GetTitle() const
    {
        return title;
    }

    void SetTitle(string _title)
    {
        title = _title;
    }

    int GetMin() const
    {
        return min;
    }

    void SetMin(int _min)
    {
        min = _min;
    }

    int GetSec() const
    {
        return sec;
    }

    void SetSec(int _sec)
    {
        sec = _sec;
    }
    Song(const Song &source)
    {
        title = source.GetTitle();
        min = source.GetMin();
        sec = source.GetSec();
    }
    Song(Song &&source)
    {
    }
    ~Song() {}
};

class Playlist
{
private:
    int totalsec;
    vector<Song> songs;

public:
    Playlist(/* args */) { totalsec = 0; }
    void add(Song &&source) { songs.push_back(source); }
    void search(string _title)
    {
        size_t position;
        for (auto &i : songs)
        {
            position = i.GetTitle().find(_title);
            if (position != string::npos)
            {
                cout << "- " << i.GetTitle() << " "
                     << "(" << i.GetMin() << ":" << setw(2) << setfill('0') << i.GetSec() << ")" << endl;
            }
        }
    }
    void print()
    {
        int totalmin = 0;
        cout << "Your playlist: " << endl;

        for (auto &i : songs)
        {
            cout << "- " << i.GetTitle() << " "
                 << "(" << i.GetMin() << ":" << setw(2) << setfill('0') << i.GetSec() << ")" << endl;
            totalsec += ((i.GetMin() * 60) + i.GetSec());
        }

        cout << "Total duration: " << totalsec / 60 << ":" << setw(2) << setfill('0') << totalsec % 60 << endl;
    }
    ~Playlist() {}
};

int main(int argc, char const *argv[])
{
    Song *s = new Song;
    Playlist *p = new Playlist;
    int choice, min, sec;
    string title;
    bool out = true;

    while (out)
    {
        cout << "\n1. Add\n2. Display\n3. Search\n4.Exit\n";
        cout << "Your Choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Enter song title: ";
            getline(cin >> ws, title);
            cout << "Enter song duration: ";
            cin >> min >> sec;
            p->add(Song(title, min, sec));
            break;
        case 2:
            p->print();
            break;
        case 3:
            cout << "Enter part of song title to search: ";
            getline(cin >> ws, title);
            p->search(title);
            break;
        case 4:
            cout << "Bye!";
            exit(1);
            break;

        default:
            cout << "Wrong!!\nBye!" << endl;
            out = false;
            break;
        }
    }

    return 0;
}
