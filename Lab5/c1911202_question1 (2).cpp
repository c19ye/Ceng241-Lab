#include <iostream>
#include <string>
using namespace std;

class Game
{
private:
    string Type;
    string name;
    double price;
    bool buy;

public:
    Game(/* args */)
    {
    }
    ~Game()
    {
    }

    string getType()
    {
        return Type;
    }

    void setType(string Type)
    {
        this->Type = Type;
    }

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    double getPrice()
    {
        return price;
    }

    void setPrice(double price)
    {
        this->price = price;
    }

    bool isBuy()
    {
        return buy;
    }

    void setBuy(bool buy)
    {
        this->buy = buy;
    }
};

int main(int argc, char const *argv[])
{
    cout << "Please Enter Amount of Game: ";
    int arrsize;
    cin >> arrsize;
    Game *g = new Game[arrsize];

    string type;
    string name;
    double price;
    for (size_t i = 0; i < arrsize; i++)
    {
        cout << "Enter Game Type, Name and Price: ";
        cin >> type;
        cin >> name;
        cin >> price;
        g[i].setType(type);
        g[i].setName(name);
        g[i].setPrice(price);
    }
    for (size_t i = 0; i < arrsize; i++)
    {
        double discounted;
        if (g[i].getType() == "Action")
        {
            discounted = g[i].getPrice() - ((g[i].getPrice() * 10) / 100);
        }
        else if (g[i].getType() == "Strategy")
        {
            discounted = g[i].getPrice() - ((g[i].getPrice() * 20) / 100);
        }
        else if (g[i].getType() == "Sport")
        {
            discounted = g[i].getPrice() - ((g[i].getPrice() * 30) / 100);
        }
        else
        {
            discounted = g[i].getPrice() - ((g[i].getPrice() * 25) / 100);
        }
        cout << "Game " << i + 1 << endl
             << "Name: " << g[i].getName() << endl
             << "Type: " << g[i].getType() << endl
             << "Price: " << g[i].getPrice() << " Discounted Price: " << discounted << endl;

        if (discounted <= 150)
        {
            g[i].setBuy(true);
        }
        else
        {
            g[i].setBuy(false);
        }

        cout << g[i].isBuy() << endl;
    }

    delete[] g;

    return 0;
}