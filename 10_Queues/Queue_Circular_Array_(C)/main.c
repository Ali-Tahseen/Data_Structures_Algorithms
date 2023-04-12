#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q,int size)
{
    q->size = size;
    q->front = q->rear = 0; // initialize front and rear indices to 0
    q->Q = (int *)malloc(q->size * sizeof(int)); // allocate memory for Q
}

void enqueue(struct Queue *q,int x)
{
    if ((q->rear + 1) % q->size == q->front) // check if queue is full
    {
        printf("Queue is Full"); // print error message
    }
    else
    {
        q->rear = (q->rear + 1) % q->size; // increment rear index
        q->Q[q->rear] = x; // store new element in rear position
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear) // check if queue is empty
    {
        printf("Queue is Empty\n"); // print error message
    }
    else
    {
        q->front = (q->front + 1) % q->size; // increment front index
        x = q->Q[q->front]; // retrieve front element
    }
    return x; // return front element or -1 if queue is empty
}

void Display(struct Queue q)
{
    int i = q.front + 1; // start from the element after the front
    do
    {
        printf("%d ", q.Q[i]); // print current element
        i = (i + 1) % q.size; // move to next element (wrapping around if needed)
    } while (i != (q.rear + 1) % q.size); // loop until we reach the element after the rear
    printf("\n");
}

int main()
{
    struct Queue q;
    create(&q, 5); // create a queue of size 5
    enqueue(&q, 10); // add some elements to the queue
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); // queue is full, should print "Queue is Full" error message
    Display(q); // display queue elements
    printf("%d ", dequeue(&q)); // remove an element from the queue and print it
    return 0;
}
