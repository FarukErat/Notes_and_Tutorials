using namespace std;
#include <iostream>

struct vector
{
	double x;
	double y;
};

vector operator * (double a, vector b)
{
	vector r;
	r.x = a * b.x;
	r.y = a * b.y;
	return r;
}
int main ()
{
	vector k, m; // No need to type "struct vector"
	k.x = 2; // To be able to write
	k.y = -1; // k = vector (2, -1)
	m = 3.1415927 * k; // Magic!
	cout << "(" << m.x << ", " << m.y << ")" << endl;
	return 0;
}