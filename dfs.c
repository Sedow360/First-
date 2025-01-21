#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int v[MAX_VERTICES], vs = -1; // Array to keep track of visited vertices
int visited[MAX_VERTICES]; // Visited array for DFS and BFS

void depthfs(int a[MAX_VERTICES][MAX_VERTICES], int n, int start) {
    int stack[MAX_VERTICES], top = -1; // Stack for DFS
    stack[++top] = start; // Push the starting vertex onto the stack

    while (top >= 0) {
        int current = stack[top--]; // Pop the top vertex from the stack

        if (!visited[current]) { // If the vertex is not visited
            visited[current] = 1; // Mark it as visited
            v[++vs] = current; // Add to visited list

            // Push all adjacent vertices onto the stack
            for (int i = n - 1; i >= 0; i--) { // Reverse order for correct traversal
                if (a[current][i] && !visited[i]) { // Check for edges and if not visited
                    stack[++top] = i; // Push adjacent vertex onto the stack
                }
            }
        }
    }
}

void breadthfs(int a[MAX_VERTICES][MAX_VERTICES], int n, int start) {
    int queue[MAX_VERTICES], front = -1, rear = -1;
    int local_visited[MAX_VERTICES] = {0}; // Local visited for BFS

    queue[++rear] = start; // Enqueue the starting vertex
    local_visited[start] = 1; // Mark it as visited

    while (front != rear) {
        front++;
        int current = queue[front]; // Dequeue the front vertex
        v[++vs] = current; // Add to visited list

        // Enqueue all adjacent vertices
        for (int i = 0; i < n; i++) {
            if (a[current][i] && !local_visited[i]) { // Check for edges and if not visited
                queue[++rear] = i; // Enqueue adjacent vertex
                local_visited[i] = 1; // Mark it as visited
            }
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    int n; 
    scanf("%d", &n);

    int a[MAX_VERTICES][MAX_VERTICES] = {0}; // Initialize adjacency matrix

    for (int i = 0; i < n; i++) {
        printf("Enter the joints for vertex %d (space-separated, end with -1): ", i);
        int j;
        while (1) {
            scanf("%d", &j);
            if (j == -1) break; // Stop input on -1
            a[i][j] = 1; // Mark the edge
        }
    }

    printf("1: DFS\n2: BFS\n3: Exit\n");
    int ch, p;
    while (1) {
        printf("Enter the choice: ");
        scanf("%d", &ch);

        if (ch == 3) {
            break;
        }

        printf("Enter the vertex to begin with: ");
        scanf("%d", &p);

        // Reset visited and vs for each traversal
        for (int i = 0; i < MAX_VERTICES; i++) {
            visited[i] = 0;
        }
        vs = -1;

        switch (ch) {
            case 1: 
                depthfs(a, n, p); 
                break;
            case 2: 
                breadthfs(a, n, p); 
                break;
        }

        printf("The visited path is: ");
        for (int i = 0; i <= vs; i++) {
            printf("%d ", v[i]);
        }
        printf("\n");
    }
    printf("Thank you!\n");
    return 0;
}