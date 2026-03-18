#include <stdio.h>

#define MAX 1000

int heap[MAX];
int size = 0;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up (after insert)
void heapifyUp(int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (heap[parent] > heap[index]) {
        swap(&heap[parent], &heap[index]);
        heapifyUp(parent);
    }
}

// Heapify Down (after extract)
void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert element into heap
void insert(int x) {
    if (size == MAX) return;
    heap[size] = x;
    heapifyUp(size);
    size++;
}

// Extract minimum element
int extractMin() {
    if (size == 0) return -1;

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);

    return root;
}

// Peek minimum element
int peek() {
    if (size == 0) return -1;
    return heap[0];
}

// Driver Code
int main() {
    int N;
    scanf("%d", &N);
    char op[20];
    int val;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);
        if (op[0] == 'i') { // insert
            scanf("%d", &val);
            insert(val);
        } else if (op[0] == 'p') { // peek
            printf("%d\n", peek());
        } else if (op[0] == 'e') { // extractMin
            printf("%d\n", extractMin());
        }
    }

    return 0;
}