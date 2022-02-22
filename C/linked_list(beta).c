#include <stdio.h>
#include <stdlib.h>

typedef struct member
{
    int value;
    struct member *next;
} Member;

typedef struct list
{
    Member* beginning;
    int memberNum;
} List;

void menu();
void prepare(List* list);
void add(List *list, int value);
void delete(List *list, int order);
void print(List *list);
void clear(List *list);

void insert(List *list);

int main(int argc, char *argv[]) {

    List list;
    prepare(&list);

    int choice, order, value;

    while(1)
    {
        menu();

        scanf("%d", &choice);
        switch (choice)
        {
            case 0:
                clear(&list);
                printf("The progam has ended!");
                exit(EXIT_SUCCESS);
                break;
            case 1:
                print(&list);
                break;
            case 2:
                scanf("%d", &value);
                add(&list, value);
                break;
            case 3:
                printf("\nThe number of member: %d", list.memberNum);
                printf("\nWhich member to delete: ");
                scanf("%d", &order);
                delete(&list, order);
                break;
            case 4:
                insert(&list);
                break;
            default:
                printf("Invalid value. Enter a valid one!");
                break;
        }
    }
    return EXIT_SUCCESS;
}

void prepare(List *list) {
    // Listeyi ilk kullanima hazirlayalim
    list->beginning = (Member*) malloc(sizeof (Member));
    list->beginning->next = NULL;
    list->memberNum = 0;
}

void add(List *list, int value) {

    // Listeye yeni eleman ekleyelim
    Member* newMember = (Member*) malloc(sizeof (Member));
    newMember->value = value;

    if (list->memberNum == 0) 
    {
        list->beginning->next = newMember;
    } 
    else 
    {
        Member* ptr = list->beginning;
        int i = 0;
        while (i < list->memberNum) 
        {
            ptr = ptr->next;
            i++;
        }
        ptr->next = newMember;
    }
    newMember->next = NULL;
    list->memberNum++;
}

void delete(List *list, int order) {
  
    if (order < 1 || order > list->memberNum) {
        printf("\nInvalid value!");
        return;
    }
    
    list->memberNum--;
    
    // Tek eleman varsa özel işlem    
    if(list->memberNum == 1){
        free(list->beginning->next);
        list->beginning->next = NULL;
        return;
    }
  
    // Cikarma isi burada yapiliyor
    Member* ptr = list->beginning;
    int i = 0;
    // cikarilacak elemana kadar git
    while (i < order-1) {
        ptr = ptr->next;
        i++;
    }
    Member *temp = ptr->next;
    ptr->next = ptr->next->next;
    free(temp);
    
}

void clear(List *list) {
    
    Member *ptr = list->beginning;
    Member *toBeCleared;
    
    printf("\nThe list is being cleared...");
    while(ptr->next != NULL){
        toBeCleared = ptr;
        ptr = ptr->next;
        free(toBeCleared);
    }
    free(ptr);
}

void print(List *list) {
    printf("\nThe number of member: %d\n", list->memberNum);
    Member* ptr = list->beginning;
    int i = 1;
    while (ptr->next != NULL) {
        printf("The %2d. member:%d\n", i, ptr->next->value);
        ptr = ptr->next;
        i++;
    }
}

void menu() {
    printf("\n----------\n  [Menu]   \n----------\n");
    printf("1. Print\n");
    printf("2. Add\n");
    printf("3. Delete\n");
    printf("4. Insert\n");
    printf("0. EXIT\n");
    printf("Enter your choice: ");
}

// 13. sorunun cevabinin bir benzeri (:
void insert(List *list) {
    int order, value;
    printf("\nWhich member to add: ");
    scanf("%d", &value);
    printf("\nWhich order to add: ");
    scanf("%d", &order);

    if (order > list->memberNum) {
        printf("There are %d members in the list\n", list->memberNum);
        printf("The order must be less than the number of the members in the list");
    }

    // Listeye yeni eleman ekleyelim
    Member* newMember = (Member*) malloc(sizeof (Member));
    newMember->value = value;
    Member* ptr = list->beginning;

    int i = 0;
    while (i < value) {
        ptr = ptr->next;
        i++;
    }

    Member *temp = ptr->next;
    ptr->next = newMember;
    newMember->next = temp->next;
    list->memberNum++;
}