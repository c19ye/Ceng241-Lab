#include <iostream>
#include <string>

using namespace std;

class calculator
{
    friend ostream &operator<<(ostream &os, const calculator &obj);

private:
    float *numbers;
    int length;

public:
    calculator();
    calculator(int);
    calculator operator+(const calculator &obj);
    calculator operator-(const calculator &obj);
    calculator operator*(const calculator &obj);
    calculator operator/(const calculator &obj);
    calculator &operator=(const calculator &obj);
    float *GetNumbers() const
    {
        return numbers;
    }
    void SetNumbers(float *num)
    {
        for (size_t i = 0; i < length; i++)
        {
            numbers[i] = num[i];
        }
    }
    int GetLength() const
    {
        return length;
    }
    void SetLength(int s)
    {
        length = s;
    }
    ~calculator();
};

calculator::calculator()
{

    numbers = nullptr;
}

calculator::calculator(int s)
{
    length = s;
    numbers = new float[length];
    for (size_t i = 0; i < length; i++)
    {
        numbers[i] = 0;
    }
}

calculator calculator::operator-(const calculator &obj)
{
    float *buff = obj.GetNumbers();
    float *buff2;
    int bigger = length;
    if (obj.GetLength() >= length)
    {
        bigger = obj.GetLength();
    }

    buff2 = new float[bigger];
    for (size_t i = 0; i < bigger; i++)
    {
        buff2[i] = numbers[i] - buff[i];
    }
    calculator temp{bigger};
    temp.SetNumbers(buff2);
    delete[] buff2;
    return temp;
}

calculator calculator::operator/(const calculator &obj)
{
    float *buff = obj.GetNumbers();
    float *buff2;
    int bigger = length;
    if (obj.GetLength() >= length)
    {
        bigger = obj.GetLength();
    }

    buff2 = new float[bigger];
    for (size_t i = 0; i < bigger; i++)
    {
        buff2[i] = numbers[i] / buff[i];
    }
    calculator temp{bigger};
    temp.SetNumbers(buff2);
    delete[] buff2;
    return temp;
}

calculator calculator::operator*(const calculator &obj)
{
    float *buff = obj.GetNumbers();
    float *buff2;
    int bigger = length;
    if (obj.GetLength() >= length)
    {
        bigger = obj.GetLength();
    }

    buff2 = new float[bigger];
    for (size_t i = 0; i < bigger; i++)
    {
        buff2[i] = numbers[i] * buff[i];
    }
    calculator temp{bigger};
    temp.SetNumbers(buff2);
    delete[] buff2;
    return temp;
}

calculator calculator::operator+(const calculator &obj)
{
    float *buff = obj.GetNumbers();
    float *buff2;
    int bigger = length;
    if (obj.GetLength() >= length)
    {
        bigger = obj.GetLength();
    }

    buff2 = new float[bigger];
    for (size_t i = 0; i < bigger; i++)
    {
        buff2[i] = numbers[i] + buff[i];
    }
    calculator temp{bigger};
    temp.SetNumbers(buff2);
    delete[] buff2;
    return temp;
}

calculator &calculator::operator=(const calculator &obj)
{
    if (this == &obj)
        return *this;
    delete[] numbers;
    numbers = new float[obj.GetLength()];
    for (size_t i = 0; i < obj.GetLength(); i++)
    {
        numbers[i] = obj.numbers[i];
    }
    length = obj.GetLength();
    return *this;
}

ostream &operator<<(ostream &os, const calculator &obj)
{
    float *buff = obj.GetNumbers();
    for (size_t i = 0; i < obj.GetLength(); i++)
    {
        os << buff[i] << " ";
    }
    return os;
}

calculator::~calculator()
{

    delete[] numbers;
}

int main(int argc, char const *argv[])
{
    char coperator;
    int size, size2;
    float *array, *array2;

    cout << "Length of the first number set: ";
    cin >> size;
    array = new float[size];
    for (size_t i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cout << "First set entered: ";
    for (size_t i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\nLength of the second number set: ";
    cin >> size2;
    array2 = new float[size2];
    for (size_t i = 0; i < size2; i++)
    {
        cin >> array2[i];
    }
    cout << "Second set entered: ";
    for (size_t i = 0; i < size2; i++)
    {
        cout << array2[i] << " ";
    }

    int bigger = size;
    if (size2 >= size)
    {
        bigger = size2;
    }

    calculator c1{bigger};
    calculator c2{bigger};

    //if sizes are not same, other numbers will be set zero by way of this code
    if (size != size2)
    {
        c1.SetLength(size);
        c2.SetLength(size2);
    }

    c1.SetNumbers(array);
    c2.SetNumbers(array2);
    delete[] array;
    delete[] array2;

    calculator c3;

    while (1)
    {
        cout << "\nChoose operation: ";
        cin >> coperator;

        switch (coperator)
        {
        case '+':
            c3 = c1 + c2;
            cout << c3;
            break;
        case '-':
            c3 = c1 - c2;
            cout << c3;
            break;
        case '*':
            c3 = c1 * c2;
            cout << c3;
            break;
        case '/':
            c3 = c1 / c2;
            cout << c3;
            break;
        default:
            exit(1);
            break;
        }
    }

    return 0;
}
