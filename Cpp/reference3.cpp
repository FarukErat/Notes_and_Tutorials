/** behavior of references
 *
 * at the moment of initialization the address is given to reference
 * (like a pointer, unlike a variable)
 *
 * but the address cannot be changed after initialization
 * (unlike a pointer, like a variable)
 *
 * with math operations, its value can be changed without using "*" operator
 * (unlike a pointer, like a variable)
 */

#include <iostream>

using namespace std;

// Here, "*" is used after the type to define a pointer, which holds the address name
void mySwap1(int *first, int *second)
{
    int temp = *first;
    // However, "*" is used to get the value on the address (dereference)
    *first = *second;
    *second = temp;
}

// Here, "&" is used after the type to define a reference
// they cannot be defined without initializing, since it needs an address
// simply, references are meant to be used to use multiple variable over the same memory location
// it is useful when we need a small amount of the features of pointers
// therefore, changes made on a reference is made on the initializing variable
// after defining a reference, it is no different from other variables
// for instance, "ref++;" does NOT move along the memory but it increases the VALUE on the address
void mySwap2(int &first, int &second)
{
    int temp = first;
    first = second;
    second = temp;
}

// built-in "swap()" funciton is the same way as mySwap2()
/*
_CONSTEXPR20 void swap(_Ty& _Left, _Ty& _Right) noexcept(
    is_nothrow_move_constructible_v<_Ty>&& is_nothrow_move_assignable_v<_Ty>) {
    _Ty _Tmp = _STD move(_Left);
    _Left    = _STD move(_Right);
    _Right   = _STD move(_Tmp);
}
*/

// return type can be reference, too
// since it is a reference-typed function and returns a reference,
// the address of the variable is given to the caller, as it is an initializing too
// it is not necessary to use "&", when passing parameters
// and not necessary to use "*" when returning values
int &max(int &a, int &b)
{
    if (a > b)
        return a;
    else
        return b;
}

int *min(int *a, int *b)
{
    if (a < b)
        return a;
    else
        return b;
}

void change(int &a, int b)
{
    a = 100;
    b = 200;
}

// name, value, address
int main()
{
    int a = 3, b = 5;
    cout << a << ", " << b << endl; // 3, 5
    // "&" operator is used to obtain the address name of the following variable (reference)
    mySwap1(&a, &b);
    cout << a << ", " << b << endl; // 5, 3
    // no need to pass the address
    // since it is done automatically when the function parameter is reference
    mySwap2(a, b);
    cout << a << ", " << b << endl; // 3, 5
    // greatest number is set to 2
    max(a, b) = 2;
    cout << a << ", " << b << endl; // 3, 2
    // smallest number is set to 10
    *min(&a, &b) = 10;
    cout << a << ", " << b << endl; // 3, 10
    change(a, b);
    cout << a << ", " << b << endl; // 100, 10

    return 0;
}
