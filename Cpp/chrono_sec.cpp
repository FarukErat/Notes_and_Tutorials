#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    time_t start, finish;
    long product;

    time(&start);
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 100000; j++)
        {
            product = i * j;
        }
    }
    time(&finish);
    cout << "Time required = " << difftime(finish, start) << " seconds";
    return 0;
}