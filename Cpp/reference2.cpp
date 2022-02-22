//A reference can be used to let a function return a variable

using namespace std;
#include <iostream>

double &biggest (double &r, double &s)
{
    if (r > s) return r;
    else return s;
}
int main ()
{
    double k = 3;
    double m = 7;

    cout << "k: " << k << endl; // Displays 3
    cout << "m: " << m << endl; // Displays 7
    cout << endl;

    biggest (k, m) = 10;
    cout << "k: " << k << endl; // Displays 3
    cout << "m: " << m << endl; // Displays 10
    cout << endl;

    biggest (k, m) ++;
    cout << "k: " << k << endl; // Displays 3
    cout << "m: " << m << endl; // Displays 11
    cout << endl;

    return 0;
}