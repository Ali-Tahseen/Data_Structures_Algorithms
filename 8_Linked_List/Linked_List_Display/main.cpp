#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
struct Node
{
    int data;
    struct Node *next;
}*first = NULL; // Global pointer variable to point to the first node in the list


// Function to create a linked list from an array of integers
void create(int A[], int n)
{
    int i;
    struct Node *t, *last; //*t is used to help create a new node

    // Create the first node in the list with the first element of the array
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0]; // give the very first element
    first->next = NULL; // there is nothing beyond this one since this is the first element but will link it below
    last = first; // at first last points on first node

    // Iterate through the remaining elements of the array and create a new node for each element
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i]; // fill up the data of the node
        t->next = NULL; // there is no next node yet so it should be made as null
        last->next = t; // the last node should point on t
        last = t; // last move to t
    }
}

// Function to display the elements of the linked list iteratively
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Function to display the elements of the linked list recursively in reverse order
void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        RDisplay(p->next); // if you put it below the print then it will print in normal order
        printf("%d ", p->data);
    }
}

// Main function
int main()
{
//    struct Node *temp;

    // Initialize an array of integers
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    int n = 8;

    // Create a linked list from the array
    create(A, n);

    // Display the elements of the linked list iteratively
    RDisplay(first);

    return 0;
}
