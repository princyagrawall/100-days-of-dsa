#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Initialize queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(struct Queue* q, int data) {
    struct Node* temp = newNode(data);
    if (q->rear == NULL) {  // Empty queue
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue operation
int dequeue(struct Queue* q) {
    if (q->front == NULL) return -1; // Empty queue

    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) // Queue became empty
        q->rear = NULL;

    free(temp);
    return data;
}

// Driver code
int main() {
    int N;
    scanf("%d", &N);

    struct Queue* q = createQueue();
    char op[20];
    int val;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);
        if (op[0] == 'e') {  // enqueue
            scanf("%d", &val);
            enqueue(q, val);
        } else if (op[0] == 'd') { // dequeue
            printf("%d\n", dequeue(q));
        }
    }

    return 0;
}