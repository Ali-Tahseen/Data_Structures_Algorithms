// Include necessary header files
#include <iostream>

#include <queue>

#include <stack>

using namespace std;

// Define the Node class for the binary tree
class Node {
  public: Node * lchild; // Pointer to the left child of a node
  int data; // Data stored in the node
  Node * rchild; // Pointer to the right child of a node
};

// Define the Tree class for the binary tree
class Tree {
  private: Node * root; // Pointer to the root node of the tree
  public: Tree(); // Constructor
  ~Tree(); // Destructor
  void CreateTree(); // Function to create a binary tree
  void Preorder(Node * p); // Function to traverse the binary tree in preorder recursively
  void Preorder() {
    Preorder(root);
  } // Wrapper function to traverse the binary tree in preorder using the private member root
  void Inorder(Node * p); // Function to traverse the binary tree in inorder recursively
  void Inorder() {
    Inorder(root);
  } // Wrapper function to traverse the binary tree in inorder using the private member root
  void Postorder(Node * p); // Function to traverse the binary tree in postorder recursively
  void Postorder() {
    Postorder(root);
  } // Wrapper function to traverse the binary tree in postorder using the private member root
  void Levelorder(Node * p); // Function to traverse the binary tree in level order
  void Levelorder() {
    Levelorder(root);
  } // Wrapper function to traverse the binary tree in level order using the private member root
  int Height(Node * p); // Function to calculate the height of the binary tree recursively
  int Height() {
    return Height(root);
  } // Wrapper function to calculate the height of the binary tree using the private member root
  void iterativePreorder(Node * p); // Function to traverse the binary tree in preorder iteratively using a stack
  void iterativePreorder() {
    iterativePreorder(root);
  } // Wrapper function to traverse the binary tree in preorder iteratively using a stack using the private member root
  void iterativeInorder(Node * p); // Function to traverse the binary tree in inorder iteratively using a stack
  void iterativeInorder() {
    iterativeInorder(root);
  } // Wrapper function to traverse the binary tree in inorder iteratively using a stack using the private member root
  void iterativePostorder(Node * p); // Function to traverse the binary tree in postorder iteratively using two stacks
  void iterativePostorder() {
    iterativePostorder(root);
  } // Wrapper function to traverse the binary tree in postorder iteratively using two stacks using the private member root
};


Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    // TODO
}

void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;

    root = new Node;
    cout << "Enter root data: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.emplace(root);

    while (! q.empty()){
        p = q.front();
        q.pop();

        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
}

void Tree::Preorder(Node *p) {
    if (p){
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p) {
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

void Tree::Levelorder(Node *p) {
    queue<Node*> q;
    cout << root->data << ", " << flush;
    q.emplace(root);

    while (! q.empty()){
        p = q.front();
        q.pop();

        if (p->lchild){
            cout << p->lchild->data << ", " << flush;
            q.emplace(p->lchild);
        }

        if (p->rchild){
            cout << p->rchild->data << ", " << flush;
            q.emplace(p->rchild);
        }
    }
}

int Tree::Height(Node *p) {
    int l = 0;
    int r = 0;
    if (p == nullptr){
        return 0;
    }

    l = Height(p->lchild);
    r = Height(p->rchild);

    if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
}

void Tree::iterativePreorder(Node *p) {
    stack<Node*> stk;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            cout << p->data << ", " << flush;
            stk.emplace(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativeInorder(Node *p) {
    stack<Node*> stk;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            stk.emplace(p);
            p = p->lchild;
        } else {
            p = stk.top();
            stk.pop();
            cout << p->data << ", " << flush;
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativePostorder(Node *p) {
    stack<long int> stk;
    long int temp;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            stk.emplace((long int)p);
            p = p->lchild;
        } else {
            temp = stk.top();
            stk.pop();
            if (temp > 0){
                stk.emplace(-temp);
                p = ((Node*)temp)->rchild;
            } else {
                cout << ((Node*)(-1 * temp))->data << ", " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}


int main() {

    Tree bt;

    bt.CreateTree();
    cout << endl;

    cout << "Preorder: " << flush;
    bt.Preorder();
    cout << endl;

    cout << "Inorder: " << flush;
    bt.Inorder();
    cout << endl;

    cout << "Postorder: " << flush;
    bt.Postorder();
    cout << endl;

    cout << "Levelorder: " << flush;
    bt.Levelorder();
    cout << endl;

    cout << "Height: " << bt.Height() << endl;

    cout << "Iterative Preorder: " << flush;
    bt.iterativePreorder();

    cout << "Iterative Inorder: " << flush;
    bt.iterativeInorder();

    cout << "Iterative Postorder: " << flush;
    bt.iterativePostorder();

    return 0;
}
