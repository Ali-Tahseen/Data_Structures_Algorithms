// Insert and create a Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

// Function to create a Linked List
void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    // Loop through the array and create nodes for each element
    for (i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Function to display the Linked List
void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Function to count the number of nodes in the linked list
int count(struct Node *p)
{
    int l = 0;

    // Traverse the linked list and increment the counter for each node
    while (p)
    {
        l++;
        p = p->next;
    }

    return l;
}

// Function to insert a node at a specific position in the Linked List
void Insert(struct Node *p, int index, int x) {
    struct Node *t;
    int i;

    // Check if index is out of bounds
    if (index < 0 || index > count(p))
        return;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0) {
        // If index is 0, set the new node as the first node
        t->next = first;
        first = t;
    } else {
        // Traverse the Linked List to find the node at the position
        for (i = 0; i < index - 1; i++)
            p = p->next;

        // Insert the new node at the position
        t->next = p->next;
        p->next = t;
    }
}

int main() {
    // Create a Linked List
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    // Insert nodes at specific positions in the Linked List
    Insert(first, 0, 15);
    Insert(first, 0, 8);
    Insert(first, 0, 9);
    Insert(first, 1, 10);

    // Display the Linked List
    Display(first);

    return 0;
}
