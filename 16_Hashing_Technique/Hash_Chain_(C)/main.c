// Including the standard library header file 'stdlib.h'
#include<stdlib.h>

// Defining a structure for a linked list node
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node with a given value in a sorted linked list
// The first argument is a pointer to a pointer to the head of the linked list
void SortedInsert(struct Node **H, int x)
{
    // Creating a new node
    struct Node *t, *q = NULL, *p = *H;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    // If the linked list is empty, make the new node the head
    if (*H == NULL)
        *H = t;
    else
    {
        // Traverse the linked list to find the correct position to insert the new node
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }

        // Insert the new node at the correct position in the linked list
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

// Function to search for a node with a given value in a linked list
// The first argument is a pointer to the head of the linked list
struct Node *Search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// Header guard for the Chains.h header file
#ifndef Chains_h
#define Chains_h

#endif /* Chains_h */

// Including the standard input/output header file 'stdio.h'
#include <stdio.h>

// Including the header file for the linked list implementation 'Chains.h'
#include "Chains.h"

// Function to calculate the hash value for a given key
int hash(int key)
{
    return key % 10;
}

// Function to insert a node with a given value in a hash table implemented using separate chaining
// The first argument is an array of pointers to the heads of the linked lists
void Insert(struct Node *H[], int key)
{
    int index = hash(key);
    SortedInsert(&H[index], key);
}

// Main function
int main()
{
    // Initializing an array of pointers to linked lists
    struct Node *HT[10];
    struct Node *temp;
    int i;

    // Initializing each pointer in the array to NULL
    for (i = 0; i < 10; i++)
        HT[i] = NULL;

    // Inserting nodes with some values in the hash table
    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);

    // Searching for a node with a given value in the hash table
    temp = Search(HT[hash(21)], 21);

    // Printing the value of the node found
    printf("%d ", temp->data);

    // Returning 0 to indicate successful execution of the program
    return 0;
}
