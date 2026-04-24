#include <stdio.h>
#include <limits.h>

#define MAX 100

int n;
int graph[MAX][MAX];

// Function to find the vertex with minimum key value
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 1; v <= n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int primMST() {
    int parent[MAX];   // Stores MST
    int key[MAX];      // Minimum weights
    int mstSet[MAX];   // Included in MST

    // Initialize
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[1] = 0;      // Start from node 1
    parent[1] = -1;

    for (int count = 1; count < n; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Calculate total weight
    int total = 0;
    for (int i = 2; i <= n; i++) {
        total += key[i];
    }

    return total;
}

int main() {
    int m, u, v, w;

    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // Undirected
    }

    int result = primMST();
    printf("%d\n", result);

    return 0;
}