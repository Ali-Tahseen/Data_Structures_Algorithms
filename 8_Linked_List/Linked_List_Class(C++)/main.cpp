// Header files
#include <iostream>
using namespace std;

// Class for Node
class Node
{
public:
    int data;
    Node *next;
};

// Class for LinkedList
class LinkedList
{
private:
    Node *first; // head pointer
public:
    LinkedList(){first=NULL;} // Constructor to initialize first as NULL
    LinkedList(int A[],int n); // Parameterized Constructor
    ~LinkedList(); // Destructor
    void Display(); // To display the linked list
    void Insert(int index,int x); // To insert a node at given index
    int Delete(int index); // To delete a node at given index
    int Length(); // To return the length of linked list
};

// Parameterized Constructor
LinkedList::LinkedList(int A[],int n)
{
    Node *last,*t;
    int i=0;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

// Destructor to delete the nodes of linked list
LinkedList::~LinkedList()
{
    Node *p=first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
}

// To display the linked list
void LinkedList::Display()
{
    Node *p=first;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

// To return the length of linked list
int LinkedList::Length()
{
    Node *p=first;
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

// To insert a node at given index
void LinkedList::Insert(int index,int x)
{
    Node *t,*p=first;
    if(index <0 || index > Length())
        return;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

// To delete a node at given index
int LinkedList::Delete(int index)
{
    Node *p,*q=NULL;
    int x=-1;
    if(index < 1 || index > Length())
        return -1;
    if(index==1)
    {
        p=first;
        first=first->next;
        x=p->data;
        delete p;
    }
    else
    {
        p=first;
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x;
}

// Main function
int main()
{
    int A[]={1,2,3,4,5};
    LinkedList l(A,5);
    l.Insert(3,10);
    l.Delete(3);
    l.Display();
    return 0;
}
