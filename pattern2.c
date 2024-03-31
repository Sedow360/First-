#include<stdio.h>
#include<cs50.h>

int main()
{
    printf("Enter the limit: ");
    int w= 0;scanf("%d", &w);
    int n=1; int c=1;
    
    for (int i=w; i>=1; i--)        //for controlling rows
    {  
        for (int sp=w-1; sp>=i; sp--)     //for printing spaces
        {
            printf(" ");
        }

        for (int s=1; s<=i; s++)   //for printing the numbers
        {
            if (n<=9)
            {printf("%d ", n); n++;}    //for numbers<9

            else      //when numbers > 9
            {
            if (c%2==0)
            {printf("9 "); c++;}

            else 
            {printf("0 "); c++;}
            }
            
        }
        //if (i>1){printf("\n");}   //for moving to the next line
        printf("\n");
     //for the descend
    }

c=1;
    
   for (int i=1; i<w; i++)   //for the ascending block
   {
    for (int sp = 2; sp <=w-i; sp++)   //for spaces
    {
        printf(" ");
    }

    for (int s = 1; s<=i+1; s++)    //for numbers
    {
        if (c%2==0)
        {printf("9 "); c++;}
        
        else {printf("0 "); c++;}
    }

    printf("\n");
   }
    return 0;

}
