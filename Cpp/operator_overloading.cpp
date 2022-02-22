#include <iostream>

class Deneme
{
    // data is private
    // only accessable through the methods of the class
private:
    int data;

public:
    Deneme(int data = 0); // constructor with default value
    // an alternative way to construct an object
    // Deneme()
    // {
    //     data = 0;
    // }
    // Deneme(int data)
    // {
    //     this->data = data;
    // }
    int getData();              // an accessor method
    void setData(int data);     // a mutator method
    Deneme operator+(Deneme d); // operator overloading
};

Deneme::Deneme(int data)
{
    this->data = data;
}

int Deneme::getData()
{
    return data;
}

void Deneme::setData(int data)
{
    this->data = data;
}

Deneme Deneme::operator+(Deneme d)
{
    Deneme temp;
    temp.data = this->data + d.data;
    return temp;
}

int main()
{
    Deneme a;     // instantiate an object withoout any value
    Deneme b(50); // instantiate an object with a value

    a.setData(10); // set the value of a

    Deneme c = a + b;
    // object b is passed to the operator overloading method of a
    // then, a returns the result of the operator overloading method
    // and the result is assigned to c
    std::cout << c.getData() << std::endl; // print the value of c
    // output: 60

    return 0;
}
