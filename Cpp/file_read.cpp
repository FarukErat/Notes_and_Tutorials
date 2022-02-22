#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    fstream f;
    
    char c;

    cout << "What's inside the test.txt file:" << endl;

    cout << endl;

    f.open("C:\\Users\\faruk\\Desktop\\Japanese.txt", ios::in);
    //f.open("Japanese.txt", ios::in); this one opens the file in the folder that the code is in

    while (! f.eof() )
    {
        f.get(c); // Or c = f.get()
        cout << c;
    }

    f.close();

    return 0;
}