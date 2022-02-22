using namespace std;
#include <iostream>

double a = 128;

int main ()
{
    double a = 256;
    cout << "Local a: " << a << endl;
    cout << "Global a: " << ::a << endl;
    return 0;
}