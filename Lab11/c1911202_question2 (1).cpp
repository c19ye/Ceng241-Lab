#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class VideoGames
{
private:
    string name;
    int price;

public:
    VideoGames(/* args */) {}
    VideoGames(string name, int price)
    {
        this->name = name;
        this->price = price;
    }
    static int totalPrice(vector<VideoGames> v)
    {
        int total = 0;
        for (auto &i : v)
        {
            total += i.GetPrice();
        }

        return total;
    }
    static void displayList(vector<VideoGames> v)
    {
        int x = 1;
        for (auto &i : v)
        {
            cout << x << " - " << i.GetName() << " "
                 << "(" << i.GetPrice() << " TL)" << endl;
            x++;
        }
    }
    string GetName() const
    {
        return name;
    }

    void SetName(string name)
    {
        this->name = name;
    }

    int GetPrice() const
    {
        return price;
    }

    void SetPrice(int price)
    {
        this->price = price;
    }
    ~VideoGames() {}
};

int main(int argc, char const *argv[])
{
    ifstream newfile;
    fstream errorfile;

    vector<VideoGames> vec;
    VideoGames objv;

    while (1)
    {
        string filename;
        cout << "\nEnter file name: ";
        getline(cin >> ws, filename);
        try
        {
            newfile.open(filename.c_str(), ios::in);
            if (newfile.is_open() != true)
            {
                throw 1;
            }
            while (1)
            {
                cout << "\nEnter your budget: ";
                int budget;
                cin >> budget;
                try
                {
                    if (budget < 0)
                    {
                        throw 1;
                    }
                    cout << "\nAvailable games are: " << endl;
                    string gamename;
                    int price;
                    while (!newfile.eof())
                    {
                        newfile >> gamename;
                        newfile >> price;
                        objv = VideoGames(gamename, price);
                        vec.push_back(objv);
                    }
                    objv.displayList(vec);
                    while (1)
                    {
                        vector<VideoGames> vectwo;
                        int selectgame = -1;
                        int index;
                        cout << "\nWhich games do you want to buy? (0 to stop): ";
                        while (selectgame != 0)
                        {
                            cin >> selectgame;
                            index = selectgame - 1;
                            if (selectgame == 0)
                            {
                                break;
                            }
                            vectwo.push_back(vec.at(selectgame - 1));
                        }
                        try
                        {
                            if (budget < objv.totalPrice(vectwo))
                            {
                                throw 1;
                            }
                            cout << "Your have bought:" << endl;
                            for (auto &i : vectwo)
                            {
                                cout << "- " << i.GetName() << endl;
                            }
                            cout << "Enjoy your games!";
                            exit(1);
                        }
                        catch (int &e)
                        {
                            errorfile.open("errors.txt", ios::app);
                            if (errorfile.is_open())
                            {
                                errorfile << "Budget is not enough!" << endl;
                                cerr << "Budget is not enough!" << endl;
                                errorfile.close();
                            }
                        }
                    }
                }
                catch (int &e)
                {

                    errorfile.open("errors.txt", ios::app);
                    if (errorfile.is_open())
                    {
                        errorfile << "Budget can not be negative!" << endl;
                        cerr << "Budget can not be negative!" << endl;
                        errorfile.close();
                    }
                }
            }

            // while (getline(newfile, line2))
            // {
            //     cout << line2 << "\n";
            // }
            newfile.close();
        }
        catch (int &e)
        {
            errorfile.open("errors.txt", ios::out);
            if (errorfile.is_open())
            {
                errorfile << "File does not exist" << endl;
                cerr << "File does not exist" << endl;
                errorfile.close();
            }
        }
    }

    return 0;
}
