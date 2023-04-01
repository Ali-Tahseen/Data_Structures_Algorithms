#include <stdio.h>
#include <stdlib.h>

// Structure to represent each node in the linked list
struct Node{
    struct Node *prev; // pointer to the previous node
    int data; // data stored in the node
    struct Node *next; // pointer to the next node
}*first=NULL,*Second=NULL; // Global pointer to the first node, initialized to NULL

// Function to create a linked list from an array
void create(int A[],int n){
    struct Node *t, *last; // temporary pointer to the newly created node, last node in the linked list
    int i;

    // Create the first node of the linked list
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first; // Use this last pointer to help create new nodes and join them

    // Create the remaining nodes of the linked list
    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node)); // use t to create new nodes
        t->data=A[i];
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t; // Update the last pointer to point to the newly created node
    }
}

// Function to display the linked list
void Display(struct Node *p){
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

// Function to calculate the length of the linked list
int length(struct Node *p){
    int len =0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

// Function to insert a new node at a given index in the linked list
void Insert(struct Node *p, int index, int x)
{
    struct Node *t; // temporary pointer to the newly created node
    int i;
    if(index <0 || index >length(p))
        return;
    if(index==0)
    {
        // Inserting the new node at the beginning of the linked list
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{
        // Inserting the new node at a position other than the beginning
        for(i=0;i<index-1;i++)
            p=p->next;
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next)p->next->prev=t;
        p->next=t;
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x=-1,i;
    if(index < 1 || index > length(p))
        return -1;

    if(index==1)
    {
        first=first->next;
        if(first)first->prev=NULL;

        x=p->data;
        free(p);
    }
    else{
        for(i=0;i<index-1;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        x=p->data;
        free(p);
    }
    return x;
}

void Reverse1(struct Node *p)
{
    int *t,i=0;
    struct Node *q=p;

    // Create an array to store the data of all nodes
    t=(int *)malloc(sizeof(int)*length(p));

    // Traverse the linked list and store the data in the array
    while(q!=NULL)
    {
        t[i]=q->data;
        q=q->next;
        i++;
    }

    q=p;
    i--;

    // Traverse the linked list again and set the data in reverse order using the array
    while(q!=NULL)
    {
        q->data=t[i];
        q=q->next;
        i--;
    }
}

void Reverse2(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;

    // Traverse the linked list and reverse the links between the nodes
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }

    first=q;
}

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


int main(){
    int A[]={10,20,30,40,50};
    create(A,5);
    Insert(first,4,25); // Insert a new node at index 5 with value 25
    Delete(first, 4);
    printf("\nLength is :%d\n",length(first));
    Reverse3(Second, firsta);
    Display(first); // Display the linked list
    return 0;
}
