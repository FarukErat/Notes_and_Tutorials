#include <stdio.h>

// declaration of a function pointer of return type void and no arguments
void (*func_ptr)();

void alpha()
{
    printf("alpha\n");
}

void beta()
{
    printf("beta\n");
    func_ptr = alpha; // func_ptr is now pointing to alpha
}

void charlie()
{
    printf("charlie\n");
    func_ptr = beta; // func_ptr is now pointing to beta
}

// func_ptr is initialized not declared
void (*func_ptr)() = charlie;

int main()
{
    func_ptr(); // charlie
    func_ptr(); // beta
    func_ptr(); // alpha
    func_ptr(); // alpha
    func_ptr(); // alpha

    return 0;
}
