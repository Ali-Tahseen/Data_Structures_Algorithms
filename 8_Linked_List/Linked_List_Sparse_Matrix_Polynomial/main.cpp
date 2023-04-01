// Implementation of Polynomial Linked List
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure of node representing each term in the polynomial
struct Node
{
    int coeff;          // coefficient of the term
    int exp;            // exponent of the term
    struct Node *next;  // pointer to the next term
}*poly=NULL;            // pointer to the polynomial list, initialized to NULL

// Function to create the polynomial list
void create()
{
    struct Node *t, *last=NULL;     // create a node to hold each term and a pointer to the last node
    int num, i;                     // number of terms and loop counter

    printf("Enter number of terms: ");
    scanf("%d", &num);              // read the number of terms

    printf("Enter each term with coeff and exp: \n");
    for (i=0; i<num; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));    // create a new node
        scanf("%d%d", &t->coeff, &t->exp);                 // read the coefficient and exponent of the term
        t->next = NULL;                                    // set the next pointer to NULL

        if (poly == NULL)           // if this is the first term in the list
        {
            poly = last = t;        // set both the head and the last pointers to this node
        }
        else                        // otherwise, add the node to the end of the list
        {
            last->next = t;         // set the next pointer of the last node to the new node
            last = t;               // set the last pointer to the new node
        }
    }
}

// Function to display the polynomial
void Display(struct Node *p)
{
    while (p)
    {
        printf("%dx%d + ", p->coeff, p->exp);   // print the coefficient and exponent of the term
        p = p->next;                            // move to the next node
    }
    printf("\n");
}

// Function to evaluate the polynomial for a given value of x
long Eval(struct Node *p, int x)
{
    long val = 0;       // variable to hold the final value of the polynomial

    while (p)
    {
        val += p->coeff * pow(x, p->exp);   // add the value of the current term to the total value
        p = p->next;                        // move to the next node
    }

    return val;         // return the final value of the polynomial
}

// Main function
int main()
{
    create();                       // create the polynomial list
    Display(poly);                  // display the polynomial
    printf("%ld\n", Eval(poly, 1)); // evaluate the polynomial for x=1 and print the result
    return 0;
}
