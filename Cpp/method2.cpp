//A method is allowed to change the variables of the instance it is acting upon:

using namespace std;
#include <iostream>

class vector
{
	public:
	double x;
	double y;
	vector its_oposite()
	{
		vector r;
		r.x = -x;
		r.y = -y;
		return r;
	}
	
	void be_oposited()
	{
		x = -x;
		y = -y;
	}
	
	void be_calculated (double a, double b, double c, double d)
	{
		x = a - c;
		y = b - d;
	}

	vector operator * (double a)
	{
		vector r;
		r.x = x * a;
		r.y = y * a;
		return r;
	}
};

int main ()
{
	vector a, b;
	a.x = 3;
	b.y = 5;
	b = a.its_oposite();
	cout << "Vector a: " << a.x << ", " << a.y << endl;
	cout << "Vector b: " << b.x << ", " << b.y << endl;

	b.be_oposited();
	cout << "Vector b: " << b.x << ", " << b.y << endl;

	a.be_calculated (7, 8, 3, 2);
	cout << "Vector a: " << a.x << ", " << a.y << endl;

	a = b * 2;
	cout << "Vector a: " << a.x << ", " << a.y << endl;

	a = b.its_oposite() * 2;
	cout << "Vector a: " << a.x << ", " << a.y << endl;
	cout << "x of oposite of a: " << a.its_oposite().x << endl;
	
	return 0;
}