using namespace std;
#include <iostream>

template <class type1, class type2>
type1 minimum (type1 a, type2 b)
{
    type1 r, b_converted;
    r = a;
    b_converted = (type1) b;
    if (b_converted < a) r = b_converted;
    return r;
}

int main ()
{
    int i;
    double d;
    i = 45;
    d = 7.41;
    cout << "Most little: " << minimum (i, d) << endl;
    cout << "Most little: " << minimum (d, i) << endl;
    cout << "Most little: " << minimum ('A', i) << endl;
    return 0;
}