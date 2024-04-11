User
#include <stdio.h>
#include <math.h>

int main()
{
    printf("Enter the number of rows and columns of first matrix: ");
    int c1, r1; scanf("%d%d", &r1, &c1);
    
    printf("Enter the number of rows and columns of second matrix: ");
    int c2, r2; scanf("%d%d", &r2, &c2);

    if (c1!=r2)
    { printf("Cannot multiply the matrices.\n"); }

    int a[r1][c1], b[r2][c2], pro[r1][c2];

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            pro[i][j]=0; int R1=0, C2=0, cr=0;
            while (R1<=r1 && C2<=c2)
            {
                while (cr<=r2)
                {
                    pro[i][j]+=a[R1][cr]*b[cr][C2];
                    cr++;
                }
                R1++; C2++;
            }
        }
        
    }
    
    printf("The product of the two matrices is as follows: \n");

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d", pro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
    
}



