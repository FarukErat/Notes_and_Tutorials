#include <iostream>

int main()
{
    int i;
    int number;
    int check;
    int power = 0;

    std::cout<<"Enter an integer\n\n";
    std::cin>>number;

    std::cout<<"\nPrime factors\n\n";

    for(i = 2; number != 1; i++)
    {
        if(number % i == 0)
        {
            power++;

            number /= i;

            if(power == 1)
            {
                std::cout<<i;
            }

            check = i--;
        }

        if(check == i)
        {
            if(power != 1)
            {
                std::cout<<"^"<<power;
            }

            std::cout<<std::endl;

            power = 0;
        }
    }

    if(power != 1)
    {
        std::cout<<"^"<<power;
    }

    return 0;
}