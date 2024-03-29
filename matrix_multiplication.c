User
#include <stdio.h>
#include <math.h>

void transpose2 (float b[2][2]);
void transpose3 (float b[3][3]);
int two_p();
int three_p();


int main()
{
    printf("Enter the order of matrices: ");
    int n=0; scanf("%d", &n);
    switch (n)
    {
    case 2: two_p();
        break;
    case 3: three_p();
        break;

    default: printf("In future, when I'll be smart enough, Maybe....");
        break;
    }
    return 0;
    
}


void transpose2( float b[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j=0; j < 2; j++)
        {
            float t=0;
            if (i==j)
            {
                continue;
            }
            t=b[i][j];
            b[i][j]= b[j][i];
            b[j][i]= t;
        }
    }
}

void transpose3(float b[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j=0; j < 3; j++)
        {
            float t=0;
            if (i==j)
            {
                continue;
            }
            t=b[i][j];
            b[i][j]= b[j][i];
            b[j][i]= t;
        }
    }
}

/*int two_p()
{
    float a[2][2], b[2][2], pro[2][2];
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2; j++)
        {
            printf("Enter the digit for %d row and %d column of first matrix: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2; j++)
        {
            printf("Enter the digit for %d row and %d column of second matrix: ", i, j);
            scanf("%f", &b[i][j]);
        }
    }

    transpose2(b);

    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2; j++)
        { 
            float r=0;
              for (int k=0; k<2; k++)
              {
                r+=a[i][k]*b[j][k];
              }
            pro[i][j]=r;
        }
    }
    printf("The product of the two given matrices is:\n");
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2; j++)
        {
            printf("%f ", pro[i][j]);
        }
        printf("\n");
    }
    return 0;

}*/
int two_p() {
    float a[2][2], b[2][2], pro[2][2];

    // Input matrices a and b
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Enter element A[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Enter element B[%d][%d]: ", i, j);
            scanf("%f", &b[i][j]);
        }
    }

    transpose2(b);

    // Multiplication loop
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            float r = 0;
            for (int k = 0; k < 2; k++) {
                r += a[i][k] * b[j][k];
            }
            pro[i][j] = r;
        }
    }

    // Output the result pro
    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f ", pro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int three_p()
{
    float a[3][3], b[3][3], pro[3][3];
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            printf("Enter the digit for %d row and %d column of first matrix: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            printf("Enter the digit for %d row and %d column of second matrix: ", i, j);
            scanf("%f", &b[i][j]);
        }
    }

    transpose3(b);

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        { 
            float r=0;
              for (int k=0; k<3; k++)
              {
                r+=a[i][k]*b[j][k];
              }
            pro[i][j]=r;
        }
    }
    printf("The product of the two given matrices is:\n");
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            printf("%f ", pro[i][j]);
        }
        printf("\n");
    }
    return 0;

}
