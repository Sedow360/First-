#include <stdio.h>

int main()
{
    int a[5];
    int *p= &a[0];
    for (int i=0; i<=4; i++)
    {
        printf("Enter aadhar index %d: ", i+1);
        scanf("%d", (p+i));
    }

    for (int j=0; j<=4; j++)
    {
        printf("Aadhar index %d is %d\n", j+1, a[j]);
    }
     return 0;
}
