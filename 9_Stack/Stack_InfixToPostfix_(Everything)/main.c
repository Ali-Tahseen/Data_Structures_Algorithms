// include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// define a Node struct with character data and a pointer to the next Node
struct Node {
    char data;
    struct Node *next;
} *top=NULL;

// define a function to push a character onto the top of the stack
void push(char x) {
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node)); // allocate memory for the new Node
    if (t == NULL)
        printf("stack is full\n");
    else {
        t->data = x; // assign data to the new Node
        t->next = top; // link the new Node to the current top Node
        top = t; // update the top Node to the new Node
    }
}

// define a function to pop the top character off the stack and return it
char pop() {
    struct Node *t;
    char x = -1;
    if (top == NULL)
        printf("Stack is Empty\n");
    else {
        t = top; // assign t to the top Node
        top = top->next; // update the top Node to the next Node in the stack
        x = t->data; // assign x to the data of the top Node
        free(t); // free the memory allocated for the top Node
    }
    return x;
}

// define a function to display the contents of the stack
void Display() {
    struct Node *p;
    p = top; // assign p to the top Node
    while (p != NULL) {
        printf("%d ", p->data); // print the data of the current Node
        p = p->next; // move to the next Node in the stack
    }
    printf("\n");
}

// define a function to check if a given expression is balanced
int isBalanced(char *exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            push(exp[i]); // push an opening parenthesis onto the stack
        else if (exp[i] == ')') {
            if (top == NULL)
                return 0; // return 0 if a closing parenthesis is encountered and the stack is empty
            pop(); // pop the top element off the stack if a closing parenthesis is encountered
        }
    }
    if (top == NULL)
        return 1; // return 1 if the stack is empty at the end of the expression
    else
        return 0;
}

// define a function to return the precedence of a given operator
int pre(char x) {
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

// define a function to check if a given character is an operand

int isOperand(char x)
{
    // Check if the character is an operand or not
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    else
        return 1;
}

char * InToPost(char *infix)
{
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));

    // Loop through the infix expression
    while(infix[i]!='\0')
    {
        // If it's an operand, add it to the postfix expression
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            // If it's an operator, check the precedence
            if(pre(infix[i])>pre(top->data))
                push(infix[i++]); // Push to the stack if the precedence is higher
            else
            {
                postfix[j++]=pop(); // Pop from the stack and add to postfix if the precedence is lower or equal
            }
        }
    }

    // Pop any remaining elements from the stack and add to the postfix expression
    while(top!=NULL)
        postfix[j++]=pop();

    // Add null terminator to the end of the postfix expression
    postfix[j]='\0';

    // Return the postfix expression
    return postfix;
}

int main()
{
    // Define the infix expression and push '#' to the stack
    char *infix="a+b*c-d/e";
    push('#');

    // Convert the infix expression to postfix and print it
    char *postfix=InToPost(infix);
    printf("%s ",postfix);

    // End the program
    return 0;
}
