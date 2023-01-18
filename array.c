#include <stdio.h>
#include <stdbool.h>
// #include<bits/stdc++.h>
#include <conio.h>
int count = 0, capacity = 10;
// void create(){
//     printf("Enter the size of the array");
//     scanf("%d",&size);
//     return;
// }
void transverse(int *arr)
{
    if (count == 0)
    {
        printf("Array is empty. Nothing to print.\n");
        printf("**************************************\n");
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d \n", arr[i]);
    }
    printf("**************************************\n");
    return;
}

void insertion(int *arr, int size)
{
    int choice;
    if (count == size)
    {
        printf("Array is full.\n");
        printf("**************************************\n");
        return;
    }
    printf("1:Beginning\n 2:End\n ");
    scanf("%d", &choice);
    printf("**************************************\n");
    switch (choice)
    {
    case (1):
    {
        int element;
        printf("Enter the element: ");
        scanf("%d", &element);
        printf("**************************************\n");
        for (int i = count; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = element;
        count++;
        printf("Element stored successfully!!\n *************\n");
        transverse(arr);
        return;
    }

    case (2):
    {
        int element;
        printf("Enter the element: ");
        scanf("%d", &element);
        arr[count] = element;
        count++;
        printf("Element stored successfully!!\n *************\n");
        transverse(arr);
        return;
    }
        // case (3):
        // {
        //     int element, index;
        //     printf("Enter the Index: ");
        //     scanf("%d", &index);
        //     if ((index > 0) && (index <= count))
        //     {
        //         for (int i = count; i >= index; i--)
        //         {
        //             arr[i] = arr[i - 1];`
        //         }
        //     printf("Enter the element: ");
        //     scanf("%d", &element);
        //     arr[index] = element;
        //     count++;
        //     printf("Element stored successfully!!\n *************\n");
        //     transverse(arr);
        //     return;
        //     }
        //     else{
        //         printf("Invalid index");
                // return;
        //     }
        //
        // }

    default:
    {
        printf("Invalid entry.\n");
        printf("**************************************\n");
        return;
    }
    }
}

void deletion(int *arr)
{
    int choice;
    if (count == 0)
    {
        printf("Array is empty.\n");
        printf("**************************************\n");
        return;
    }
    printf("1:Beginning\n 2:End\n 3:Element\n");
    scanf("%d", &choice);
    printf("**************************************\n");

    switch (choice)
    {
    case (1):
    {
        int element = arr[0];
        transverse(arr);
        for (int i = 0; i < (count - 1); i++)
        {
            arr[i] = arr[i + 1];
        }
        printf("Element=%d deleted successfully!!\n *************\n", element);
        count--;
        transverse(arr);
        break;
    }

    case (2):
    {
        printf("Element=%d deleted successfully!!\n *************\n", arr[count - 1]);
        count--;
        transverse(arr);
        break;
    }

    case (3):
    {
        int element, index;
        bool conclusion = false;
        printf("Enter the element: ");
        scanf("%d", &element);
        for (int i = 0; i < count; i++)
        {
            if (arr[i] == element)
            {
                index = i;
                conclusion = true;
            }
        }
        if (conclusion)
        {
            for (int i = index; i < (count - 1); i++)
            {
                arr[index] = arr[index + 1];
            }
        }
        else
        {
            printf("element is not present in array.\n");
            printf("**************************************\n");
            return;
        }
        count--;
        printf("Element=%d at index %d deleted successfully!!\n *************\n", element, index);
        transverse(arr);
        break;
    }

    default:
    {
        printf("Invalid entry.\n");
        printf("**************************************\n");
        break;
    }
    }
    return;
}

void search(int *arr)
{
    int element;
    printf("enter the element to search: ");
    scanf("%d", &element);
    printf("**************************************\n");
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == element)
        {
            printf("Element is present at index %d\n", i);
            printf("**************************************\n");
            transverse(arr);
            return;
        }
    }
    printf("Element is not present in array\n");
    printf("**************************************\n");
    transverse(arr);
    return;
}

void sort(int *arr)
{
    int least;
    for (int i = 0; i < count; i++)
    {
        least = arr[i];
        for (int j = i; j < count; j++)
        {
            if (least > arr[j])
            {
                least = arr[j];
                arr[j] = arr[i];
                arr[i] = least;
            }
        }
    }
    printf("Congo!, Your array has been sorted\n");
    transverse(arr);
}
int main()
{
    int size;
    bool con = true;
    while (con)
    {
        printf("Enter the size of the array");
        scanf("%d", &size);
        if ((size > 0) && (size <= capacity))
        {
            con = false;
        }
        else
        {
            printf("Invalid input.\n Please enter a size from 1 to 10");
        }
    }
    int arr[size];
    // int arr[]={45,48,74,96};
    int choice;
    con = true;
    while (con)
    {
        printf(" 1:Print \n 2:Insert \n 3:Delete \n 4:Search \n 5:Sort \n 6:Exit \n");
        printf("Enter the action you want to perform: ");
        scanf("%d", &choice);
        printf("**************************************\n");
        switch (choice)
        {
        case (1):
            transverse(arr);
            break;
        case (2):
            insertion(arr, size);
            break;
        case (3):
            deletion(arr);
            break;
        case (4):
            search(arr);
            break;
        case (5):
            sort(arr);
            break;
        case (6):
            con = false;
            break;
        default:
            printf("Enter invalid input\n");
            break;
        }
    }
}