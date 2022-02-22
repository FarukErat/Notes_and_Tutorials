using namespace std;
#include <iostream>

class vector
{
    public:

    double x;
    double y;
    static int count;

    vector (double a = 0, double b = 0)
    {
        x = a;
        y = b;
        count++;
    }
    
    ~vector()
    {
        count--;
    }
};

int vector::count = 0;

int main ()
{
    cout << "Number of vectors:" << endl;

    vector a;
    cout << vector::count << endl;

    vector b;
    cout << vector::count << endl;

    vector *r, *u;
    r = new vector;
    cout << vector::count << endl;

    u = new vector;
    cout << a.count << endl;

    delete r;
    cout << vector::count << endl;

    delete u;
    cout << b.count << endl;
    
    return 0;
}