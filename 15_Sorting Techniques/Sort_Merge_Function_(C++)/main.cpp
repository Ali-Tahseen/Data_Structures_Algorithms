#include <iostream>  // Include the iostream header file

using namespace std;  // Use the standard namespace



template <class T>  // Declare a template function with a generic type T


void Print(T& vec, int n, string s){  // Define a function to print an array
    cout << s << ": [" << flush;  // Output the string s and start the array
    for (int i=0; i<n; i++){  // Loop through the array
        cout << vec[i] << flush;  // Output the current element
        if (i < n-1){  // If this is not the last element
            cout << ", " << flush;  // Output a comma and space
        }
    }
    cout << "]" << endl;  // End the array and output a newline
}

void Merge(int x[], int y[], int z[], int m, int n){  // Define a function to merge two sorted arrays
    int i = 0;  // Initialize a counter for the first array
    int j = 0;  // Initialize a counter for the second array
    int k = 0;  // Initialize a counter for the merged array
    while (i < m && j < n){  // While there are still elements in both arrays
        if (x[i] < y[j]){  // If the current element of the first array is smaller
            z[k++] = x[i++];  // Add it to the merged array and increment the counters
        } else {
            z[k++] = y[j++];  // Otherwise, add the current element of the second array to the merged array and increment the counters
        }
    }
    while (i < m){  // If there are still elements in the first array
        z[k++] = x[i++];  // Add them to the merged array and increment the counters
    }
    while (j < n){  // If there are still elements in the second array
        z[k++] = x[j++];  // Add them to the merged array and increment the counters
    }
}

void MergeSingle(int A[], int low, int mid, int high){  // Define a function to merge two sorted subarrays of a larger array
    int i = low;  // Initialize a counter for the first subarray
    int j = mid+1;  // Initialize a counter for the second subarray
    int k = low;  // Initialize a counter for the merged subarray
    int B[high+1];  // Create a temporary array to store the merged subarray
    while (i <= mid && j <= high){  // While there are still elements in both subarrays
        if (A[i] < A[j]){  // If the current element of the first subarray is smaller
            B[k++] = A[i++];  // Add it to the merged subarray and increment the counters
        } else {
            B[k++] = A[j++];  // Otherwise, add the current element of the second subarray to the merged subarray and increment the counters
        }
    }
    while (i <= mid){  // If there are still elements in the first subarray
        B[k++] = A[i++];  // Add them to the merged subarray and increment the counters
    }
    while (j <= high){  // If there are still elements in the second subarray
        B[k++] = A[j++];  // Add them to the merged subarray and increment the counters
    }
    for (int i=low; i<=high; i++){  // Copy the merged subarray from B back to A
        A[i] = B[i];
    }
}

int main() {

    int A[] = {2, 10, 18, 20, 23};  // Define an array of integers
    int m = sizeof(A)/sizeof(A[0]);  // Calculate the size of the array
    Print(A, m, "\t A");  // Print the array

    int B[] = {4, 9, 19, 25};  // Define another array of integers
    int n = sizeof(B)/sizeof(B[0]);  // Calculate the size of the array
    Print(B, n, "\t B");  // Print the array

    int r = m+n;  // Calculate the size of the merged array
    int C[r];  // Declare an array to store the merged array
    Merge(A, B, C, m, n);  // Merge the two arrays and store the result in C

    // Print function does not work for variable length array C
    cout << "Sorted" << ": [" << flush; // Output a message indicating that the array is sorted and start the array
    for (int i=0; i<r; i++){  // Loop through the merged array
        cout << C[i] << flush;  // Output the current element
        if (i < r-1){  // If this is not the last element
            cout << ", " << flush;  // Output a comma and space
        }
    }
    cout << "]" << endl;  // End the array and output a newline

    cout << endl;  // Output a newline

    int D[] = {2, 5, 8, 12, 3, 6, 7, 10};  // Define another array of integers
    Print(D, sizeof(D)/sizeof(D[0]), "\t\tD");  // Print the array
    MergeSingle(D, 0, 3, 7);  // Merge two subarrays of D and store the result in D
    Print(D, sizeof(D)/sizeof(D[0]), " Sorted D");  // Print the sorted array

    return 0;  // Return 0 to indicate successful completion of the program
}
