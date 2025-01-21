#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node
{
    int value; 
    struct Node* link;
};

struct Node* head = NULL;
int insf(int n);
int insl(int n);
int ins(int n, int p);
int print();

int main()
{
    int l, n; printf("Enter the number of elements: ");
    scanf("%d", &l);
    printf("Enter the values:\n");

    for (int i=0; i<l; i++)
    {
        scanf("%d", &n); insl(n);
    }

    for (;;)
    {
        printf("What is your order?\n");
        int c; scanf("%d", &c); int con = 0;

        switch(c)
        {
            case 1: scanf("%d", &n);insf(n); break;
            case 2: scanf("%d", &n); insl(n); break;
            case 3: printf("Where do you want to insert, before which element?\n"); int p; scanf("%d", &p);
                    scanf("%d", &n); ins(n, p); break;

            default: con++; break;
        }

        print();
        if (con!=0) {break;}
    }

    return 0;
}

int insf(int n)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->value = n;
    temp->link = head;

    head = temp;
    free(temp);

    return 0;
}

int insl(int n)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    while (head->link != NULL)
    {
        head = head->link;
    }

    temp->value = n;
    temp->link = NULL;
    head->link = temp;

    free(temp);

    return 0;
}

int ins(int n, int p)
{
    struct Node* pre = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    while (head->value != p)
    {
        pre = head;
        head = head->link;
    }

    temp->value = n;
    temp->link = head;
    pre->link = temp;

    free(pre);
    free(temp);

    return 0;
}

int print()
{
    printf("The list is as follows:\n");
    
    while (head->link != NULL)
    {
        printf("%d ", head->value);
    }

    return 0;
}