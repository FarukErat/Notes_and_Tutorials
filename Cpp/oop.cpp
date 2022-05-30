#include <iostream>

using namespace std;

class Number
{
private:
    int value;

public:
    Number();
    Number(int value);
    int getValue();
    void setValue(int number);
    bool isPrime();
    friend ostream &operator<<(ostream &os, Number &number);
};

class PrimeFactor : public Number
{
private:
    Number number;
    Number **factors;
    int factorNum = 0;

public:
    PrimeFactor();
    PrimeFactor(Number &s);
    void findFactorNum();
    void process();
    int getNumber();
    int getFactorNum();
    friend ostream &operator<<(ostream &os, PrimeFactor &a);
    ~PrimeFactor();
};

int main()
{
    Number s(300);
    cout << "Is " << s << " prime: " << s.isPrime() << endl;
    PrimeFactor as1(s);
    cout << as1;
    as1.~PrimeFactor();
    s.setValue(37);
    cout << "Is " << s << " prime: " << s.isPrime() << endl;
    PrimeFactor as2(s);
    cout << as2;
    as2.~PrimeFactor();

    return 0;
}

Number::Number()
{
    this->value = 1;
}
Number::Number(int value)
{
    if (value < 0)
        this->value = 1;
    else
        this->value = value;
}
void Number::setValue(int number)
{
    if (number > 0)
        value = number;
}
int Number::getValue()
{
    return value;
}
bool Number::isPrime()
{
    for (int i = 2; i < value; i++)
    {
        if (value % i == 0)
            return false;
    }
    return true;
}

ostream &operator<<(ostream &os, Number &number)
{
    os << number.value;
    return os;
}

PrimeFactor::PrimeFactor()
{
    factorNum = 0;
    factors = NULL;
}
PrimeFactor::PrimeFactor(Number &s)
{
    number = s.getValue();
    findFactorNum();
    process();
}
void PrimeFactor::findFactorNum()
{
    int division = number.getValue();
    int factor = 2;
    while (division != 1)
    {
        if (division % factor == 0)
        {
            factorNum++;
            division /= factor;
        }
        else
            factor++;
    }
}
void PrimeFactor::process()
{
    int division = number.getValue();
    int factor = 2;
    int i = 0;
    factors = new Number *[factorNum];
    while (division != 1)
    {
        if (division % factor == 0)
        {
            factors[i++] = new Number(factor);
            division /= factor;
        }
        else
            factor++;
    }
}
int PrimeFactor::getNumber()
{
    return number.getValue();
}
int PrimeFactor::getFactorNum()
{
    return factorNum;
}
PrimeFactor::~PrimeFactor()
{
    delete[] factors;
}

ostream &operator<<(ostream &os, PrimeFactor &a)
{
    for (int i = 0; i < a.factorNum; i++)
    {
        if (i != 0)
            os << " * ";
        os << *a.factors[i];
        if (i == a.factorNum - 1)
            os << "\n";
    }
    return os;
}
