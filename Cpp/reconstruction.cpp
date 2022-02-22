/*
 * the aim is recalling a constructor of the same object
 * it does not occupy any different memory space
 * it occupies the same memory location
 * it is useful when we want to reconstruct the same object
 */
#include <iostream>

using namespace std;

class MyClass
{
public:
    int check1;
    // not only does reconstruction apply to constructors,
    // but also to the variables initialized by default
    // so check2 will be initialized to 0
    int check2 = 0;
    int a[5][5];
    MyClass(int);
    ~MyClass();
};

void printArr(int[5][5]);

MyClass::MyClass(int num)
{
    cout << "Constructor called" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = num;
        }
    }
}

MyClass::~MyClass()
{
    cout << "Destructor called" << endl;
}

int main()
{
    int num = 5;
    MyClass obj(num);
    obj.check1 = 10;
    obj.check2 = 20;
    cout << "print the initialized array" << endl;
    printArr(obj.a);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            obj.a[i][j] = 1;
        }
    }
    cout << "print the modified array" << endl;
    printArr(obj.a);
    // creating a pointer to the object with parameters
    // but on the same memory location
    // so that it will apply to the same object
    // it will not create a new object
    MyClass *ptr = new (&obj) MyClass(num);
    cout << "print the reconstructed array" << endl;
    printArr(obj.a);
    cout << obj.check1 << " " << obj.check2 << endl;

    return 0;
}

void printArr(int arr[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
