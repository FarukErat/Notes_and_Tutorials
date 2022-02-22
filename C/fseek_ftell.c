#include <stdio.h>

typedef struct
{
    int x, y;
} Point;

void main(void)
{
    Point points[30];
    Point point;
    
    FILE *file;   
    file = fopen("C:\\Users\\faruk\\Desktop\\data.bin", "ab+");    

    int i;
    for (i = 0; i < 30; i++)
        points[i].x = points[i].y = i;
    
    fwrite(points, sizeof (Point), 30, file);
    rewind(file);
    
    fread(&(point), sizeof (Point), 1, file);
    printf(" % d % d\n", point.x, point.y);
    
    fseek(file, 2 * sizeof (Point), SEEK_CUR);
    fread(&(point), sizeof (Point), 1, file);
    
    printf(" % d % d\n", point.x, point.y);
    fseek(file, 5 * sizeof (Point), SEEK_SET);
    
    fread(&(point), sizeof (Point), 1, file);
    printf(" % d % d\n", point.x, point.y);
    
    fwrite(&(points[10]), sizeof (Point), 10, file);
    fseek(file, -5 * sizeof (Point), SEEK_END);
    
    fread(&(point), sizeof (Point), 1, file);
    printf(" % d % d\n", point.x, point.y);
    
    fclose(file);
}