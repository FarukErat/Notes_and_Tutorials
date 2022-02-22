#include <iostream>
#include <cmath>

using namespace std;

class octopus
{
    public:

    virtual double module() = 0; // = 0 implies function is not defined.
                                 //This makes instances of this class cannot be declared.
};

double biggest_module (octopus &a, octopus &b, octopus &c)
{
    double r = a.module();

    if (b.module() > r) r = b.module();
    if (c.module() > r) r = c.module();

    return r;
}

class vector: public octopus
{
    public:

    double x;
    double y;

    vector (double a = 0, double b = 0)
    {
        x = a;
        y = b;
    }
    
    double module()
    {
        return sqrt (x * x + y * y);
    }
};

class number: public octopus
{
    public:

    double n;

    number (double a = 0)
    {
        n = a;
    }

    double module()
    {
        if (n >= 0) return n;
        else return -n;
    }
};

int main ()
{
    vector k (1,2), m (6,7), n (100, 0);
    number p (5), q (-3), r (-150);

    cout << biggest_module (k, m, n) << endl;
    cout << biggest_module (p, q, r) << endl;
    cout << biggest_module (p, q, n) << endl;

    return 0;
}