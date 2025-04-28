#include<stdio.h>
#include<stdlib.h>

int N;
int sol = 1;
int is_safe(int ans[], int row, int col)
{
    for (int i=0; i<row; i++)
    {
        if (ans[i] == col || abs(ans[i] - col) == abs(i - row))
        return 0;
    }
    return 1;
}

void n_queens(int ans[N], int row)
{
    if (row==N)
    {
        printf("Solution %d:\n", sol);
        for (int i=0; i<N; i++)
        {
            printf("Queen %d: (%d, %d)\n", i+1, i+1, ans[i]+1);
        }
        sol++;
    }
    for (int col=0; col<N; col++)
    {
        if (is_safe(ans, row, col))
        {
            ans[row] = col;
            n_queens(ans, row+1);
            //resetting move
            ans[row] = -1;
        }
    }
}

int main()
{
    printf("Number of queens: ");
    scanf("%d", &N);

    int* ans = (int*)malloc(N*sizeof(int));
    for(int i=0; i<N; i++)
        ans[i] = -1;
    n_queens(ans, 0);

    free(ans);
    return 0;
}