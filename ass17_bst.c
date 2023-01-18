#include <stdio.h>
#include <stdlib.h>
struct node *head;
struct node
{
    struct node *left;
    int item;
    struct node *right;
};

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

void showInorder(struct node *root)
{
    if (root)
    {
        showInorder(root->left);
        printf("%d ", root->item);
        showInorder(root->right);
    }
}
void showPostorder(struct node *root)
{
    if (root)
    {
        showPostorder(root->left);
        showPostorder(root->right);
        printf("%d ", root->item);
    }
}
void showPreorder(struct node *root)
{
    if (root)
    {
        printf("%d ", root->item);
        showPreorder(root->left);
        showPreorder(root->right);
    }
}
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
