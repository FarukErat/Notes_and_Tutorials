#include <stdio.h>

typedef struct
{
    char name[100];
    char director[50];
    int releaseDate;
}Film;

int main(void)
{
    Film film = {"Contact", "Robert Zemeckis", 1997};
    char *fileName = "film.bin";
    FILE* file = NULL;
    
    file = fopen(fileName, "rb+");
    if(file == NULL){
        printf("The file not found!");
        return 0;
    }
    fwrite(&film, sizeof(Film), 1, file);
    fclose(file);

    Film film1;

    file = fopen(fileName, "rb+");
    if (file == NULL) {
        printf("The file not found\n");
        return 0;
    }

    fread(&film1, sizeof(Film), 1, file);
    fclose(file);
    
    printf("The movie info obtained from the file\n");
    printf("------------------------------\n");
    puts(film1.name);
    puts(film1.director);
    printf("%d\n", film1.releaseDate);
    return 0;
}
