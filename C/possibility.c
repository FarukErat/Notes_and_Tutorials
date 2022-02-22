#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, rate;
  
    srand (time(NULL));
  
    num = rand()%(100);
  
    do
    {
        printf("enter rate between 0 and 100: ");
        scanf("%d",&rate);
        
    } while (rate < 0 || rate > 100);
  
    if (num < rate)
    {
        puts("YES");
    }
    
    else
    {
        puts("NO");
    }
}