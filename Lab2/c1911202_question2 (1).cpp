#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int arr[10];
    cout << "Enter bar heights: ";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[j] != 0)
            {
                cout << " #";
                arr[j]--;
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}
