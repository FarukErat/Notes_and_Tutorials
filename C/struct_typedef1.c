#include <stdio.h>

typedef struct
{
	char name[100];
	char director[50];
	int release_date;
} nickname;

int main()
{
	nickname film1;
	
	printf("The name of the movie: ");
	gets(film1.name);
	
	printf("The director of the movie: ");
	gets(film1.director);
	
	printf("The release date of the movie: ");
	scanf("%d",&film1.release_date);
	
	printf("--------------------------------\n");
	printf("%s\n%s\n%d",film1.name, film1.director, film1.release_date);
	
	return 0;
}