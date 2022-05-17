#include <stdio.h>
#include <stdlib.h> // malloc(), free()
#include <conio.h>  // getche()

// structure of the nodes
typedef struct stackNode
{
    int data;
    struct stackNode *nextPtr; // pointer to next node
} StackNode;

typedef StackNode *StackNodePtr; // in order not to have to type * all the time

/**
 * @brief Pushes a value of type char on top of the stack pointed to by topPtr.
 *
 * @param topPtr
 * @param value
 */
void push(StackNodePtr *topPtr, int value)
{
    StackNodePtr newPtr; // Pointer to a new node

    newPtr = (StackNodePtr)malloc(sizeof(StackNode)); // Allocate memory for new node
    newPtr->data = value;                             // Assign data to new node
    newPtr->nextPtr = *topPtr;                        // Link new node to top of stack
    *topPtr = newPtr;                                 // Update topPtr to point to new node
}

/**
 * @brief Pops a value off the stack pointed to by topPtr and returns the popped value.
 *
 * @param topPtr
 * @return char
 */
int pop(StackNodePtr *topPtr)
{
    int value;
    StackNodePtr tempPtr; // Temporary pointer

    // If topPtr is NULL, then stack is empty
    if (*topPtr == NULL)
    {
        printf("Stack is empty.\n");
        return 0;
    }
    else
    {
        tempPtr = *topPtr;            // Copy pointer
        value = (*topPtr)->data;      // Get data from top node
        *topPtr = (*topPtr)->nextPtr; // Update topPtr
        free(tempPtr);                // Deallocate memory used by old top node
        return value;                 // Return data from old top node
    }
}

/**
 * @brief Prints the stack pointed to by topPtr.
 *
 * @param topPtr
 */
void printStackRaw(StackNodePtr topPtr)
{
    // Use recursion to print the stack in reverse order to maintain readability
    if (topPtr != NULL)
    {
        printStackRaw(topPtr->nextPtr);
        printf("%d\t\t", topPtr);
        printf("%d\t", topPtr->data);
        printf("%d\n", topPtr->nextPtr);
    }
}

/**
 * @brief prints the headers of printStackRaw(),
 * since it is recursive and would print the headers repeatedly.
 *
 * @param topPtr
 */
void printStack(StackNodePtr topPtr)
{
    printf("AddressOfTheNode\tData\tAddressOfTheNextNode\n");
    printStackRaw(topPtr);
}

/**
 * @brief reallocates the memory used by the stack pointed to by topPtr.
 *
 * @param topPtr
 */
void deleteStack(StackNodePtr *topPtr)
{
    StackNodePtr tempPtr; // Temporary pointer

    // Iterate through the stack and deallocate the memory of each node till null
    while (*topPtr != NULL)
    {
        tempPtr = *topPtr;            // Copy pointer
        *topPtr = (*topPtr)->nextPtr; // Update topPtr
        free(tempPtr);                // Deallocate memory used by old top node
    }
}

/**
 * @brief gets a character from the user, converts it to an integer and returns it.
 *
 * @return int
 */
int getChoice()
{
    int choice = getche() - '0';
    putchar('\n');
    return choice;
}

// driver function
int main()
{
    StackNodePtr topPtr = NULL; // Pointer to top of stack
    int number;

    printf("Enter your choice:\n");
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Exit\n");

        switch (getChoice())
        {
        case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d", &number);
            push(&topPtr, number);
            break;
        case 2:
            printf("Popped value: %d\n", pop(&topPtr));
            break;
        case 3:
            printStack(topPtr);
            break;
        case 4:
            printf("Exiting...\n");
            deleteStack(&topPtr);
            return 0;
        default:
            printf("Invalid choice. Please enter again.\n");
            break;
        }
    }

    return 0;
}
