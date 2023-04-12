#include <iostream>

using namespace std;

class Queue {
private:
    int size;
    int front;
    int rear;
    int* Q;
public:
    Queue(int size); // Constructor to create a queue
    ~Queue(); // Destructor to deallocate memory
    bool isFull(); // Check if queue is full
    bool isEmpty(); // Check if queue is empty
    void enqueue(int x); // Add an element to the rear of the queue
    int dequeue(); // Remove an element from the front of the queue
    void display(); // Display the elements of the queue
};

Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int [size];
}

Queue::~Queue() {
    delete [] Q;
}

bool Queue::isEmpty() {
    if (front == rear) { // If the front and rear are equal, the queue is empty
        return true;
    }
    return false;
}

bool Queue::isFull() {
    if (rear == size-1) { // If the rear is equal to the size-1, the queue is full
        return true;
    }
    return false;
}

void Queue::enqueue(int x) {
    if (isFull()) { // If the queue is full, display an error message
        cout << "Queue Overflow" << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue() {
    int x = -1;
    if (isEmpty()) { // If the queue is empty, display an error message
        cout << "Queue Underflow" << endl;
    } else {
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::display() {
    for (int i = front + 1; i <= rear; i++) { // Loop through the queue
        cout << Q[i] << flush;
        if (i < rear) { // If not the last element, display an arrow
            cout << " <- " << flush;
        }
    }
    cout << endl;
}

int main() {
    int A[] = {1, 3, 5, 7, 9};
    Queue q(sizeof(A)/sizeof(A[0]));

    // Enqueue
    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++) {
        q.enqueue(A[i]);
    }

    // Display
    q.display();

    // Overflow
    q.enqueue(10);

    // Dequeue
    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++) {
        q.dequeue();
    }

    // Underflow
    q.dequeue();

    return 0;
}
