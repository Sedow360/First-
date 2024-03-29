#include<stdio.h>
#include<math.h>

int main()
{
    int x, *ptr=&x;
    int **pptr=&ptr;
    x=9;
    printf("%u\n", ptr);
    printf("%d\n", *pptr);
    printf("%d\n", **pptr);
    printf("%p\n", pptr);
    /**ptr=0;
    printf("%d\n", x);
    printf("%d\n", *ptr);

    *ptr += 5;
    printf("%d\n", x);
    printf("%d\n", *ptr);

    (*ptr)++;
    printf("%d\n", x);
    printf("%d\n", *ptr);
    printf("%p\n", ptr);
    printf("%u\n", ptr);*/

    return 0;
}