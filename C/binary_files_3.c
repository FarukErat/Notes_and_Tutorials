#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    int age;
    float salary;
} Employee;

int main()
{
    char *fileName = "test.dat";
    Employee *emp = (Employee *)malloc(sizeof(Employee) * 3);
    FILE *fp = fopen(fileName, "wb");
    if (fp == NULL)
    {
        printf("Error opening file %s\n", fileName);
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        emp[i].age = 20 + i;
        emp[i].salary = 1000.0 + i * 100.0;
        sprintf(emp[i].name, "Name %d", i);
    }

    fwrite(emp, sizeof(Employee), 3, fp); // write 3 employees at once
    fclose(fp);

    fp = fopen(fileName, "rb");
    if (fp == NULL)
    {
        printf("Error opening file %s\n", fileName);
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        fread(emp, sizeof(Employee), 1, fp);
        printf("Name: %s, Age: %d, Salary: %f\n", emp->name, emp->age, emp->salary);
    }

    free(emp);
    fclose(fp);

    return 0;
}
