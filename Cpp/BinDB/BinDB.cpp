#include <iostream>
#include "binDB.hpp"

int main()
{
    BinDB<int> db("test.bin", 10);
    int source[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, target[10];
    db.write(source, 10, 0);
    db.read(target, 10, 0);
    for (int i = 0; i < 10; i++)
    {
        std::cout << target[i] << ' ';
    }
    std::cout << std::endl;
    // 0 1 2 3 4 5 6 7 8 9
    db.write(source, 5, 5);
    db.read(target, 10, 0);
    for (int i = 0; i < 10; i++)
    {
        std::cout << target[i] << ' ';
    }
    std::cout << std::endl;
    // 0 1 2 3 4 0 1 2 3 4

    return 0;
}
