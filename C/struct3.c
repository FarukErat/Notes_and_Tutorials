#include <stdio.h>

struct movie
{
	char name[100];
	char director[50];
	int release_date;
};

int main()
{
	struct movie movie1;
	
	printf("the size of struct name: %d", sizeof(movie1.name));
	printf("\nthe size of struct director: %d", sizeof(movie1.director));
	printf("\nthe size of struct release_date: %d", sizeof(movie1.release_date));
	printf("\nthe size of struct: %d", sizeof(movie1));
	
	return 0;
}