#include<stdio.h>
#include<limits.h>
int V;

int find_min(int key[], int visited[])
{
    int min = INT_MAX, mindex;
    for (int i=0; i<V; i++)
    {
        if (!visited[i] && key[i] < min)
        {
            min = key[i]; mindex = i;
        }
    }

    return mindex;
}

int prim(int graph[][V], int ans[][V])
{
    int key[V], visited[V];

    for (int i=0; i<V; i++)
    {
        key[i] = INT_MAX, visited[i] = 0;
    }

    key[0] = 0;

    for (int c=0; c<V-1; c++)
    {
        int u = find_min(key, visited);
        visited[u] = 1;

        for (int v=0; v<V; v++)
        {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                ans[u][v] = ans[v][u] = key[v] = graph[u][v];
            }
        }
    }

    printf("Minimum spanning tree:\n");
    for (int i=0; i<V; i++)
    {
        for (int j=0; j<V; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("Number of vertices: ");
    scanf("%d", &V);

    int graph[V][V], ans[V][V];
    printf("Adjacency matrix:\n");
    for (int i=0; i<V; i++)
    {
        for (int j=0; j<V; j++)
        {
            scanf("%d", &graph[i][j]);
            ans[i][j] = 0;
        }
    }

    prim(graph, ans);
    return 0;
}