// Binary Tree Create

#include <stdio.h> //include standard input/output library

#include <stdlib.h> //include standard library

// Queue Header File

struct Node {
  struct Node * lchild; //pointer to the left child node
  int data; //data of the node
  struct Node * rchild; //pointer to the right child node
};

struct Queue {
  int size; //maximum size of the queue
  int front; //index of the front element of the queue
  int rear; //index of the rear element of the queue
  struct Node ** Q; //array of pointers to nodes representing the queue
};

void create(struct Queue * q, int size) {
  q -> size = size; //set the maximum size of the queue
  q -> front = q -> rear = 0; //initialize the front and rear indices of the queue to be 0
  q -> Q = (struct Node ** ) malloc(q -> size * sizeof(struct Node * )); //allocate memory for the array of pointers to nodes representing the queue
}

void enqueue(struct Queue * q, struct Node * x) {
  if ((q -> rear + 1) % q -> size == q -> front) { //if the queue is full
    printf("Queue is Full"); //print a message indicating that the queue is full
  } else {
    q -> rear = (q -> rear + 1) % q -> size; //increment the rear index of the queue
    q -> Q[q -> rear] = x; //add the node to the rear of the queue
  }
}

struct Node * dequeue(struct Queue * q) {
  struct Node * x = NULL; //initialize a pointer to a node to be NULL
  if (q -> front == q -> rear) { //if the queue is empty
    printf("Queue is Empty\n"); //print a message indicating that the queue is empty
  } else {
    q -> front = (q -> front + 1) % q -> size; //increment the front index of the queue
    x = q -> Q[q -> front]; //remove the node from the front of the queue and store it in the pointer to a node
  }
  return x; //return the pointer to the removed node
}

int isEmpty(struct Queue q) {
  return q.front == q.rear; //return 1 if the queue is empty and 0 otherwise
}
//#include "Queue.h" //include the header file for the Queue data structure

struct Node * root = NULL; //initialize the root of the binary tree to be NULL

void Treecreate() {
  struct Node * p, * t; //initialize two pointers to nodes
  int x; //initialize an integer variable
  struct Queue q; //initialize a queue
  create( & q, 100); //create the queue with a maximum size of 100
  printf("Enter root value "); //prompt the user to input the value for the root node
  scanf("%d", & x); //read in the value for the root node
  root = (struct Node * ) malloc(sizeof(struct Node)); //allocate memory for the root node
  root -> data = x; //set the data for the root node to be the input value
  root -> lchild = root -> rchild = NULL; //initialize the left and right child nodes of the root to be NULL
  enqueue( & q, root); //enqueue the root node into the queue
  while (!isEmpty(q)) { //while the queue is not empty
    p = dequeue( & q); //dequeue a node from the front of the queue
    printf("Enter left child of %d ", p -> data); //prompt the user to input the value for the left child node
    scanf("%d", & x); //read in the value for the left child node
    if (x != -1) { //if the value is not -1
      t = (struct Node * ) malloc(sizeof(struct Node)); //allocate memory for the left child node
      t -> data = x; //set the data for the left child node to be the input value
      t -> lchild = t -> rchild = NULL; //initialize the left and right child nodes of the left child to be NULL
      p -> lchild = t; //set the left child node of the current node to be the newly created node
      enqueue( & q, t); //enqueue the left child node into the queue
    }
    printf("Enter right child of %d ", p -> data); //prompt the user to input the value for the right child node
    scanf("%d", & x); //read in the value for the right child node
    if (x != -1) { //if the value is not -1
      t = (struct Node * ) malloc(sizeof(struct Node)); //allocate memory for the right child node
      t -> data = x; //set the data for the right child node to be the input value
      t -> lchild = t -> rchild = NULL; //initialize the left and right child nodes of the right child to be NULL
      p -> rchild = t; //set the right child node of the current node to be the newly created node
      enqueue( & q, t); //enqueue the right child node into the queue
    }
  }
}

void Preorder(struct Node * p) {
  if (p) { //if the node exists
    printf("%d ", p -> data); //print the data of the node
    Preorder(p -> lchild); //recursively traverse the left subtree
    Preorder(p -> rchild); //recursively traverse the right subtree
  }
}

void Inorder(struct Node * p) {
  if (p) { //if the node exists
    Inorder(p -> lchild); //recursively traverse the left subtree
    printf("%d ", p -> data); //print the data of the node
    Inorder(p -> rchild); //recursively traverse the right subtree
  }
}

void Postorder(struct Node * p) {
  if (p) { //if the node exists
    Postorder(p -> lchild); //recursively traverse the left subtree
    Postorder(p -> rchild); //recursively traverse the right subtree
    printf("%d ", p -> data); //print the data of the node
  }
}

int main() {
  Treecreate(); //create the binary tree
  printf("Pre Order: "); //print the message for pre-order traversal
  Preorder(root); //traverse the binary tree in pre-order
  printf("\nPost Order: "); //print the message for post-order traversal
  Postorder(root); //traverse the binary tree in post-order
  return 0; //return 0 to indicate successful program execution
}
