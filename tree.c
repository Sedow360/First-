#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* create(int d) 
{
    if (d == -1) {
        return NULL; 
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = d; 
    newNode->left = NULL;
    newNode->right = NULL; 

    printf("Enter next element (or -1 to stop): ");
    int n; 
    scanf("%d", &n);

    
    if (n < d) 
    {
        newNode->left = create(n);
    }
    else if (n != -1) 
    { 
        newNode->right = create(n);
    }

    return newNode; 
}
void preorder(struct node* t)
{
    if (t == NULL)
    {
        //printf("(No node)");
        return;
    }
    printf("%d ", t->data);
    preorder(t->left);
    preorder(t->right);
}

void inorder(struct node* t)
{
    if (t == NULL)
    {
        //printf("(No node)");
        return;
    }
    inorder(t->left);
    printf("%d ", t->data);
    inorder(t->right);
}

void postorder(struct node* t)
{
    if (t == NULL)
    {
        //printf("(No node)");
        return;
    }
    postorder(t->left);
    postorder(t->right);
    printf("%d ", t->data);
}

int main()
{
    int d, ch; printf("Enter the root: ");
    scanf("%d", &d);
    struct node *root = create(d);
    printf("View the tree in:\n1. Preorder\n2. Inorder\n3. Postorder\n4. Exit");
    while(1)
    {
        printf("\nChoose the format: "); scanf("%d", &ch);
        if (ch == 4) {break;}
        switch (ch)
        {
        case 1: printf("The tree in preorder traversal is as follows:\n");preorder(root);break;
        case 2: printf("The tree in inorder traversal is as follows:\n");inorder(root); break;
        case 3: printf("The tree in postorder traversal is as follows:\n");postorder(root); break;
        default: printf("Invalid Choice!\n");
            break;
        }
    }

    printf("Thank you!\n");
    return 0;
}