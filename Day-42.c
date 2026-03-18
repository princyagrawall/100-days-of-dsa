#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Queue structure
struct Queue {
    int arr[MAX];
    int front, rear;
};

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Queue functions
void enqueue(struct Queue* q, int x) {
    q->rear++;
    q->arr[q->rear] = x;
}

int dequeue(struct Queue* q) {
    if (q->front > q->rear) return -1; // empty
    int val = q->arr[q->front];
    q->front++;
    return val;
}

// Stack functions
void push(struct Stack* s, int x) {
    s->top++;
    s->arr[s->top] = x;
}

int pop(struct Stack* s) {
    if (s->top == -1) return -1; // empty
    int val = s->arr[s->top];
    s->top--;
    return val;
}

// Driver code
int main() {
    int N;
    scanf("%d", &N);

    struct Queue q;
    q.front = 0;
    q.rear = -1;

    struct Stack s;
    s.top = -1;

    // Read queue elements
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    // Step 1: Push all elements of queue into stack
    for (int i = q.front; i <= q.rear; i++)
        push(&s, q.arr[i]);

    // Step 2: Pop from stack and overwrite queue
    for (int i = q.front; i <= q.rear; i++)
        q.arr[i] = pop(&s);

    // Print reversed queue
    for (int i = q.front; i <= q.rear; i++)
        printf("%d ", q.arr[i]);
    printf("\n");

    return 0;
}