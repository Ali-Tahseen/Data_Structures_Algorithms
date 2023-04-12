#include <iostream>               // Include standard input/output stream header file
#include <queue>                  // Include queue header file
#include <stack>                  // Include stack header file

using namespace std;

class Node{                       // Declare a Node class for tree
public:
    Node* lchild;                // Pointer to left child node
    int data;                    // Node data
    Node* rchild;                // Pointer to right child node
};

class Tree{                       // Declare a Tree class
private:
    Node* root;                  // Pointer to root node
public:
    Tree();                      // Constructor
    ~Tree();                     // Destructor
    void CreateTree();           // Function to create a tree
    void Preorder(Node* p);      // Recursive preorder traversal function
    void Preorder() { Preorder(root); }  // Passing private parameter in constructor
    void Inorder(Node* p);       // Recursive inorder traversal function
    void Inorder() { Inorder(root); }
    void Postorder(Node* p);     // Recursive postorder traversal function
    void Postorder() { Postorder(root); }
    void Levelorder(Node* p);    // Function for level order traversal
    void Levelorder() { Levelorder(root); }
    int Height(Node* p);         // Function to calculate height of the tree
    int Height() { return Height(root); }
    void iterativePreorder(Node* p);     // Iterative preorder traversal function
    void iterativePreorder() { iterativePreorder(root); }
    void iterativeInorder(Node* p);      // Iterative inorder traversal function
    void iterativeInorder() { iterativeInorder(root); }
    void iterativePostorder(Node* p);    // Iterative postorder traversal function
    void iterativePostorder() { iterativePostorder(root); }
};

Tree::Tree() {                   // Tree class constructor
    root = nullptr;              // Set the root to null
}

Tree::~Tree() {                  // Tree class destructor
    // TODO
}

void Tree::CreateTree() {        // Function to create a tree
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;

    root = new Node;             // Allocate memory for root node
    cout << "Enter root data: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.emplace(root);            // Add the root to the queue

    while (! q.empty()){        // Loop while the queue is not empty
        p = q.front();          // Get the front node of the queue
        q.pop();                // Remove the front node from the queue

        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){           // If the entered data is not -1
            t = new Node;       // Allocate memory for a new node
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;      // Add the new node as the left child of the current node
            q.emplace(t);       // Add the new node to the queue
        }

        // Prompts the user to enter data for the left child of a node
        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;

        // If the entered data is not -1, create a new node with the data,
        // set its child pointers to nullptr, set the parent's left child to the new node,
        // and add the new node to the queue of nodes to be processed later
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }
    }
}

