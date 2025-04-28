#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int V;

typedef struct edge
{
    int u, v, weight;
}edge;

int cycle(int parent[], int u, int v)
{
    int t = u;
}
void kruskal(int graph[][V], int ans[][V])
{
    int parent[V], visited[V], edge_Count = 0;
    edge arr[V*V];

    for (int i=0; i<V; i++)
    {
        parent[i] = -1, visited[i] = 0;
        for (int j=i+1; j<V; j++)
        {
            arr[edge_Count].u = i, arr[edge_Count].v = j;
            arr[edge_Count].weight = graph[i][j];
            edge_Count++;
        }
    }

    qsort(arr, edge_Count, sizeof(edge), compare);

    for (int i=0; i<edge_Count; i++)
    {
        int curr = arr[i].weight, p = arr[i].u, q = arr[i].v;
        parent[q] = p;
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

    kruskal(graph, ans);
    return 0;
}