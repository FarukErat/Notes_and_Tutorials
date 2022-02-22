using namespace std;
#include <iostream>

class vector
{
	public:
	double x;
	double y;
	double surface(); // The ; and no {} show it is a prototype
};

double vector::surface() // This is the method
{
	double s = 0;
	for (double i = 0; i < x; i++)
	{
		s = s + y;
	}
	return s;
}

int main ()
{
	vector k;
	k.x = 4;
	k.y = 5;
	cout << "Surface: " << k.surface() << endl;
	return 0;
}