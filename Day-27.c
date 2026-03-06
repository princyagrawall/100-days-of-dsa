#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create linked list
struct node* createList(int n) {
    struct node *head = NULL, *temp, *newnode;
    int val;

    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

// Function to find length
int length(struct node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection
void findIntersection(struct node *h1, struct node *h2) {
    int l1 = length(h1);
    int l2 = length(h2);

    int diff;

    if(l1 > l2) {
        diff = l1 - l2;
        while(diff--) h1 = h1->next;
    } else {
        diff = l2 - l1;
        while(diff--) h2 = h2->next;
    }

    while(h1 != NULL && h2 != NULL) {
        if(h1->data == h2->data) {
            printf("%d", h1->data);
            return;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    printf("No Intersection");
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct node *head1 = createList(n);

    scanf("%d", &m);
    struct node *head2 = createList(m);

    findIntersection(head1, head2);

    return 0;
}