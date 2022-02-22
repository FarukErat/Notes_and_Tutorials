#include <stdio.h>

int main ()
{
  int num;

  printf("enter a value: ");
  scanf("%d",&num);

  printf("new value: %d",num > 0 ? num : -num);

  return 0;
}