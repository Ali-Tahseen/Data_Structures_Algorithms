// Reverse a Linked List

#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

// Function to display the Linked List
void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

// Function to count the number of nodes in the linked list
int count(struct Node *p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}


// Function to create a Linked List
void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

// Function to reverse the Linked List using an array
void Reverse1(struct Node *p)
{
    int *A,i=0;
    struct Node *q=p;

    // Create an array and store the elements of the Linked List
    A=(int *)malloc(sizeof(int)*count(p));
    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }

    q=p;
    i--;

    // Update the elements of the Linked List using the array in reverse order
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}

// Function to reverse the Linked List using two pointers this is more preferred than Reverse 1
void Reverse2(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }

    first=q;
}

// Function to reverse the Linked List using recursion
void Reverse3(struct Node *q,struct Node *p)
{
    if(p)
    {
        Reverse3(p,p->next);
        p->next=q;
    }
    else
        first=q;
}

int main()
{
    int A[]={10,20,40,50,60};
    create(A,5);

    Reverse3(NULL,first); // Call the function to reverse the Linked List

    Display(first); // Display the reversed Linked List

    return 0;
}
