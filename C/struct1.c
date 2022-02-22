#include <stdio.h>
#include <string.h>

struct book_info
{
	char name[15];
	float price;
	int rate;
};

int main()
{
	struct book_info books[2] = {"sefiller", 15.75, 9};
	
	struct book_info *bookPtr = &books;
	
	printf("the name  : %s\n", books[0].name);
	printf("the price : %.2f\n", (*bookPtr).price);
	printf("the rate  : %d\n\n", bookPtr->rate);
	
	strcpy(books[1].name, books[0].name);
	books[1].price = books[0].price;
	books[1].rate = books[0].rate;
	
	printf("the name  : %s\n", books[1].name);
	printf("the price : %.2f\n", (*(bookPtr + 1)).price);
	printf("the rate  : %d", (bookPtr + 1)->rate);
	
	return 0;
}