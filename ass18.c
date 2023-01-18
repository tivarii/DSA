#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    int item;
    struct node *right;
};
struct nodeSpost
{
    struct node *ptr;
    char flag;
};
struct node *head;
int size = 0, tos = -1;
struct node **arr;
struct nodeSpost **arr1;

void create()
{
    tos=-1;
    arr = (struct node **)malloc(size * sizeof(struct node *));
}

void push(struct node *ptr)
{
    tos++;
    arr[tos] = ptr;
}

struct node *pop()
{
    if (tos == -1)
    {
        return NULL;
    }
    struct node *temp = arr[tos];
    tos--;
    return temp;
}

void createPost()
{
    tos=-1;
    free(arr1);
    arr1 = (struct nodeSpost **)malloc(size * sizeof(struct nodeSpost *));
}

void pushPost(struct node *ptr, char p)
{
    tos++;
    arr1[tos]->ptr = ptr;
    arr1[tos]->flag = p;
}

struct nodeSpost *popPost()
{
    if (tos == -1)
    {
        return NULL;
    }
    struct nodeSpost *temp = arr1[tos];
    tos--;
    return temp;
}

struct node *insertBST(struct node *root, int k)
{
    if (root)
    {
        if (k >= ((*root).item))
        {
            root->right = insertBST(root->right, k);
        }
        else if (k < root->item)
        {
            root->left = insertBST(root->left, k);
        }
        return root;
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->item = k;
        n->left = NULL;
        n->right = NULL;
        return n;
    }
}

struct node *delete(struct node *root, int k)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->item != k)
    {
        if (k > root->item)
        {
            root->right = delete (root->right, k);
        }
        else if (k < root->item)
        {
            root->left = delete (root->left, k);
        }
        return root;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL)
        {
            struct node *child = root->left ? root->left : root->right;
            free(root);
            return child;
        }
        else
        {
            struct node *child, *parents;
            parents = root;
            child = parents->left;
            while (child->right != NULL)
            {
                parents = child;
                child = child->right;
            }
            root->item = child->item;
            if (parents->left == child)
            {
                parents->left = delete (child, child->item);
            }
            else if (parents->right == child)
            {
                parents->right = delete (child, child->item);
            }
        }
    }
}

struct node *search(struct node *root, int k)
{
    if (root == NULL)
        return root;
    if (root->item == k)
    {
        return root;
    }
    else if (root->item < k)
    {
        return search(root->right, k);
    }
    else
    {
        return search(root->left, k);
    }
}

void showPreorder(struct node *root)
{
    create();
    while (root != NULL)
    {
        printf("%d ", root->item);
        if (root->right != NULL)
        {
            push(root->right);
        }
        root = root->left;
        if (root == NULL)
        {
            root = pop();
        }
    }
    free(arr);
}
void showInorder(struct node *root)
{
    create();
    void firstloop(struct node * root)
    {
        while (root != NULL)
        {
            push(root);
            root = root->left;
        }
    }
    firstloop(root);
    do
    {
        root = pop();
        if (root != NULL)
        {
            printf(" %d, ", root->item);
            if (root->right != NULL)
            {
                root = root->right;
                firstloop(root);
            }
        }

    } while (root != NULL);
}

void showPostorder(struct node *root)
{
    createPost();
    printf("yha");
    struct nodeSpost *ptr;
    void firstloop(struct node * r)
    {
        while (r != NULL)
        {
            pushPost(r, 'l');
            if (r->right != NULL)
            {
                pushPost(r->right, 'r');
            }
            r = r->left;
        }
    }
    firstloop(root);
    while(1)
    {
        ptr = popPost();
        if(ptr==NULL)
            break;
        
        if (ptr->flag == 'l')
        {
            printf("%d, ", ptr->ptr->item);
        }
        else if (ptr->flag == 'r')
        {
            firstloop(ptr->ptr);
        }

    }
}

// void showInorder(struct node *root)
// {
//     if (root)
//     {
//         showInorder(root->left);
//         printf("%d ", root->item);
//         showInorder(root->right);
//     }
// }

// void showPostorder(struct node *root)
// {
//     if (root)
//     {
//         showPostorder(root->left);
//         showPostorder(root->right);
//         printf("%d ", root->item);
//     }
// }
// void showPreorder(struct node *root)
// {
//     if (root)
//     {
//         printf("%d ", root->item);
//         showPreorder(root->left);
//         showPreorder(root->right);
//     }
// }

int main()
{
    int choice;
    while (1)
    {
        printf("\n1.Insert\n2.Search\n3.Delete\n4.ShowInorder\n5.ShowPreorder\n6.ShowPostorder\nAnything else to exit.");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int k;
            printf("\nEnter data: ");
            scanf("%d", &k);
            head = insertBST(head, k);
            size++;
            showInorder(head);
            break;
        }
        case 2:
        {
            int k;
            printf("\nEnter data: ");
            scanf("%d", &k);
            struct node *n = search(head, k);
            if (n == NULL)
                printf("\n%d is not present\n", k);
            else
                printf("\n%d is present\n", k);
            if (head == NULL)
            {
                printf("\nNothing to show");
                break;
            }
            showInorder(head);
            break;
        }
        case 3:
        {
            int k;
            printf("\nEnter data: ");
            scanf("%d", &k);
            head = delete (head, k);
            if (head == NULL)
            {
                printf("\nNothing to show");
                break;
            }
            showInorder(head);
            break;
        }
        case 4:
        {
            if (head == NULL)
            {
                printf("\nNothing to show");
                break;
            }
            showInorder(head);
            break;
        }
        case 5:
        {
            if (head == NULL)
            {
                printf("\nNothing to show");
                break;
            }
            showPreorder(head);
            break;
        }
        case 6:
        {
            if (head == NULL)
            {
                printf("\nNothing to show");
                break;
            }
            showPostorder(head);
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
}
