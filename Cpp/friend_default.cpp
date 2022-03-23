#include <iostream>

using namespace std;

class MyClass
{
private:
    int data;
public:
    MyClass(int d) : data(d) {}
/*
    MyClass(int d)
    {
        data = d;
    }
*/
    MyClass() : data(321) {cout << "Default constructor called " << data << endl;}
/*
    MyClass()
    {
        data = 321; // assignment is done first
        cout << "Default constructor called " << data << endl;
    }
*/
    friend void display(MyClass obj);
};

void display(MyClass obj)
{
    cout << "Data: " << obj.data << endl;
}

int main()
{
    MyClass m(123);
    display(m);
    MyClass n;
    display(n);

    return 0;
}
