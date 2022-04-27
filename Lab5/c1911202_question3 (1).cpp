#include <iostream>

using namespace std;

class Rectangles
{
private:
    int length, breadth;
    static int total_area, total_perimeter;

public:
    int getLength();
    void setLength(int);
    int getBreadth();
    void setBreadth(int);
    static int getTotal_area();
    static void setTotal_area(int);
    static int getTotal_perimeter();
    static void setTotal_perimeter(int);
    void userInput();
    Rectangles(/* args */);
    int calculateArea(int, int);
    ~Rectangles();
};
int Rectangles::total_area = 0;
int Rectangles::total_perimeter = 0;
Rectangles::Rectangles(/* args */)
{
    cout << "default constructor" << endl;
}
void Rectangles::userInput()
{
    cout << "Enter length and breadth respectively: ";
    int a, b;
    cin >> a >> b;
    setLength(a);
    setBreadth(b);
}
int Rectangles::getLength()
{
    return length;
}
void Rectangles::setLength(int length)
{
    this->length = length;
}

int Rectangles::getBreadth()
{
    return breadth;
}
void Rectangles::setBreadth(int breadth)
{
    this->breadth = breadth;
}
int Rectangles::getTotal_area()
{
    return total_area;
}
void Rectangles::setTotal_area(int _total_area)
{
    total_area = _total_area;
}
int Rectangles::getTotal_perimeter()
{
    return total_perimeter;
}
void Rectangles::setTotal_perimeter(int _total_perimeter)
{
    total_perimeter = _total_perimeter;
}

Rectangles::~Rectangles()
{
    cout << "destructor is executed for the object\n";
}

int main(int argc, char const *argv[])
{
    Rectangles *r = new Rectangles[3];
    for (size_t i = 0; i < 3; i++)
    {
        r[i].userInput();
    }
    for (size_t i = 0; i < 3; i++)
    {
        cout << "Area: " << r[i].getLength() * r[i].getBreadth() << endl;
        r[i].setTotal_area(r[i].getTotal_area() + (r[i].getLength() * r[i].getBreadth()));
        r[i].setTotal_perimeter(r[i].getTotal_perimeter() + (r[i].getLength() + r[i].getBreadth()));
    }
    cout << "Total Area: " << r[0].getTotal_area() << " Total Perimeter: " << r[0].getTotal_perimeter() << endl;
    delete[] r;
    return 0;
}
