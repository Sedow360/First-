#include<stdio.h>
#include<cs50.h>

int main()
{
    printf("Enter the maximum width of the diamond: ");
    int w= 0;scanf("%d", &w);
    for (int i=1; i<=w; i++)   //for controlling rows
    {
        for (int sp=1; sp<=w-i; sp++)  //for printing spaces
        {
            printf(" ");
        }

        for (int s=1; s<=i; s++)     //for printing the stars
        {
            printf("* ");
        }    

        printf("\n");   //for going next line
    }                         //for the upper part of the diamond

    for (int i=w-1; i>=1; i--)        //for controlling rows
    {
        for (int sp=w-1; sp>=i; sp--)     //for printing spaces
        {
            printf(" ");
        }

        for (int s=1; s<=i; s++)   //for printing the stars
        {
            printf("* ");
        }

        printf("\n");   //for moving to the next line
    }       //for thr lower part of the diamond
    return 0;

}
