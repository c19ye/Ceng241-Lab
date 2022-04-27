#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    fstream newfile;
    string filename;
    string line;
    cout << "Enter file name: ";
    cin >> filename;
    cout << "Enter information to store: " << endl;
    string yesno = "y";
    while (yesno == "y")
    {
        newfile.open(filename.c_str(), ios::app);
        getline(cin >> ws, line);
        if (newfile.is_open())
        {
            newfile << line << endl;
            newfile.close();
        }
        cout << "Want to enter more ? <y/n>: ";
        cin >> yesno;
    }
    cout << "\nThe information successfully stored in the file..!!\n"
         << endl;
    cout << "Want to see ? <y/n>: ";
    cin >> yesno;
    if (yesno == "y")
    {
        newfile.open(filename.c_str());
        if (newfile.is_open())
        {
            string line2;
            cout << endl;
            while (getline(newfile, line2))
            {
                cout << line2 << "\n";
            }
            newfile.close();
        }
    }
    else
    {
        exit(1);
    }
    return 0;
}
