#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    char letter[26];
    int x = 1;
    cout << "Enter your letters: ";
    for (int i = 0; i < 26; i++)
    {
        cin >> letter[i];
    }
    cout << "Result: ";
    for (int i = 0; i < 26; i++)
    {
        if (letter[i] == letter[i + 1])
        {
            x++;
        }
        else
        {
            cout << x << " ";
            x = 1;
        }
    }

    return 0;
}
//hhheeeelloooooowwooorllddd