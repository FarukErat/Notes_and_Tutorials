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
    
    double module()
    {
        return sqrt (x*x + y*y);
    }
    
    double surface()
    {
        return x * y;
    }
};

class trivector: public vector // trivector is derived from vector
{
    public:

    double z; // added to x and y from vector
    trivector (double m=0, double n=0, double p=0): vector (m, n)
    {
        z = p; // vector constructor will be called before trivector constructor, with parameters m and n
    }

    trivector (vector a) // What to do if a vector is cast to a trivector
    {
        x = a.x;
        y = a.y;
        z = 0;
    }
    
    double module () // define module() for trivector
    {
        return sqrt (x*x + y*y + z*z);
    }
    
    double volume ()
    {
        return this->surface() * z; // or x * y * z
    }
};

int main ()
{
    vector a (4, 5);
    trivector b (1, 2, 3);

    cout << "a (4, 5) b (1, 2, 3) *r = b" << endl << endl;
    cout << "Surface of a: " << a.surface() << endl;
    cout << "Volume of b: " << b.volume() << endl;
    cout << "Surface of base of b: " << b.surface() << endl;
    cout << "Module of a: " << a.module() << endl;
    cout << "Module of b: " << b.module() << endl;
    cout << "Module of base of b: " << b.vector::module() << endl;

    trivector k;
    k = a; // thanks to trivector(vector) definition copy of x and y, k.z = 0
    vector j;
    j = b; // copy of x and y. b.z leaved out
    vector *r;
    r = &b;
    cout << "Surface of r: " << r->surface() << endl;
    cout << "Module of r: " << r->module() << endl;
    
    return 0;
}