#include <stdio.h>

// declaration
// of
// a function pointer of return type void and no arguments
// and
// functions of return type void and no arguments
void (*func_ptr)();
void alpha();
void beta();
void charlie();

int main()
{
    func_ptr(); // alpha
    func_ptr(); // beta
    func_ptr(); // charlie
    func_ptr(); // alpha
    func_ptr(); // beta
    func_ptr(); // charlie

    return 0;
}

// definition
// of
// a function pointer of return type void and no arguments
// and
// functions of return type void and no arguments

void (*func_ptr)() = alpha; // func_ptr is now pointing to alpha

void alpha()
{
    printf("alpha\n");
    func_ptr = beta; // func_ptr is now pointing to charlie
}

void beta()
{
    printf("beta\n");
    func_ptr = charlie; // func_ptr is now pointing to alpha
}

void charlie()
{
    printf("charlie\n");
    func_ptr = alpha; // func_ptr is now pointing to beta
}
