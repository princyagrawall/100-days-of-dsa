#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int n, m, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize
    for(int i = 0; i < n; i++) {
        indegree[i] = 0;
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    // Add all nodes with indegree 0
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0)
            enqueue(i);
    }

    int topo[MAX], index = 0;

    while(!isEmpty()) {
        int node = dequeue();
        topo[index++] = node;

        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    // Check for cycle
    if(index != n) {
        printf("Cycle exists! Topological sort not possible.\n");
    } else {
        printf("Topological Order: ");
        for(int i = 0; i < n; i++)
            printf("%d ", topo[i]);
        printf("\n");
    }

    return 0;
}