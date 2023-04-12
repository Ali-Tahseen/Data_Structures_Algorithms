// Include necessary libraries
#include <iostream>

// Use the standard namespace
using namespace std;

// Define a class for a node in the AVL tree
class Node {
public:
    // Pointers to left and right child nodes
    Node* lchild;
    Node* rchild;
    // Data stored in the node
    int data;
    // Height of the node
    int height;
};

// Define a class for the AVL tree
class AVL {
public:
    // Pointer to the root node of the AVL tree
    Node* root;

    // Constructor for the AVL tree
    AVL(){ root = nullptr; }

    // Helper methods for inserting/deleting
    int NodeHeight(Node* p);
    int BalanceFactor(Node* p);
    Node* LLRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* LRRotation(Node* p);
    Node* RLRotation(Node* p);
    Node* InPre(Node* p);
    Node* InSucc(Node* p);

    // Insert a node with a given key into the AVL tree
    Node* rInsert(Node* p, int key);

    // Traverse the AVL tree in-order
    void Inorder(Node* p);
    void Inorder(){ Inorder(root); }
    Node* getRoot(){ return root; }

    // Delete a node with a given key from the AVL tree
    Node* Delete(Node* p, int key);
};

// Method to calculate the height of a given node in the AVL tree
int AVL::NodeHeight(Node *p) {
    int hl;
    int hr;

    // Calculate the height of the left and right subtrees
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    // Return the maximum of the heights plus one (for the current node)
    return hl > hr ? hl + 1 : hr + 1;
}

// Method to calculate the balance factor of a given node in the AVL tree
int AVL::BalanceFactor(Node *p) {
    int hl;
    int hr;

    // Calculate the height of the left and right subtrees
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    // Return the difference between the heights of the left and right subtrees
    return hl - hr;
}


Node * AVL::LLRotation(Node * p) { // Define a function for left-left rotation
  Node * pl = p -> lchild; // Set pl as the left child of p
  Node * plr = pl -> rchild; // Set plr as the right child of pl

  pl -> rchild = p; // Set p as the right child of pl
  p -> lchild = plr; // Set plr as the left child of p

  // Update height
  p -> height = NodeHeight(p); // Update the height of p
  pl -> height = NodeHeight(pl); // Update the height of pl

  // Update root
  if (root == p) { // If p is the root
    root = pl; // Set pl as the new root
  }
  return pl; // Return pl as the new root
}

Node * AVL::RRRotation(Node * p) { // Define a function for right-right rotation
  Node * pr = p -> rchild; // Set pr as the right child of p
  Node * prl = pr -> lchild; // Set prl as the left child of pr

  pr -> lchild = p; // Set p as the left child of pr
  p -> rchild = prl; // Set prl as the right child of p

  // Update height
  p -> height = NodeHeight(p); // Update the height of p
  pr -> height = NodeHeight(pr); // Update the height of pr

  // Update root
  if (root == p) { // If p is the root
    root = pr; // Set pr as the new root
  }
  return pr; // Return pr as the new root
}

Node * AVL::LRRotation(Node * p) { // Define a function for left-right rotation
  Node * pl = p -> lchild; // Set pl as the left child of p
  Node * plr = pl -> rchild; // Set plr as the right child of pl

  pl -> rchild = plr -> lchild; // Set the left child of plr as the right child of pl
  p -> lchild = plr -> rchild; // Set the right child of plr as the left child of p

  plr -> lchild = pl; // Set pl as the left child of plr
  plr -> rchild = p; // Set p as the right child of plr

  // Update height
  pl -> height = NodeHeight(pl); // Update the height of pl
  p -> height = NodeHeight(p); // Update the height of p
  plr -> height = NodeHeight(plr); // Update the height of plr

  // Update root
  if (p == root) { // If p is the root
    root = plr; // Set plr as the new root
  }
  return plr; // Return plr as the new root
}

Node* AVL::RLRotation(Node *p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    // Update height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    // Update root
    if (root == p){
        root = prl;
    }
    return prl;
}

Node* AVL::InPre(Node *p) {
    while (p && p->rchild != nullptr){
        p = p->rchild;
    }
    return p;
}

Node* AVL::InSucc(Node *p) {
    while (p && p->lchild != nullptr){
        p = p->lchild;
    }
    return p;
}

Node* AVL::rInsert(Node *p, int key) {
    Node* t;
    if (p == nullptr){
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        t->height = 1;  // Starting height from 1 onwards instead of 0
        return t;
    }

    if (key < p->data){
        p->lchild = rInsert(p->lchild, key);
    } else if (key > p->data){
        p->rchild = rInsert(p->rchild, key);
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
        return RLRotation(p);
    }

    return p;
}

void AVL::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

Node* AVL::Delete(Node *p, int key) {
    if (p == nullptr){
        return nullptr;
    }

    if (p->lchild == nullptr && p->rchild == nullptr){
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }

    if (key < p->data){
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    } else {
        Node* q;
        if (NodeHeight(p->lchild) > NodeHeight(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {  // L1 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){  // L-1 Rotation
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){  // R-1 Rotation
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){  // R1 Rotation
        return RLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0){  // L0 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0){  // R0 Rotation
        return RRRotation(p);
    }

    return p;
}


int main() {

    AVL tree;

    int A[] = {10, 20, 30, 25, 28, 27, 5};
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        tree.root = tree.rInsert(tree.root, A[i]);
    }

    tree.Inorder();
    cout << endl;

    tree.Delete(tree.root, 28);

    tree.Inorder();
    cout << endl;

    return 0;
}
