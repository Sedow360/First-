#include<stdio.h>
#include<stdlib.h>

int sort_ascend(int a[], int n)
{
    int swap = 0;

    for (int i = 0; i < n-1 ; i++ )
    {
        int min, flag=0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (a[j]>a[j+1])
            {
                min=a[j+1];
                a[j+1]=a[j];
                a[j]=min; flag++; swap++;
            }
        }
        if (flag==0)
        {break;}
    }
    
    printf("The number of swaps required to sort the elements in ascending order is %d.\n", swap);
    
    return swap;
}

int sort_descend(int a[], int n)
{
    int swap = 0;

    for (int i = 0; i < n-1 ; i++ )
    {
        int min, flag=0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (a[j]<a[j+1])
            {
                min=a[j+1];
                a[j+1]=a[j];
                a[j]=min; flag++; swap++;
            }
        }
        if (flag==0)
        {break;}
    }
    
    printf("The number of swaps required to sort the elements in descending order is %d.\n", swap);
    
    return swap;
}

int main()
{
    int n; printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    int a[n], b[n];

    printf("Enter the elements:\n");

    for (int  i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    int sa = sort_ascend(a, n);
    int sd = sort_descend(b, n);
    
    if (sa>sd)
    {
        printf("The best way is to sort in descending order and swaps required is %d.\n", sd);
    }
    else
    {
        printf("The best way is to sort in ascending order and swaps required is %d.\n", sa);
    }

    return 0;
}