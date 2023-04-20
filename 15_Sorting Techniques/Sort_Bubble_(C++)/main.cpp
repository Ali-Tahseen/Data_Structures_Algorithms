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

void BubbleSort(int A[], int n){
    int flag = 0;
    for (int i=0; i<n-1; i++){  // Loop through each element in the array
        for (int j=0; j<n-1-i; j++){  // Loop through each element in the unsorted part of the array
            if (A[j] > A[j+1]){  // If the current element is greater than the next element
                swap(&A[j], &A[j+1]);  // Swap the current element with the next element
                flag = 1;  // Set the flag to indicate that a swap has occurred
            }
        }
        if (flag == 0){  // If no swaps occurred in the inner loop, the array is already sorted, so return
            return;
        }
    }
}

int main() {

    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};  // Initialize an array of integers
    int n = sizeof(A)/sizeof(A[0]);  // Get the size of the array
    Print(A, n, "\t\tA");  // Print the original array

    BubbleSort(A, n);  // Sort the array using Bubble Sort
    Print(A, n, " Sorted A");  // Print the sorted array

    return 0;  // End the program
}
