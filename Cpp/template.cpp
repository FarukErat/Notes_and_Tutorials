using namespace std;
#include <iostream>

template <class ttype>
ttype minimum (ttype a, ttype b)
{
    ttype r;
    r = a;
    if (b < a) r = b;
    return r;
}

int main ()
{
    int i1, i2, i3;
    i1 = 34;
    i2 = 6;
    i3 = minimum (i1, i2);

    cout << "Most little: " << i3 << endl;

    double d1, d2, d3;
    d1 = 7.9;
    d2 = 32.1;
    d3 = minimum (d1, d2);

    cout << "Most little: " << d3 << endl;
    cout << "Most little: " << minimum (d3, 3.5) << endl;
    
    return 0;
}