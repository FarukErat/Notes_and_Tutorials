#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    fstream f;

    f.open("C:\\Users\\faruk\\Desktop\\Cpp_deneme.txt", ios::out);

    f << "This is a text output to a file." << endl;

    double a = 345;

    f << "A number: " << a << endl;

    f.close();

    return 0;
}