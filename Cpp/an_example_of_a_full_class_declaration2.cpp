using namespace std;

#include <iostream>
#include <cmath>

class vector
{
    public:

    double x;
    double y;

    vector (double = 0, double = 0);
    vector operator + (vector);
    vector operator - (vector);
    vector operator - ();
    vector operator * (double);
    double module();
    void set_length (double = 1);
};

vector::vector (double a, double b)
{
    x = a;
    y = b;
}

vector vector::operator + (vector a)
{
    return vector (x + a.x, y + a.y);
}

vector vector::operator - (vector a)
{
    return vector (x - a.x, y - a.y);
}

vector vector::operator - ()
{
    return vector (-x, -y);
}

vector vector::operator * (double a)
{
    return vector (a * x, a * y);
}

double vector::module()
{
    return sqrt (x * x + y * y);
}

void vector::set_length (double a)
{
    vector &the_vector = *this;
    double length = the_vector.module();
    x = x / length * a;
    y = y / length * a;
}

ostream& operator << (ostream& o, vector a)
{
    o << "(" << a.x << ", " << a.y << ")";
    return o;
}

int main ()
{
    vector c (3, 5);
    vector *r; // r is a pointer to a vector.
    r = new vector; // new allocates the memory necessary
    cout << *r << endl; // to hold a vectors' variable,
                        // calls the constructor who will
                        // initialize it to 0, 0. Then finally
                        // new returns the address of the vector.
    r->x = 94;
    r->y = 345;
    cout << *r << endl;
    *r = vector (94, 343);
    cout << *r << endl;
    *r = *r - c;
    r->set_length(3);
    cout << *r << endl;
    *r = (-c * 3 + -*r * 4) * 5;
    cout << *r << endl;
    delete r; // Calls the vector destructor then
    // frees the memory.
    r = &c; // r points towards vector c
    cout << *r << endl;
    r = new vector (78, 345); // Creates a new vector.
    cout << *r << endl; // The constructor will initialise
    // the vector's x and y at 78 and 345
    cout << "x component of r: " << r->x << endl;
    cout << "x component of r: " << (*r).x << endl;
    delete r;
    r = new vector[4]; // creates an array of 4 vectors
    r[3] = vector (4, 5);
    cout << r[3].module() << endl;
    delete [] r; // deletes the array
    int n = 5;
    r = new vector[n]; // Cute!
    r[1] = vector (432, 3);
    cout << r[1] << endl;
    delete [] r;
    return 0;
}