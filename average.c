#include<stdio.h>
#include<math.h>
int main(){
    int  n1, n2, n3;
    
    printf("Enter the numbers: \n");
    scanf("%d%d%d", &n1, &n2, &n3);
    printf("The average is : %d", (n1+n2+n3)/3);
    return 0;
}