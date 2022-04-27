#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Application
{
protected:
    string name;
    string type;

public:
    string GetName() const
    {
        return name;
    }

    void SetName(string _name)
    {
        name = _name;
    }

    string GetType() const
    {
        return type;
    }

    void SetType(string _type)
    {
        type = _type;
    }
    Application(/* args */) {}
    Application(string _name, string _type) : name(_name), type(_type) {}
    void print() {}
    ~Application() {}
};

class DesktopAplication : public Application
{
private:
    int size;

public:
    int GetSize() const
    {
        return size;
    }

    void SetSize(int _size)
    {
        size = _size;
    }
    DesktopAplication(/* args */) {}
    DesktopAplication(string _name, string _type, int _size) : size(_size)
    {
        name = _name;
        type = _type;
    }
    void print()
    {
        cout << "- " << GetName() << ", " << GetType() << " (" << GetSize() << " MB)" << endl;
    }
    ~DesktopAplication() {}
};

class WebApplication : public Application
{
private:
    string address;

public:
    string GetAddress() const
    {
        return address;
    }

    void SetAddress(string _address)
    {
        address = _address;
    }
    WebApplication(/* args */) {}
    WebApplication(string _name, string _type, string _address) : address(_address)
    {
        name = _name;
        type = _type;
    }
    void print()
    {
        cout << "- " << GetName() << ", " << GetType() << ", Address: " << GetAddress() << endl;
    }
    ~WebApplication() {}
};
int main(int argc, char const *argv[])
{
    vector<DesktopAplication> d;
    vector<WebApplication> w;

    string title, type, webaddress;
    int choice, size = 0;

    while (1)
    {

        if (d.empty())
        {
            cout << "\n1. New desktop application" << endl;
        }
        else
        {
            cout << "\n1. Desktop application" << endl;
        }
        if (w.empty())
        {
            cout << "2. New web application" << endl;
        }
        else
        {
            cout << "2. Web application" << endl;
        }
        cout << "3. Exit" << endl;
        cout << "Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Application title: ";
            getline(cin >> ws, title);
            cout << "Application type: ";
            getline(cin >> ws, type);
            cout << "Application size: ";
            cin >> size;
            d.push_back(DesktopAplication(title, type, size));
            break;
        case 2:
            cout << "Application title: ";
            getline(cin >> ws, title);
            cout << "Application type: ";
            getline(cin >> ws, type);
            cout << "Web address: ";
            cin >> webaddress;
            w.push_back(WebApplication(title, type, webaddress));
            break;
        case 3:
            cout << "Desktop Applications: " << endl;
            if (d.empty())
            {
                cout << "(None)" << endl;
            }
            else
            {
                for (auto &i : d)
                {
                    i.print();
                }
            }

            cout << "Web Applications: " << endl;
            if (w.empty())
            {
                cout << "(None)" << endl;
            }
            else
            {
                for (auto &i : w)
                {
                    i.print();
                }
            }
            cout << "Bye!";
            exit(1);
            break;
        default:
            cout << "Wrong!\nBye!";
            exit(1);
            break;
        }
    }

    return 0;
}
