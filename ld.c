#include<stdio.h>
#include<stdlib.h>

int ins(int* a, int n, int p, int l);
int del(int *a, int n, int l);

int main()
{
    int l, i, co=0;
    printf("Enter the length of the array: ");
    scanf("%d", &l);
    printf("Enter the elements:\n");
    int *a = (int*)calloc(l, sizeof(int));

    for (i=0; i<l; i++)
    {
        scanf("%d", a+i);
    }

    printf("1: To insert an element in a desired position\n2: To delete an element already in the array\nChoose: ");
    int c; scanf("%d", &c);

    switch(c)
    {
        case 1: printf("Enter the value and the desired position: ");
                int n, p; scanf("%d%d", &n, &p);
                co=ins(a, n, p-1, l+1);
                break;

        case 2: printf("Enter the element to be deleted: ");
                int e; scanf("%d", &e);
                co=del(a, e, l);
                break;

        default: printf("Invalid output!\n");
                break;
    }

    printf("The modified array is as follows: ");
    for (i=0; i<l-co; i++)
    {
        printf("%d ", *(a+i));
    }
    printf("\n");

    free(a);

    return 0;
}

int ins(int *a, int n, int p, int l)
{
    (int*)realloc(a, l*sizeof(int));
    int i;

    for (i=l-1; i>p; i--)
    {
        *(a+i)=*(a+i-1);
    }

    *(a+i)=n;

    /*printf("The modified array is as follows: ");
    for (i=0; i<l; i++)
    {
        printf("%d ", *(a+i));
    }
    printf("\n");*/

    return 0;
}

int del(int *a, int n, int l)
{
    int i, j, co=0; 

    for (i = 0; i < l; i++) 
    {
        if (a[i] == n) 
        {
            co++;
        } 
        else 
        {
            a[i - co] = a[i];
        }
    }

    /*printf("The modified array is as follows: ");
    for (i=0; i<l-co; i++)
    {
        printf("%d ", *(a+i));
    }
    printf("\n");*/

    return co;
}