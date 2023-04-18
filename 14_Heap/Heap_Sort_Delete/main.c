#include <stdio.h>   // Include necessary header files

void Insert(int A[], int n) {   // Define function to insert an element into the heap
    int i = n, temp;
    temp = A[i];
    while (i > 1 && temp > A[i/2]) {   // While the new element is greater than its parent and not at the root
        //while (i > 1 && temp < A[i/2]) for min heap
        A[i] = A[i/2];   // Swap the new element with its parent
        i = i/2;   // Move up to the parent index
    }
    A[i] = temp;   // Insert the new element in its correct position
}

int Delete(int A[], int n) {   // Define function to delete the maximum element from the heap
    int i, j, x, temp, val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i*2;
    while (j <= n-1) {   // While the node being visited has a child
        if (j < n-1 && A[j+1] > A[j])   // If the right child is greater than the left child
            j = j+1;   // Move to the right child
        if (A[i] < A[j]) {   // If the current node is less than the child node
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;   // Swap the current node with the child node
            i = j;
            j = 2*j;
        }
        else
            break;   // Otherwise, the heap property is satisfied
    }
    return val;   // Return the value of the maximum element that was deleted
}

int main() {
    int H[] = {0, 14, 15, 5, 20, 30, 8, 40};   // Define the heap
    int i;
    for (i = 2; i <= 7; i++) {   // Loop over all elements in the heap except the root
        Insert(H, i);   // Insert the current element into the heap
    }
    for (i = 7; i > 1; i--) {   // Loop over all elements in the heap except the root
        Delete(H, i);   // Delete the maximum element from the heap
    }
    for (i = 1; i <= 7; i++) {   // Loop over all elements in the heap
        printf("%d ", H[i]);   // Print the current element
    }
    printf("\n");   // Print a newline character
    return 0;   // End the program
}
