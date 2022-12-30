/*
Since C++11, you can use placement new to construct an object in a pre-allocated memory location.
This allows you to use the memory of an existing object to construct a new object.
However, you must be careful when using placement new, because it can lead to memory leaks.
It was meant to be used to locate where an object is to be constructed, not to create a new object.
*/

#include <iostream>

using namespace std;

class MyClass
{
public:
    int data = 0;
};

int main()
{
    MyClass mc;
    mc.data = 5;
    cout << mc.data << " : " << &mc << endl; // 5 : 0x61ff08
    MyClass *temp = new (&mc) MyClass();
    cout << mc.data << " : " << &mc << endl; // 0 : 0x61ff08

    return 0;
}
