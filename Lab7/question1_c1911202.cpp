#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;
    string writer;
    float price;

public:
    Book(/* args */);
    Book(string, string, float);
    Book(const Book &);
    string getTitle();
    void setTitle(string);
    string getWriter();
    void setWriter(string);
    float getPrice();
    void setPrice(float);
    ~Book();
};

Book::Book(/* args */)
{
}

Book::Book(string title, string writer, float price)
{
    this->title = title;
    this->writer = writer;
    this->price = price;
}

Book::Book(const Book &obj)
{

    this->title = obj.title;
    this->writer = obj.writer;
    this->price = obj.price;
}
string Book::getTitle()
{
    return title;
}
void Book::setTitle(string title)
{
    this->title = title;
}
string Book::getWriter()
{
    return writer;
}
void Book::setWriter(string writer)
{
    this->writer = writer;
}
float Book::getPrice()
{
    return price;
}
void Book::setPrice(float price)
{
    this->price = price;
}

Book::~Book()
{
}

int main(int argc, char const *argv[])
{
    Book b[2];
    Book bcopy;
    string title, writer;
    float price;
    int choice;
    for (size_t i = 0; i < 2; i++)
    {
        cout << "Enter Title: ";
        getline(cin >> ws, title);
        b[i].setTitle(title);
        cout << "Enter Writer: ";
        getline(cin >> ws, writer);
        b[i].setWriter(writer);
        cout << "Enter Price: ";
        cin >> price;
        b[i].setPrice(price);
    }
    cout << "The book you wanna copy 1 or 2:";
    cin >> choice;
    if (choice == 1)
    {
        bcopy = b[0];
    }
    else if (choice == 2)
    {
        bcopy = b[1];
    }

    for (size_t i = 0; i < 2; i++)
    {
        cout << "book " << i + 1 << ":" << endl;
        cout << b[i].getTitle() << " " << b[i].getWriter() << " " << b[i].getPrice() << endl;
    }

    cout << "copy book: " << endl
         << bcopy.getTitle() << " " << bcopy.getWriter() << " " << bcopy.getPrice();

    return 0;
}
