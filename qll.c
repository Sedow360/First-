#include<stdio.h>
#include<stdlib.h>
#define N 6
int p = 0;

struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL, *r = NULL;

struct node* create(int n)
{ 
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = n;
    new->next = NULL;
    return new;
}

int underflow()
{
    if (p == 0)
    {
        return 1; 
    }return 0;
}

int overflow()
{
    if (p == N)
    {
        return 1;
    }return 0;
}

void enQueue()
{
    if (overflow())
    {
        printf("Overflow!\n"); return;
    }
    int n; printf("Enter the value: ");
    scanf("%d", &n);

    struct node *t = create(n);

    if (underflow())
    {
        f = t; r = t;
    }
    else
    {
        r->next = t;
        r = r->next;
    }
    p++;
}

void deQueue()
{
    if (underflow())
    {
        printf("Underflow!\n"); return;
    }

    struct node *t = f;
    f = f->next;
    printf("The value dequeued is %d!\n", t->data);
    free(t); p--;
}

void print()
{
    struct node *t = f;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    int ch; printf("1. EnQueue\n2. DeQueue\n3. Print\n4. End\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch == 4) {break;}
        switch(ch)
        {
            case 1: enQueue(); break;
            case 2: deQueue(); break;
            case 3: print(); break;

            default: printf("Invalid input!\n"); break;
        }
    }

    printf("Thank you!\n");
    return 0;
}