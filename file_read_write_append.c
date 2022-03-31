#include <stdio.h>  // no need to explain why
#include <string.h> // for strlen

void readFromFile(char *filename);
void writeToFile(char *filename, char *buffer);
void appendToFile(char *filename, char *buffer);

int main()
{
    char *filename = "test.txt";               // filename to read from and write to
    char *buffer = "Hello World!\nUniverse\n"; // buffer to write to file
    writeToFile(filename, buffer);             // write to file
    appendToFile(filename, "appended text");   // append to file
    readFromFile(filename);                    // read from file
    /*
    output:
    Hello World!
    Universe
    appended text
    */
    return 0;
}

void readFromFile(char *filename)
{
    FILE *fp;                  // file pointer
    char ch;                   // character
    fp = fopen(filename, "r"); // open file for reading
    if (fp == NULL)            // check if file exists
    {
        printf("File cannot be opened\n"); // if not, print error message
        return;                            // and exit
    }
    while (!feof(fp)) // while not end of file
    {
        ch = fgetc(fp);   // read character
        printf("%c", ch); // print character
    }
    fclose(fp); // close file
}

void writeToFile(char *filename, char *buffer)
{
    FILE *fp;
    fp = fopen(filename, "w"); // open file for writing
    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return;
    }
    fputs(buffer, fp); // write to file
    fclose(fp);
}

void appendToFile(char *filename, char *buffer)
{
    FILE *fp;
    fp = fopen(filename, "a"); // open file for appending
    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return;
    }
    fputs(buffer, fp);
    fclose(fp);
}
