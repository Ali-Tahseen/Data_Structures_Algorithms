// AVL Tree
#include <stdio.h>

// Node struct
struct Node
{
    struct Node *lchild; // left child pointer
    int data;            // integer data stored in node
    int height;          // height of the node
    struct Node *rchild; // right child pointer
}*root=NULL;

// Function to calculate the height of a node
int NodeHeight(struct Node *p)
{
    int hl,hr;
    // Calculate the height of left child, if it exists, otherwise 0
    hl = p && p->lchild ? p->lchild->height : 0;
    // Calculate the height of right child, if it exists, otherwise 0
    hr = p && p->rchild ? p->rchild->height : 0;
    // Return the maximum of the two heights plus 1
    return hl > hr ? hl + 1 : hr + 1;
}

// Function to calculate the balance factor of a node
int BalanceFactor(struct Node *p)
{
    int hl,hr;
    // Calculate the height of left child, if it exists, otherwise 0
    hl = p && p->lchild ? p->lchild->height : 0;
    // Calculate the height of right child, if it exists, otherwise 0
    hr = p && p->rchild ? p->rchild->height : 0;
    // Return the difference between the two heights
    return hl - hr;
}

// Function to perform a left-left rotation
struct Node * LLRotation(struct Node *p)
{
    // Store pointers to left child and its right child
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    // Perform the rotation
    pl->rchild = p;
    p->lchild = plr;
    // Update the heights of the nodes involved in the rotation
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    // If the root node has changed, update the root pointer
    if(root == p)
        root = pl;
    // Return the new root of the subtree
    return pl;
}


// Function to perform a left-right rotation
struct Node * LRRotation(struct Node *p)
{
    // Store pointers to left child and its right child
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    // Perform the rotation
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    // Update the heights of the nodes involved in the rotation
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);
    // If the root node has changed, update the root pointer
    if(root == p)
        root = plr;
    // Return the new root of the subtree
    return plr;
}

// Function to perform a right-right rotation
struct Node * RRRotation(struct Node *p)
{
    // Return null because this function is not implemented
    return NULL;
}

// Function to perform a right-left rotation
struct Node * RLRotation(struct Node *p)
{
    // Return null because this function is not implemented
    return NULL;
}


// Function to recursively insert a new node with the given key into the AVL tree rooted at p
struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t = NULL;
    // If the current node is null, create a new node with the given key and return it
    if (p == NULL) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    // Recursively insert the node into the appropriate subtree
    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);
    // Update the height of the current node
    p->height = NodeHeight(p);
    // Check if the tree is unbalanced and perform the appropriate rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);
    // Return the current node
    return p;
}

// Main function
int main()
{
    // Insert a node with key 50 into the AVL tree rooted at root
    root = RInsert(root, 50);
    // Insert a node with key 10 into the AVL tree rooted at root
    RInsert(root, 10);
    // Insert a node with key 20 into the AVL tree rooted at root
    RInsert(root, 20);
    // Return 0 to indicate successful execution
    return 0;
}
