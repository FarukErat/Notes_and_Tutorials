#include <stdio.h>
#include <stdlib.h>

typedef struct member
{
    int value;
    struct member *next;
    struct member *previous;
}Member;

typedef struct list
{
    Member *beginning;
    Member *finish;
    int memberNum;
}List;

enum PrintingStyle{AZ = 0, ZA = 1};

void prepare(List *list);
void clear(List *list);
void addToEnd(List* list, int member);
void delete(List* list, int order);
void print(List* list, int ZA);
void menu();
 

int main(int argc, char* argv[]) {
    List list;
    prepare(&list);

    int choice, order, value;

    while (1) {
        menu();

        scanf("%d", &choice);
        switch (choice) {
            case 0:
                clear(&list);
                printf("The program has ended.");
                exit(EXIT_SUCCESS);
                break;
            case 1:
                print(&list,AZ);
                break;
            case 2:
                print(&list,ZA);
                break;
            case 3:
                printf("Enter the number you want to add: ");
                scanf("%d", &value);
                addToEnd(&list, value);
                break;
            case 4:
                printf("\nThe number of the members   :%d", list.memberNum);
                printf("\nWhich member will be deleted?: ");
                scanf("%d", &order);
                delete(&list, order);
                break;
            default:
                printf("Invalid choice. Please enter a valid one!");
                break;
        }
    }
    return EXIT_SUCCESS;
}

void prepare(List *list){
    
    list->beginning = (Member*) malloc(sizeof (Member));
    list->beginning->previous = NULL;
    list->beginning->next = NULL;
    list->finish = list->beginning;
    list->memberNum = 0;
    
}

void addToEnd(List* list, int member){
    
    if(list->memberNum == 0){
        list->beginning->value = member;
        list->memberNum++;
        return;
    }
    
    // Eklenecek eleman icin bellekten yer ayiralim
    Member* toBeAdded = (Member*)malloc(sizeof(Member));
    toBeAdded->value = member;
    
    list->finish->next = toBeAdded;
    toBeAdded->previous = list->finish;
    list->finish = toBeAdded;
    list->finish->next = NULL;
    list->memberNum++;
}

void delete(List* list, int member) {

    if (list->memberNum == 0 || member > list->memberNum) {      
        printf("\nInvalid Value!");
        return;
    }

    if (list->memberNum == 1) {
        list->memberNum--;        
        printf("\nThe number has been deleted.");
        return;
    }
    
    Member *ptr = NULL;

    // ilk elemani cikar
    if(member == 1) {
        ptr = list->beginning;
        list->beginning = list->beginning->next;
        list->beginning->previous = NULL;
        list->memberNum--;
        free(ptr);
        return;
    }
    
    // son elemani cikar
    if(member == list->memberNum){
        ptr = list->finish;
        list->finish = list->finish->previous;
        list->finish->next = NULL;
        list->memberNum--;
        free(ptr);
        return;
    }
    
  
    int i = 1;
    ptr = list->beginning;
    while(i < member - 1 && ptr->next != NULL){
        ptr = ptr->next;
        i++;
    }
 
    Member* toBeDeleted = ptr->next;
    toBeDeleted->previous->next = toBeDeleted->next;
    toBeDeleted->next->previous = toBeDeleted->previous;
    free(toBeDeleted);
    list->memberNum--;
    printf("\nThe number has been deleted.");
}

void print(List* list, int ZA){
    if(list->memberNum == 0){
        printf("\nThe list is empty.");
        return;
    }
    
    Member* ptr;
    if(ZA){
        ptr = list->finish;
        printf("%d ", ptr->value);
        while(ptr->previous != NULL){
            ptr=ptr->previous;
            printf("%d ", ptr->value);
        }
    }
    else {
        ptr = list->beginning;
        printf("%d ", ptr->value);
        while (ptr->next != NULL) {
            ptr = ptr->next;
            printf("%d ", ptr->value);
        }
    }
}

void clear(List* list) {
    Member *ptr = list->beginning;
    Member *toBeCleared;
    
    printf("\nThe list has been cleared.");

    while (ptr->next != NULL) {
        toBeCleared = ptr;
        ptr = ptr->next;
        free(toBeCleared);
    }
    free(ptr);
}

void menu() {
    printf("\n---------------\n  [ M E N U ]   \n---------------\n");
    printf("1. Print the list\n");
    printf("2. Print the list descended\n");
    printf("3. Ad member to the list\n");
    printf("4. Delete a member from the list\n");
    printf("0. EXIT\n");
    printf("\nEnter your choice: ");
}