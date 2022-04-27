#include <iostream>
using namespace std;
typedef struct
{
    char classroom;
    int number;
    int learned;
} Classs;
int main(int argc, char const *argv[])
{
    Classs classs[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Information for " << i + 1 << ". class: " << endl;
        cout << "Letter: ";
        cin >> classs[i].classroom;
        cout << "Total number of students: ";
        cin >> classs[i].number;
        cout << "Number of students who have learned to read: ";
        cin >> classs[i].learned;
        cout << endl;
    }
    cout << "Percentage of students who have learned top read: " << endl;
    int y = 0;
    for (int i = 0; i < 5; i++)
    {
        int x = (100 * classs[i].learned) / classs[i].number;
        cout << "\nClassroom 1-" << classs[i].classroom << ": " << x << "%";
        y += x;
    }
    cout << "\nSchool total: " << y / 5 << "%";
    return 0;
}
