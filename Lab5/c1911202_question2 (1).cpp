#include <iostream>

using namespace std;
class Student
{
private:
    int id;
    string name;
    int year;
    float gpa;
    float exam;
    float total;

public:
    Student()
    {
        id = 0;
        name = "Empty";
        year = 0;
        gpa = 0.00;
        exam = 0;
    }

    int getId()
    {
        return id;
    }

    void setId(int id)
    {
        this->id = id;
    }

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    int getYear()
    {
        return year;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    float getGpa()
    {
        return gpa;
    }

    void setGpa(float gpa)
    {
        this->gpa = gpa;
    }

    float getExam()
    {
        return exam;
    }

    void setExam(float exam)
    {
        this->exam = exam;
    }

    float getTotal()
    {
        return total;
    }

    void setTotal(float total)
    {
        this->total = total;
    }
};
int main(int argc, char const *argv[])
{
    int id;
    string name;
    int year;
    float gpa;
    int exam;
    Student *s = new Student[4];
    for (size_t i = 0; i < 4; i++)
    {
        cout << "Enter information for student(id name year gpa exam(must be in range 0-5)): ";
        cin >> id >> name >> year >> gpa >> exam;
        s[i].setId(id);
        s[i].setName(name);
        s[i].setYear(year);
        s[i].setGpa(gpa);
        s[i].setExam(exam);
        s[i].setTotal((exam * gpa) / 2);
    }
    cout << "Results-> ";
    string highname = "";
    float highpoint = 0;
    for (size_t i = 0; i < 4; i++)
    {
        cout << s[i].getName() << ":" << s[i].getTotal() << ", ";
        if (highpoint < s[i].getTotal())
        {
            highname = s[i].getName();
            highpoint = s[i].getTotal();
        }
    }
    cout << "\n"
         << highname << " has just employeed";

    delete[] s;

    return 0;
}
