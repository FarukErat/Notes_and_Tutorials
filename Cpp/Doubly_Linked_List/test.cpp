#include <iostream>

#include "DLList.hpp"

using namespace std;

int main()
{
    DLList<int> l({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    while (l.getSize() > 0)
    {
        cout << l.pop() << endl;
    }
    cout << l << ": " << l.getSize() << endl;

    return 0;
}
