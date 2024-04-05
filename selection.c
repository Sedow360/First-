#include<stdio.h>

int main()
{
    int n;printf("Input the number of values: ");
    scanf("%d", &n);
    int a[n];int min;
    for (int i=0; i< n; i++)
    {
        printf("Enter the digit for index no. %d: ", i+1);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) //for moving forward in the unsorted sub-array; i=unsorted
    {
        int temp=a[i];  int j=i-1;
        while (j>=0 && a[j]>temp)   //for moving backwards in the sorted sub-array; j=sorted
        {
            a[j+1]=a[j]; j--;
        }
        a[j+1]=temp;
    }

    printf("The sorted array is as follows: ");
    for (int  i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
    
}