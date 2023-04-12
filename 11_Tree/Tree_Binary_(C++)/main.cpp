#include <iostream>

using namespace std;

// Define a class for a node in a binary tree
class Node{
public:
    Node* lchild; // Pointer to left child node
    int data; // Data stored in the node
    Node* rchild; // Pointer to right child node
};

// Define a class for a queue that stores pointers to nodes
class Queue{
private:
    int size; // Maximum size of the queue
    int front; // Index of the front of the queue
    int rear; // Index of the rear of the queue
    Node** Q; // Array of pointers to nodes
public:
    // Constructor: initialize the queue with a given size
    Queue(int size);
    // Destructor: free the memory used by the queue
    ~Queue();
    // Check if the queue is full
    bool isFull();
    // Check if the queue is empty
    bool isEmpty();
    // Add a node pointer to the rear of the queue
    void enqueue(Node* x);
    // Remove and return a node pointer from the front of the queue
    Node* dequeue();
};

// Constructor for the queue: allocate memory for the queue array
Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node* [size];
}

// Destructor for the queue: free the memory used by the queue array
Queue::~Queue() {
    delete [] Q;
}

// Check if the queue is empty
bool Queue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}

// Check if the queue is full
bool Queue::isFull() {
    if (rear == size-1){
        return true;
    }
    return false;
}

// Add a node pointer to the rear of the queue
void Queue::enqueue(Node* x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}

// Remove and return a node pointer from the front of the queue
Node* Queue::dequeue() {
    Node* x = nullptr;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front++;
        x = Q[front];
    }
    return x;
}

// Create a global variable for the root node of the binary tree
Node* root = new Node;


void createTree(){
    Node* p;  // declare pointer p of Node type
    Node* t;  // declare pointer t of Node type
    int x;    // declare integer variable x
    Queue q(10);  // declare an instance of Queue class with size 10

    cout << "Enter root value: " << flush;  // output "Enter root value: "
    cin >> x;  // input the value of x from user
    root->data = x;  // assign the value of x to the data member of root
    root->lchild = nullptr;  // set the left child of root to nullptr
    root->rchild = nullptr;  // set the right child of root to nullptr
    q.enqueue(root);  // enqueue the root into the queue

    while (! q.isEmpty()){  // while queue is not empty
        p = q.dequeue();  // dequeue a node and assign it to p

        cout << "Enter left child value of " << p->data << ": " << flush;  // output the message to input the value of left child
        cin >> x;  // input the value of x from user
        if (x != -1){  // if x is not equal to -1
            t = new Node;  // allocate memory for a new node and assign its address to t
            t->data = x;  // assign the value of x to the data member of t
            t->lchild = nullptr;  // set the left child of t to nullptr
            t->rchild = nullptr;  // set the right child of t to nullptr
            p->lchild = t;  // set t as the left child of p
            q.enqueue(t);  // enqueue t into the queue
        }

        cout << "Enter left child value of " << p->data << ": " << flush;  // output the message to input the value of right child
        cin >> x;  // input the value of x from user
        if (x != -1){  // if x is not equal to -1
            t = new Node;  // allocate memory for a new node and assign its address to t
            t->data = x;  // assign the value of x to the data member of t
            t->lchild = nullptr;  // set the left child of t to nullptr
            t->rchild = nullptr;  // set the right child of t to nullptr
            p->rchild = t;  // set t as the right child of p
            q.enqueue(t);  // enqueue t into the queue
        }
    }
}

void preorder(Node* p){
    if (p){                             // if the node is not NULL
        cout << p->data << ", " << flush;  // output the value of the node
        preorder(p->lchild);             // recursively traverse the left subtree
        preorder(p->rchild);             // recursively traverse the right subtree
    }
}

void inorder(Node* p){
    if (p){                             // if the node is not NULL
        inorder(p->lchild);             // recursively traverse the left subtree
        cout << p->data << ", " << flush;  // output the value of the node
        inorder(p->rchild);             // recursively traverse the right subtree
    }
}

void postorder(Node* p){
    if (p){                             // if the node is not NULL
        postorder(p->lchild);           // recursively traverse the left subtree
        postorder(p->rchild);           // recursively traverse the right subtree
        cout << p->data << ", " << flush;  // output the value of the node
    }
}


int main() {

    createTree();                       // create the binary tree

    preorder(root);                     // traverse the tree using pre-order traversal
    cout << endl;

    inorder(root);                      // traverse the tree using in-order traversal
    cout << endl;

    postorder(root);                    // traverse the tree using post-order traversal
    cout << endl;

    return 0;                           // indicate successful completion of the program
}
