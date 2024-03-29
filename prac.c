#include<stdio.h> 
//int printchar();
int printarrayreverse(int a[]);

int main()
{
    // printchar();
    int a[]={5, 4, 6, 9};
    printarrayreverse(a);

return 0;
}


/*int printchar()
{
    for (int i=65; i<=90; i++)
    { char a=i;
        printf("%c\n", a);
    }
    return 0;
    
}*/
int printarrayreverse(int a[])
{
    
    for (int i=3; i>=0; i--)
    {
        printf("%d ", a[i]);
    }
    return 0;
}