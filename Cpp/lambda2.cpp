#include <iostream>

using namespace std;

struct B
{
    const int &a;

    B(const int &a) : a(a) {}

    // variable syntax (Sean Farell's idea)
    operator int() const { return a + 1; }

    // function syntax
    int operator()() const { return a + 1; }
};

int main()
{
    int a;
    B b(a);
    a = 3;
    cout << b << '\n'; // variable syntax
    a = 4;
    cout << b() << '\n'; // function syntax
}
