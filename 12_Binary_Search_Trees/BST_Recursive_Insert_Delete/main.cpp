#include <iostream>

using namespace std;

class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class BST{
private:
    Node* root;
public:
    BST(){ root = nullptr; }
    Node* getRoot(){ return root; }
    void iInsert(int key);
    void Inorder(Node* p);
    Node* iSearch(int key);
    Node* rInsert(Node* p, int key);
    Node* rSearch(Node* p, int key);
    Node* Delete(Node* p, int key);
    int Height(Node* p);
    Node* InPre(Node* p);
    Node* InSucc(Node* p);
};

void BST::iInsert(int key) {

    Node* t = root;
    Node* p;
    Node* r;

    // root is empty
    if (root == nullptr){
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }

    while(t != nullptr){
        r = t;
        if (key < t->data){
            t = t->lchild;
        } else if (key > t->data){
            t = t->rchild;
        } else {
            return;
        }
    }

    // Now t points at NULL and r points at insert location
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;

    if (key < r->data){
        r->lchild = p;
    } else {
        r->rchild = p;
    }

}

void BST::Inorder(Node* p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

Node* BST::iSearch(int key) {
    Node* t = root;
    while (t != nullptr){
        if (key == t->data){
            return t;
        } else if (key < t->data){
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }
    return nullptr;
}

Node* BST::rInsert(Node *p, int key) {
    Node* t;
    if (p == nullptr){//if we get to leaf node then we create a new node using this
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        return t;
    }

    if (key < p->data){//if key less than root the Lchild gets filled
        p->lchild = rInsert(p->lchild, key);
    } else if (key > p->data){//if key greater than root the Rchild gets filled
        p->rchild = rInsert(p->rchild, key);
    }
    return p;  // key == p->data
}

Node* BST::rSearch(Node *p, int key) {
    if (p == nullptr){
        return nullptr;
    }

    if (key == p->data){
        return p;
    } else if (key < p->data){
        return rSearch(p->lchild, key);
    } else {
        return rSearch(p->rchild, key);
    }
}

Node* BST::Delete(Node *p, int key) {
    Node* q;

    if (p == nullptr){
        return nullptr;
    }

    if (p->lchild == nullptr && p->rchild == nullptr){// if root doesn't have any branch
        if (p == root){// if p is root
            root = nullptr;// delete root
        }
        delete p;
        return nullptr;
    }

    if (key < p->data){// if key less then root then perform search on left hand side
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){// if key greater then root then perform search on right hand side
        p->rchild = Delete(p->rchild, key);
    } else {// if key if found
        if (Height(p->lchild) > Height(p->rchild)){//the height will determine
            q = InPre(p->lchild);// take inorderpredecessor
            p->data = q->data;// make the child take it's parents place
            p->lchild = Delete(p->lchild, q->data);//delete the child
        } else {
            q = InSucc(p->rchild);// take inordersucessor
            p->data = q->data;// make the child take it's parents place
            p->rchild = Delete(p->rchild, q->data);//delete the child
        }
    }
    return p;
}

int BST::Height(Node *p) {//find the height of the tree
    int x;
    int y;
    if (p == nullptr){// if is null
        return 0;//height is zero
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;// if x>y return x+1 or else return y+1 for y>x
}

Node* BST::InPre(Node *p) {
    while (p && p->rchild != nullptr){//if p not null and rchild is not null
        p = p->rchild;// take right most child
    }
    return p;
}

Node* BST::InSucc(Node *p) {
    while (p && p->lchild != nullptr){//if p not null and lchild is not null
        p = p->lchild;// take left most child
    }
    return p;
}


int main() {

    BST bst;

    // Iterative insert
    bst.iInsert(10);
    bst.iInsert(5);
    bst.iInsert(20);
    bst.iInsert(8);
    bst.iInsert(30);

    // Inorder traversal
    bst.Inorder(bst.getRoot());
    cout << endl;

    // Iterative search
    Node* temp = bst.iSearch(2);
    if (temp != nullptr){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }

    // Recursive search
    temp = bst.rSearch(bst.getRoot(), 20);
    if (temp != nullptr){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }

    // Recursive insert
    bst.rInsert(bst.getRoot(), 50);
    bst.rInsert(bst.getRoot(), 70);
    bst.rInsert(bst.getRoot(), 1);
    bst.Inorder(bst.getRoot());
    cout << "\n" << endl;

    // Inorder predecessor and inorder successor
    BST bs;
    bs.iInsert(50);
    bs.iInsert(10);
    bs.iInsert(40);
    bs.iInsert(20);
    bs.iInsert(30);


    temp = bs.InPre(bs.getRoot());
    cout << "InPre: " << temp->data << endl;

    temp = bs.InSucc(bs.getRoot());
    cout << "InSucc: " << temp->data << endl;

    bs.Inorder(bs.getRoot());
    cout << endl;

    // Delete
    bs.Delete(bs.getRoot(), 50);
    bs.Inorder(bs.getRoot());

    return 0;
}
