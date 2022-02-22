using namespace std;

#include <iostream>
#include <cmath>

class vector
{
    public:

    double x;
    double y;

    vector (double a = 0, double b = 0)
    {
        x = a;
        y = b;
    }

    double surface()
    {
        return fabs (x * y);
    }
};

class number
{
    public:

    double z;

    number (double a)
    {
        z = a;
    }

    int is_negative ()
    {
        if (z < 0) return 1;
        else return 0;
    }
};
class trivector: public vector, public number
{
    public:

    trivector(double a=0, double b=0, double c=0): vector(a,b), number(c)
    {
    }
    // The trivector constructor calls the vector constructor, then the number constructor,
    //and in this example does nothing more.

    double volume()
    {
        return fabs (x * y * z);
    }
};
int main ()
{
    trivector a(2, 3, -4);

    cout << a.volume() << endl;
    cout << a.surface() << endl;
    cout << a.is_negative() << endl;

    return 0;
}