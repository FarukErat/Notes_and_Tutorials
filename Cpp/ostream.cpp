#include <iostream>

using namespace std;

void streamfun(ostream & obj)
{
    obj<< "deneme" ;
}

int main()
{
    streamfun(cout);
    
    return 0;
}