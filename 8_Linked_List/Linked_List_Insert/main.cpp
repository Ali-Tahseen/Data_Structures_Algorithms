#include <stdio.h>
#include <stdlib.h>

// Define structure for node
struct Node {
    int data;
    struct Node *next;
} *first = NULL;

// Function to create linked list
void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    // Create the first node
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    // Traverse the array and create nodes for the remaining elements
    for (i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Function to display the linked list
void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Function to count the number of nodes in the linked list
int count(struct Node *p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

// Function to insert a node at a specified index
void Insert(struct Node *p, int index, int x) {
    struct Node *t; // for creating new node we take a pointer t
    int i;
    // Check if index is valid
    if (index < 0 || index > count(p)) // if index is greater then linked list then it is invalid
        return;

    // Create the new node
    t = (struct Node *)malloc(sizeof(struct Node)); // create new node is heap
    t->data = x; // fill the data in node

    // Insert the new node at the beginning of the list
    if (index == 0) {
        t->next = first;
        first = t;
    }
    // Insert the new node at a specific index in the list
    else {
        for (i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}



// Main function
int main() {
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    Insert(first, 0, 5);
    Display(first);
    return 0;
}
