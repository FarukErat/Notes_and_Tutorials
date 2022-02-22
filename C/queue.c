#include <stdio.h>
#include <stdlib.h>

typedef struct member
{
    int value;
    struct member *next;
} Member;

typedef struct queue
{
    Member * beginning;
    Member * finish;
    int memberNum;

} Queue;

int delete(Queue *queue);
void add(Queue *queue, int value);

int main(void)
{

    Queue queue;
    queue.beginning = NULL;
    queue.finish = NULL;
    queue.memberNum = 0;

    int value;
    do
    {
        printf("Enter an integer(-1 to quit):");
        scanf("%d", &value);

        if (value != -1)
            add(&queue, value);

    } while (value != -1);

    int size = queue.memberNum;
    int i = 0;
    while (i < size) {
        printf("%d\n", delete(&queue));
        i++;
    }

    return 0;
}

int delete(Queue *queue) {

    Member *member = queue->beginning;
    queue->beginning = queue->beginning->next;
    if (queue->beginning == NULL)
        queue->finish = NULL;

    int value = member->value;
    free(member);
    queue->memberNum--;
    return value;

}

void add(Queue *queue, int value) {
    Member* member = (Member*) malloc(sizeof (Member));
    member->value = value;

    queue->memberNum++;
    if (queue->beginning == NULL) {
        queue->beginning = member;
        queue->finish = member;
        return;
    }

    queue->finish->next = member;
    queue->finish = member;

}