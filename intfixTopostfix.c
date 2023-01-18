#include <stdio.h>
#include <stdlib.h>
int nop, np;
int ind = -1,indP=-1;
int noOfoperator = 0, noOfoperand = 0;
char infix[10], postfix[10];
char arr[15];
int capacity = 15, top = -1;
void push(char x)
{
    if (top == capacity)
    {
        printf("Overflow\n");
        return;
    }
    top++;
    arr[top] = x;
}
char pop()
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
char peep()
{
    if (top == -1)
    {
        printf("Underflow\n");
        return 0;
    }
    return arr[top];
}
void infixTopostfix()
{
    for (int i = 0; i <= ind; i++)
    {
        char x = infix[i];
        if (x == '*' || x == '/' || x == '+' || x == '-' || x == '^')
        {
            if(peep()<)
            push(x);
        }
        else if (x >= 65 || x <= 90 || x >= 97 || x <= 122){
            insertP(x);
        }
    }
}
void insertP(char x){
    indP++;
    postfix[indP]=x;
}

int insert(char x, char *arr)
{
    if (x == 10)
        return 1;

    ind++;
    arr[ind] = x;

    if (x == '*' || x == '/' || x == '+' || x == '-' || x == '^')
    {
        noOfoperator++;
    }
    else if (x >= 65 || x <= 90 || x >= 97 || x <= 122)
    {
        noOfoperand++;
    }
    else if (x == 40 || x == 41 || x == 91 || x == 93 || x == 123 || x == 125)
    {
    }

    else
    {
        printf("invalid input you may be used special character.\n");
        return 1;
    }

    if ((noOfoperator > noOfoperand) || ((noOfoperator + 1) < noOfoperand))
    {
        printf("you have enter input invalid entry.\n");
        return 1;
    }
    // printf("\nno.of_operator=%d:",noOfoperator);
    // printf("\nno.of_operand=%d",noOfoperand);
    return 0;
}
void show(char *arr)
{
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == '\0')
            break;
        printf("%c", arr[i]);
    }
}

int main()
{
    printf("enter infix expression: ");
    for (int i = 0; i < 10; i++)
    {
        char x;
        scanf("%c", &x);
        if (insert(x, infix))
        {
            break;
        }
    }
    if (noOfoperand == noOfoperator)
    {
        printf("invalid input.\n");
    }
    show(infix);
}