#include <iostream>

using std::cout;
using std::endl;
using std::flush;
using std::string;

// Function to print an array
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

// Function to perform Shell Sort
void ShellSort(int A[], int n){
    // Start with a large gap and reduce by half in each iteration
    for (int gap=n/2; gap>=1; gap/=2){
        // Perform Insertion Sort on subarrays separated by gap
        for (int j=gap; j<n; j++){
            int temp = A[j];
            int i = j - gap;
            while (i >= 0 && A[i] > temp){
                A[i+gap] = A[i];
                i = i-gap;
            }
            A[i+gap] = temp;
        }
    }
}

// Driver function
int main() {

    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = sizeof(A)/sizeof(A[0]);

    // Print the original array
    Print(A, n, "\t\tA");

    // Sort the array using Shell Sort
    ShellSort(A, n);

    // Print the sorted array
    Print(A, n, " Sorted A");

    return 0;
}
