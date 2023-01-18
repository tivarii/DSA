#include <stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *next;
};
struct node *front, *rear, *last;
// int cap;
// int isFull()
// {
//     if (rear)
//         return (rear->next == front);
//     return 0;
// }

int isEmpty()
{
    return (front == NULL);
}

void show()
{
    if (isEmpty())
    {
        printf("\nQueue is empty");
        return;
    }
    struct node *temp = front;
    while (1)
    {
        printf("\n%d,", temp->item);
        if (temp == rear)
            break;
        temp = temp->next;
    }
}

void insert(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->item=data;
    if (last == NULL)
    {
        last = n;
        last->next = n;
    }
    else
    {
        n->next = last->next;
        last->next = n;
    }
}

void enqueue(int item)
{
    // if (isFull())
    // {
    //     printf("Queue is full.");
    //     return;
    // }

    if (isEmpty())
    {
        insert(item);
        front = rear = last->next;
    }
    else
    {
        insert(item);
        rear = rear->next;
    }
    // rear->item = item;
}

int dequeue()
{
    struct node *n=front;
    int k = front->item;
    if (front == rear)
    {
        front = rear = last=NULL;
        return k;
    }
    else
        front = front->next;
    last->next=front;
    free (n);
    return k;
}

// int main()
// {
//     front = rear = last = NULL;
//     printf("\nEnter capacity of queue: ");
//     scanf("%d", &cap);
//     create();
//     while (1)
//     {
//         printf("\n1.Enqueue\n2.Dequeue\n3.Show\nAnything else to exit.");
//         printf("\nEnter choice:");
//         int choice;
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//         {
//             if (isFull())
//             {
//                 printf("\n Queue is full");
//                 break;
//             }
//             printf("\nEnter value you want to enter: ");
//             int item;
//             scanf("%d", &item);
//             enqueue(item);
//             show();
//             break;
//         }
//         case 2:
//         {
//             if (isEmpty())
//             {
//                 printf("\n Queue is empty.");
//                 break;
//             }
//             int k = dequeue();
//             printf("\nThe %d is dequed", k);
//             show();
//             break;
//         }
//         case 3:
//         {
//             show();
//             break;
//         }
//         default:
//         {
//             choice = 10;
//             break;
//         }
//         }
//         if (choice == 10)
//             break;
//     }
// }