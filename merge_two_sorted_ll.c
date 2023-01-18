#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *next;
};
struct node *head1 = NULL, *head2 = NULL;
void mergeLL()
{
    struct node NL[100];
    int i = 0;
    struct node *temp1 = head1, *temp2 = head2;
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
    NL[i].next=NULL;

    printf("merged Array: ");
    for (int j = 0; j < i; j++)
    {
        printf("%d, ", (NL[j].item));
    }
}

int main()
{
    struct node N1[100];
    struct node L1[100];
    head2 = &L1[0];
    head1=&N1[0];
    // N1.next = &N2;
    // N2.next = &N3;
    // N3.next = &N4;
    // N4.next = NULL;
    printf("Enter 1st Linked list\n");
    for (int i=0;i<100;i++){
        printf("\nEnter value:");
        scanf("%d",&(N1[i].item));
        if(i>0 && (N1[i].item<N1[i-1].item)){
            printf("please enter value greater than previous.\n");
            i--;
            continue;
        }
        N1[i].next=&N1[i+1];
        printf("Enter 1 to exit and else to continue");
        int m;
        scanf("%d",&m);
        if(m==1){
            N1[i].next=NULL;
            break;
        }
    }
    printf("Enter 2nd Linked list\n");
    for (int i=0;i<100;i++){
        int m;
        printf("\nEnter value:");
        scanf("%d",&(L1[i].item));
        if(i>0 && (L1[i].item<L1[i-1].item)){
            printf("please enter value greater than previous.\n");
            i--;
            continue;
        }
        L1[i].next=&L1[i+1];
        printf("Enter 1 to exit and else to continue");
        scanf("%d",&m);
        if(m==1){
            L1[i].next=NULL;
            break;
        }
    }
    printf("\n1st linked list: ");
    for(int i=0;i<100;i++){
        printf("%d, ", (N1[i].item));
        if(N1[i].next==NULL){
            break;
        }
    }
    printf("\n2nd linked list: ");
    for(int i=0;i<100;i++){
        printf("%d, ", (L1[i].item));
        if(L1[i].next==NULL){
            break;
        }
    }
    // while(1){
    // printf("1. Merge\n 2. Count");
    // int m;
    // scanf("%d",&m);
    // }
    mergeLL();

}