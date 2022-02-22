using namespace std;
#include <iostream>

double test (double a, double b)
{
    return a + b;
}

int test (int a, int b)
{
    return a - b;
}

int main ()
{
    double m = 7, n = 4;
    int k = 5, p = 3;

    cout << test(m, n) << " , " << test(k, p) << endl;
    
    return 0;
}