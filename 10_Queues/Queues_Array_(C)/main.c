#include <stdio.h>
#include <stdlib.h>

// Define the Queue data structure
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

// Function to create a new Queue
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

// Function to enqueue an element in the Queue
void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1) // check if the Queue is full
        printf("Queue is Full");
    else
    {
        q->rear++; // increment rear
        q->Q[q->rear] = x; // add the element at the rear of the Queue
    }
}

// Function to dequeue an element from the Queue
int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear) // check if the Queue is empty
        printf("Queue is Empty\n");
    else
    {
        q->front++; // increment front
        x = q->Q[q->front]; // get the element from the front of the Queue
    }
    return x;
}

// Function to display the elements in the Queue
void Display(struct Queue q)
{
    int i;
    for (i = q.front + 1; i <= q.rear; i++) // loop through the Queue elements
        printf("%d ", q.Q[i]); // print the current element
    printf("\n");
}

// Main function
int main()
{
    struct Queue q;
    create(&q, 5); // create a new Queue with a maximum size of 5

    // add some elements to the Queue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    Display(q); // display the elements in the Queue

    printf("%d ", dequeue(&q)); // dequeue an element and print it

    return 0;
}
