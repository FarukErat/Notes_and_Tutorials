//They are automatically called whenever an instance of a class is created or destroyed
//(variable declaration, end of program, new, delete...).
//The constructor will initialize the variables of the instance, do some
//calculation, allocate some memory for the instance, output some text...
//whatever is needed.

using namespace std;
#include <iostream>

class vector
{
	public:
	double x;
	double y;
	vector () // same name as class
	{
		x = 0;
		y = 0;
	}
	vector (double a, double b)
	{
		x = a;
		y = b;
	}
};

int main ()
{
	vector k; // vector () is called
	cout << "vector k: " << k.x << ", " << k.y << endl << endl;
	vector m (45, 2); // vector (double, double) is called
	cout << "vector m: " << m.x << ", " << m.y << endl << endl;
	k = vector (23, 2); // vector created, copied to k, then erased
	cout << "vector k: " << k.x << ", " << k.y << endl << endl;
	return 0;
}