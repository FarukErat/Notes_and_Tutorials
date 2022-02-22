//References can be used to allow a function to modify a calling variable

using namespace std;
#include <iostream>

void change (double &r, double s);

int main ()
{
    double k, m;
    k = 3;
    m = 4;
    change (k, m);
    cout << k << ", " << m << endl; // Displays 100, 4.
    return 0;
}

void change (double &r, double s)
{
    r = 100;
    s = 200;
}