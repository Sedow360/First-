#include<stdio.h>

int string(char a[], int l);
int num(int n, int l);

int main()
{
    int c; printf("What would you like to reverse?\n['1' for string, '2' for number/Integer]\n");
    scanf(" %d", &c);
    printf("Enter the length of the string: ");
    int l; scanf("%d", &l);
    int n; char s[100];
    switch (c)
    {
    case 1: printf("Enter the string: ");
            scanf(" %s", s);
            string(s, l); 
            break;
    
    case 2: printf("Enter the number/integer: "); scanf(" %d", &n);
            num(n, l);
            break;
    
    default: printf("Incorrect input!");
        break;
    }

    return 0;
}

int string(char a[], int l)
{
    for (int i=0, j=l-1; i<=j; i++, j--)
    {
        char t=a[i];
        a[i]=a[j];
        a[j]=t;
    }

    printf("The reversed string is as follows: %s", a);

    return 0;
}

int num(int n, int l)
{
    int r=0, d=0;
    for (int i = l; i > 0; i--)
    {
        d=n%10;
        r=(r*10)+d;
        n=(n-d)/10;
    }
    printf("The reversed number/integer is: %d", r);

    return 0;
}