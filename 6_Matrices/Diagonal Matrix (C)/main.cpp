#include <iostream>

using namespace std;

// Define a struct for the matrix, containing an integer array and the size of the matrix
struct Matrix
{
    int A[10];
    int n;
};

// Function to set the value of a matrix element at position (i,j) to x
void set(struct Matrix *m, int i, int j, int x)
{
    // Check if the row and column indices are within the bounds of the matrix
    if(i<=m->n && j<=m->n && i>0 && j>0) {
        // Check if the element is on the diagonal
        if(i==j) {
            // Set the value of the element at position (i,j) to x
            m->A[i-1] = x;
        }
    }
}

// Function to get the value of a matrix element at position (i,j)
int get(struct Matrix m, int i, int j)
{
    // Check if the row and column indices are within the bounds of the matrix
    if(i<=m.n && j<=m.n && i>0 && j>0) {
        // Check if the element is on the diagonal
        if(i==j) {
            // Return the value of the element at position (i,j)
            return m.A[i-1];
        }
    }
    // If the indices are out of bounds or the element is not on the diagonal, return 0
    return 0;
}

// Function to display the matrix elements in diagonal form
void Display(struct Matrix m)
{
    int i,j;
    for(i=0;i<m.n;i++)
    {
        for(j=0;j<m.n;j++)
        {
            // If the element is on the diagonal, print its value
            if(i==j)
                printf("%d ", m.A[i]);
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
    // Declare a Matrix struct with size n=4
    struct Matrix m;
    m.n=4;

    // Set the values of the diagonal elements of the matrix
    set(&m,1,1,5);
    set(&m,2,2,8);
    set(&m,3,3,9);
    set(&m,4,4,12);

    // Get the value of the element at position (2,2) in the matrix and print it
    printf("%d \n", get(m,2,2));

    // Display the matrix elements in diagonal form
    Display(m);

    return 0;
}
// This code defines a struct for a matrix and provides functions to set and get the values of the diagonal elements of the matrix, as well as a function to display the matrix elements in diagonal form.

// In the main function, a Matrix struct is declared with size n=4, and the set function is used to set the values of the diagonal elements of the matrix. The get function is then used to retrieve the value at position (2,2) of the matrix, which is printed to the console. Finally, the Display function is called to print the matrix elements in diagonal form.

// The code is appropriately commented to explain the purpose of each function and the logic behind the implementation.
