using namespace std;

#include <iostream>
#include <cstring>

class person
{
	public:

	char *name;
	int age;
	
	person (char *n = "no name", int a = 0)
	{
		name = new char[100];
		strcpy (name, n);
		age = a;
	}
	
	person (const person &s) // The COPY CONSTRUCTOR
	{
		name = new char[100];
		strcpy (name, s.name);
		age = s.age;
	}
	
	person& operator= (const person &s) // overload of =
	{
		strcpy (name, s.name);
		age = s.age;
		return *this;
	}
	
	~person ()
	{
		delete [] name;
	}
};

int main ()
{
	person p;
	cout << p.name << ", age " << p.age << endl << endl;
	person k ("John", 56);
	cout << k.name << ", age " << k.age << endl << endl;
	p = k;
	cout << p.name << ", age " << p.age << endl << endl;
	p = person ("Bob", 10);
	cout << p.name << ", age " << p.age << endl << endl;
	return 0;
}