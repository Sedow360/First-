#include <stdio.h>
#include<stdlib.h>
#include<string.h>

/*int dec(int n, int d, int step)
{
    if(n==0) {return step;}
    int max, temp, n1=n-d;
    temp=n1;
    max=n1%10;
    while (temp!=0)
    {
        if(temp%10>max)
        {
            max=temp%10;
        }
        d=temp%10; temp=(temp-d)/10;
    }
    step++;
    return dec(n1, max, step);
}
int main()
{
    int n, step=0, d, max;
    printf("Enter the number: ");
    scanf("%d", &n);
    /*while (n!=0)
    {
        max=n%10;
        while (n!=0)
        {
            d=n%10;
            if(max<d) {max=d;}
            n=n/10;
        }
        n=n-max;
        step++;
    } 
    printf("The minimum no. of steps required are: %d.\n", dec(n, n%10, 0));
    return 0;
}*/

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        int k=0;
        for (int j = 0; j < n; j++)
        { 
            if (k<i) {printf("%d ", n-k); k++;}
            else {printf("%d ", n-k);}
        }
        for (int j = n; j < 2*n-1; j++)
        { 
            if(j>=2*n-i-1) {k--;}
            printf("%d ", n-k);
        }
        printf("\n");
    }
    for (int i = n-1; i > 0; i--)
    {
        int k=0;
        for (int j = 0; j < n; j++)
        { 
            if (k<i-1) {printf("%d ", n-k); k++;}
            else {printf("%d ", n-k);}
        }
        for (int j = n; j < 2*n-1; j++)
        { 
            if(j>2*n-i-1) {k--;}
            printf("%d ", n-k);
        }
        printf("\n");
    }
    
    
    return 0;
}