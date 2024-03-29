#include<stdio.h>
#include<math.h>
int main(){
    int l;
    printf("Enter limit : ");
    scanf("%d", &l);
    int s=0;
    for (int i=1; i<=l; i++)
    {
        s=s+i;
    }
    printf("The sum is : %d \n", s);
      printf("The numbers used were : \n");
      for (int i=l; i>=1; i--)
      {
         printf("%d \n", i);
      }
    return 0;

}