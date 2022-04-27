#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct
{
    string coursecode;
    double grade;
} course;

int main(int argc, char const *argv[])
{
    course t;
    vector<course> cs;
    char yn = 'y';
    double lessoncount = 0;
    double cgpa = 0;
    while (yn == 'y')
    {
        cout << "Enter course code and grade: ";
        cin >> t.coursecode;
        cin >> t.grade;
        cs.push_back(t);
        lessoncount++;
        cout << "Add new course? ";
        cin >> yn;
    }
    cout << "\nList of entered " << lessoncount << " courses:" << endl;
    for (int i = 0; i < lessoncount; i++)
    {
        cout << "- " << cs.at(i).coursecode << ", Grade: " << cs.at(i).grade << endl;
        cgpa += cs.at(i).grade;
    }
    cout << "CGPA: " << cgpa / lessoncount;

    int x;
    cin >> x;
    return 0;
}
