#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Min Heap Node
struct HeapNode {
    int vertex;
    int dist;
};

// Min Heap structure
struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

// Create new node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

// Swap heap nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(struct MinHeap* heap, int idx) {
    while (idx && heap->heap[(idx - 1)/2].dist > heap->heap[idx].dist) {
        swap(&heap->heap[(idx - 1)/2], &heap->heap[idx]);
        idx = (idx - 1)/2;
    }
}

// Heapify down
void heapifyDown(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < heap->size && heap->heap[left].dist < heap->heap[smallest].dist)
        smallest = left;

    if (right < heap->size && heap->heap[right].dist < heap->heap[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->heap[idx], &heap->heap[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Insert into heap
void push(struct MinHeap* heap, int v, int dist) {
    heap->heap[heap->size].vertex = v;
    heap->heap[heap->size].dist = dist;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// Extract min
struct HeapNode pop(struct MinHeap* heap) {
    struct HeapNode root = heap->heap[0];
    heap->heap[0] = heap->heap[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

// Dijkstra function
void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[MAX];

    struct MinHeap heap;
    heap.size = 0;

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(&heap, src, 0);

    while (heap.size > 0) {
        struct HeapNode top = pop(&heap);
        int u = top.vertex;

        struct Node* temp = graph->adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Main function
int main() {
    struct Graph graph;
    graph.V = 5;

    for (int i = 0; i < graph.V; i++)
        graph.adj[i] = NULL;

    addEdge(&graph, 0, 1, 2);
    addEdge(&graph, 0, 2, 4);
    addEdge(&graph, 1, 2, 1);
    addEdge(&graph, 1, 3, 7);
    addEdge(&graph, 2, 4, 3);
    addEdge(&graph, 3, 4, 1);

    dijkstra(&graph, 0);

    return 0;
}