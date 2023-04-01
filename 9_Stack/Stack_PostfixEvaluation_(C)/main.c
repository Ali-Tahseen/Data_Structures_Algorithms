// includes necessary header files
#include <stdio.h>
#include <stdlib.h>
#include<strings.h>

// define a node for the stack
struct Node
{
    int data;           // data stored in the node
    struct Node *next;  // pointer to the next node
}*top=NULL;             // initialize the top of the stack to NULL

// push an element onto the stack
void push(int x)
{
    struct Node *t;     // create a new node
    t=(struct Node*)malloc(sizeof(struct Node));   // allocate memory for the new node
    if(t==NULL)
        printf("stack is full\n");                 // check if memory allocation failed
    else
    {
        t->data=x;                                  // set the data of the new node to the given value
        t->next=top;                                // point the next of the new node to the previous top of the stack
        top=t;                                      // set the new node as the new top of the stack
    }
}

// pop an element from the stack
int pop()
{
    struct Node *t;     // create a new node
    int x=-1;           // initialize the value to be returned
    if(top==NULL)
        printf("Stack is Empty\n");                 // check if stack is empty
    else
    {
        t=top;                                      // set the new node to be the previous top of the stack
        top=top->next;                              // set the new top of the stack to be the next node
        x=t->data;                                  // set the value to be returned to be the data of the previous top node
        free(t);                                    // free memory of the previous top node
    }
    return x;                                           // return the popped value
}

// display the elements in the stack
void Display()
{
    struct Node *p;
    p=top;                                              // set a pointer to the top of the stack
    while(p!=NULL)                                      // loop through the stack
    {
        printf("%d ",p->data);                          // print the data of the current node
        p=p->next;                                      // move the pointer to the next node
    }
    printf("\n");                                       // print a newline character
}

// check if an expression is balanced
int isBalanced(char *exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            push(exp[i]);                               // push opening parentheses onto the stack
        else if(exp[i]==')')
        {
            if(top==NULL)                               // check if stack is empty
                return 0;                               // return false if stack is empty
            pop();                                      // pop the top element of the stack
        }
    }
    if(top==NULL)                                       // check if stack is empty
        return 1;                                       // return true if stack is empty
    else
        return 0;                                       // return false if stack is not empty
}

// check the precedence of an operator
int pre(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    return 0;
}

// check if a character is an operand
int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;                                       // return false if character is an operator
    else
        return 1;                                       // return true if character is an operand
}

// convert an infix expression to postfix
char * InToPost(char *infix)
{
    int i=0,j=0;
    char *postfix;
    long len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));
    push('#'); // push a sentinel value to the stack
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else
        {
            if(pre(infix[i])>pre(top->data))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++]=pop();
            }
        }
    }
    while(top!=NULL && top->data != '#') // add remaining operators to postfix
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}

// Function to evaluate postfix expression
int Eval(char *postfix)
{
    int i=0;
    int x1,x2,r=0 ;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            if(top==NULL) // check if stack is empty before popping elements
            {
                printf("Invalid postfix expression\n");
                return -1;
            }
            x2=pop();
            if(top==NULL) // check if stack is empty before popping elements
            {
                printf("Invalid postfix expression\n");
                return -1;
            }
            x1=pop();
            switch(postfix[i])
            {
                case '+':r=x1+x2; break;
                case '-':r=x1-x2; break;
                case '*':r=x1*x2; break;
                case '/':r=x1/x2; break;
            }
            push(r);
        }
    }
    if(top==NULL) // check if stack is empty before returning the top element
    {
        printf("Invalid postfix expression\n");
        return -1;
    }
    return top->data;
}


int main()
{
    char *infix="234*+82/-";
    push('#'); // push a sentinel value to the stack
    char *postfix=InToPost(infix); // convert an infix expression to postfix
    printf("%s\n", postfix);
    printf("Result is %d\n", Eval(postfix)); // evaluate the postfix expression
    return 0;
}
