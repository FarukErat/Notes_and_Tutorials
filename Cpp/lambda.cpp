#include <iostream>

using namespace std;

int main()
{
    int num1 = 3;
    auto myLambda =
        [num1]                   /*lambda introducer*/
        (int num2 = 7)           /*parameters*/
    { return num1 + num2 * 9; }; /*body*/
    cout << myLambda() << endl;

    return 0;
}
