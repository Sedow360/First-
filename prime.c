#include<stdio.h>
#include<math.h>

int main()
{
    int l, c=0;
    printf("Enter limit :");
    scanf("%d \n", &l);
    for ( int i=2; i<=l; i++)
    {
        for (int j=1;j<=i;j++)
        {
            if(i%j==0){c++;}

        
    }
    if (c<=2)
        {printf("%d\n", i);}
        c=0;
        
        }return 0;
}
        

    
