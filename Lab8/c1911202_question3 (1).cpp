#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
class D
{
private:
    /* data */
public:
    int *numbers = new int[10];
    D(/* args */)
    {

        for (size_t i = 0; i < 10; i++)
        {
            numbers[i] = rand() % 100;
        }
    }
    ~D()
    {
        delete[] numbers;
    }
};
class A
{
private:
    /* data */
protected:
    D d;
    int count;

public:
    A(/* args */)
    {

        count = 0;
    }
    void print()
    {
        for (size_t i = 0; i < 10; i++)
        {
            cout << d.numbers[i] << " ";
        }
    }
    ~A()
    {
    }
};
class B : public A
{
private:
    /* data */
public:
    B(/* args */)
    {
        cout << "B array: ";
    }
    int evens()
    {
        cout << endl
             << "B evens: ";
        for (size_t i = 0; i < 10; i++)
        {
            if (d.numbers[i] % 2 == 0)
            {
                count++;
            }
        }

        return count;
    }
    ~B() {}
};
class C : public A
{
private:
    /* data */
public:
    int odds()
    {
        cout << endl
             << "C odds: ";
        for (size_t i = 0; i < 10; i++)
        {
            if (d.numbers[i] % 2 != 0)
            {
                count++;
            }
        }

        return count;
    }
    C(/* args */)
    {
        cout << "\nC array: ";
    }
    ~C() {}
};

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    B b;
    b.print();
    cout << b.evens() << endl;

    C c;
    c.print();
    cout << c.odds() << endl;

    return 0;
}
