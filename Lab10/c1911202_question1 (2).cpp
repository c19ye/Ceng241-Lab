#include <iostream>

using namespace std;

class DistanceUnit
{
private:
    /* data */
protected:
    float value;

public:
    DistanceUnit(/* args */)
    {
        value = 0;
    }

    float getValue()
    {
        return value;
    }

    void operator++(int)
    {
        value++;
    }
    void operator--(int)
    {
        value--;
    }
    void operator+=(int x)
    {
        value = value + x;
    }
    void operator-=(int x)
    {
        value = value - x;
    }

    ~DistanceUnit() {}
};
class Foot : public DistanceUnit
{
private:
    /* data */
public:
    Foot(/* args */) {}
    float toMeters()
    {
        return value / 3.2808;
    }
    ~Foot() {}
};
class Meter : public DistanceUnit
{
private:
    /* data */
public:
    Meter(/* args */) {}
    float toFeet()
    {
        return value * 3.2808;
    }
    ~Meter() {}
};

int main(int argc, char const *argv[])
{
    int choice, n;
    cout << "1.Set distance to feet\n2.Set distance to meters\nChoice: ";
    cin >> choice;
    Meter m;
    Foot f;
    switch (choice)
    {
    case 1:
        while (1)
        {
            cout << "\n\nDistance:" << f.getValue() << " feet\n1.Move 1 foot forwards\n2.Move 1 foot backwards\n3.Move N foot forwards\n4.Move N foot backwards\n5.Convert to meters\n6.Exit\nYour choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                f++;
                break;
            case 2:
                f--;
                break;
            case 3:
                cout << "Enter N: ";
                cin >> n;
                f += n;
                break;
            case 4:
                cout << "Enter N: ";
                cin >> n;
                f -= n;
                break;
            case 5:
                cout << f.getValue() << " feet: " << f.toMeters() << " meters";
                break;
            case 6:
                cout << "Bye" << endl;
                exit(1);
                break;

            default:
                cout << "Wrong!";
                exit(1);
                break;
            }
        }

        break;
    case 2:
        while (1)
        {
            cout << "\n\nDistance:" << m.getValue() << " meter\n1.Move 1 meter forwards\n2.Move 1 meter backwards\n3.Move N meter forwards\n4.Move N meter backwards\n5.Convert to feet\n6.Exit\nYour choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                m++;
                break;
            case 2:
                m--;
                break;
            case 3:
                cout << "Enter N: ";
                cin >> n;
                m += n;
                break;
            case 4:
                cout << "Enter N: ";
                cin >> n;
                m -= n;
                break;
            case 5:
                cout << m.getValue() << " meters: " << m.toFeet() << " feet";
                break;
            case 6:
                cout << "Bye" << endl;
                exit(1);
                break;

            default:
                cout << "Wrong!";
                exit(1);
                break;
            }
        }
        break;
    default:
        cout << "Wrong!";
        exit(1);
        break;
    }

    return 0;
}
