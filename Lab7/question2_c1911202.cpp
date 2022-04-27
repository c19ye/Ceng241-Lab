#include <iostream>
#include <string>
using namespace std;

class SpecialDay
{
private:
    int year;
    int month;
    int day;
    string title;
    bool repetitive;

public:
    SpecialDay(/* args */);
    SpecialDay(string, int, int, int);
    SpecialDay(const SpecialDay &);
    int GetYear() const
    {
        return year;
    }

    void SetYear(int year)
    {
        this->year = year;
    }

    int GetMonth() const
    {
        return month;
    }

    void SetMonth(int month)
    {
        this->month = month;
    }

    int GetDay() const
    {
        return day;
    }

    void SetDay(int day)
    {
        this->day = day;
    }

    string GetTitle() const
    {
        return title;
    }

    void SetTitle(string title)
    {
        this->title = title;
    }

    bool GetRepetitive() const
    {
        return repetitive;
    }

    void SetRepetitive(bool repetitive)
    {
        this->repetitive = repetitive;
    }

    ~SpecialDay();
};

SpecialDay::SpecialDay(/* args */)
{
    title = " ";
    day = 0;
    month = 0;
    year = 0;
}
SpecialDay::SpecialDay(string title, int day, int month, int year)
{
    this->title = title;
    this->day = day;
    this->month = month;
    this->year = year;
}
SpecialDay::SpecialDay(const SpecialDay &obj)
{
    this->title = obj.title;
    this->day = obj.day;
    this->month = obj.month;
    this->year = obj.year + 1;
}

SpecialDay::~SpecialDay()
{
}

int main(int argc, char const *argv[])
{
    cout << "Enter number if days to record: ";
    int number, day, month, year, count = 0;
    string title, repetitive;
    cin >> number;
    SpecialDay *special = new SpecialDay[number];
    for (size_t i = 0; i < number; i++)
    {
        cout << "Enter title, day, month and year respectively: ";
        getline(cin >> ws, title);
        cin >> day >> month >> year;
        special[i].SetTitle(title);
        special[i].SetDay(day);
        special[i].SetMonth(month);
        special[i].SetYear(year);
        cout << "Is the day repetitive?" << endl;
        cin >> repetitive;
        if (repetitive == "yes")
        {
            special[i].SetRepetitive(true);
            count++;
        }
        else if (repetitive == "no")
        {
            special[i].SetRepetitive(false);
        }
        else
        {
            cout << "Wrong!";
        }
    }
    cout << "Your Special Occasions:" << endl;
    for (size_t i = 0; i < number; i++)
    {
        cout << special[i].GetTitle() << " " << special[i].GetDay() << "/" << special[i].GetMonth() << "/" << special[i].GetYear() << endl;
    }
    cout << "\nRepetitive Occasions:" << endl;

    for (size_t i = 0; i < number; i++)
    {
        if (special[i].GetRepetitive() == true)
        {
            SpecialDay s1 = special[i];
            cout << s1.GetTitle() << " " << s1.GetDay() << "/" << s1.GetMonth() << "/" << s1.GetYear() << endl;
        }
    }

    return 0;
}
