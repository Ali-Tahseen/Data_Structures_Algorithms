// Queue using Linked List
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL; // Declare front and rear pointers as global variables

// Function to add an element to the queue
void enqueue(int x) {
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("Queue is Full\n");
    else {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear = t; // If queue is empty, set both front and rear to point to the new node
        else {
            rear->next = t;
            rear = t;
        }
    }
}

// Function to remove an element from the queue
int dequeue() {
    int x = -1;
    struct Node* t;
    if(front == NULL)
        printf("Queue is Empty\n");
    else {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

// Function to display the contents of the queue
void Display() {
    struct Node *p = front;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Add elements to the queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    Display(); // Display the queue elements
    printf("%d ", dequeue()); // Remove an element from the queue and display it
    return 0;
}
