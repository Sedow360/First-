#include<stdio.h>

int swap(int a, int b);//int _swap(int *a, int *b);

int main()
{ int a, b;
    scanf("%d%d", &a, &b );
    swap(a, b);
    //_swap(&a, &b);
    printf("The value of a is %d and that of b is %d\n", a, b);
}
//call by value
int swap(int a, int b)
{
    int t=0;
    t=a; a=b; b=t;
    printf("The value of a is %d and that of b is %d\n", a, b);
    return 0;

}

 //call by reference
/*int _swap(int *a, int *b)
{
    int t=0;
    t=*a; *a=*b; *b=t;
    printf("The value of a is %d and that of b is %d\n", *a, *b);
    return 0;

}*/