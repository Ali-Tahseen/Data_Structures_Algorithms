#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class CircularLinkedList{
private:
    Node* head;
public:
    CircularLinkedList(int A[], int n); // constructor
    void Display(); // function to display the elements of the circular linked list
    void recursiveDisplay(Node* p); // function to recursively display the elements of the circular linked list
    Node* getHead(){ return head; } // function to get the head of the circular linked list
    ~CircularLinkedList(); // destructor

};

CircularLinkedList::CircularLinkedList(int *A, int n) {
    Node* t;
    Node* tail;

    // creating a new node and initializing the head
    head = new Node;
    head->data = A[0];
    head->next = head;
    tail = head;

    // creating nodes for the remaining elements of the circular linked list
    for (int i=1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}

void CircularLinkedList::Display() {
    Node* p = head;
    do {
        cout << p->data << " -> " << flush; // displaying the current node's data
        p = p->next; // moving to the next node
    } while (p != head); // repeating until the head is reached again
    cout << endl; // printing a newline character at the end
}

void CircularLinkedList::recursiveDisplay(Node *p) {
    static int flag = 0; // static variable to keep track of the first node
    if (p != head || flag == 0){
        flag = 1; // setting the flag to 1 if the first node is not reached yet
        cout << p->data << " -> " << flush; // displaying the current node's data
        recursiveDisplay(p->next); // recursively calling the function with the next node
    }
    flag = 0; // resetting the flag to 0 when the head is reached again
}

CircularLinkedList::~CircularLinkedList() {
    Node* p = head;
    while (p->next != head){
        p = p->next; // moving to the last node
    }

    while (p != head){
        p->next = head->next; // making the next node the new head
        delete head; // deleting the old head
        head = p->next; // updating the head
    }

    if (p == head){
        delete head;
        head = nullptr;
    }

}


int main() {
    int A[] = {1, 3, 5, 7, 9};

    CircularLinkedList cl(A, sizeof(A)/sizeof(A[0])); // creating a circular linked list object

    cl.Display(); // displaying the circular linked list using the Display function

    Node* h = cl.getHead();
    cl.recursiveDisplay(h); // displaying the circular linked list using the recursiveDisplay function

    return 0;
}
