// Inserting in a Sorted Linked List

#include <stdio.h>
#include <stdlib.h>

// define a Node structure with data and next pointer
struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL; // initialize three Node pointers as NULL

// function to display elements in the linked list
void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

// function to create a linked list from an array
void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node)); // allocate memory for first Node
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node)); // allocate memory for new Node
        t->data=A[i];
        t->next=NULL;
        last->next=t; // link last Node with new Node
        last=t; // move last pointer to new Node
    }
}

// function to insert an element in a sorted linked list
void SortedInsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL; // define two Node pointers, t and q
    t=(struct Node*)malloc(sizeof(struct Node)); // allocate memory for new Node
    t->data=x;
    t->next=NULL;
    if(first==NULL) // if linked list is empty
        first=t;
    else
    {
        while(p && p->data<x) // traverse the linked list until a node with greater value is found
        {
            q=p; // update q as the previous node
            p=p->next; // update p as the next node
        }
        if(p==first) // insert at the beginning
        {
            t->next=first;
            first=t;
        }
        else // insert in the middle or end
        {
            t->next=q->next; // link new Node with next Node
            q->next=t; // link previous Node with new Node
        }
    }
}

// main function
int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);
    SortedInsert(first,15); // insert 15 in the sorted linked list
    Display(first); // display the linked list
    return 0;
}
