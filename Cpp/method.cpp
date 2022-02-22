using namespace std;
#include <iostream>

struct vector
{
	double x;
	double y;
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
	a.x = 3;
	a.y = 4;
	cout << "The surface of a: " << a.surface() << endl;
	return 0;
}