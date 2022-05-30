#include <iostream>
#include <cstring>

using namespace std;

class A
{
protected:
    int i;
    char *s;

public:
    A() : s(NULL), i(-1) {}
    void foo(int ii)
    {
        i = ii;
        s = new char(0);
    }
    void foo(char *ss)
    {
        i = 0;
        if (s)
            delete s;
        s =
            new char[strlen(ss)];
        strcpy(s, ss);
    }
    void report() { cout << i << " " << s << endl; }
};

class B : public A
{
public:
    void nothing() { ; }
    // error: shadowing of 'f', if uncommented, will shadow the base class method 'foo'
    void foo(int ii, char *ss)
    {
        i = ii;
        if (s)
            delete s;
        s =
            new char[strlen(ss)];
        strcpy(s, ss);
    }
};

int main()
{
    A a;
    a.foo(1);
    a.report();
    a.foo("Hello"); // warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
    a.report();

    B b;
    b.nothing();
    b.foo(3, "Oops");
    b.report();
    b.A::foo(4);
    b.report();

    return 0;
}
