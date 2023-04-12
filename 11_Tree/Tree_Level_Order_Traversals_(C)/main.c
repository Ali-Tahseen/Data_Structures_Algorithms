// Import necessary header files
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

// Initialize the root of the tree as NULL
struct Node *root = NULL;

// Function to create a binary tree
void Treecreate()
{
    struct Node *p, *t;
    int x;

    // Create a queue for level-order traversal and set its size to 100
    struct Queue q;
    create(&q, 100);

    // Get the root node data from the user and create a node for it
    printf("Eneter root value ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;

    // Enqueue the root node to the queue
    enqueue(&q, root);

    // Perform level-order traversal and create nodes for each child
    while (!isEmpty(q))
    {
        p = dequeue(&q);

        // Get data for left child of current node and create a node for it
        printf("eneter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        // Get data for right child of current node and create a node for it
        printf("eneter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

// Function to perform level-order traversal of a binary tree
void LevelOrder(struct Node *root)
{
    // Create a queue for level-order traversal and set its size to 100
    struct Queue q;
    create(&q, 100);

    // Print the root node data and enqueue it to the queue
    printf("%d ", root->data);
    enqueue(&q, root);

    // Perform level-order traversal and print each node's data
    while (!isEmpty(q))
    {
        root = dequeue(&q);

        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if (root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

// Main function to execute the program
int main()
{
    // Create a binary tree
    Treecreate();

    // Perform level-order traversal and print the nodes' data
    LevelOrder(root);

    // Exit the program
    return 0;
}
