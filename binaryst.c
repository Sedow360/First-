#include <stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* create(int n)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = n;
    new->left = new->right = NULL;

    return new;
}

struct node *root = NULL;

void ins(int n, struct node *t)
{
    if (t == NULL)
    {
        t = create(n);
        
        return;
    }
    
    if (t->data == n)
    {return;}

    if (n < t->data)
    {ins(n, t->left);}

    else
    {ins(n, t->right);}
}

void inorder(struct node *t)
{
    if (t == NULL) {return;}

    inorder(t->left);
    printf("%d ", t->data);
    inorder(t->right);
}

int main()
{
    int n; printf("Enter the number of elements: ");
    scanf("%d", &n);

    int d, i;
    printf("Enter the elements:\n");

    for (i=0; i<n; i++)
    {
        scanf("%d", &d);
        ins(d, root);
    }

    printf("The inorder traversal of the binary search tree is: ");
    inorder(root);

    return 0;
}