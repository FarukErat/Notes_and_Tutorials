#include <stdio.h>

typedef enum {
	false = 0,
	true = 1
} bool;

// the code belove also works, however, to make it more readable, the one above is preferred
/*
typedef enum {
	false,
	true
} bool;
*/

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i < n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    printf("%d\n", isPrime(2)); // 1
    printf("%d\n", isPrime(3)); // 1
    printf("%d\n", isPrime(4)); // 0
    printf("%d\n", isPrime(5)); // 1
    return 0;
}
