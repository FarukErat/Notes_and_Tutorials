#include <iostream>
#include "SLList.hpp"

using namespace std;

int main()
{
    SLL<int> sll;
    sll.add(1);
    sll.insert(2, 0);
    sll.insert(3, 2);
    cout << sll << endl;
    while (sll.getSize() > 0)
    {
        cout << sll.pop() << endl;
    }

    return 0;
}
