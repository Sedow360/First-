#include <stdio.h>

int fibonacci(int n)
{
    if(n==0)
    {
    return 0;
    }
    if(n==1)
    {
    return 1;
    }
    int sum=fibonacci(n-1)+fibonacci(n-2);
    //int ans= sum+n;
    //printf("%d\n", sum);
    return sum;

}

int main()
{
    /*printf("Enter the limit:");
    int l=0;
    scanf("%d", &l);
    for (int i=1; i<=l; i++)
    {
        printf("%d ", fibonacci(i));
    }*/

    int n, n1=0, n2=1, s=0; printf("Enter the limit: "); scanf("%d", &n);
    for (int i=0; i<n; i++)  //without recursion
    {
        printf("%d ", n2);
        s=n1+n2;
        n1=n2; 
        n2=s;
    }

    return 0;
}