#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{

    cout << "Enter any string first: ";
    string str;
    getline(cin >> ws, str);
    cout << "Enter Substring you want to search: ";
    string str2;
    getline(cin >> ws, str2);
    size_t position = str.find(str2);
    if (position != string::npos)
        cout << "\nThe substring[ " << str2 << " ] is present in given string at position[ " << position << " ]";
    else
        cout << "Sorry, " << str2 << " not found" << endl;

    return 0;
}
