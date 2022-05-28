#include <iostream>

using namespace std;

int main()
{
    int year = 3;
    auto day = [&]() { return year * 365; };
    cout << day() << '\n';
    year = 4;
    cout << day() << '\n';

    return 0;
}
