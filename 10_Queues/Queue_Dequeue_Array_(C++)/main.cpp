#include <iostream>

using namespace std;

class DEQueue {
    private:
        int front;  // index of front element
        int rear;   // index of rear element
        int size;   // size of the DEQueue
        int* Q;     // pointer to dynamic array

    public:
        // constructor
        DEQueue(int size) {
            this->size = size;
            front = -1;
            rear = -1;
            Q = new int[size];
        }

        // destructor
        ~DEQueue() {
            delete[] Q;
        }

        // check if the DEQueue is empty
        bool isEmpty() {
            if (front == rear) {
                return true;
            }
            return false;
        }

        // check if the DEQueue is full
        bool isFull() {
            if (rear == size - 1) {
                return true;
            }
            return false;
        }

        // add an element to the front of the DEQueue
        void enqueueFront(int x) {
            if (front == -1) {
                cout << "DEQueue Overflow" << endl;
            } else {
                Q[front] = x;
                front--;
            }
        }

        // add an element to the rear of the DEQueue
        void enqueueRear(int x) {
            if (isFull()) {
                cout << "DEQueue Overflow" << endl;
            } else {
                rear++;
                Q[rear] = x;
            }
        }

        // remove and return the front element of the DEQueue
        int dequeueFront() {
            int x = -1;
            if (isEmpty()) {
                cout << "DEQueue Underflow" << endl;
            } else {
                x = Q[front];
                front++;
            }
            return x;
        }

        // remove and return the rear element of the DEQueue
        int dequeueRear() {
            int x = -1;
            if (rear == -1) {
                cout << "DEQueue Underflow" << endl;
            } else {
                x = Q[rear];
                rear--;
            }
            return x;
        }

        // display the elements of the DEQueue
        void display() {
            for (int i = front + 1; i <= rear; i++) {
                cout << Q[i] << flush;
                if (i < rear) {
                    cout << " <- " << flush;
                }
            }
            cout << endl;
        }
};

int main() {

    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};

    DEQueue deq(sizeof(A) / sizeof(A[0]));

    // add elements from array A to rear of DEQueue
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        deq.enqueueRear(A[i]);
    }
    deq.display();
    deq.enqueueRear(11);

    // remove elements from front of DEQueue
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        deq.dequeueFront();
    }
    deq.dequeueFront();

    cout << endl;

    // add elements from array B to front of DEQueue
    for (int i = 0; i < sizeof(B) / sizeof(B[0]); i++) {
        deq.enqueueFront(B[i]);
    }
    deq.display();
    deq.enqueueFront(10);
    deq.enqueueFront(12);

    // remove elements from rear of DEQueue
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.dequeueRear();
    }
    deq.display();
    deq.dequeueRear();
    deq.dequeueRear();

    return 0;
}
