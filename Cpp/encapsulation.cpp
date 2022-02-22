#include <iostream>

using namespace std;

class vector
{
    //private: // the variables or the methods below can be accessed and used everywhere in the program
    protected: // accessible only to methods of the class AND to methods of derived classes

    double x;
    double y;

    public: // ONLY to methods of the class

    void set_x (int n)
    {
        x = n;
    }

    void set_y (int n)
    {
        y = n;
    }

    double get_x ()
    {
        return x;
    }

    double get_y ()
    {
        return y;
    }

    double surface ()
    {
        double s;
        s = x * y;
        if (s < 0) s = -s;
        return s;
    }
};

int main ()
{
    vector a;

    a.set_x (3);
    a.set_y (4);

    cout << "The surface of a: " << a.surface() << endl;
    cout << "The width of a: " << a.get_x() << endl;
    cout << "The height of a: " << a.get_y() << endl;

    return 0;
}