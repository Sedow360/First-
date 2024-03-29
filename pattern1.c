#include <stdio.h>

int increasing(int l)
{
   
        for( int h=1; h<=l; h++)
        {
            if (h == l && h%l == 0)
            {
                printf("*\n");
            }
            else
            {
                printf("  ");
            }
        }
    
    return 0;
}



int main()
{
    int l=0;
    printf("Enter the line limit: \n");
    scanf("%d", &l);
    for (int n=1; n<=l; n++)
    {
        int c=0;
        if (n%4 != 0)
        {
            
            increasing((n%4));
           
        
           
        }
        if (n%4 == 0)
        {
            printf("  ");printf("*\n");
            
        }
       
        

    }
   
    return 0;
}
