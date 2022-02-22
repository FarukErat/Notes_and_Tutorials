#include <stdio.h>

int main()
{
	//How many numbers are there with 3 digits and all digits are different?

	int a,b,c,x,y;

	for(x=100;x<=999;x+=1)
	{
		a=x/100;
		b=(x/10)%10;
		c=x%10;
	
		if(a!=b && b!=c && c!=a)
		{
			y++;
		} 
	} 
	printf("%d",y); 

	return 0;
}