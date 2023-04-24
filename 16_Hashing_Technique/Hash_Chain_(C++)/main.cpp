// Including the input/output stream header file 'iostream'
#include <iostream>

// Importing the 'std' namespace
using namespace std;

// Linked List node class
class Node {

public:
    int data;
    Node* next;
};

// Hash Table class
class HashTable {

public:
    Node** HT;
    HashTable();
    int hash(int key);
    void Insert(int key);
    int Search(int key);
    ~HashTable();
};

// Constructor for the HashTable class
HashTable::HashTable() {
    // Initializing the hash table with an array of 10 pointers
    HT = new Node*[10];

    // Initializing each pointer in the array to NULL
    for (int i = 0; i < 10; i++) {
        HT[i] = nullptr;
    }
}

// Function to calculate the hash value for a given key
int HashTable::hash(int key) {
    return key % 10;
}

// Function to insert a node with a given value in the hash table
void HashTable::Insert(int key) {
    // Calculating the index for the given key
    int hIdx = hash(key);
    Node* t = new Node;
    t->data = key;
    t->next = nullptr;

    // Case: No nodes in the linked list
    if (HT[hIdx] == nullptr) {
        HT[hIdx] = t;
    } else {
        Node* p = HT[hIdx];
        Node* q = HT[hIdx];

        // Traverse to find the correct position to insert the new node
        while (p && p->data < key) {
            q = p;
            p = p->next;
        }

        // Case: Insert position is at the beginning of the linked list
        if (q == HT[hIdx]) {
            t->next = HT[hIdx];
            HT[hIdx] = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
}

// Function to search for a node with a given value in the hash table
int HashTable::Search(int key) {
    // Calculating the index for the given key
    int hIdx = hash(key);
    Node* p = HT[hIdx];

    // Traverse the linked list to find the node with the given value
    while (p) {
        if (p->data == key) {
            return p->data;
        }
        p = p->next;
    }
    return -1;
}

// Destructor for the HashTable class
HashTable::~HashTable() {
    for (int i = 0; i < 10; i++) {
        Node* p = HT[i];

        // Freeing the memory allocated for each node in the linked list
        while (HT[i]) {
            HT[i] = HT[i]->next;
            delete p;
            p = HT[i];
        }
    }
    // Freeing the memory allocated for the array of pointers to linked lists
    delete[] HT;
}

// Main function
int main() {
    // Initializing an array of integers
    int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};

    // Calculating the size of the array
    int n = sizeof(A) / sizeof(A[0]);

    // Creating a HashTable object
    HashTable H;

    // Inserting each integer in the array into the hash table
    for (int i = 0; i < n; i++) {
        H.Insert(A[i]);
    }

    // Searching for a key in the hash table and printing the result
    cout << "Successful Search" << endl;
    int key = 6;
    int value = H.Search(key);
    cout << "Key: " << key << ", Value: " << value << endl;

    // Searching for a key that is not in the hash table and printing the result
    cout << "Unsuccessful Search" << endl;
    key = 95;
    value = H.Search(key);
    cout << "Key: " << key << ", Value: " << value << endl;

    // Returning 0 to indicate successful execution of the program
    return 0;
}
