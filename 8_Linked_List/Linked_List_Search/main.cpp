#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*first = NULL;

// Function to create a linked list
void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
// q is a tail pointer
// Function to search a linked list iteratively
struct Node* LSearch(struct Node *p, int key) {
    struct Node *q = NULL; // Initialize a pointer to keep track of previous node
    while(p != NULL) {
        if(key == p->data) {
            q->next = p->next; // Remove the found node from its current position
            p->next = first; // Insert the found node at the beginning
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

// Function to search a linked list recursively
struct Node* RSearch(struct Node *p, int key) {
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    return RSearch(p->next, key);
}

int main() {
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);
    temp = LSearch(first, 8); // Search for the key 8 in the linked list
    printf("%d", temp->data);
    return 0;
}
