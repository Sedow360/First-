#include<stdio.h>

int** generateMat(int r, int c)
{
    int **mat;
    mat=(int**)malloc(r*sizeof(*int));
    for (int i=0; i<r; i++)
    {
        mat[r]=(int*)malloc(c*sizeof(int));
    }

    return mat; 
}

void free(int** mat, int r)
{
    for (int i=0; i<r; i++) {free(mat[r]);}

    free(mat);
}

int** hori(int** mat, int r, int R, int c, int C, int k, int count)
{
    if (count==0) {return mat;}
    mat[r][c]=k;
    if (c<C) { return hori(mat, r, R, c+1, C, k+1, count-1);}
    else { return vert(mat, r+1, R-1, c+1, C-1, k+1, count-1);}
}

int** vert(int **mat, int r, int R, int c, int C, int k, int count)
{
    if (count==0) {return mat;}
    mat[r][c]=k;
    if (r<R) { return vert(mat, r+1, R, c, C, k+1, count-1);}
    else { return hori(mat, r+1, R-1, c+1, C-1, k+1, count-1);}
}

int main()
{
    printf("Enter the dimensions of the matrix: ");
    int r, c, r1=1, c1=1; scanf("%d%d", &r, &c);

    int a[r][c]=generateMat(r, c); int k=1; int count=r*c;

    
}