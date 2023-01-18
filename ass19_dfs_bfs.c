#include <stdio.h>
#include <stdlib.h>
int v_count, e_count, **adj;
int *arrS, *arr;
int front, rear, tos;

void createGraph(int v_no, int e_no)
{
    v_count = v_no;
    e_count = e_no;
    adj = (int **)malloc(v_count * sizeof(int *));
    for (int i = 0; i < v_count; i++)
    {
        adj[i] = (int *)malloc(v_count * sizeof(int));
        for (int k = 0; k < v_count; k++)
        {
            adj[i][k] = 0;
        }
    }
    for (int i = 0; i < e_count; i++)
    {
        int u, v;
        printf("\nEnter vertex no. connected by edge-%d: ", i);
        scanf("%d %d", &u, &v);
        if (u >= 0 && v >= 0 && u < v_count && u < v_count)
        {
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        else
        {
            printf("you have enter invalid values");
            i--;
            continue;
        }
    }
}
void createQueue()
{
    rear = front = -1;
    arrS = (int *)malloc(v_count * sizeof(int));
    arr = (int *)malloc(v_count * sizeof(int));
    for (int i = 0; i < v_count; i++)
    {
        arr[i] = 0;
    }
}
void enque(int n)
{
    if (front == -1)
    {
        front++;
        rear++;
        arrS[rear] = n;
    }
    else
    {
        rear++;
        arrS[rear] = n;
    }
}
int deque()
{
    if (front == -1)
    {
        return -1;
    }
    else if (front == rear)
    {
        int n = arrS[front];
        front = rear = -1;
        return n;
    }
    int n = arrS[front];
    front++;
    return n;
}
void createStack()
{
    free(arr);
    free(arrS);
    tos = -1;
    arrS = (int *)malloc(v_count * sizeof(int));
    arr = (int *)malloc(v_count * sizeof(int));
    for (int i = 0; i < v_count; i++)
    {
        arr[i] = 0;
    }
}
void push(int i)
{
    tos++;
    arrS[tos] = i;
}
int pop()
{
    if (tos == -1)
    {
        return -1;
    }
    int n = arrS[tos];
    tos--;
    return n;
}
void insertAdjacent_stack(int v)
{
    if (v < v_count && v >= 0)
    {
        for (int i = 0; i < v_count; i++)
        {
            if (adj[v][i] == 1)
            {
                if (arr[i] == 0)
                {
                    push(i);
                    arr[i] = 1;
                }
            }
        }
    }
}

void printMatrix()
{
    printf("\n");
    for (int i = 0; i < v_count; i++)
    {
        printf("\n");
        for (int k = 0; k < v_count; k++)
        {
            printf("%d ", adj[i][k]);
        }
    }
}
void insertAdjacent_node(int v)
{
    if (v < v_count && v >= 0)
    {
        for (int i = 0; i < v_count; i++)
        {
            if (adj[v][i] == 1)
            {
                if (arr[i] == 0)
                {
                    enque(i);
                    arr[i] = 1;
                }
            }
        }
    }
}
int isIsolated(int v)
{
    if (v < v_count && v >= 0)
    {
        for (int i = 0; i < v_count; i++)
        {
            if (adj[v][i] == 1)
            {
                return 0;
            }
        }
    }
    return 1;
}

void bfs()
{
    int v = 0;
    createQueue();
    enque(0);
    arr[0] = 1;
    while (front != -1)
    {
        int v = deque();
        printf("v%d, ", v);
        insertAdjacent_node(v);
    }
}

void dfs()
{
    int v = 0;
    createStack();
    push(0);
    arr[0] = 1;
    while (tos != -1)
    {
        int v = pop();
        printf("v%d, ", v);
        insertAdjacent_stack(v);
    }
}
int main()
{
    int v, e;
    printf("\nEnter vertex numbers: ");
    scanf("%d", &v);
    printf("\nEnter edge numbers: ");
    scanf("%d", &e);
    createGraph(v, e);
    printMatrix();
    int choice;
    while (1)
    {
        printf("\n1.DFS\n2.BFS\nAnything else to end: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            dfs();
            break;
        }
        case 2:
        {
            bfs();
            break;
        }

        default:
        {
            choice = 0;
            break;
        }
        }
        if (!choice)
            break;
    }
};