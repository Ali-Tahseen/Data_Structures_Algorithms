// Checking if a Linked List is Sorted

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;

// Function to display the linked list
void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Function to create a linked list
void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Function to check if the linked list is sorted
int isSorted(struct Node *p) {
    int x = -65536;

    while (p != NULL) {
        if (p->data < x) {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    printf("%d\n", isSorted(first));

    return 0;
}
