//It is a good practice to try not to overload the constructors. Best is to declare
//only one constructor and give it default parameters wherever possible:

using namespace std;
#include <iostream>

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
};

int main ()
{
	vector k;
	cout << "vector k: " << k.x << ", " << k.y << endl << endl;
	vector m (45, 2);
	cout << "vector m: " << m.x << ", " << m.y << endl << endl;
	vector p (3);
	cout << "vector p: " << p.x << ", " << p.y << endl << endl;
	return 0;
}