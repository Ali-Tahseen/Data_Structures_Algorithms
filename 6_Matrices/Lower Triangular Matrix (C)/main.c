// check video 146-147 for more details

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a lower triangular matrix
struct Matrix
{
    int *A; // Pointer to store matrix elements
    int n; // Size of the matrix
};



// Function to set the value of a matrix element at position (i,j) to x
// This is done using column major mapping instead of row major mapping operation check video 148 for more clarification of the formula
void Set(struct Matrix *m,int i,int j,int x)
{
    // Check if the element is in the lower triangular part of the matrix (i.e., i>=j)
    if(i>=j)
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j]=x;
        // m->A[i*(i-1)/2=j-1]=x; for row major mapping
}

// Function to get the value of a matrix element at position (i,j)
int Get(struct Matrix m,int i,int j)
{
    // Check if the element is in the lower triangular part of the matrix (i.e., i>=j)
    if(i>=j)
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]; // m.A[i*(i-1)/2+j-1] is for row major mapping
    else
        return 0;
}

// Function to display the matrix elements
void Display(struct Matrix m)
{
    int i,j;
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            // If the element is in the lower triangular part of the matrix, print its value
            if(i>=j)
                printf("%d ",m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]); // m.A[i*(i-1)/2+j-1] for row major mapping
            // Otherwise, print 0
            else
                printf("0 ");
        }
        // Print a new line after each row
        printf("\n");
    }
}

// Main function
int main()
{
    struct Matrix m;
    int i,j,x;

    // Prompt the user to enter the size of the matrix
    printf("Enter Dimension: ");
    scanf("%d",&m.n);

    // Allocate memory for the matrix elements in heap
    m.A=(int *)malloc(m.n*(m.n+1)/2*sizeof(int));

    // Prompt the user to enter all the elements of the matrix
    printf("Enter all elements:\n");
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            scanf("%d",&x);
            // Set the value of the element at position (i,j) to x
            Set(&m,i,j,x);
        }
    }

    printf("\n\n");
    // Display the matrix elements
    Display(m);

    return 0;
}
