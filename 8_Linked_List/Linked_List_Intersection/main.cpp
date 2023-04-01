#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* head = new Node; // Create a new Node pointer head and assign it the address of a new Node object
Node* second = new Node; // Create a new Node pointer second and assign it the address of a new Node object

void create(int A[], int n){
    Node* temp;
    Node* tail;

    head->data = A[0]; // Store the first element of the array in the data member of the head Node
    head->next = nullptr; // Set the next member of the head Node to null
    tail = head; // Set tail pointer to head Node

    for (int i=1; i<n; i++){ // Iterate through the array starting from the second element
        temp = new Node; // Create a new Node object and assign its address to temp pointer
        temp->data = A[i]; // Store the i-th element of the array in the data member of the temp Node
        temp->next = nullptr; // Set the next member of the temp Node to null
        tail->next = temp; // Set the next member of the tail Node to temp Node
        tail = temp; // Move tail pointer to the temp Node
    }
}

void createSecond(int A[], int n, Node* p){
    Node* temp;
    Node* tail;

    second->data = A[0]; // Store the first element of the array in the data member of the second Node
    second->next = nullptr; // Set the next member of the second Node to null
    tail = second; // Set tail pointer to the second Node

    for (int i=1; i<n; i++){ // Iterate through the array starting from the second element
        temp = new Node; // Create a new Node object and assign its address to temp pointer
        temp->data = A[i]; // Store the i-th element of the array in the data member of the temp Node
        temp->next = nullptr; // Set the next member of the temp Node to null
        tail->next = temp; // Set the next member of the tail Node to temp Node
        tail = temp; // Move tail pointer to the temp Node
    }
    tail->next = p; // Set the next member of the last Node to the passed pointer p
}

void Intersection(Node* p, Node* q){
    // Populate first stack
    stack<Node*> stk1; // declare a stack of Node pointers
    while (p != nullptr){ // while there are still nodes in the first list
        stk1.push(p); // push the current node to the top of the stack
        p = p->next; // move to the next node
    }

    // Populate second stack
    stack<Node*> stk2; // declare another stack of Node pointers
    while (q != nullptr){ // while there are still nodes in the second list
        stk2.push(q); // push the current node to the top of the stack
        q = q->next; // move to the next node
    }

    Node* r; // declare a Node pointer r
    while (stk1.top() == stk2.top()){ // while the top nodes of both stacks are the same
        r = stk1.top(); // set r to the top node of the first stack (or the second, since both will have the same top)
        stk1.pop(); // remove the top node from the first stack
        stk2.pop(); // remove the top node from the second stack
    }
    cout << "Intersecting Node: " << r->data << endl; // print the value of the intersecting node
}


int main() {

    // Create First Linked List
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21}; // create an array of integers
    create(A, sizeof(A)/sizeof(A[0])); // create a linked list from the array

    // Create Second Linked List
    Node* temp = head; // set a temporary Node pointer to the head of the first list
    int i = 5;
    while (i>0){ // move the temporary pointer 5 nodes down the list
        temp = temp->next;
        i--;
    }
    cout << temp->data << endl; // print the value of the node 5 positions down

    int B[] = {2, 4, 6, 8, 10}; // create another array of integers
    createSecond(B, sizeof(B)/sizeof(B[0]), temp); // create a second linked list from the array, with the intersecting node at temp

    // Find Intersection
    Intersection(head, second); // call the intersection function with the two linked lists as parameters

    return 0; // end the program
}
