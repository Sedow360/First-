#include<stdio.h>
#include<stdlib.h>
#define N 6
int a[N], f = 0, r = -1;

int overflow()
{
    if (r == N-1)
    {return 1;}
    return 0;
}

int underflow()
{
    if (r<f)
    {return 1;}
    return 0;
}

void enQueue()
{
    if (overflow())
    {
        printf("Overflow!\n"); return;
    }
    int n; printf("Enter the value: ");
    scanf("%d", &n);

    if (underflow())
    {
        a[f] = n;
        r = f;
    }
    else
    {
        a[++r] = n;
    }
}

void deQueue()
{
    if (underflow())
    {
        printf("Underflow!\n"); return;
    }
    //for circular queue
    printf("The value dequeued is %d!\n", a[f]);
    for (int i = f; i<r; i++)
    {
        a[i] = a[i+1];
    }
    r--; return;
    //
    printf("The value dequeued is %d!\n", a[f++]);
}

void print()
{
    for (int i = f; i<=r; i++)
    {
        printf("%d ", a[i]);
    }
    //for circular queue
    printf(" -> %d", a[f]);
    //
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