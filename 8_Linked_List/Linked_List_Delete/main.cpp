#include <stdio.h>
#include <stdlib.h>

// define the structure for a linked list node
struct Node {
    int data;
    struct Node *next;
} *first=NULL;

// create a linked list from an array
void create(int A[], int n) {
    int i;
    struct Node *t, *last;

    // create the first node
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    // create the remaining nodes
    for(i=1; i<n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// display a linked list iteratively
void Display(struct Node *p) {
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// display a linked list recursively
void RDisplay(struct Node *p) {
    if(p != NULL) {
        RDisplay(p->next);
        printf("%d ", p->data);
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

// delete a node from a linked list
int Delete(struct Node *p, int index) {
    struct Node *q = NULL; //q pointer follows p pointer so that p pointer can be used the delete the node and q pointer is used
    // to point to the next node and keep the sequence
    int x = -1, i; // x is taken to store the value of the node when it is deleted

    // check for invalid index
    if(index < 1 || index > count(p))
        return -1;

    // delete the first node
    if(index == 1) {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    // delete a node other than the first node
    else {
        for(i=0; i<index-1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    // delete the node at index 2
    printf("%d\n", Delete(first, 2));

    // display the updated linked list
    Display(first);

    return 0;
}
