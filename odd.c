#include<stdio.h>
#include<math.h>

int main()
{
    int s, l;
    printf("Enter the starting and ending point :");
    scanf("%d%d", &s, &l);
    for (int i=s; i<=l; i++)
    {
        if (i%2 != 0)
        {
            printf("%d \n", i);
        }
        
    }
    return 0;

}