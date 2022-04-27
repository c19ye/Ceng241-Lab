#include <iostream>
#include <time.h>
#include <cstdio>
using namespace std;

class NumberArray
{
private:
    virtual void generate()
    {
        for (size_t i = 0; i < amount; i++)
        {
            numbers[i] = rand() % 1000;
        }
    }
    void print()
    {
        cout << numbers[0];
        for (size_t i = 1; i < amount; i++)
        {
            cout << " -> ";
            cout << numbers[i];
        }
        cout << endl;
    }

protected:
    int *numbers;
    int amount;

public:
    NumberArray(/* args */) {}
    NumberArray(int x)
    {
        amount = x;
        numbers = new int[amount];
    }
    void generateAndPrint()
    {
        generate();
        print();
    }
    ~NumberArray() {}
};
class PrimeNUmberArray : public NumberArray
{
private:
    void generate() override
    {
        int count = 0;
        while (count != amount)
        {
            int flag = 0;
            int x = rand() % 1000;
            for (size_t i = 2; i < x; i++)
            {
                if (x % i == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                numbers[count] = x;
                count++;
            }
        }
    }

public:
    PrimeNUmberArray(/* args */) {}
    PrimeNUmberArray(int x)
    {
        amount = x;
        numbers = new int[x];
    }
    ~PrimeNUmberArray() {}
};
class EvenNumberArray : public NumberArray
{
private:
    void generate() override
    {
        int count = 0;
        while (count != amount)
        {
            int x = rand() % 1000;
            if (x % 2 == 0)
            {
                numbers[count] = x;
                count++;
            }
        }
    }

public:
    EvenNumberArray(/* args */) {}
    EvenNumberArray(int x)
    {
        amount = x;
        numbers = new int[x];
    }
    ~EvenNumberArray() {}
};
class OddNumberArray : public NumberArray
{
private:
    void generate() override
    {
        int count = 0;
        while (count != amount)
        {
            int x = rand() % 1000;
            if (x % 2 != 0)
            {
                numbers[count] = x;
                count++;
            }
        }
    }

public:
    OddNumberArray(/* args */) {}
    OddNumberArray(int x)
    {
        amount = x;
        numbers = new int[x];
    }
    ~OddNumberArray() {}
};

int main(int argc, char const *argv[])
{
    int x;
    srand(time(NULL));
    cout << "Enter length for normal number array: ";
    cin >> x;
    NumberArray *n = new NumberArray(x);

    cout << "Enter length for prime number array: ";
    cin >> x;
    NumberArray *p = new PrimeNUmberArray(x);

    cout << "Enter length for even number array: ";
    cin >> x;
    NumberArray *e = new EvenNumberArray(x);

    cout << "Enter length for odd number array: ";
    cin >> x;
    NumberArray *o = new OddNumberArray(x);

    cout << "Normal numbers: ";
    n->generateAndPrint();

    cout << "Prime numbers: ";
    p->generateAndPrint();

    cout << "Even numbers: ";
    e->generateAndPrint();

    cout << "Odd numbers: ";
    o->generateAndPrint();

    delete n;
    delete p;
    delete e;
    delete o;

    return 0;
}
