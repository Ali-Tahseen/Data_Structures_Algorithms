// Include necessary header files
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

// Define a struct for a binary tree node
struct Node *root=NULL;

// Function to create a binary tree
void Treecreate() {
  struct Node *p, *t;
  int x;
  struct Queue q;

  // Initialize a queue to hold tree nodes
  create(&q, 100);

  // Get the root value from the user
  printf("Eneter root value ");
  scanf("%d", &x);

  // Create a root node and enqueue it into the queue
  root = (struct Node *)malloc(sizeof(struct Node));
  root->data = x;
  root->lchild = root->rchild = NULL;
  enqueue(&q, root);

  // Continue creating the tree until the queue is empty
  while (!isEmpty(q)) {
    // Dequeue a node from the queue
    p = dequeue(&q);

    // Get the left child value from the user
    printf("eneter left child of %d ", p->data);
    scanf("%d", &x);

    // Create a left child node and enqueue it into the queue
    if (x != -1) {
      t = (struct Node *)malloc(sizeof(struct Node));
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      enqueue(&q, t);
    }

    // Get the right child value from the user
    printf("eneter right child of %d ", p->data);
    scanf("%d", &x);

    // Create a right child node and enqueue it into the queue
    if (x != -1) {
      t = (struct Node *)malloc(sizeof(struct Node));
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      enqueue(&q, t);
    }
  }
}

// Function to count the number of nodes in the binary tree
int count(struct Node *root) {
  if (root)
    return count(root->lchild) + count(root->rchild) + 1;
  return 0;
}

// Function to find the height of the binary tree
int height(struct Node *root) {
  int x=0,y=0;
  if (root == 0)
    return 0;

  // Recursively find the heights of the left and right subtrees
  x = height(root->lchild);
  y = height(root->rchild);

  // Return the larger height plus one for the root node
  if (x > y)
    return x + 1;
  else
    return y + 1;
}

// Main function to run the program
int main() {
  Treecreate();
  printf("%d", count(root));  // Print the number of nodes in the binary tree
  printf("%d", height(root)); // Print the height of the binary tree
  return 0;
}
