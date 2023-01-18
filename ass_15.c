#include "stackLL.c"
int main()
{
    front = rear = NULL;
    int k;
    while (1)
    {
        printf("\n1.Queue\n2.Stack\nAnything else to exit.");
        scanf("%d", &k);
        switch (k)
        {
        case 1:
        {
            while (1)
            {
                printf("\n1.enqueue\n2.dequeue\n3.show\nAnything else to exit.");
                printf("\nEnter choice:");
                int choice;
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                {
                    printf("\nEnter value you want to enter: ");
                    int item;
                    scanf("%d", &item);
                    enqueue(item);
                    show();
                    break;
                }
                case 2:
                {
                    if (isEmptyLL())
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
                };
                if (choice == 10)
                    break;
            }
            break;
        }

        case 2:
        {
            tos=NULL;
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
                    showSt();
                    break;
                }
                case 2:
                {
                    printf("The popped element is %d.\n", pop());
                    showSt();
                    break;
                }
                case 3:
                {
                    printf("The element at TOP is %d\n", peep());
                    break;
                }
                case 4:
                {
                    showSt();
                    break;
                }
                default:
                {
                    c = 0;
                    break;
                }
                }
                if(c==0)
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
    if(k==10)
        break;
    }
}