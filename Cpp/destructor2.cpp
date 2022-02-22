using namespace std;
#include <iostream>
#include <cstdlib>
class array
{
	public:
	int size;
	double *data;
	array (int s)
	{
		size = s;
		data = new double [s];
	}
	
	~array ()
	{
		delete [] data;
	}
	
	double &operator [] (int i)
	{
		if (i < 0 || i >= size)
		{
			cerr << endl << "Out of bounds" << endl;
			exit (EXIT_FAILURE);
		}
	else return data [i];
	}
};

int main ()
{
	array t (5);
	t[0] = 45; // OK
	t[4] = t[0] + 6; // OK
	cout << t[4] << endl; // OK
	t[10] = 7; // error!
	return 0;
}