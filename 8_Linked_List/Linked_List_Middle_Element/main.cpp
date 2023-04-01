#include <iostream> // include iostream library
#include <cmath> // include cmath library
#include <stack> // include stack library

using namespace std; // use std namespace

class Node{ // define a class Node
public:
    int data;
    Node* next;
};

Node* head = new Node; // create a new Node and assign it to head

void create(int A[], int n){ // function to create a linked list from an array
    Node* temp; // create a temporary Node pointer
    Node* tail; // create a tail Node pointer

    head->data = A[0]; // assign the first element of the array to the data of head Node
    head->next = nullptr; // assign null to the next of head Node
    tail = head; // assign head Node to tail Node

    for (int i=1; i<n; i++){ // loop through the array from the second element
        temp = new Node; // create a new Node using dynamic memory allocation
        temp->data = A[i]; // assign the current element of the array to the data of temp Node
        temp->next = nullptr; // assign null to the next of temp Node
        tail->next = temp; // assign the address of temp Node to the next of tail Node
        tail = temp; // assign temp Node to tail Node
    }
}

void middleNode1(Node* p){ // function to find the middle element of a linked list using length
    int length = 0; // initialize length variable to 0
    while (p){ // loop through the linked list
        length++; // increment length variable
        p = p->next; // move p pointer to the next Node
    }

    int index = (int)ceil(length/2.0); // calculate the index of the middle element
    Node* q = head; // create a new Node pointer q and assign it to head Node
    for (int i=0; i<index-1; i++){ // loop through the linked list until the middle element
        q = q->next; // move q pointer to the next Node
    }
    cout << "Middle Element (Method-I): " << q->data << endl; // print the middle element
}

void middleNode2(Node* p){ // function to find the middle element of a linked list using two pointers
    Node* q = p; // create a new Node pointer q and assign it to p Node
    while (q){ // loop through the linked list
        q = q->next; // move q pointer to the next Node
        if (q){ // check if q pointer is not null
            q = q->next; // move q pointer to the next Node
        }
        if (q){ // check if q pointer is not null
            p = p->next; // move p pointer to the next Node
        }
    }
    cout << "Middle Element (Method-II): " << p->data << endl; // print the middle element
}

void middleNode3(Node* p){ // function to find the middle element of a linked list using a stack
    stack<Node*> s; // create a new stack of Node pointers
    while (p){ // loop through the linked list
        s.push(p); // push the Node pointer to the stack
        p = p->next; // move p pointer to the next Node
    }
    int length = s.size(); // get the size of the stack
    int popLength = (int)(floor(length/2.0)); // calculate the number of times to pop from the stack
    while (popLength){ // loop through the stack until it reaches the middle element
        s.pop(); // pop from the stack
        popLength--; // decrement the number of times to pop
    }
    cout << "Middle Element (Method-III): " << s.top()->data << endl; // print the middle element
}


int main() {

    int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21}; // create an array
    create(A, sizeof(A)/sizeof(A[0])); // create a linked list from the array

    cout << endl;
    middleNode1(head); // find the middle element of the linked list using length
    middleNode2(head); // find the middle element of the linked list using two pointers
    middleNode3(head); // find the middle element of the linked list using a stack

    return 0; // return 0 to terminate the program
}
