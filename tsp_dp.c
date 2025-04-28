#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void tsp(int n, int graph[][n], int start)
{
    int **dp = (int**)malloc((1<<n)*sizeof(int*));
    int **parent = (int**)malloc((1<<n)*sizeof(int*));
    for (int i=0; i<(1<<n); i++)
    {
        dp[i] = parent[i] = (int*)malloc(n*sizeof(int));
        for (int j=0; j<n; j++)
        {
            dp[i][j] = INT_MAX;
            parent[i][j] = -1;
        }
    }

    dp[1<<start][start] = 0;

    for (int size=2; size<=n; size++)
    {
        int count, mask;
        for (mask=1; mask<(1<<n); mask++)
        {
            count = 0;
            for (int j=0; j<n; j++)
            {
                if (mask & (1<<j)) count++;
            }
        
        if (count != size || !(mask & (1<<start))) continue;

        for (int u=0; u<n; u++)
        {
            if (!(mask & (1<<u))) continue;

            int prev_mask = mask^(1<<u);

            if (prev_mask == 0 && u != start) continue;

            for (int v=0; v<n; v++)
            {
                if (!(prev_mask & (1<<v)) || v==u) continue;

                if (dp[prev_mask][v] != INT_MAX && graph[v][u] != INT_MAX)
                {
                    int new = graph[v][u] + dp[prev_mask][v];
                    if (new < dp[mask][u])
                    {
                        dp[mask][u] = new;
                        parent[mask][u] = v;
                    }
                }
            }
        }
    }
}

    int final_mask = (1<<n) - 1;
    int min_cost = INT_MAX; int end_city = -1;

    for (int u = 0; u<n; u++)
    {
        if (u!=start && dp[final_mask][u] != INT_MAX && graph[u][start] != INT_MAX)
        {
            int cost = dp[final_mask][u] + graph[u][start];
            if (cost < min_cost)
            {
                min_cost = cost;
                end_city = u;
            }
        }
    }

    // Reconstruct the path
    printf("Optimal path: ");
    int curr_mask = final_mask;
    int curr_city = end_city;
    int *path = (int*)malloc((n + 1) * sizeof(int));
    int path_index = n - 1;
    
    path[n] = start;  // Return to start
    path[path_index--] = end_city;
    
    while (curr_city != start) {
        int prev_city = parent[curr_mask][curr_city];
        path[path_index--] = prev_city;
        curr_mask ^= (1 << curr_city);
        curr_city = prev_city;
    }
    
    for (int i = 0; i <= n; i++) {
        printf("%d", path[i]);
        if (i < n) printf(" -> ");
    }
    printf("\nTotal cost: %d\n", min_cost);
    
    // Free allocated memory
    free(path);
    for (int i = 0; i < (1 << n); i++) {
        free(dp[i]);
        free(parent[i]);
    }
    free(dp);
    free(parent);
}

int main()
{
    int n; printf("Enter no. of cities: ");
    scanf("%d", &n);

    int graph[n][n];
    printf("Enter adjacency matrix:\n");
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int start; printf("Start: ");
    scanf("%d", &start);

    tsp(n, graph, start);

    return 0;
}