#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

// Function to create a linked list from an array of integers
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    // Allocate memory for the first node in the list
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    // Iterate through the remaining elements of the array and create a new node for each element
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
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

// Recursive function to count the number of nodes in the linked list
int Rcount(struct Node *p)
{
    if (p != NULL)
        return Rcount(p->next) + 1;
    else
        return 0;
}

// Function to calculate the sum of all the elements in the linked list
int sum(struct Node *p)
{
    int s = 0;

    // Traverse the linked list and add the data of each node to the sum
    while (p != NULL)
    {
        s += p->data;
        p = p->next;
    }

    return s;
}

// Recursive function to calculate the sum of all the elements in the linked list
int Rsum(struct Node *p)
{
    if (p == NULL)
        return 0;
    else
        return Rsum(p->next) + p->data;
}

// Main function
int main()
{
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};

    // Create a linked list from the array
    create(A, 8);

    // Call the count function and print the result to the console
    printf("Count %d\n", count(first));

    // Call the sum function and print the result to the console
    printf("Sum %d\n", sum(first));

    return 0;
}
