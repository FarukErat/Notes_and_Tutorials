// taken from: https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm

#include <iostream>
using namespace std;

double division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by zero condition!";
    }
    return (a / b);
}

int main()
{
    int x = 50;
    int y = 0;
    double z = 0;

    // if any throw occurs in try block
    try
    {
        z = division(x, y);
        cout << z << endl;
    }
    // catch block will get the thrown exception as a parameter
    catch (const char *msg)
    {
        cerr << msg << endl;
    }

    return 0;
}
