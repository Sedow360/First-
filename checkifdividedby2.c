#include<stdio.h>
#include<math.h>

int main(){
    int a;
    printf("enter a number :");
    scanf("%d", &a);
    printf( "%d", (a%2) == 0);
    return 0;

}