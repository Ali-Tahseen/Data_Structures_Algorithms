#include <iostream>

// BST can only be in sorted tree where left side is smaller than root and right side is bigger than root

// Include necessary headers and namespaces
using namespace std;

// Define a Node class for the binary search tree
class Node {
  public: Node * lchild; // Pointer to the left child node
  int data; // Data stored in the node
  Node * rchild; // Pointer to the right child node
};

// Define a binary search tree class
class BST {
  private: Node * root; // Pointer to the root node of the tree
  public:
    // Constructor to initialize the root node to nullptr
    BST() {
      root = nullptr;
    }

  // Getter function to return the root node
  Node * getRoot() {
    return root;
  }

  // Function to insert a new node into the binary search tree
  void Insert(int key);

  // Function to perform an inorder traversal of the binary search tree
  void Inorder(Node * p);

  // Function to search for a node with a given key in the binary search tree
  Node * Search(int key);

  // Recursive function to search for a node with a given key in the binary search tree
  Node * RSearch(Node * t, int key);
};

// Function to insert a new node into the binary search tree
void BST::Insert(int key) {

  Node * t = root; // Pointer to traverse the tree
  Node * p; // Pointer to hold the new node being inserted
  Node * r; // Pointer to hold the tail node, i.e., the last node before t becomes null

  // If the root is empty, create a new node and make it the root
  if (root == nullptr) {
    p = new Node;
    p -> data = key;
    p -> lchild = nullptr;
    p -> rchild = nullptr;
    root = p;
    return;
  }

  // Traverse the tree until a null pointer is reached
  while (t != nullptr) {
    r = t;
    if (key < t -> data) { // If the key to be inserted is smaller than the current node's data, move left
      t = t -> lchild;
    } else if (key > t -> data) { // If the key to be inserted is greater than the current node's data, move right
      t = t -> rchild;
    } else { // If the key to be inserted already exists in the tree, return
      return;
    }
  }

  // Now t points at null and r points at the last node before t became null
  p = new Node;
  p -> data = key;
  p -> lchild = nullptr;
  p -> rchild = nullptr;

  // Insert the new node in the correct position in the tree
  if (key < r -> data) {
    r -> lchild = p;
  } else {
    r -> rchild = p;
  }

}

// Function to perform an inorder traversal of the binary search tree
void BST::Inorder(Node * p) {
  if (p) { // If the node is not null
    Inorder(p -> lchild); // Traverse the left subtree
    cout << p -> data << ", " << flush; // Print the node's data
    Inorder(p -> rchild); // Traverse the right subtree
  }
}

// Define the Search function for BST class that searches for a given key and returns the corresponding node
Node * BST::Search(int key) {
  Node * t = root;
  // While loop to traverse the tree starting from root
  while (t != nullptr) {
    if (key == t -> data) {
      // If the key is found in the current node, return the node
      return t;
    } else if (key < t -> data) {
      // If the key is smaller than the current node's data, move to the left child
      t = t -> lchild;
    } else {
      // If the key is greater than the current node's data, move to the right child
      t = t -> rchild;
    }
  }
  // If the key is not found in the tree, return null pointer
  return nullptr;
}

// Define the RSearch function for BST class that recursively searches for a given key and returns the corresponding node
Node * BST::RSearch(Node * t, int key) {
  if (t == nullptr) {
    // If the current node is null, return null pointer
    return nullptr;
  }
  if (key == t -> data) {
    // If the key is found in the current node, return the node
    return t;
  } else if (key < t -> data) {
    // If the key is smaller than the current node's data, recursively call the function on the left child
    return RSearch(t -> lchild, key);
  } else {
    // If the key is greater than the current node's data, recursively call the function on the right child
    return RSearch(t -> rchild, key);
  }
}

int main() {
  BST bst;

  // Insert some values into the BST
  bst.Insert(10);
  bst.Insert(5);
  bst.Insert(20);
  bst.Insert(8);
  bst.Insert(30);

  // Perform inorder traversal of the BST and print the values
  bst.Inorder(bst.getRoot());
  cout << endl;

  // Search for a specific value in the BST using RSearch
  Node * temp = bst.RSearch(bst.getRoot(), 8);
  if (temp != nullptr) {
    cout << temp -> data << endl;
  } else {
    cout << "Element not found" << endl;
  }

  return 0;
}
