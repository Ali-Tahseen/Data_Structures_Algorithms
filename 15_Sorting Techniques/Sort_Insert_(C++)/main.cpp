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

void InsertionSort(int A[], int n){
    for (int i=1; i<n; i++){  // Loop through each element in the array
        int j = i-1;
        int x = A[i];  // Store the current element in x
        while (j>-1 && A[j] > x){  // Loop through each element in the sorted part of the array
            A[j+1] = A[j];  // Move the current element to the right
            j--;
        }
        A[j+1] = x;  // Insert the current element in its correct position
    }
}

int main() {

    int A[] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1};  // Initialize an array of integers
    Print(A, sizeof(A)/sizeof(A[0]), "       A");  // Print the original array

    InsertionSort(A, sizeof(A)/sizeof(A[0]));  // Sort the array using Insertion Sort
    Print(A, sizeof(A)/sizeof(A[0]), "Sorted A");  // Print the sorted array

    return 0;  // End the program
}
