// this way works only with functions with same return type and parameters

#include <iostream>

using namespace std;

void first(int num1, int num2)
{
    cout << "First function called with " << num1 << " and " << num2 << endl;
}

void second(int num1, int num2)
{
    cout << "Second function called with " << num1 << " and " << num2 << endl;
}

void third(int num1, int num2)
{
    cout << "Third function called with " << num1 << " and " << num2 << endl;
}

int main()
{
    // create a list to store functions
    void (*funcs[])(int, int) = {first, second, third};
    funcs[1](0, 5); // call second function with 0 and 5
    funcs[0](3, 1); // call first function with 3 and 1
    funcs[2](7, 2); // call third function with 7 and 5

    return 0;
}
