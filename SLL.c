#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int info;
    struct node *next;
};
struct node *head = NULL,*head1=NULL,*mmergedll=NULL;
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
        printf("%d ", temp->info);
        temp = temp->next;
    }
    return;
}
// void transverseSec()
// {
//     struct node *temp = head1;
//     if (temp == NULL)
//     {
//         printf("no element in list");
//         return;
//     }
//     printf("the list is : \n");
//     while (temp != NULL)
//     {
//         printf("%d ", temp->info);
//         temp = temp->next;
//     }
//     return;
// }
// void transverseMergedlist()
// {
//     struct node *temp = mmergedll;
//     if (temp == NULL)
//     {
//         printf("no element in list");
//         return;
//     }
//     printf("the list is : \n");
//     while (temp != NULL)
//     {
//         printf("%d ", temp->info);
//         temp = temp->next;
//     }
//     return;
// }
// void insertAtlast(int x){
//         struct node * temp=mmergedll;
//         struct node *ptr = (struct node *)malloc(sizeof(struct node));
//         if (temp == NULL)
//         {
//             ptr->info=x;
//             ptr->next=temp;
//             temp->next=ptr;
//             return;
//         }
//         if (temp->next == NULL)
//         {
//             ptr->info = x;
//             ptr->next = NULL;
//             temp->next = ptr;
//             mmergedll = temp;
//             return;
//         }
//         while (temp->next != NULL)
//             temp = temp->next;
//         ptr->next = NULL;
//         ptr->info = x;
//         temp->next = ptr;
//         return;
// }

void insertion()
{
    int input, i;

    printf("enter the number\n");
    scanf("%d", &i);

    struct node *temp = head;

    printf("\n1. enter in beginning\n");
    printf("2. enter in end\n");
    printf("3. enter at particular position \n");

    scanf("%d", &input);

    if (input == 1)
    {
        if (head == NULL)
        {
            printf("no elements present, setting first element\n");
            struct node *ptr = (struct node *)malloc(sizeof(struct node));
            ptr->info = i;
            ptr->next = NULL;
            head = ptr;
            transverse();
            return;
        }
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->next = temp;
        ptr->info = i;
        head = ptr;
        transverse();
        return;
    }
    else if (input == 2)
    {
        if (temp == NULL)
        {
            printf("no elements present,first insert\n");
            return;
        }
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        if (temp->next == NULL)
        {
            ptr->info = i;
            ptr->next = NULL;
            temp->next = ptr;
            head = temp;
            transverse();
            return;
        }
        while (temp->next != NULL)
            temp = temp->next;
        ptr->next = NULL;
        ptr->info = i;
        temp->next = ptr;
        transverse();
        return;
    }
    else if (input == 3)
    {
        if (temp == NULL)
        {
            printf("no elements present,minimum 2elements needed\n");
            return;
        }
        if (temp->next == NULL)
        {
            printf("only 1 elements present, minimum 2 elements needed\n");
            transverse();
            return;
        }

        printf("enter the number, after which insertion is applied\n");
        int pos, val = 1;
        scanf("%d", &pos);
        while (temp != NULL)
        {
            if (temp->info == pos)
            {
                val = 0;
                break;
            }

            temp = temp->next;
        }
        if (val)
        {
            printf("element not found\n");
            return;
        }
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = i;
        ptr->next = temp->next;
        temp->next = ptr;
        transverse();
        return;
    }

    else
        printf("enter valid entry\n");
    return;
}
// void insertionsecondll()
// {
//     int input, i;

//     printf("enter the number\n");
//     scanf("%d", &i);

//     struct node *temp = head1;

//     printf("\n1. enter in beginning\n");
//     printf("2. enter in end\n");
//     printf("3. enter at particular position \n");

//     scanf("%d", &input);

//     if (input == 1)
//     {
//         if (head1 == NULL)
//         {
//             printf("no elements present, setting first element\n");
//             struct node *ptr = (struct node *)malloc(sizeof(struct node));
//             ptr->info = i;
//             ptr->next = NULL;
//             head1 = ptr;
//             transverseSec();
//             return;
//         }
//         struct node *ptr = (struct node *)malloc(sizeof(struct node));
//         ptr->next = temp;
//         ptr->info = i;
//         head1 = ptr;
//         transverseSec();
//         return;
//     }
//     else if (input == 2)
//     {
//         if (temp == NULL)
//         {
//             printf("no elements present,first insert\n");
//             return;
//         }
//         struct node *ptr = (struct node *)malloc(sizeof(struct node));
//         if (temp->next == NULL)
//         {
//             ptr->info = i;
//             ptr->next = NULL;
//             temp->next = ptr;
//             head1 = temp;
//             transverseSec();
//             return;
//         }
//         while (temp->next != NULL)
//             temp = temp->next;
//         ptr->next = NULL;
//         ptr->info = i;
//         temp->next = ptr;
//         transverseSec();
//         return;
//     }
//     else if (input == 3)
//     {
//         if (temp == NULL)
//         {
//             printf("no elements present,minimum 2elements needed\n");
//             return;
//         }
//         if (temp->next == NULL)
//         {
//             printf("only 1 elements present, minimum 2 elements needed\n");
//             transverseSec();
//             return;
//         }

//         printf("enter the number, after which insertion is applied\n");
//         int pos, val = 1;
//         scanf("%d", &pos);
//         while (temp != NULL)
//         {
//             if (temp->info == pos)
//             {
//                 val = 0;
//                 break;
//             }

