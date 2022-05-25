#include <iostream>
using namespace std;

int add(int x, int y)
{
    return x + y;
}

int multiply(int x, int y)
{
    return x * y;
}

// Function that takes a pointer to a function
int invoke(int x, int y, int (&func)(int, int))
{
    return func(x, y);
}

int main()
{
    // Pass pointers to add & multiply function as required
    cout << "Addition of 20 and 10 is ";
    cout << invoke(20, 10, add) << endl;

    cout << "Multiplication of 20 and 10 is ";
    cout << invoke(20, 10, multiply) << endl;

    return 0;
}
