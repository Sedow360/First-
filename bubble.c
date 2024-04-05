#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    int a[n];

    for (int  i = 0; i < n; i++)
    {
        printf("Enter the value for index no. %d : ", i+1);scanf("%d", &a[i]);
    }

    for (int i = 0; i<n-1 ; i++ )
    {
        int flag=0, min;
        for (int j = 0; j < n-1-i; j++)
        {
            if (a[j]>a[j+1])
            {
                min=a[j+1];
                a[j+1]=a[j];
                a[j]=min;flag++;
            }
        }
        if (flag==0)
        {break;}
    }
    
    printf("The sorted array is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
    return 0;
}