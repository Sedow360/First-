#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int n, graph[MAX][MAX], path[MAX];

int safe(int t, int pos)
{
    if (pos == n-1 && graph[t][path[0]] == 0)
    return 0;

    if (pos > 0 && graph[path[pos-1]][t] == 0)
    return 0;

    for (int i=0; i<pos; i++)
    {
        if (t==path[i])
        return 0;
    }

    return 1;
}

void printPath()
{
    printf("Path:\n");
    for (int i=0; i<n; i++)
    printf("%d ", path[i]);

    printf("-> %d\n", path[0]);
}

void hamiltonian(int pos)
{
    if (pos == n)
    {
        printPath();
        return;
    }
    for (int i=0; i<n; i++)
    {
        if (safe(i, pos))
        {
            path[pos] = i;
            hamiltonian(pos+1);
            path[pos] = -1;
        }
    }
}

int main()
{
    printf("Number of vertices: ");
    scanf("%d", &n);

    printf("Enter the edges:\n");
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
        path[i] = -1;
    }

    int start; printf("Start: ");
    scanf("%d", &start);

    path[0] = start;
    hamiltonian(1);

    return 0;
}