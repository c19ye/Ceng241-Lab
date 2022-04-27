#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    int numbers[10];
    string direction;
} NUMBERLIST;
void ptr_func(NUMBERLIST *);
void ref_func(NUMBERLIST &);
void ptr_func(NUMBERLIST *number)
{
    cout << "Enter 10 integers and order of summation: ";
    for (size_t i = 0; i < 10; i++)
    {
        cin >> number->numbers[i];
    }
    cin >> number->direction;
    cout << "Result: ";
    if (number->direction == "left-to-right")
    {
        int x = 0;
        cout << number->numbers[0];
        for (size_t i = 1; i < 10; i++)
        {
            x = number->numbers[i - 1] + number->numbers[i];
            number->numbers[i] = x;
            cout << " " << number->numbers[i];
        }
    }
    else if (number->direction == "right-to-left")
    {
        int x = 0;
        for (size_t i = 9; i > 0; i--)
        {
            x = number->numbers[i] + number->numbers[i - 1];
            number->numbers[i - 1] = x;
        }
        for (size_t i = 0; i < 10; i++)
        {
            cout << " " << number->numbers[i];
        }
    }
    else
    {
        cout << "Wrong!!!";
        exit(1);
    }
    cout << "\n\n";
}
void ref_func(NUMBERLIST &number)
{
    cout << "Enter 10 integers and order of summation: ";
    for (size_t i = 0; i < 10; i++)
    {
        cin >> number.numbers[i];
    }
    cin >> number.direction;
    cout << "Result: ";
    if (number.direction == "left-to-right")
    {
        int x = 0;
        cout << number.numbers[0];
        for (size_t i = 1; i < 10; i++)
        {
            x = number.numbers[i - 1] + number.numbers[i];
            number.numbers[i] = x;
            cout << " " << number.numbers[i];
        }
    }
    else if (number.direction == "right-to-left")
    {
        int x = 0;
        for (size_t i = 9; i > 0; i--)
        {
            x = number.numbers[i] + number.numbers[i - 1];
            number.numbers[i - 1] = x;
        }
        for (size_t i = 0; i < 10; i++)
        {
            cout << " " << number.numbers[i];
        }
    }
    else
    {
        cout << "Wrong!!!";
        exit(1);
    }
}
int main(int argc, char const *argv[])
{
    NUMBERLIST *numberptr = new NUMBERLIST;
    NUMBERLIST number;
    ptr_func(numberptr);
    ref_func(number);

    delete numberptr;

    int das;
    cin >> das;
    return 0;
}
