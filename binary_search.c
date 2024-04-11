#include<stdio.h>
#include<stdlib.h>

int main()
{
     int l, t;
    printf("Enter the length of the sorted array: ");
    scanf("%d", &l);int a[l];

    for (int  i = 0; i < l; i++)
    {
        printf("Enter the value for %d index: ", i+1);
        scanf("%d", &a[i]);
    }
    
    printf("Enter the value to be searched: ");
    scanf("%d", &t);
    l=sizeof(a);

    for (int i=l/2; i<l; i++)
    {
        if (a[l/2]>t)
        {
            l/=2;i=0;
        }
        
        else if (a[l/2]<t)
        {
            i=l/2;
        }

        else if(t==a[i])
        {
            printf("The index of %d is %d in the given array.", t, i); break;
        }
    }

    return 0;

}