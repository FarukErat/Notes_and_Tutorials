#include <iostream>
#include "BiTree.hpp"

using namespace std;

int main()
{
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.display(tree.getRoot());
    cout << endl;
    tree.remove(5);
    tree.display(tree.getRoot());
    cout << endl;
    tree.search(5);

    return 0;
}
