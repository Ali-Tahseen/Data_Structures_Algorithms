#include <stdio.h>
#include <stdlib.h>

// Define the Stack structure
struct Stack
{
    int size;  // Maximum size of the stack
    int top;   // Index of the top element in the stack
    int *S;    // Pointer to the array that holds the stack elements
};

// Function to create a stack
void create(struct Stack *st)
{
    printf("Enter Size");
    scanf("%d",&st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

// Function to display the stack elements
void Display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        printf("%d ", st.S[i]);
    }
    printf("\n");
}

// Function to push an element to the stack
void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

// Function to pop an element from the stack
int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

// Function to get the value of the element at a given index in the stack
int peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
    {
        printf("Invalid Index \n");
    }
    x = st.S[st.top - index + 1];
    return x;
}

// Function to check if the stack is empty
int isEmpty(struct Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    return 0;
}

// Function to check if the stack is full
int isFull(struct Stack st)
{
    return st.top == st.size - 1;
}

// Function to get the value of the top element in the stack
int stackTop(struct Stack st)
{
    if (!isEmpty(st))
    {
        return st.S[st.top];
    }
    return -1;
}

// Main function
int main()
{
    struct Stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    printf("%d \n", peek(st, 2));
    Display(st);
    return 0;
}
