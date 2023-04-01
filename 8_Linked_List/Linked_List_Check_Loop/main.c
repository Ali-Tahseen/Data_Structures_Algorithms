#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

// Function to display the Linked List
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Function to create a Linked List
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Function to check if there is a loop in the Linked List
int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f; //at first they are both pointing to the first node

    // Use Floyd's cycle-finding algorithm
    do
    {
        p = p->next;//move one node
        q = q->next;//move two nodes
        q = q ? q->next : q;
        //The operation starts by checking if q is a valid pointer or not.
        //If q is not NULL, the statement q->next is executed and its value is assigned to q.
        //This means that if q has a valid next node, then q will be assigned to the next node, otherwise, q will remain unchanged.
    } while (p && q && p != q);

    // If p == q, then there is a loop in the Linked List
    if (p == q)
        return 1;
    else
        return 0;
}

int main()
{
    struct Node *t1, *t2;
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    // Create a loop in the Linked List
    t1 = first->next->next; // this pointer is pointing to the third node
    t2 = first->next->next->next->next; // this pointer is pointing to the last node
    t2->next = t1; // since t2 will become null after the last node to assign it to t1 which is pointing on the third node.

    // Check if there is a loop in the Linked List
    printf("%d\n", isLoop(first));

    return 0;
}
