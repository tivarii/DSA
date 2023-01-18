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
        if (temp->next == head)
        {
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
            ptr->next = ptr;
            ptr->pre = ptr;
            head = ptr;
            transverse();
            return;
        }
        else if (temp->next == temp)
        {
            struct node *ptr = (struct node *)malloc(sizeof(struct node));
            ptr->next = temp;
            ptr->pre = temp;
            temp->pre = ptr;
            temp->next = ptr;
            ptr->info = i;
            head = ptr;
            transverse();
            return;
        }
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->next = temp;
        ptr->pre = temp->pre;
        temp->pre = ptr;
        ptr->pre->next = ptr;
        ptr->info = i;
        head = ptr;
        transverse();
        return;
    }
    case (2):
    {
        if (temp == NULL)
        {
            struct node *ptr = (struct node *)malloc(sizeof(struct node));
            ptr->info = i;
            ptr->next = ptr;
            ptr->pre = ptr;
            head = ptr;
            transverse();
            return;
        }
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        if (temp->next == temp)
        {
            ptr->info = i;
            temp->next = ptr;
            ptr->pre = temp;
            ptr->next = temp;
            head = temp;
            temp->pre = ptr;
            transverse();
            return;
        }
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head;
        ptr->info = i;
        ptr->pre = temp;
        head->pre = ptr;
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
            if (temp->next == head)
            {
                break;
            }
            temp = temp->next;
        }
        if (cond)
        {
            printf("element not present");
            return;
        }
        struct node *ptr = (struct node *)malloc(sizeof(struct node));

        ptr->info = i;
        ptr->next = temp->next;
        ptr->pre = temp;
        temp->next = ptr;
        ptr->next->pre = ptr;
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
        if (temp->next == temp)
        {
            head = NULL;
            printf("element deleted successfully.");
            transverse();
            return;
        }
        temp->next->pre = temp->pre;
        temp->pre->next = temp->next;
        head = temp->next;
        free(temp);
        transverse();
        return;
    }
    case (2):
    {
        if (temp->next == temp)
        {
            head = NULL;
            printf("element deleted successfully.");
            transverse();
            return;
        }
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        struct node *last = temp->next;
        temp->next = head;
        head->pre = temp;
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
            if (temp->next == head)
            {
                break;
            }
            temp = temp->next;
        }
        if (cond)
        {
            printf("element not present");
            return;
        }
        if (temp->next == head)
        {
            // if (temp->next == temp)
            // {
            //     head = NULL;
            //     printf("element deleted successfully.");
            //     transverse();
            //     return;
            // }
            struct node *ptr=head;
            ptr->next->pre = ptr->pre;
            ptr->pre->next = ptr->next;
            head = ptr->next;
            free(ptr);
            transverse();
            return;
        }
        struct node *ptr;
        ptr = temp->next;
        temp->next = ptr->next;
        ptr->next->pre = temp;
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
