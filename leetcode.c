#include<stdio.h>
#include<stdlib.h>
/*
typedef struct
{
    int min, max;
}minMax;

minMax findMinMax(int a[], int lb, int ub)
{
    minMax result, left, right;
    if (lb == ub)
    {
        result.min = result.max = a[lb];
        return result;
    }

    if (lb + 1 == ub)
    {
        result.min = (a[lb] < a[ub]) ? a[lb] : a[ub];
        result.max = (a[lb] > a[ub]) ? a[lb] : a[ub];
        return result;
    }

    int mid = lb + ((ub-lb)/2);
    left = findMinMax(a, lb, mid);
    right = findMinMax(a, mid+1, ub);

    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;
    return result;
}

int main()
{
    int a[] = {65};
    int l = sizeof(a)/sizeof(a[0]);

    minMax result = findMinMax(a, 0, l-1);

    printf("Min: %d, Max: %d\n", result.min, result.max);
    return 0;
}
*/


int calcCost(int dim[], int i, int j, int** mem)
{
    if (i == j)
    return 0;

    if (mem[i][j] != -1)
    return mem[i][j];

    int minCost = __INT_MAX__, cost = 0;

    for (int k = i; k<j; k++)
    {
        cost = calcCost(dim, i, k, mem) + calcCost(dim, k+1, j, mem) + dim[i-1]*dim[k]*dim[j];

        if (cost < minCost)
        minCost = cost;
    }

    mem[i][j] = minCost;
    return minCost;
}

int memo(int dim[], int n)
{
    int** mem = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i<n; i++)
    {
        mem[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j<n; j++)
        {
            mem[i][j] = -1;
        }
    }

    int cost = calcCost(dim, 1, n-1, mem);

    for (int i =0; i<n; i++)
    {
        free(mem[i]);
    }
    free(mem);

    return cost;
}

int main()
{
    int dim[] = {40, 20, 30, 10};
    int mat = sizeof(dim)/sizeof(dim[0]) -1;

    printf("%d", memo(dim, mat +1));

    return 0;
}