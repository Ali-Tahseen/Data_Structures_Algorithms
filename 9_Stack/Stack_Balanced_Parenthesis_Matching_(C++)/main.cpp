#include <iostream>
#include <cstring>
using namespace std;

class Node {
public:
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack();
    ~Stack();
    void push(char x);
    char pop();
    char peek(int index);
    int isEmpty();
    int isFull();
    char stackTop();
};

// Constructor
Stack::Stack() {
    top = nullptr;
}

// Destructor
Stack::~Stack() {
    Node* p = top;
    while (top) {
        top = top->next;
        delete p;
        p = top;
    }
}

// Add item to the top of the stack
void Stack::push(char x) {
    Node* t = new Node;
    if (t == nullptr) {
        cout << "Stack Overflow!" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// Remove item from the top of the stack
char Stack::pop() {
    Node* p;
    char x = -1;
    if (top == nullptr) {
        cout << "Stack Underflow!" << endl;
    } else {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}

// Check if the stack is full
int Stack::isFull() {
    Node* t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}

// Check if the stack is empty
int Stack::isEmpty() {
    return top ? 0 : 1;
}

// Return the top item of the stack
char Stack::stackTop() {
    if (top) {
        return top->data;
    }
    return -1;
}

// Return the item at a specified index of the stack
char Stack::peek(int index) {
    if (isEmpty()) {
        return -1;
    } else {
        Node* p = top;

        for (int i=0; p != nullptr && i<index-1; i++) {
            p = p->next;
        }

        if (p != nullptr) {
            return p->data;
        } else {
            return -1;
        }
    }
}

// Check if a given expression has balanced parentheses
int isBalanced(char* exp) {
    Stack stk;

    for (int i=0; i<strlen(exp); i++) {
        if (exp[i] == '(') {
            stk.push(exp[i]);
        } else if (exp[i] == ')') {
            if (stk.isEmpty()) {
                return false;
            } else {
                stk.pop();
            }
        }
    }
    return stk.isEmpty() ? true : false;
}

int main() {

    char E[] = "((a+b)*(c-d))";
    cout << isBalanced(E) << endl;

    char F[] = "((a+b)*(c-d)))";
    cout << isBalanced(F) << endl;

    char G[] = "(((a+b)*(c-d))";
    cout << isBalanced(G) << endl;

    return 0;
}