//             temp = temp->next;
//         }
//         if (val)
//         {
//             printf("element not found\n");
//             return;
//         }
//         struct node *ptr = (struct node *)malloc(sizeof(struct node));
//         ptr->info = i;
//         ptr->next = temp->next;
//         temp->next = ptr;
//         transverseSec();
//         return;
//     }

//     else
//         printf("enter valid entry\n");
//     return;
// }
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
// void mergeLL()
// {
//     // struct node NL[8];
//     int i = 0;
//     struct node *temp1 = head, *temp2 = head1;
//     while (temp1 && temp2)
//     {
//         if (temp1->info > temp2->info && temp2)
//         {
//             // NL[i].info = temp2->info;
//             // temp2 = temp2->next;
//             // NL[i].next = &(NL[i + 1]);
//             // i++;
//             insertAtlast(temp2->info);
//         }
//         else if (temp1->info < temp2->info && temp1)
//         {
//             // NL[i].info = temp1->info;
//             // temp1 = temp1->next;
//             // NL[i].next = &NL[i + 1];
//             // i++;
//             insertAtlast(temp1->info);
//         }
//         else if (temp1 && temp2)
//         {
//             // NL[i].info = temp1->info;
//             // temp1 = temp1->next;
//             // NL[i].next = &NL[i + 1];
//             // i++;
//             // NL[i].info = temp2->info;
//             // temp2 = temp2->next;
//             // NL[i].next = &NL[i + 1];
//             // i++;
//             insertAtlast(temp1->info);
//             insertAtlast(temp2->info);
//         }
//     }

//     if (!temp1&&temp2)
//     {
//         while (temp2 != NULL)
//         {
//             // NL[i].info = temp2->info;
//             // temp2 = temp2->next;
//             // NL[i].next = &(NL[i + 1]);
//             // i++;
//             insertAtlast(temp2->info);
//         }
//     }
//     else if (!temp2&&temp1)
//     {
//         while (temp1 != NULL)
//         {
//             // NL[i].info = temp1->info;
//             // temp1 = temp1->next;
//             // NL[i].next = &NL[i + 1];
//             // i++;
//             insertAtlast(temp1->info);
//         }
//     }
//     transverseMergedlist();
//     // for (int j = 0; j < i; j++)
//     // {
//     //     printf("%d, ", (NL[j].info));
//     // }
    
// }
// void deletion()
// {
//     if (head == NULL)
//     {
//         printf("list is empty\n");
//         return;
//     }
//     int input;

//     printf("\n1. delete in beginning\n");
//     printf("2. delete in end\n");
//     printf("3. delete at particular position \n");

//     printf("enter the choice number\n");
//     scanf("%d", &input);
//     struct node *temp = head;
//     if (input == 1)
//     {
//         if (temp->next == NULL)
//         {
//             head = NULL;
//             transverse();
//             return;
//         }
//         head = temp->next;
//         free(temp);
//         transverse();
//         return;
//     }
//     else if (input == 2)
//     {
//         if (temp->next == NULL)
//         {
//             printf("only one element present, minimum 2 needed\n");
//             transverse();
//             return;
//         }
//         while (temp->next->next != NULL)
//         {
//             temp = temp->next;
//         }
//         struct node *last = temp->next;
//         temp->next = NULL;
//         free(last);
//         transverse();
//         return;
//     }
//     else if (input == 3)
//     {

//         if (temp->next == NULL)
//         {
//             printf("only one element present, minimum 3 needed\n");
//             transverse();
//             return;
//         }
//         if (temp->next->next == NULL)
//         {
//             printf("only 2 elements present, minimum 3 element required\n");
//             transverse();
//             return;
//         }
//         printf("enter the number to delete\n");
//         int pos, val = 1;
//         scanf("%d", &pos);
//         while (temp->next != NULL)
//         {
//             if (temp->next->info == pos)
//             {
//                 val = 0;
//                 break;
//             }

//             temp = temp->next;
//         }
//         if (val)
//         {
//             printf("element not found\n");
//             return;
//         }
//         struct node *mid = temp->next;
//         temp->next = temp->next->next;
//         free(mid);
//         transverse(head);
//         return;
//     }

//     else
//         printf("enter valid entry\n");
//     return;
// }

int main()
{
    int choice;
    bool check = true;

    // head->info=NULL;
    // head->next=NULL;

    while (check)
    {
        printf("***************************");
        printf("\nenter the choice to perform action\n");
        printf("1. traverse \n");
        printf("2. insertion \n");
        // printf("3. deletion \n");
        printf("4. Exit \n");
        printf("5. Reverse \n");
        printf("6. Count \n");
        // printf("7. Merge \n");
        // printf("8. insert in second linked list.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            transverse();
            break;
        }
        case 2:
        {
            insertion();
            printf("***************************");
            break;
        }
        case 3:
        {
            // deletion();
            // printf("***************************");
            printf("Invalid input.");
            break;
        }
        case 4:
        {
            check = false;
            printf("exiting..");
            break;
        }
        case 5:{
            reverse();
            transverse();
        }
        case 6:{
            printf("no of count: %d\n",count());
            break;
        }
        // case 7:{
        //     mergeLL();
        //     break;

        // }
        // case 8:{
        //     insertionsecondll();
        // }
        default:
            printf("enter valid entry\n");
            printf("***************************");
        }
    }

    transverse();
    return 0;
}
