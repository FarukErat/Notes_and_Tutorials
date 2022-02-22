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
		name = new char [100]; // better than malloc!
		strcpy (name, n);
		age = a;
		cout << "Instance initialized, 100 bytes allocated" << endl;
	}
	
	~person () // The destructor
	{
		delete name; // instead of free!
		// delete [] name would be more
		// academic but it is not vital
		// here since the array contains
		// no C++ sub-objects that need
		// to be deleted.
		cout << "Instance going to be deleted, 100 bytes freed" << endl;
	}
};
int main ()
{
	cout << "Hello!" << endl << endl;
	person a;
	cout << a.name << ", age " << a.age << endl << endl;
	person b ("John");
	cout << b.name << ", age " << b.age << endl << endl;
	b.age = 21;
	cout << b.name << ", age " << b.age << endl << endl;
	person c ("Miki", 45);
	cout << c.name << ", age " << c.age << endl << endl;
	cout << "Bye!" << endl << endl;
	return 0;
}