#include <stdio.h>
void sortArr(int *a, int l)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < (l-i); j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j+1] = temp;
            }
        }
    }
}
int binarySearch(int *a, int strt, int lst, int item)
{
    int m;
    if (strt > lst)
    {
        return -1;
    }
    m = (strt + lst) / 2;
    if (item == a[m])
        return m;
    else if (item < a[m])
        binarySearch(a, strt, (m - 1), item);
    else
        binarySearch(a, (m + 1), lst, item);
}
int main()
{
    int a[50], n, r;
    printf("\nEnter the number of element you want to enter in array: ");
    scanf("%d", &n);
    printf("\nEnter element.");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sortArr(a, (n - 1));
    for (int i = 0; i < n; i++)
    {
        printf("%d ,",a[i]);
    }
    while (1)
    {
        int item;
        printf("\nEnter the element you want to search: ");
        scanf("%d", &item);
        r = binarySearch(a, 0, (n - 1), item);
        if (r != -1)
        {
            printf("\nThe element %d is found at index %d", item, r);
        }
        else
        {
            printf("\nThe element is not present in array");
        }
        printf("\nEnter 0 if you want to exit or anything else to search again: ");
        scanf("%d", &r);
        if (!r)
            break;
    }
}