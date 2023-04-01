#include <iostream>
#include <cstring>
using namespace std;

class Stack{
private:
    int size;
    int top;
    char* S;
public:
    Stack(int size);  // Stack constructor
    ~Stack();         // Stack destructor
    void push(char x); // push operation
    char pop();        // pop operation
    char peek(int index); // returns the element from the top with given index
    int isFull();      // check if stack is full
    int isEmpty();     // check if stack is empty
    void display();    // display the stack
    char stackTop();   // return the top element of the stack
};

Stack::Stack(int size) { // Stack constructor
    this->size = size;
    top = -1;
    S = new char[size];
}

Stack::~Stack() {  // Stack destructor
    delete[] S;
}

void Stack::push(char x) { // push operation
    if (isFull()){
        cout << "Stack Overflow!" << endl;
    } else {
        top++;
        S[top] = x;
    }
}

char Stack::pop() { // pop operation
    char x = 1;
    if (isEmpty()){
        cout << "Stack Underflow!" << endl;
    } else {
        x = S[top];
        top--;
    }
    return x;
}

char Stack::peek(int index) { // returns the element from the top with given index
    char x = -1;
    if (top-index+1 < 0 || top-index+1 == size){
        cout << "Invalid position!" << endl;
    } else {
        x = S[top-index+1];
    }
    return x;
}

int Stack::isFull() {  // check if stack is full
    if (top == size-1){
        return 1;
    }
    return 0;
}

int Stack::isEmpty() { // check if stack is empty
    if (top == -1){
        return 1;
    }
    return 0;
}

void Stack::display() { // display the stack
    for (int i=top; i>=0; i--){
        cout << S[i] << " | " << flush;
    }
    cout << endl;
}

char Stack::stackTop() { // return the top element of the stack
    if (isEmpty()){
        return -1;
    }
    return S[top];
}

bool isBalanced(char* exp){

    // Create a stack
    Stack stk((int)strlen(exp));

    // Process expression
    for (int i=0; i<strlen(exp); i++){

        // ( found: Push to stack
        if (exp[i] == '('){
            stk.push(exp[i]);

            // ) found
        } else if (exp[i] == ')'){

            // ) and stack is empty: Unbalanced expression
            if (stk.isEmpty()){
                return false;

            // ) and stack is not empty
            } else {
                stk.pop();
            }
        }
    }

    // If stack is empty then balanced else unbalanced
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
