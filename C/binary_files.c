#include <stdio.h>

typedef struct
{
    char name[20];
    int age;
    float salary;
} Employee;

int main()
{
    FILE *fp;
    char *filename = "employee.dat";
    Employee e1 = {"John", 25, 10000.00};
    Employee e2;

    fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    fwrite(&e1, sizeof(Employee), 1, fp);
    fclose(fp);

    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    fread(&e2, sizeof(Employee), 1, fp);
    fclose(fp);

    printf("Name: %s, Age: %d, Salary: %f\n", e2.name, e2.age, e2.salary);

    return 0;
}
