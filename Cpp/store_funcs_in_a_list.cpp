#include <iostream>

using namespace std;

void first(void)
{
    cout << "first" << endl;
}

void second(void)
{
    cout << "second" << endl;
}

void third(void)
{
    cout << "third" << endl;
}

int main()
{
    // create a list to store functions
    void (*funcs[])(void) = {first, second, third};
    funcs[1](); // second
    funcs[0](); // first
    funcs[2](); // third

    return 0;
}
