#include<stdio.h>
#include<stdlib.h>

typedef struct member
{
    int value;
    struct member *next;
}Member;

void push(int val, Member *head);
int pop(Member *head);

int main(void) {
    
    Member *beginning, *finish;
    int value;
    
    beginning = (Member *) malloc(sizeof (Member));
    finish = (Member *) malloc(sizeof (Member));
    beginning->next = finish;
    
    do {
        printf("Enter an integer(-1 to quit): ");
        scanf("%d", &value);
    
        if (value != -1)
            push(value, beginning);
        
    } while (value != -1);
    
    printf("Stack ascending:\n");
    
    do{
        printf("%d\n", pop(beginning));
    } 
    while (beginning->next != finish);
}

void push(int val, Member *beginning) {
    Member *toBeAdded;
    toBeAdded = (Member *) malloc(sizeof (Member));
    toBeAdded->value = val;
    toBeAdded->next = beginning->next; 
    beginning->next = toBeAdded;
}

int pop(Member *beginning) {
    Member *temp;
    int val;
    val = beginning->next->value; 
    temp = beginning->next;
    beginning->next = beginning->next->next;
    free(temp);
    return val;
}