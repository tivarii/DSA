#include <stdio.h>
#include <stdlib.h>
#include "ass14_Queue_linked_list.c"
int arr[50];
int frontArr, rearArr, cap;
int isFullArr()
{
    return (((rearArr + 1) % cap) == frontArr);
}

int isEmptyArr()
{
    if (frontArr == -1)
    {
        return 1;
    }
    return 0;
}

void showArr()
{
    if (isEmptyArr())
    {
        printf("\nQueue is empty");
        return;
    }
    int i = frontArr;
    while (1)
    {
        printf("\n%d,", arr[i]);
        if (i == rearArr)
        {
            break;
        }
        else
        {
            i = (i + 1) % cap;
        }
    }
}

void enqueueArr(int item)
{
    // if(isFullArr()){
    //     printf("\n Queue is full");
    //     return;
    // }
    if (rearArr == (cap - 1))
    {
        rearArr = 0;
    }
    else
        rearArr++;
    arr[rearArr] = item;
    if (isEmptyArr())
        frontArr++;
}

int dequeueArr()
{
    int k = arr[frontArr];
    // if(isEmptyArr()){
    //     printf("\n Queue is empty.");
    //     return 0;
    // }
    if (frontArr == rearArr)
        frontArr = rearArr = -1;
    // else if(frontArr==(cap-1))
    //     frontArr=(frontArr+1)%cap;
    else
        frontArr = (frontArr + 1) % cap;
    return k;
}

int main()
{
    int k;
    while (1)
    {
        printf("\n1.QueuebyArray\n2.QueuebyLinkedlist\nAnything else to exit.");
        scanf("%d", &k);
        switch (k)
        {
        case 1:
        {
            frontArr = rearArr = -1;
            printf("\nEnter capacity of queue: ");
            scanf("%d", &cap);
            while (1)
            {
                printf("\n1.enqueueArr\n2.dequeueArr\n3.showArr\nAnything else to exit.");
                printf("\nEnter choice:");
                int choice;
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                {
                    if (isFullArr())
                    {
                        printf("\n Queue is full");
                        break;
                    }
                    printf("\nEnter value you want to enter: ");
                    int item;
                    scanf("%d", &item);
                    enqueueArr(item);
                    showArr();
                    break;
                }
                case 2:
                {
                    if (isEmptyArr())
                    {
                        printf("\n Queue is empty.");
                        break;
                    }
                    int k = dequeueArr();
                    printf("\nThe %d is dequed", k);
                    showArr();
                    break;
                }
                case 3:
                {
                    showArr();
                    break;
                }
                default:
                {
                    choice = 10;
                    break;
                }
                }
                if (choice == 10)
                    break;
            }
            break;
        }

        case 2:
        {
            front = rear = last = NULL;
            while (1)
            {
                printf("\n1.Enqueue\n2.Dequeue\n3.Show\nAnything else to exit.");
                printf("\nEnter choice:");
                int choice;
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                {
                    // if (isFull())
                    // {
                    //     printf("\n Queue is full");
                    //     break;
                    // }
                    printf("\nEnter value you want to enter: ");
                    int item;
                    scanf("%d", &item);
                    enqueue(item);
                    show();
                    break;
                }
                case 2:
                {
                    if (isEmpty())
                    {
                        printf("\n Queue is empty.");
                        break;
                    }
                    int k = dequeue();
                    printf("\nThe %d is dequed", k);
                    show();
                    break;
                }
                case 3:
                {
                    show();
                    break;
                }
                default:
                {
                    choice = 10;
                    break;
                }
                }
                if (choice == 10)
                    break;
            }
            break;
        }
        default:
        {
            k = 10;
            break;
        }
        }
        if (k == 10)
            break;
    }
}