#include <stdio.h>
#include <string.h>

#define PI 3.14

typedef struct
{
	float x;
	float y;
} Point;

typedef struct
{
	float radius;
	Point center;
} Circle;

void print_circle_info(Circle c);

int main()
{
	Circle circle;
	
	printf("Enter the coordinates of the circle\n");
	
	printf("x: ");
	scanf("%f",&circle.center.x);
	
	printf("y: ");
	scanf("%f",&circle.center.y);
	
	printf("Enter the radius of the circle: ");
	scanf("%f",&circle.radius);
	
	print_circle_info(circle);
	
	return 0;
}

void print_circle_info(Circle c)
{
	float perimeter = 2 * PI * c.radius;
	float area = PI * c.radius * c.radius;
	
	printf("\n[THE INFO OF THE CIRCLE]\n");
	printf("\nThe coordinates of the center: %.2f, %.2f", c.center.x, c.center.y);
	printf("\nThe radius: %.2f", c.radius);
	printf("\nThe perimeter: %.2f", perimeter);
	printf("\nThe area: %.2f", area);
}