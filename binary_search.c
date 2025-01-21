#include<stdio.h>
#include<stdlib.h>

int main()
{
    int mid, t, l;
    printf("Enter the length of the sorted array: ");
    scanf("%d", &l);int a[l], ub=l-1, lb=0;

    for (int  i = 0; i < l; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &a[i]);
    }
    
    printf("Enter the value to be searched: ");
    scanf("%d", &t);

    while (lb<ub)
    {
        mid = (ub+lb)/2;
        if (a[mid]==t)
        {
            printf("The element %d is at index %d.\n", t, mid+1);
            break;
        }

        if (a[mid]>t)
        {ub=mid-1;}

        if (a[mid]<t)
        {lb=mid+1;}
    }

    return 0;

}