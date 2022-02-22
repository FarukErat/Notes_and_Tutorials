using namespace std;
#include <iostream>

double test (double a, double b = 7) {
    return a - b;
}

int main ()
{
    cout << test (14, 5) << endl; // Displays 14 - 5
    cout << test (14) << endl; // Displays 14 - 7
    return 0;
}