#include <iostream>

using namespace std;

template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;  // Print the label for the vector
    for (int i=0; i<n; i++){  // Loop through each element in the vector
        cout << vec[i] << flush;  // Print the current element
        if (i < n-1){  // If the current element is not the last element, print a comma and a space
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;  // Print the closing bracket and a newline character
}

void swap(int* x, int* y){
    int temp = *x;  // Store the value of *x in a temporary variable
    *x = *y;        // Assign the value of *y to *x
    *y = temp;      // Assign the value of temp to *y
}

void SelectionSort(int A[], int n){
    for (int i=0; i<n-1; i++){  // Loop through each element in the array
        int j;
        int k;
        for (j=k=i; j<n; j++){  // Find the minimum element in the unsorted part of the array
            if (A[j] < A[k]){
                k = j;
            }
        }
        swap(&A[i], &A[k]);  // Swap the minimum element with the first element in the unsorted part of the array
    }
}

int main() {

    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};  // Initialize an array of integers
    int n = sizeof(A)/sizeof(A[0]);  // Calculate the size of the array
    Print(A, n, "\t\tA");  // Print the original array

    SelectionSort(A, n);  // Sort the array using Selection Sort
    Print(A, n, " Sorted A");  // Print the sorted array

    return 0;  // End the program
}
