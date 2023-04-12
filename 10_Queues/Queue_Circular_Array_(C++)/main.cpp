#include <iostream>

using namespace std;

class CircularQueue{
private:
    int size; // size of the queue
    int front; // index of the front element of the queue
    int rear; // index of the rear element of the queue
    int* Q; // pointer to the array to hold the queue elements
public:
    CircularQueue(int size); // constructor to initialize the queue
    ~CircularQueue(); // destructor to deallocate memory
    bool isFull(); // check if the queue is full
    bool isEmpty(); // check if the queue is empty
    void enqueue(int x); // insert an element in the queue
    int dequeue(); // remove an element from the queue
    void display(); // display the elements of the queue
};

CircularQueue::CircularQueue(int size) {
    this->size = size;
    front = 0;
    rear = 0;
    Q = new int [size]; // allocate memory for the queue
}

CircularQueue::~CircularQueue() {
    delete [] Q; // deallocate memory for the queue
}

bool CircularQueue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}

bool CircularQueue::isFull() {
    if ((rear + 1) % size == front){
        return true;
    }
    return false;
}

void CircularQueue::enqueue(int x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear = (rear + 1) % size; // update the rear index
        Q[rear] = x; // insert the element at the rear index
    }
}

int CircularQueue::dequeue() {
    int x = -1;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front = (front + 1) % size; // update the front index
        x = Q[front]; // remove the element at the front index
    }
    return x; // return the removed element
}

void CircularQueue::display() {
    int i = front + 1; // index of the first element
    do {
        cout << Q[i] << flush; // display the element
        if (i < rear) {
            cout << " <- " << flush; // add an arrow if there are more elements
        }
        i = (i + 1) % size; // increment the index in a circular way
    } while (i != (rear + 1) % size); // loop until the rear index is reached
}


int main() {

    int A[] = {1, 3, 5, 7, 9};

    CircularQueue cq(sizeof(A)/sizeof(A[0]) + 1); // create a circular queue with the size of the array plus one

    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.enqueue(A[i]); // insert the elements of the array into the queue
    }

    // Display
    cq.display(); // display the elements of the queue
    cout << endl;

    // Overflow
    cq.enqueue(10); // try to insert an element into a full queue

    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.dequeue(); // remove the elements from the queue
    }

    // Underflow
    cq.dequeue(); // try to remove an element from an empty queue

    return 0; // exit
}
