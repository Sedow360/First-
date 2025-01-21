#include<stdio.h>
#include<math.h>

int prime(int n)
{
    int c=0;
    for (int i=1; i<=n; i++)
    {
        if (n%i==0) {c++;}
    }    //5
    if (c==2) {return 1;}
    else {return 0;}
} 

int sum(int lb, int ub)
{    //6
    if (lb==ub)
    {
        return lb;
    }
    return ub+sum(lb, ub-1);
}

int hcf(int n1, int n2)
{
    if (n2!=0)    //4
    {
        return hcf(n2, n1%n2);
    }
    else {return n1;}
}
int main()
{
    /*int n, n1=0, n2=1, s=0; printf("Enter the limit: "); scanf("%d", &n);
    for (int i=0; i<n; i++)  //2
    {
        s=n1+n2;
        n1=n2; 
        n2=s;
        printf("%d ", n2);
    }*/

    /*int lb, ub; printf("Enter the range: ");
    scanf("%d%d", &lb, &ub);    //5
    for (int i=lb; i<=ub; i++)
    {
        if (prime(i)==1)
        {printf("%d is a prime number.\n", i);}
    }*/
    
    int lb, ub; printf("Enter the upper and lower bounds: ");
    scanf("%d %d", &lb, &ub);     //6
    printf("The sum of natural numbers between %d and %d is %d.\n", lb, ub, sum(lb, ub));

    /*int l, n, c=0; printf("Enter the length of the array: "); scanf("%d", &l);
    int a[l];  //3
    printf("Enter the values for index no.\n");
    for (int i=0; i<l; i++)
    {
        printf("Index no. %d: ", i+1); scanf("%d", &a[i]);
    }
    printf("Enter the value to be searhed for: "); scanf("%d", &n);
    for (int j=0; j<l; j++)
    {
        if (a[j]==n)   
        {
            printf("The value %d appears at index no. %d.\n", n, j+1); c++;
        }
    }
    if (c==0)
    {
        printf("The value is not present in the array.\n");
    }*/

    /*int n1, n2; printf("Enter the two numbers: ");
    scanf("%d %d", &n1, &n2);   //4
    printf("The HCF of %d and %d is %d.\n", n1, n2, hcf(n1, n2));*/

    return 0;
}