#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

// skip odd numbers
int foo1(int bottom, int top)
{
    if (bottom > top)
        return 0;
    if (bottom % 2 != 0)
        bottom++;
    int sum = 0;
    for (int i = bottom; i <= top; i += 2)
    {
        sum += i;
    }
    return sum;
}

// check if even
int foo2(int bottom, int top)
{
    if (bottom > top)
        return 0;
    int sum = 0;
    for (int i = bottom; i <= top; i++)
    {
        if (i % 2 == 0)
            sum += i;
    }
    return sum;
}

// recursive skip odd numbers
int foo3(int bottom, int top)
{
    if (bottom > top)
        return 0;
    if (bottom % 2 != 0)
        bottom++;
    return bottom + foo3(bottom + 2, top);
}

// recursive check if even
int foo4(int bottom, int top)
{
    int num = 0;
    if (bottom > top)
        return 0;
    if (bottom % 2 == 0)
        num = bottom;
    return num + foo4(bottom + 1, top);
}

// measure time of function execution
void chrono(int (*foo)(int, int), int bottom, int top, int times)
{
    clock_t start, end;
    int result;
    start = clock();
    for (int i = 0; i < times; i++)
    {
        result = foo(bottom, top);
    }
    end = clock();
    cout << "time in ms = " << end - start << endl;
    cout << "result = " << result << endl;
}

// driver function
int main()
{
    // set parameters
    const int till = 100;
    const int times = 1000000;

    // measure times of functions
    chrono(foo1, 1, till, times);
    chrono(foo2, 1, till, times);
    chrono(foo3, 1, till, times);
    chrono(foo4, 1, till, times);

    return 0;
}
