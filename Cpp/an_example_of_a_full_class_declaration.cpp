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
    return vector (x * a, y * a);
}

double vector::module()
{
    return sqrt (x * x + y * y);
}

void vector::set_length (double a)
{
    double length = this->module();
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
    vector a;
    vector b;
    vector c (3, 5);

    a = c * 3;
    a = b + c;
    c = b - c + a + (b - a) * 7;
    c = -c;

    cout << "The module of vector c: " << c.module() << endl;
    cout << "The content of vector a: " << a << endl;
    cout << "The oposite of vector a: " << -a << endl;
    
    c.set_length(2); // Transforms c in a vector of size 2.
    a = vector (56, -3);
    b = vector (7, c.y);
    b.set_length(); // Transforms b in an unitary vector.
    cout << "The content of vector b: " << b << endl;
    double k;
    k = vector(1, 1).module(); // k will contain 1.4142.
    cout << "k contains: " << k << endl;
    return 0;
}