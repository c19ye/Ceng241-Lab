#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class ChessPiece
{
private:
    string type;
    char xcoord;
    int ycoord;

public:
    ChessPiece();
    ChessPiece(string);
    ChessPiece(string, char, int);
    string RandomType();
    char RandomXcoord();
    int RandomYcoord();
    string getType();
    void setType(string);
    char getXcoord();
    void setXcoord(char);
    int getYcoord();
    void setYcoord(int);
    void print();
    ~ChessPiece();
};
string ChessPiece::RandomType()
{

    srand(time(NULL));
    int randomat = rand() % 6;
    vector<string> t{"pawn", "queen", "king", "bishop", "knight", "rook"};
    return t.at(randomat);
}
char ChessPiece::RandomXcoord()
{
    srand(time(NULL));
    int randomat = rand() % 8;
    vector<char> x{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    return x.at(randomat);
}
int ChessPiece::RandomYcoord()
{
    srand(time(NULL));
    int randomat = rand() % 8;
    vector<int> y{1, 2, 3, 4, 5, 6, 7, 8};
    return y.at(randomat);
}
ChessPiece::ChessPiece()
{
    this->type = RandomType();
    this->xcoord = RandomXcoord();
    this->ycoord = RandomYcoord();
}
ChessPiece::ChessPiece(string type)
{
    this->type = type;
    this->xcoord = RandomXcoord();
    this->ycoord = RandomYcoord();
}
ChessPiece::ChessPiece(string type, char xcoord, int ycoord)
{
    this->type = type;
    this->xcoord = xcoord;
    this->ycoord = ycoord;
}
string ChessPiece::getType()
{
    return type;
}
void ChessPiece::setType(string type)
{
    this->type = type;
}
char ChessPiece::getXcoord()
{
    return xcoord;
}
void ChessPiece::setXcoord(char xcoord)
{
    this->xcoord = xcoord;
}
int ChessPiece::getYcoord()
{
    return ycoord;
}
void ChessPiece::setYcoord(int ycoord)
{
    this->ycoord = ycoord;
}
void ChessPiece::print()
{
    cout << type << " is at " << xcoord << ycoord << endl;
}
ChessPiece::~ChessPiece()
{
}

int main(int argc, char const *argv[])
{
    ChessPiece *c1 = new ChessPiece();

    string type;
    char x;
    int y;
    cout << "Enter type for second piece: ";
    cin >> type;
    ChessPiece *c2 = new ChessPiece(type);
    cout << "Enter type and coordinates for third piece: ";
    cin >> type >> x >> y;
    ChessPiece *c3 = new ChessPiece(type, x, y);

    cout << "First piece: ";
    c1->print();
    cout << "Second piece: ";
    c2->print();
    cout << "Third piece: ";
    c3->print();

    delete c1;
    delete c2;
    delete c3;
    return 0;
}
