#include <stdio.h>

int main()
{
    enum UserLevels
	{
		guest = 1,
		student = 2,
		teacher = 3,
		admin = 4
	};
	
	enum UserLevels level;
	
	printf("Enter the permission level between 1 and 4: ");
	scanf("%d", &level);
	
	switch (level)
	{
		case (guest):
			printf("The permisson level is %d, which is guest.", level);
			break;
			
		case (student):
			printf("The permisson level is %d, which is student.", level);
			break;
			
		case (teacher):
			printf("The permisson level is %d, which is teacher.", level);
			break;
			
		case (admin):
			printf("The permisson level is %d, which is admin.", level);
			break;
	}
	
	return 0;
}