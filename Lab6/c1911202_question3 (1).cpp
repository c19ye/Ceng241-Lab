#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Collatz
{
private:
    int start;
    int limit;
    vector<int> numbers;

public:
    Collatz(/* args */);
    Collatz(int, int);
    int getStart();
    void setStart(int);
    int getLimit();
    void setLimit(int);
    void generate();
    void print();
    ~Collatz();
};

Collatz::Collatz()
{
    limit = 10;
}
Collatz::Collatz(int start, int limit)
{
    this->start = start;
    this->limit = limit;
}
int Collatz::getStart()
{
    return start;
}
void Collatz::setStart(int start)
{
    this->start = start;
}
int Collatz::getLimit()
{
    return limit;
}
void Collatz::setLimit(int limit)
{
    this->limit = limit;
}
void Collatz::generate()
{
    numbers.push_back(start);
    while (numbers.back() != 1 && numbers.size() != limit)
    {
        if (numbers.back() % 2 == 0)
        {
            numbers.push_back(numbers.back() / 2);
        }
        else
        {
            numbers.push_back(numbers.back() * 3 + 1);
        }
    }
}
void Collatz::print()
{
    for (auto &i : numbers)
    {
        cout << i << " -> ";
    }
    cout << "end" << endl
         << endl;
}

Collatz::~Collatz()
{
}

int main(int argc, char const *argv[])
{
    cout << "1. Default (start: random, limit: 10)" << endl
         << "2. Custom" << endl;
    int choice, start, limit;
    Collatz *c = new Collatz[5];
    srand(time(NULL));
    for (size_t i = 0; i < 5; i++)
    {
        cout << "Your choice: ";
        cin >> choice;
        if (choice == 1)
        {

            int rndm = (rand() % 41) + 10;
            c[i].setStart(rndm);
            c[i].generate();
        }
        else if (choice == 2)
        {
            cout << "Enter start number and limit: ";
            cin >> start >> limit;
            c[i] = Collatz(start, limit);
            c[i].generate();
        }
    }

    for (size_t i = 0; i < 5; i++)
    {
        c[i].print();
    }

    delete[] c;

    return 0;
}
