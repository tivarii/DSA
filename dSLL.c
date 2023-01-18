#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int info;
    struct node *next;
    struct node *pre;
};
struct node *head = NULL;
void transverse()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("no element in list");
        return;
    }
    printf("the list is : \n");
    while (true)
    {
        printf("%d ", temp->info);
        if(temp->next==NULL){
            return;
        }
        temp = temp->next;
    }
    return;
}

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
    switch (input)
    {
    case (1):
    {
        if (head == NULL)
        {
            // printf("no elements present, setting first element\n");
            struct node *ptr = (struct node *)malloc(sizeof(struct node));
            ptr->info = i;
            ptr->next = NULL;
            ptr->pre = NULL;
            head = ptr;
            transverse();
            return;
        }
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->next = temp;
        ptr->pre = NULL;
        ptr->info = i;
        head = ptr;
        transverse();
        return;
    }
    case (2):
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
            temp->next = ptr;
            ptr->pre = temp;
            ptr->next = NULL;
            head = temp;
            head->pre = NULL;
            transverse();
            return;
        }
        while (temp->next != NULL)
            temp = temp->next;
        ptr->next = NULL;
        ptr->info = i;
        temp->next = ptr;
        ptr->pre = temp;
        transverse();
        return;
    }
     case (3):
    {
        if (temp == NULL)
        {
            printf("no elements present\n");
            return;
        }
        int ele;
        printf("Enter the elemtent.");
        scanf("%d",&ele);
        bool cond=true;
        while(true){
            if(temp->info==ele){
                cond=false;
                break;
            }
            if(temp->next==head){
                break;
            }
            temp=temp->next;
        }
        if(cond){
            printf("element not present");
            return;
        }
        struct node *ptr = (struct node *)malloc(sizeof(struct node));

        ptr->info=i;
        ptr->next=temp->next;
        // ptr->pre=temp;
        temp->next=ptr;
        // ptr->next->pre=ptr;
        transverse();
        return;
        
    }

    default:
        printf("enter valid entry\n");
    }
    return;
}
void deletion()
{
    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    int input;

    printf("\n1. delete in beginning\n");
    printf("2. delete in end\n");
    printf("3. delete at particular position \n");

    printf("enter the choice number\n");
    scanf("%d", &input);
    struct node *temp = head;
    switch (input)
    {
    case (1):
    {
        if (temp->next == NULL)
        {
            head = NULL;
            printf("element deleted successfully.");
            transverse();
            return;
        }
        head = temp->next;
        free(temp);
        head->pre == NULL;
        transverse();
        return;
    }
    case (2):
    {
        if (temp->next == NULL)
        {
            head = NULL;
            printf("element deleted successfully.");
            transverse();
            return;
        }
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        struct node *last = temp->next;
        temp->next = NULL;
        free(last);
        transverse();
        return;
    }
    case (3):
    {
        if (temp == NULL)
        {
            printf("no elements present\n");
            return;
        }
        int ele;
        printf("Enter the elemtent.");
        scanf("%d", &ele);
        bool cond = true;
        while (true)
        {
            if (temp->info == ele)
            {
                cond = false;
                break;
            }
            if (temp->next == NULL)
            {
                break;
            }
            printf("YHa h");
            temp = temp->next;
        }
        if (cond)
        {
            printf("element not present");
            return;
        }
        if (temp->next == NULL)
        {
            printf("Enter a valid entry.");
            return;
        }
        struct node *ptr;
        ptr = temp->next;
        temp->next = ptr->next;
        // ptr->next->pre = temp;
        free(ptr);
        transverse();
        return;
    }


    default:
        printf("enter valid entry\n");
    }
    return;
}

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
        printf("3. deletion \n");
        printf("4. Exit \n");
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
            deletion();
            printf("***************************");
            break;
        }
        case 4:
        {
            check = false;
            printf("exiting..");
            break;
        }
        default:
            printf("enter valid entry\n");
            printf("***************************");
        }
    }

    transverse();
    return 0;
}
