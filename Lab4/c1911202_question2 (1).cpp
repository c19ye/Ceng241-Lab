#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    cout << "How many numbers letters are you going to enter? ";
    int numberofletter;
    cin >> numberofletter;
    int *repeatednumber = new int[numberofletter];
    char *repeatedletter = new char[numberofletter];
    int all = 0;
    for (int i = 0; i < numberofletter; i++)
    {
        cout << "Enter letter and how many times it will be repeated: ";
        cin >> repeatedletter[i];
        cin >> repeatednumber[i];
        all += repeatednumber[i];
    }
    for (int i = 0; i < numberofletter; i++)
    {
        for (int j = 0; j < repeatednumber[i]; j++)
        {
            cout << repeatedletter[i];
        }
    }
    delete[] repeatedletter;
    delete[] repeatednumber;
    int x;
    cin >> x;
    return 0;
}
