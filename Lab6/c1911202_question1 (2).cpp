#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Song
{
private:
    string title;
    int min;
    int sec;

public:
    Song(/* args */);
    Song(string);
    Song(string, int, int);
    void setTitle(string);
    string getTitle();
    void setMin(int);
    int getMin();
    void setSec(int);
    int getSec();
    ~Song();
};

Song::Song(/* args */)
{
    setTitle("Empty");
    setMin(0);
    setSec(0);
}
Song::Song(string title)
{
    this->title = title;
    this->min = 0;
    this->sec = 0;
}
Song::Song(string title, int min, int sec)
{
    this->title = title;
    this->min = min;
    this->sec = sec;
}
string Song::getTitle()
{
    return title;
}

void Song::setTitle(string title)
{
    this->title = title;
}

void Song::setMin(int min)
{
    this->min = min;
}
int Song::getMin()
{
    return min;
}
void Song::setSec(int sec)
{
    this->sec = sec;
}
int Song::getSec()
{
    return sec;
}
Song::~Song()
{
}

int main(int argc, char const *argv[])
{
    string title;
    int min;
    int sec;
    Song s1;
    cout << "Enter title and duration of first song: ";
    getline(cin, title);
    cin >> min;
    cin >> sec;
    s1.setTitle(title);
    s1.setMin(min);
    s1.setSec(sec);
    Song *s2 = new Song(title);
    cout << "Enter title and duration of second song: ";
    getline(cin >> ws, title);
    cin >> min;
    cin >> sec;
    s2->setTitle(title);
    s2->setMin(min);
    s2->setSec(sec);
    Song *s3 = new Song(title, min, sec);
    cout << "Enter title and duration of third song: ";
    getline(cin >> ws, title);
    cin >> min >> sec;
    s3->setTitle(title);
    s3->setMin(min);
    s3->setSec(sec);

    cout << "\nYour playlist: " << endl;
    cout << "- " << s1.getTitle() << " (" << s1.getMin() << ":" << setw(2) << setfill('0') << s1.getSec() << ")\n";
    cout << "- " << s2->getTitle() << " (" << s2->getMin() << ":" << setw(2) << setfill('0') << s2->getSec() << ")\n";
    cout << "- " << s3->getTitle() << " (" << s3->getMin() << ":" << setw(2) << setfill('0') << s3->getSec() << ")\n";
    int totalmin = s1.getMin() + s2->getMin() + s3->getMin();
    int totalsec = s1.getSec() + s2->getSec() + s3->getSec();
    if (totalsec >= 60 && totalsec < 120)
    {
        totalmin++;
        totalsec -= 60;
    }
    else if (totalsec >= 120)
    {
        totalmin += 2;
        totalsec -= 120;
    }

    cout << "Total duration: " << totalmin << " minutes, " << setw(2) << setfill('0') << totalsec << " seconds.";

    delete s2;
    delete s3;
    return 0;
}
