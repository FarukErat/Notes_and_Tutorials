#include <iostream>
using namespace std;

template <typename T>
class MyClass
{
private:
    T data;

public:
    MyClass(T data)
    {
        this->data = data;
    }
    T getData()
    {
        return data;
    }
    template <typename U>
    T operator+(MyClass<U> &mc)
    {
        return data + mc.getData();
    }
};

int main()
{
    MyClass<int> mci(1);
    MyClass<double> mcd(3.14);
    cout << mci + mcd << endl; // output: 4
    cout << mcd + mci << endl; // output: 4.14
    return 0;
}
