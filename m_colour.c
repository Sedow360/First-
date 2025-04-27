#include<stdio.h>
int n, graph[20][20], colours[20], m;

int complete()
{
    for (int i=0; i<n; i++)
    {
        if (colours[i] == -1)
        return 0;
    }

    return 1;
}
int safe(int pos)
{
    for (int i=0; i<n; i++)
    {
        if ((graph[i][pos] > 0 || graph[pos][i] >0) && colours[pos] == colours[i])
        return 0;
    }

    return 1;
}

void print()
{
    printf("Combinations:\n");
    for (int i=0; i<n; i++)
    printf("Vertex %d -> Color %d\n", i, colours[i]);
}

void colouring(int pos)
{
    if (complete())
    {
        print();
        return;
    }

    for (int t=0; t<m; t++)
    {
        colours[pos] = t;
        if (safe(pos))
        {
            colouring(pos+1);
        }
        colours[pos] = -1;
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
        colours[i] = -1;
    }

    printf("Enter number of colours: ");
    scanf("%d", &m);
    
    colouring(0);

    return 0;
}