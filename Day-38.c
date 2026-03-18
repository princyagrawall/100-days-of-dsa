#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int empty() {
    return (front == -1);
}

// Size
int size() {
    if (empty()) return 0;
    return (rear - front + 1);
}

// Push front
void push_front(int x) {
    if (front == 0) {
        printf("Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        front--;
    }
    deque[front] = x;
}

// Push back
void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

// Pop front
void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// Pop back
void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

// Get front
void get_front() {
    if (empty()) printf("-1\n");
    else printf("%d\n", deque[front]);
}

// Get back
void get_back() {
    if (empty()) printf("-1\n");
    else printf("%d\n", deque[rear]);
}

// Display deque
void display() {
    if (empty()) return;

    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
}

// Main
int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'p' && op[5] == 'f') {        // push_front
            scanf("%d", &x);
            push_front(x);
        }
        else if (op[0] == 'p' && op[5] == 'b') {   // push_back
            scanf("%d", &x);
            push_back(x);
        }
        else if (op[0] == 'p' && op[4] == 'f') {   // pop_front
            pop_front();
        }
        else if (op[0] == 'p' && op[4] == 'b') {   // pop_back
            pop_back();
        }
        else if (op[0] == 'f') {                  // front
            get_front();
        }
        else if (op[0] == 'b') {                  // back
            get_back();
        }
        else if (op[0] == 's') {                  // size
            printf("%d\n", size());
        }
        else if (op[0] == 'e') {                  // empty
            printf("%d\n", empty());
        }
    }

    return 0;
}