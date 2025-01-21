#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data; 
    struct node *left, *right;
};

struct node *root = NULL;

struct node* create(int d)
{
    if (d==-1)
    {return NULL;}

    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = d;
}

void insert(int n, struct node *t)
{   
    if (t == NULL) 
    {
        t = create(n);
        return;
    }
    else if (t->data < n)
    {insert(n, t->right);}
    else if (t->data > n)
    {insert(n, t->left);}
}

int search(int n, struct node *t)
{
    if (t == NULL) {return 0;}
    if (n == t->data)
    {return 1;}
    else if (t->data < n)
    {insert(n, t->right);}
    else if (t->data > n)
    {insert(n, t->left);}

    return 0;
}

void delete(int n, struct node *t)
{
    if (!search(n, root)) 
    {
        printf("Element not found!\n");
        return;
    }
    if (t == NULL) {return;}
    
    if (n == t->data)
    {
        if (t->left == NULL && t->right == NULL)
        {free(t); return;}

        else if (t->left == NULL)
        {t->data = t->right->data; free(t->right); return;}

        else if (t->right == NULL)
        {t->data = t->left->data; free(t->left); return;}

        else
        {
            t->data = t->left->data;
            free(t->left);
            return;
        }
    }
    else if (t->data < n)
    {insert(n, t->right);}
    else if (t->data > n)
    {insert(n, t->left);}
}

void inorder(struct node* t)
{
    if (t == NULL)
    {
        printf("(No node)");
        return;
    }
    inorder(t->left);
    printf("%d ", t->data);
    inorder(t->right);
}

int main()
{
    int ch, n;
    printf("1. Insert an element\n2. Delete an element\n3. View the tree\n4. Exit\n");
    while(1)
    {
        printf("Choose: "); scanf("%d", &ch);
        if (ch == 4) {break;}
        switch (ch)
        {
        case 1: printf("Enter the element: ");
                scanf("%d", &n); 
                if (search(n, root))
                {
                    printf("No duplicates are allowed!\n");
                    break;
                }
                else
                {insert(n, root); break;}
        case 2: printf("Enter the element: ");
                scanf("%d", &n); delete(n, root); break;
        case 3: printf("The tree in inorder traversal is as follows:\n");inorder(root); break;
        default: printf("Invalid Choice!\n");
            break;
        }
    }

    printf("Thank you!\n");
    return 0;
}