// Traverses the tree in preorder, printing each node's data as it is visited
void Tree::Preorder(Node *p) {
    if (p){
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

// Traverses the tree in inorder, printing each node's data as it is visited
void Tree::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

// Traverses the tree in postorder, printing each node's data as it is visited
void Tree::Postorder(Node *p) {
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

// Traverses the tree in level order, printing each node's data as it is visited
void Tree::Levelorder(Node *p) {
    queue<Node*> q;
    cout << p->data << ", " << flush;
    q.emplace(p);

    while (! q.empty()){
        p = q.front();
        q.pop();

        // If the current node has a left child, print its data and add it to the queue
        if (p->lchild){
            cout << p->lchild->data << ", " << flush;
            q.emplace(p->lchild);
        }

        // If the current node has a right child, print its data and add it to the queue
        if (p->rchild){
            cout << p->rchild->data << ", " << flush;
            q.emplace(p->rchild);
        }
    }
}

int Tree::Height(Node *p) {
    int l = 0; // Initialize left height to 0
    int r = 0; // Initialize right height to 0
    if (p == nullptr){ // If current node is null
        return 0; // return 0
    }

    l = Height(p->lchild); // Recursively call the height function for left child and store it in l
    r = Height(p->rchild); // Recursively call the height function for right child and store it in r

    if (l > r){ // If left height is greater than right height
        return l + 1; // Return left height plus one (plus one for the current node)
    } else {
        return r + 1; // Return right height plus one (plus one for the current node)
    }
}

void Tree::iterativePreorder(Node *p) {
    stack<Node*> stk; // Declare a stack to store nodes
    while (p != nullptr || ! stk.empty()){ // While current node is not null or the stack is not empty
        if (p != nullptr){ // If current node is not null
            cout << p->data << ", " << flush; // Print the data of the current node
            stk.emplace(p); // Push the current node to stack
            p = p->lchild; // Traverse to the left child
        } else {
            p = stk.top(); // Get the top node from stack
            stk.pop(); // Pop the top node from stack
            p = p->rchild; // Traverse to the right child
        }
    }
    cout << endl;
}

void Tree::iterativeInorder(Node *p) {
    stack<Node*> stk; // Declare a stack to store nodes
    while (p != nullptr || ! stk.empty()){ // While current node is not null or the stack is not empty
        if (p != nullptr){ // If current node is not null
            stk.emplace(p); // Push the current node to stack
            p = p->lchild; // Traverse to the left child
        } else {
            p = stk.top(); // Get the top node from stack
            stk.pop(); // Pop the top node from stack
            cout << p->data << ", " << flush; // Print the data of the current node
            p = p->rchild; // Traverse to the right child
        }
    }
    cout << endl;
}int Tree::Height(Node *p) {
    int l = 0; // Initialize left height to 0
    int r = 0; // Initialize right height to 0
    if (p == nullptr){ // If current node is null
        return 0; // return 0
    }

    l = Height(p->lchild); // Recursively call the height function for left child and store it in l
    r = Height(p->rchild); // Recursively call the height function for right child and store it in r

    if (l > r){ // If left height is greater than right height
        return l + 1; // Return left height plus one (plus one for the current node)
    } else {
        return r + 1; // Return right height plus one (plus one for the current node)
    }
}

void Tree::iterativePreorder(Node *p) {
    stack<Node*> stk; // Declare a stack to store nodes
    while (p != nullptr || ! stk.empty()){ // While current node is not null or the stack is not empty
        if (p != nullptr){ // If current node is not null
            cout << p->data << ", " << flush; // Print the data of the current node
            stk.emplace(p); // Push the current node to stack
            p = p->lchild; // Traverse to the left child
        } else {
            p = stk.top(); // Get the top node from stack
            stk.pop(); // Pop the top node from stack
            p = p->rchild; // Traverse to the right child
        }
    }
    cout << endl;
}

void Tree::iterativeInorder(Node *p) {
    stack<Node*> stk; // Declare a stack to store nodes
    while (p != nullptr || ! stk.empty()){ // While current node is not null or the stack is not empty
        if (p != nullptr){ // If current node is not null
            stk.emplace(p); // Push the current node to stack
            p = p->lchild; // Traverse to the left child
        } else {
            p = stk.top(); // Get the top node from stack
            stk.pop(); // Pop the top node from stack
            cout << p->data << ", " << flush; // Print the data of the current node
            p = p->rchild; // Traverse to the right child
        }
    }
    cout << endl;
}

void Tree::iterativePostorder(Node *p) { // Defines a method for performing iterative postorder traversal of a binary tree
    stack<long int> stk; // Initializes a stack for storing nodes
    long int temp; // Initializes a long integer variable for temporarily storing the value of a node
    while (p != nullptr || ! stk.empty()){ // Loops until all nodes in the binary tree have been processed
        if (p != nullptr){ // If the current node is not null
            stk.emplace((long int)p); // Adds the current node to the stack
            p = p->lchild; // Sets the current node to its left child
        } else { // If the current node is null
            temp = stk.top(); // Stores the top value of the stack in the temporary variable
            stk.pop(); // Removes the top value from the stack
            if (temp > 0){ // If the value is positive (i.e. the node is an internal node)
                stk.emplace(-temp); // Adds the negative value of the node to the stack to indicate that its right subtree needs to be processed
                p = ((Node*)temp)->rchild; // Sets the current node to the right child of the node that was just processed
            } else { // If the value is negative (i.e. the node is a leaf node or has already been processed)
                cout << ((Node*)(-1 * temp))->data << ", " << flush; // Prints the value of the leaf node or already processed node
                p = nullptr; // Sets the current node to null to indicate that it has been processed
            }
        }
    }
    cout << endl; // Prints a newline character after all nodes have been processed
}

int main() { // Entry point of the program
    Tree bt; // Initializes a binary tree

    bt.CreateTree(); // Calls the CreateTree method of the binary tree object to create a binary tree
    cout << endl; // Prints a newline character

    cout << "Preorder: " << flush; // Prints a message to indicate that preorder traversal is starting
    bt.Preorder(); // Calls the Preorder method of the binary tree object to perform preorder traversal
    cout << endl; // Prints a newline character after preorder traversal is complete

    cout << "Inorder: " << flush; // Prints a message to indicate that inorder traversal is starting
    bt.Inorder(); // Calls the Inorder method of the binary tree object to perform inorder traversal
    cout << endl; // Prints a newline character after inorder traversal is complete

    cout << "Postorder: " << flush; // Prints a message to indicate that postorder traversal is starting
    bt.Postorder(); // Calls the Postorder method of the binary tree object to perform postorder traversal
    cout << endl; // Prints a newline character after postorder traversal is complete

    cout << "Levelorder: " << flush; // Prints a message to indicate that levelorder traversal is starting
    bt.Levelorder(); // Calls the Levelorder method of the binary tree object to perform levelorder traversal
    cout << endl; // Prints a newline character after levelorder traversal is complete

    cout << "Height: " << bt.Height() << endl; // Prints the height of the binary tree

    cout << "Iterative Preorder: " << flush;
    // Prints a message to indicate that iterative preorder traversal is starting
    bt.iterativePreorder(); // Calls the iterativePreorder method of the binary tree object to perform iterative preorder traversal

    cout << "Iterative Inorder: " " << flush;
    bt.iterativeInorder();

    cout << "Iterative Postorder: " << flush;
    bt.iterativePostorder();

    return 0;
}
