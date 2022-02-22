#include <iostream>
#include <strstream>
#include <cstring>

using namespace std;

int main ()
{
    char a[1024];
    istrstream b(a, 1024);
    strcpy (a, "45.656");
    double k, p;
    b.seekg(0); // Start from first character.
    b >> k;
    k = k + 1;
    cout << k << endl;
    strcpy (a, "444.23 56.89");
    b.seekg(0);
    b >> k >> p;
    cout << k << ", " << p + 1 << endl;
    return 0;
}