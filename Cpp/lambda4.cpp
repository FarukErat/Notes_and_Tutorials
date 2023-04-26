#include <iostream>

using std::cout;
using std::endl;

int main() {
    int x = 42;
    int y = 43;

    auto alpha = [](int x, int y) {
        cout << "Passed values:   " << x << " : " << y << endl;
        return x + y;
    };
    auto beta = [x, y]() {
        cout << "Copied values:   " << x << " : " << y << endl;
        return x + y;
    };
    auto charlie = [&x, &y]() {
        cout << "Captured values: " << x << " : " << y << endl;
        x = 1;
        y = 2;
        return x + y;
    };

    alpha(50, 60);
    beta();
    charlie();

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    return 0;
}
