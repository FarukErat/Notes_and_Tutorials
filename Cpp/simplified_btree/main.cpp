#include <iostream>
#include "btree.hpp"

using namespace std;

int main()
{
    BBTree<int> tree;

    tree.add(5);
    tree.add(1);
    tree.add(3);
    tree.add(2);
    tree.add(1);
    tree.add(4);
    tree.print();

    tree.remove(1);
    tree.print();

    tree.remove(2);
    tree.print();

    cout << tree.find(5) << endl;
    cout << tree.find(2) << endl;

    return 0;
}