#include <iostream>

using namespace std;

template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;  // Print the ith element of the vector
        if (i < n-1){
            cout << ", " << flush;  // Print a comma and a space if it's not the last element
        }
    }
    cout << "]" << endl;  // Print the closing bracket and a newline character
}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Quick Sort using INT_MAX or INFINITY
int partitionA(int A[], int low, int high){
    int pivot = A[low];  // Choose the pivot element
    int i = low;
    int j = high;

    do {
        // Increment i as long as elements are smaller/equal to pivot
        do {i++;} while (A[i] <= pivot);

        // Decrement j as long as elements are larger than pivot
        do {j--;} while (A[j] > pivot);

        if (i < j){
            swap(&A[i], &A[j]);  // Swap A[i] and A[j] if i is less than j
        }
    } while (i < j);

    swap(&A[low], &A[j]);  // Swap the pivot element with A[j]
    return j;  // Return the index of the pivot element
}

void QuickSortA(int A[], int low, int high){
    if (low < high){
        int j = partitionA(A, low, high);  // Partition the array using the pivot element
        QuickSortA(A, low, j);    // Sort the left subarray recursively
        QuickSortA(A, j+1, high);  // Sort the right subarray recursively
    }
}

// Last Element is Pivot + without using INT_MAX or INFINITY
int partitionLast(int A[], int low, int high){
    int pivot = A[high];  // Choose the pivot element
    int i = low - 1;
    for (int j=low; j<=high-1; j++){
        if (A[j] < pivot){
            i++;
            swap(&A[i], &A[j]);  // Swap A[i] and A[j] if A[j] is less than the pivot
        }
    }
    swap(&A[i+1], &A[high]);  // Swap the pivot element with the element at A[i+1]
    return i+1;  // Return the index of the pivot element
}

void QuickSortLast(int A[], int low, int high){
    if (low < high){
        int p = partitionLast(A, low, high); // A[p] in sorted position
        QuickSortLast(A, low, p-1); // Sort elements in range: A[low], A[p-1]
        QuickSortLast(A, p+1, high); // Sort elements in range: A[p+1], A[high]
    }
}

// First Element is Pivot + without using INT_MAX or INFINITY
int partition(int A[], int low, int high){
    int pivot = A[low];  // Choose the pivot element
    int i = low + 1;
    int j = high;

    while (true){
        while (i <= j && A[i] <= pivot){
            i++;  // Increment i as long as A[i] is less than or equal to the pivot
        }
        while (A[j] >= pivot && j >= i){
            j--;  // Decrement j as long as A[j] is greater than or equal to the pivot
        }
        if (j < i){
            break;  // If j is less than i, break out of the loop
        } else {
            swap(&A[i], &A[j]);  // Swap A[i] and A[j] if i is less than or equal to j
        }
    }
    swap(&A[low], &A[j]);  // Swap the pivot element with A[j]
    return j;  // Return the index of the pivot element
}

void QuickSort(int A[], int low, int high){
    if (low < high){
        int p = partition(A, low, high);  // Partition the array using the pivot element
        QuickSort(A, low, p-1);  // Sort the left subarray recursively
        QuickSort(A, p+1, high);  // Sort the right subarray recursively
    }
}

int main() {

    cout << "Using INT_MAX or Infinity" << endl;
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, 32767};  // Define an array of integers
    int n = sizeof(A)/sizeof(A[0]);  // Calculate the size of the array
    Print(A, n-1, "\t\tA");  // Print the array A

    QuickSortA(A, 0, n-1);  // Sort the array A using QuickSortA
    Print(A, n-1, " Sorted A");  // Print the sorted array A
    cout << endl;


    cout << "Last Element as Pivot + w/o INT_MAX or Infinity" << endl;
    int B[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};  // Define an array of integers
    Print(B, sizeof(B)/sizeof(B[0]), "\t\tB");  // Print the array B

    QuickSortLast(B, 0, sizeof(B)/sizeof(B[0])-1);  // Sort the array B using QuickSortLast
    Print(B, sizeof(B)/sizeof(B[0]), " Sorted B");  // Print the sorted array B
    cout << endl;

    cout << "First Element as Pivot + w/o INT_MAX or Infinity" << endl;
    int C[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};  // Define an array of integers
    Print(C, sizeof(C)/sizeof(C[0]), "\t\tC");  // Print the array C

    QuickSort(C, 0, sizeof(C)/sizeof(C[0])-1);  // Sort the array C using QuickSort
    Print(C, sizeof(C)/sizeof(C[0]), " Sorted C");  // Print the sorted array C

    return 0;
}
