#include <stdio.h>
#include <stdlib.h>
int *arr;
int capacity, top = -1;
void push(int x)
{
    if (top == capacity)
    {
        printf("Overflow\n");
        return;
    }
    top++;
    arr[top] = x;
}
int pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
        return 0;
    }
    int x = arr[top];
    top--;
    return x;
}
int peep()
{
    if (top == -1)
    {
        printf("Underflow\n");
        return 0;
    }
    return arr[top];
}
void show()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("|%d|\n", arr[i]);
        printf("-----\n");
    }
    
    return;
}
int main()
{
    printf("Enter the capacity of the stack.");
    scanf("%d", &capacity);
    arr = (int *)malloc((sizeof(int)) * capacity);
    int cond, c = 1;
    while (c)
    {
        printf("\n1.Push\n2.Pop\n3.Peep\n4.Show \nAnything else to exit.");
        printf("\nEnter choice: ");
        scanf("%d", &cond);
        switch (cond)
        {
        case 1:
        {
            int x;
            printf("\nEnter the element: ");
            scanf("%d", &x);
            push(x);
            show();
            break;
        }
        case 2:
        {
            printf("The popped element is %d.\n", pop());
            show();
            break;
        }
        case 3:
        {
            printf("The element at TOP is %d\n", peep());
            break;
        }
        case 4:
        {
            show();
            break;
        }
        default:
        {
            c = 0;
            break;
        }
        }
    }
}