#include <stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *next;
};

struct node *front, *rear;

int isEmptyLL()
{
    return (front == NULL)?1:0;
}

void show()
{
    if (isEmptyLL())
    {
        printf("\nQueue is empty");
        return;
    }
    struct node *temp = front;
    while (temp)
    {
        printf("\n%d,", temp->item);
        temp = temp->next;
    }
}

void enqueue(int item)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    // struct node *temp;
    n->item = item;
    n->next = NULL;
    if (isEmptyLL())
    {
        front = rear = n;
    }
    else
    {
        rear->next = n;
        rear=n;
    }
}

int dequeue()
{
    if (isEmptyLL())
    {
        printf("Queue is empty.");
        return -1;
    }
    int k = front->item;
    struct node *temp;
    temp = front;
    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;
    free (temp);
    return k;
}