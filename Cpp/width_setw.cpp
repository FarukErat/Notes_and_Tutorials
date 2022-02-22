#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int i;
    cout << "A list of numbers:" << endl;
    for (i = 1; i <= 1024; i *= 2)
    {
        cout.width (7);
        cout << i << endl;
    }
    cout << "A table of numbers:" << endl;
    for (i = 0; i <= 4; i++)
    {
        cout << setw(3) << i << setw(5) << i * i * i << endl;
    }
    return 0;
}