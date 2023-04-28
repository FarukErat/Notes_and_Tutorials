#include <stdio.h>

void alpha(int a) {
    printf("alpha: %d\n", a);
}

void beta(int a) {
    printf("beta: %d\n", a);
}

void(*func_point)(int);

void (*get_func(int a))(int) {
    if (a > 0)
        return alpha;
    else
        return beta;
}

int main() {
    func_point = get_func(1);
    func_point(1);
    func_point = get_func(-1);
    func_point(-1);

    return 0;
}
