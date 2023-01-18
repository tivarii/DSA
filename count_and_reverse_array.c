// #include "SLL.c"
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct node
    {
        int item;
        struct node *next;
    };
struct node *head,;
int count()
{
    struct node *temp = head;
    int i = 1;
    if (head)
    {
        while (temp->next != NULL)
        {
            i++;
            temp = temp->next;
        }
        return i;
    }
    else{
        printf("link list is empty");
        return 0;
    }
}
void reverse(){
    struct node *current=head,*prev=NULL,*saving;
    while(current!=NULL){
        saving=current->next;
        current->next=prev;
        prev=current;
        current=saving;
    }
    head=prev;   
}
void mergeLL()
{
    // struct node NL[8];
    int i = 0;
    struct node *temp1 = head, *temp2 = head2;
    while (temp1 && temp2)
    {
        if (temp1->item > temp2->item && temp2)
        {
            NL[i].item = temp2->item;
            temp2 = temp2->next;
            NL[i].next = &(NL[i + 1]);
            i++;
        }
        else if (temp1->item < temp2->item && temp1)
        {
            NL[i].item = temp1->item;
            temp1 = temp1->next;
            NL[i].next = &NL[i + 1];
            i++;
        }
        else if (temp1 && temp2)
        {
            NL[i].item = temp1->item;
            temp1 = temp1->next;
            NL[i].next = &NL[i + 1];
            i++;
            NL[i].item = temp2->item;
            temp2 = temp2->next;
            NL[i].next = &NL[i + 1];
            i++;
        }
    }

    if (!temp1&&temp2)
    {
        while (temp2 != NULL)
        {
            NL[i].item = temp2->item;
            temp2 = temp2->next;
            NL[i].next = &(NL[i + 1]);
            i++;
        }
    }
    else if (!temp2&&temp1)
    {
        while (temp1 != NULL)
        {
            NL[i].item = temp1->item;
            temp1 = temp1->next;
            NL[i].next = &NL[i + 1];
            i++;
        }
    }

    for (int j = 0; j < i; j++)
    {
        printf("%d, ", (NL[j].item));
    }
}
void transverse()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("no element in list");
        return;
    }
    printf("the list is : \n");
    while (temp != NULL)
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }
    return;
}
int main()
{
    struct node *t1=(struct node*) malloc (sizeof(struct node));
    struct node *t2=(struct node*) malloc (sizeof(struct node));
    struct node *t3=(struct node*) malloc (sizeof(struct node));
    struct node *t4=(struct node*) malloc (sizeof(struct node));
    struct node *t5=(struct node*) malloc (sizeof(struct node));
    head=t1;
    t1->item = 785;
    t2->item = 14;
    t3->item = 965;
    t4->item = 16;
    t5->item = 1;
    t1->next = t2;
    // t1->next = NULL;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = NULL;
    printf()
    printf("there are %d node in linked list\n",count());
    while(1){
    transverse();
    reverse();
    printf("Linked list after reverse\n");
    transverse();
    printf("1.To reverse again")
    }
}