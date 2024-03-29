#include<stdio.h>


int main(){
    int n1, n2;
    printf("Enter the numbers: ");
    scanf("%d %d", &n1, &n2);
    
    if(n1>>n2)
    { printf("%d is the smallest number", n2);} 
    else if(n2>>n1)
    {  printf("%d is the smallest number", n1); }
    
return 0;

}