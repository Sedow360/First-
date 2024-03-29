#include<stdio.h>
#include<math.h>

int main()
{
    int n, p=1;
    printf("Enter the number :");
    scanf("%d", &n);
    for (int i=n; n>=1; n--)
    {
        p*=n;
    }
    printf("%d", p);
    return 0;

}